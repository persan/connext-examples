with DDS;
package Persistence_Service is
   Config :  DDS.String := DDS.To_Dds_String
     ("<?xml version=""1.0"" encoding=""ISO-8859-1""?>" &
        "<dds xmlns:xsi=""http://www.w3.org/2001/XMLSchema-instance"" xsi:noNamespaceSchemaLocation=""../schema/rti_persistence_service.xsd"">" &
      -- "<!-- ================================================================= -->" &
      -- "<!-- Persist all data in memory -->" &
      -- "<!-- ================================================================= -->" &
        "<persistence_service name=""default"">" &

        "    <annotation>" &
        "        <documentation>" &
        "            Persists in memory all topics published with TRANSIENT durability.       " &
        "        </documentation>" &
        "    </annotation>" &

        "    <participant name=""defaultParticipant"">" &
        "        <!-- <domain_id>0</domain_id> -->" &
        "        <persistence_group name=""persistAll"">" &
        "            <filter>*</filter>" &
        "        </persistence_group>" &
        "    </participant>" &

        "</persistence_service>" &
      --  "<!-- ================================================================= -->" &
      --  "<!-- Persist all data in disk -->" &
      --  "<!-- ================================================================= -->" &
        "<persistence_service name=""defaultDisk"">" &

        "    <annotation>" &
        "        <documentation>" &
        "            Persists in the file system all topics published with PERSISTENT durability." &
        "        </documentation>" &
        "    </annotation>" &

        "    <persistent_storage>" &
        "        <filesystem>" &
        "            <!-- <directory>MyDirectory</directory> -->" &
        "            <!-- <file_prefix>MyPersistenceFiles_</file_prefix> -->" &
        "        </filesystem>" &
        "    </persistent_storage>" &
        "    <participant name=""defaultParticipant"">" &
        "        <!-- <domain_id>0</domain_id> -->" &
        "        <persistence_group name=""persistAll"">" &
        "            <filter>*</filter>" &
        "        </persistence_group>" &
        "    </participant>" &
        "</persistence_service>" &
        "" &
        "</dds>");

end Persistence_Service;
