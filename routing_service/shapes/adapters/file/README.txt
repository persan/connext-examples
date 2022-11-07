Example : Using a File Adapter in C
====================================

This example illustrates how to use RTI Routing Service Adapter SDK to create an 
adapter that writes and reads data from files. Routing Service allows you to 
bridge data from different data domains with a pluggable adapter interface.

To learn how to implement your own adapter, you can follow this example and 
others in this folder to inspect the code that is distributed with these 
adapters. The file adapter can read data from files with a specific format 
and provide it to Routing Service, or receive data from Routing Service and 
write it into files.

In this example, we will first write topic data (a colored square and circle) 
into a file and then use that file to write it back into Connext DDS, allowing 
us to modify the data with a text editor.

Steps
------

1. Compile the Adapter in adapters/file/src:

    - Set NDDSHOME to point to your RTI Connext DDS installation.

    - On Linux and macOS systems, enter:

        cd <path to examples>/routing_service/adapters/file/make
        make -f Makefile.<architecture>

    The adapter shared library, libfileadapter.so, will be copied to 
    <path to examples>/routing_service/adapters/file.

    - On Windows systems:
        Open the Visual Studio solution under 
        <path to examples>/routing_service/adapters/file/windows. 
        For example, if you are using Visual Studio 2013, open 
        fileadapter-vs2013.sln. Build the solution. The adapter shared 
        library, fileadapter.dll, will be copied to <path to examples>/routing_service/adapters/file.

2. Route data from Connext DDS to files:

    Run Shapes Demo and Routing Service:

    - Start Shapes Demo on domain 0 (the default domain).

    - Start Routing Service by entering the following in a command shell:

        cd <NDDSHOME>
        bin/rtiroutingservice
            -cfgFile <path to examples>/routing_service/shapes/file_bridge.xml \
            -cfgName dds_to_file

    - In Shapes Demo, publish some Squares.

    - Wait a few seconds and then stop Routing Service by pressing Ctrl-c.

    A file called MySquare.txt should have been created in the current directory. 
    Open it with a text editor of your choice. It should contain several lines, 
    each consisting of a list of <field>=<value> elements. Each line represents 
    a sample (Square) published by Shapes Demo and written by Routing Service 
    and the file adapter.

    - On Linux and macOS systems, you can see how new samples are appended to the 
    file by running the following command while Routing Service runs:

        tail - f MySquare.txt

3. Route data from a file to Connext DDS:

    - In Shapes Demo, delete the Square publisher and create a Square subscriber.

    - Start Routing Service by entering the following in a command shell:

        cd <NDDSHOME>
        bin/rtiroutingservice
                -cfgFile <path to examples>/routing_service/shapes/file_bridge.xml \
                -cfgName file_to_dds

    You should see squares being received by Shapes Demo. These samples come 
    from what we recorded before.

    You might have noticed that the rate at which the shape moves is much slower. 
    This is the rate at which the file adapter is providing data to Routing Service. 
    To change this rate, open <path to examples>/routing_service/shapes/file_bridge.xml 
    and look for <route name=”square_file”> within <routing service name=”file_to_dds”>. 
    In the <property> tag, change the property ReadPeriod from 1000 (milliseconds) to 100.

    - Stop Routing Service and restart it as described in previous steps. The squares 
    should be received and displayed about ten times faster.

    Other properties that you can configure in the file adapter are: 
        - In the input:
            - FileName
            - MaxSampleSize
            - Loop
            - SamplesPerRead
        - In the output:
            - FileName
            - WriteMode
            - Flush

    You can also edit the text file and publish the new data.

    - Open MySquare.txt and replace all the occurrences of “shapesize=30” with “shapesize=100”.

    - Stop Routing Service and restart it as described in previous steps. The 
    squares will have the same position and color, but they will be bigger now.

4. Customize the File Adapter:

    In the example, the file adapters use a specific format, which you already saw 
    in the file MySquare.txt. Now try adapting the example to your own format.

    The code that reads/writes from the file is in adapters/file/src/LineConversion.c.

    - Edit the function RTI_RoutingServiceFileAdapter_read_sample to implement how 
    file data maps into a sample.

    - Edit the function RTI_RoutingServiceFileAdapter_write_sample to implement how 
    a sample is written to a file.