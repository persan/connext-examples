/*
 * (c) 2021 Copyright, Real-Time Innovations, Inc.  All rights reserved.
 * RTI grants Licensee a license to use, modify, compile, and create derivative
 * works of the Software.  Licensee has the right to distribute object form
 * only for use with RTI products.  The Software is provided "as is", with no
 * warranty of any type, including any warranty for fitness for any purpose.
 * RTI is under no obligation to maintain or support the Software.  RTI shall
 * not be liable for any incidental or consequential damages arising out of the
 * use or inability to use the software.
 */

var rti = rti || {};

/**
 * @namespace rti.builtintopicsdemo
 */
rti.builtintopicsdemo = {
    /**
     * Sets up the DomainParticipant to be able to read discovery information
     * and also initializes the mermaid framework
     */
    setupScenario: function() {
        // Variables for urls to enable and the settings
        const participantUrl =
            "/dds/rest1/applications/BuiltinTopicsDemoApp" +
            "/domain_participants/MyParticipant";
        const builtinSubscriberUrl =
            participantUrl +
            "/builtin_subscribers/Default";
        const participantReaderUrl =
            builtinSubscriberUrl +
            "/builtin_data_readers/ParticipantReader";
        const publicationReaderUrl =
            builtinSubscriberUrl +
            "/builtin_data_readers/PublicationReader";
        const subscriptionReaderUrl =
            builtinSubscriberUrl +
            "/builtin_data_readers/SubscriptionReader";
        
        const enableSettings = {
            method: "PUT",
            headers: "Cache-Control: no-cache"
        };

        // We make 5 PUT petitions in this specific order to correctly enable
        // the built-in DataReaders:
        // 1. Enable the built-in Subscriber
        // 2. Enable the three built-in DataReaders (order doesn't matter)
        // 3. Enable the DomainParticipant
        $.ajax()
        .then(function() {
            $.ajax(builtinSubscriberUrl, enableSettings);
        })
        .then(function() {
            $.ajax(participantReaderUrl, enableSettings);
            $.ajax(publicationReaderUrl, enableSettings);
            $.ajax(subscriptionReaderUrl, enableSettings);
        })
        .done(function() {
            $.ajax(participantUrl, enableSettings);
        });

        // Initialize the Mermaid framework
        const mermaidConfig = {
            startOnLoad: true,
            flowchart: {
                curve: 'basis',
                useMaxWidth: false
            }
        };
        mermaid.initialize(mermaidConfig);
    },

    /**
     * Sets up the enviroment for reading discovery information.
     * readBuiltinTopics will call the methods that will read discovery
     * information every 2 seconds.
     */
    readBuiltinTopics: function() {
        const participantReaderUrl =
            "/dds/rest1/applications/BuiltinTopicsDemoApp" +
            "/domain_participants/MyParticipant" +
            "/builtin_subscribers/Default" +
            "/builtin_data_readers/ParticipantReader";
        const publicationReaderUrl =
            "/dds/rest1/applications/BuiltinTopicsDemoApp" +
            "/domain_participants/MyParticipant" +
            "/builtin_subscribers/Default" +
            "/builtin_data_readers/PublicationReader";
        const subscriptionReaderUrl =
            "/dds/rest1/applications/BuiltinTopicsDemoApp" +
            "/domain_participants/MyParticipant" +
            "/builtin_subscribers/Default" +
            "/builtin_data_readers/SubscriptionReader";
        
        const getSettings = {
            sampleFormat: "json",
            removeFromReaderCache: "true"
        };

        const builtinTopicsDemoIntervalPeriod = 2000; // in milliseconds

        // Read the discovery information and update the hierarchy
        // to later call drawGraph() with the updated entities.
        // Participant data must be read before publication and subscription
        // data.
        // drawGraph() is called after all the updates have finished
        setInterval(function(){
            $.ajax()
            .then(function() {
                // Read participant data
                $.getJSON(participantReaderUrl, getSettings, function(data) {
                    rti.builtintopicsdemo.updateParticipants(data);
                });
            })
            .then(function() {
                // Read publication data
                $.getJSON(publicationReaderUrl, getSettings, function(data) {
                    rti.builtintopicsdemo.updatePublications(data);
                });

                // Read subscription data
                $.getJSON(subscriptionReaderUrl, getSettings, function(data) {
                    rti.builtintopicsdemo.updateSubscriptions(data);
                });
            })
            .done(function() {
                // Now we draw the graph with the updated entities
                rti.builtintopicsdemo.drawGraph();
            });
        }, builtinTopicsDemoIntervalPeriod);
    },

    /**
     * Updates the discovered DomainParticipants with the information recieved
     * via discovery
     * @param sampleSeq Sequence of samples recieved from participant data
     */
    updateParticipants: function(sampleSeq) {
        if (sampleSeq.length > 0) {
            rti.builtintopicsdemo.redrawGraph = true;
        }

        sampleSeq.forEach(function(sample) {
            // Process metadata
            const validData = sample.read_sample_info.valid_data;
            const instanceHandle = sample.read_sample_info.instance_handle;

            if (validData) {
                // Get the pid of the process the discovered DomainParticipant
                // belongs to
                const pid = sample.data
                    .property.value.find(
                        (prop) => prop.name == "dds.sys_info.process_id")
                    .value;
                // We add the new DomainParticipant if the data is valid
                rti.builtintopicsdemo.participants.push({
                    "key": sample.data.key,
                    "instanceHandle": instanceHandle,
                    "name": sample.data.participant_name.name,
                    "pid": pid,
                    "publishers": [],
                    "subscribers": []
                });
            } else {
                // Otherwise we remove the DomainParticipant with the specific
                // instance handle
                rti.builtintopicsdemo.participants.splice(
                    rti.builtintopicsdemo.participants.findIndex(participant =>
                        participant.instanceHandle == instanceHandle
                    )
                );
            }
        });
    },

    /**
     * Updates the discovered publications with the information recieved via
     * discovery
     * @param sampleSeq Sequence of samples recieved from publication data
     */
    updatePublications: function (sampleSeq) {
        if (sampleSeq.length > 0) {
            rti.builtintopicsdemo.redrawGraph = true;
        }

        sampleSeq.forEach(function (sample) {
            // Process metadata
            const validData = sample.read_sample_info.valid_data;
            const instanceHandle = sample.read_sample_info.instance_handle;

            if (validData) {
                const parentParticipantIndex = rti.builtintopicsdemo
                    .participants.findIndex(function(participant) {
                        return participant.key.value.toString()
                            == sample.data.participant_key.value.toString();
                    });

                // First we check that the parent DomainParticipant exists
                // If it doesn't, we don't do anything else
                if (parentParticipantIndex != -1) {
                    let parentPublisherIndex = rti.builtintopicsdemo
                        .participants[parentParticipantIndex]
                        .publishers.findIndex(function(publisher) {
                            return publisher.key.value.toString()
                                == sample.data.publisher_key.value.toString()
                        });
                    
                    // Now we check that parent Publisher exists, and add it if
                    // it doesn't exist yet
                    if (parentPublisherIndex == -1) {
                        parentPublisherIndex = rti.builtintopicsdemo
                            .participants[parentParticipantIndex]
                            .publishers.push({
                                "key": sample.data.publisher_key,
                                "dataWriters": []
                            }) - 1;
                    }

                    // Now we add the corresponding DataWriter
                    rti.builtintopicsdemo
                        .participants[parentParticipantIndex]
                        .publishers[parentPublisherIndex]
                        .dataWriters.push({
                            "key": sample.data.key,
                            "instanceHandle": instanceHandle,
                            "name": sample.data.publication_name.name,
                            "topic_name": sample.data.topic_name
                        });
                }
            } else {
                // Otherwise we remove the corresponding DataWriter. For that,
                // we search for the DataWriter with the given instance handle
                for (let participant of rti.builtintopicsdemo.participants) {
                    let foundWriter = false;

                    for (let [i, publisher] of participant.publishers.entries()) {
                        for (let [j, dataWriter] of publisher.dataWriters.entries()) {
                            // If we find the DataWriter, delete it
                            if (dataWriter.instanceHandle == instanceHandle) {
                                publisher.dataWriters.splice(j);
                                foundWriter = true;
                                break;
                            }
                        }

                        if (foundWriter) {
                            // If the Publisher doesn't have DataWriters,
                            // delete it too
                            if (publisher.dataWriters.length == 0) {
                                participant.publishers.splice(i);
                            }
                            break;
                        }
                    }

                    if (foundWriter) {
                        break;
                    }
                }
            }
        });
    },

    /**
     * Updates the discovered subscriptions with the information recieved via
     * discovery
     * @param sampleSeq Sequence of samples recieved from subscription data
     */
    updateSubscriptions: function (sampleSeq) {
        if (sampleSeq.length > 0) {
            rti.builtintopicsdemo.redrawGraph = true;
        }

        sampleSeq.forEach(function (sample) {
            // Process metadata
            const validData = sample.read_sample_info.valid_data;
            const instanceHandle = sample.read_sample_info.instance_handle;

            if (validData) {
                const parentParticipantIndex = rti.builtintopicsdemo
                    .participants.findIndex(function(participant) {
                        return participant.key.value.toString()
                            == sample.data.participant_key.value.toString();
                    });
                
                // First we check that the parent DomainParticipant exists
                // If it doesn't, we don't do anything else
                if (parentParticipantIndex != -1) {
                    let parentSubscriberIndex = rti.builtintopicsdemo
                        .participants[parentParticipantIndex]
                        .subscribers.findIndex(function(subscriber) {
                            return subscriber.key.value.toString()
                                == sample.data.subscriber_key.value.toString();
                        });
                    
                    // Now we check that parent Subscriber exists, and add it if
                    // it doesn't exist yet
                    if (parentSubscriberIndex == -1) {
                        parentSubscriberIndex = rti.builtintopicsdemo
                            .participants[parentParticipantIndex]
                            .subscribers.push({
                                "key": sample.data.subscriber_key,
                                "dataReaders": []
                            }) - 1;
                    }

                    // Now we add the corresponding DataReader
                    rti.builtintopicsdemo
                        .participants[parentParticipantIndex]
                        .subscribers[parentSubscriberIndex]
                        .dataReaders.push({
                            "key": sample.data.key,
                            "instanceHandle": instanceHandle,
                            "name": sample.data.subscription_name.name,
                            "topic_name": sample.data.topic_name
                        });
                }
            } else {
                // Otherwise we remove the corresponding DataReader. For that,
                // we search for the DataReader with the given instance handle
                for (let participant of rti.builtintopicsdemo.participants) {
                    let foundReader = false;
                    
                    for (let [i, subscriber] of participant.subscribers.entries()) {
                        for (let [j, dataReader] of subscriber.dataReaders.entries()) {
                            // If we find the DataReader, delete it
                            if (dataReader.instanceHandle == instanceHandle) {
                                subscriber.dataReaders.splice(j);
                                foundReader = true;
                                break;
                            }
                        }

                        if (foundReader) {
                            // If the Subscriber doesn't have DataReaders,
                            // delete it too
                            if (subscriber.dataReaders.length == 0) {
                                participant.subscribers.splice(i);
                            }
                            break;
                        }
                    }

                    if (foundReader) {
                        break;
                    }
                }
            }
        });
    },
    
    /**
     * Generates the string representation of the graph and adds it to the
     * corresponding mermaid div, which is responsible of rendering the graph.
     */
    drawGraph: function() {
        if (rti.builtintopicsdemo.redrawGraph) {
            let graphDefinition = "graph LR\n";

            // We build the graph definition by drawing every DomainParticipant
            // in a different subgraph
            rti.builtintopicsdemo.participants.forEach(function(participant, i) {
                graphDefinition += `subgraph Participant_${i}[${participant.pid}-DP`;

                if (participant.name != "") {
                    graphDefinition += ": " + participant.name;
                }

                graphDefinition += "]\n";

                // Generate the Publishers subgraphs
                participant.publishers.forEach(function(publisher, j) {
                    dataWritersDefinition = "";
                    
                    publisher.dataWriters.forEach(function(dataWriter, k) {
                        if (rti.builtintopicsdemo.isValidTopic(dataWriter.topic_name)) {
                            dataWritersDefinition += `DataWriter_${i}_${j}_${k}[DW`;
                            
                            if (dataWriter.name != "") {
                                dataWritersDefinition += ": " + dataWriter.name;
                            }
                            
                            dataWritersDefinition += "]\n";
                        }
                    });

                    // Draw the Publisher graph only if there's at least one
                    // DataWriter to render
                    if (dataWritersDefinition != "") {
                        graphDefinition += `subgraph Publisher_${i}_${j}[Publisher]\n`;
                        graphDefinition += dataWritersDefinition;
                        graphDefinition += "end\n";
                    }
                });

                // Generate the Subscribers subgraphs
                participant.subscribers.forEach(function(subscriber, j) {
                    dataReadersDefinition = "";

                    subscriber.dataReaders.forEach(function (dataReader, k) {
                        if (rti.builtintopicsdemo.isValidTopic(dataReader.topic_name)) {
                            dataReadersDefinition += `DataReader_${i}_${j}_${k}[DR`;

                            if (dataReader.name != "") {
                                dataReadersDefinition += ": " + dataReader.name;
                            }

                            dataReadersDefinition += "]\n";
                        }
                    });

                    // Draw the Subscriber graph only if there's at least one
                    // DataReader to render
                    if (dataReadersDefinition != "") {
                        graphDefinition += `subgraph Subscriber_${i}_${j}[Subscriber]\n`;
                        graphDefinition += dataReadersDefinition;
                        graphDefinition += "end\n";
                    }
                });

                graphDefinition += "end\n";
            });

            // Now we generate the nodes that connect the DataReaders/DataWriters
            // to the Topics
            rti.builtintopicsdemo.participants.forEach(function(participant, i) {
                participant.publishers.forEach(function(publisher, j) {
                    publisher.dataWriters.forEach(function(dataWriter, k) {
                        if (rti.builtintopicsdemo.isValidTopic(dataWriter.topic_name)) {
                            graphDefinition += `DataWriter_${i}_${j}_${k}
                                -- publishes to --- ${dataWriter.topic_name}\n`;
                        }
                    });
                });

                participant.subscribers.forEach(function(subscriber, j) {
                    subscriber.dataReaders.forEach(function(dataReader, k) {
                        if (rti.builtintopicsdemo.isValidTopic(dataReader.topic_name)) {
                            graphDefinition += `DataReader_${i}_${j}_${k}
                                -- subscribes to --- ${dataReader.topic_name}\n`;
                        }
                    });
                });
            });

            // We need this conditional because mermaid doesn't like empty
            // graphs
            if (graphDefinition == "graph LR\n") {
                $('#mermaid').html("<strong>No discovered entities</strong>");
            }
            else {
                $('#mermaid').html(graphDefinition).removeAttr('data-processed');
                mermaid.init(undefined, $("#mermaid"));
            }

            rti.builtintopicsdemo.redrawGraph = false;
        }
    },

    /**
     * This function switches the drawing of RTI internal Topics
     */
    toggleInternalTopics: function() {
        rti.builtintopicsdemo.drawInternalTopics =
            !rti.builtintopicsdemo.drawInternalTopics;
        rti.builtintopicsdemo.redrawGraph = true;
    },

    /**
     * This function checks if a Topic name should be rendered or not
     */
    isValidTopic: function(topic_name){
        return !topic_name.startsWith("rti")
            || rti.builtintopicsdemo.drawInternalTopics;
    }
}

/**
 * Array of DomainParticipants
 */
rti.builtintopicsdemo.participants = [];

/**
 * Variable to control when we need to redraw the graph
 */
rti.builtintopicsdemo.redrawGraph = true;

/**
 * Variable to control whether to draw RTI internal Topics or not
 * 
 */
rti.builtintopicsdemo.drawInternalTopics = false;
