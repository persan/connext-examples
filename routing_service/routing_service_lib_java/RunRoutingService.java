/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

import com.rti.dds.domain.DomainParticipantFactory;
import com.rti.routingservice.*;
import com.rti.routingservice.infrastructure.*;

public class RunRoutingService {
    

    public static void main(String[] args) {
        RoutingServiceProperty property = new RoutingServiceProperty();

        property.serviceName = "RoutingService";
        if (args.length >= 1){
            property.cfgFile = args[0];
        } else {
            property.cfgStrings = EXAMPLE_CONFIG_XML;
        }


        /* Uncomment this to turn on additional logging
            property.serviceVerbosity = RoutingService.LOG_VERBOSITY_INFO;
            property.ddsVerbosity = RoutingService.LOG_VERBOSITY_WARNINGS;
        */

        try (RoutingService rs = new RoutingService(property)) {
            rs.start();
            System.out.println("Routing Service started");
    
            Runtime.getRuntime().addShutdownHook(new Thread() {
            public void run() {
                    rs.stop();
                    rs.close();
                    DomainParticipantFactory.finalize_instance();
                    System.out.println("Routing Service deleted");
                }
            });

            /* Wait to be stopped */
            while (true) {
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException ix) {
                }
            }
        } catch (RoutingServiceException ex) {
            System.out.println("Error running routing service: " + ex);
        }
    }
    
    static final String[] EXAMPLE_CONFIG_XML = {"<?xml version=\"1.0\"?>\n"
            + "<dds xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">\n"
            + "  <routing_service name=\"RoutingService\">\n"
            + "      \n"
            + "    <domain_route name=\"DomainRoute\">\n"
            + "      <participant name=\"1\">\n"
            + "        <domain_id>0</domain_id>\n"
            + "      </participant>\n"
            + "      <participant name=\"2\">\n"
            + "        <domain_id>1</domain_id>\n"
            + "      </participant>\n"
            + "      \n"
            + "      <session name=\"Session\">\n"
            + "        <auto_topic_route name=\"AllForward\">\n"
            + "          <input participant=\"1\">\n"
            + "            <creation_mode>ON_DOMAIN_MATCH</creation_mode>\n"
            + "          <deny_topic_name_filter>rti/*</deny_topic_name_filter>\n"
            + "          </input>\n"
            + "          <output>\n"
            + "            <creation_mode>ON_DOMAIN_OR_ROUTE_MATCH</creation_mode>\n"
            + "          <deny_topic_name_filter>rti/*</deny_topic_name_filter>\n"
            + "          </output>\n"
            + "        </auto_topic_route>\n"
            + "        \n"
            + "        <auto_topic_route name=\"AllBackward\">\n"
            + "          <input participant=\"2\">\n"            
            + "          <deny_topic_name_filter>rti/*</deny_topic_name_filter>\n"
            + "            <creation_mode>ON_DOMAIN_OR_ROUTE_MATCH</creation_mode>\n"
            + "          </input>\n"
            + "          <output>\n"
            + "            <creation_mode>ON_DOMAIN_MATCH</creation_mode>\n"            
            + "          <deny_topic_name_filter>rti/*</deny_topic_name_filter>\n"
            + "          </output>\n"
            + "        </auto_topic_route>\n"
            + "      </session>\n"
            + "    </domain_route>\n"
            + "  </routing_service>\n"
            + "</dds>\n"};
}
