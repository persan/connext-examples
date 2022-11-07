with RTIDDS.Low_Level.routingservice_routingservice_infrastructure_h;
with RTIDDS.Low_Level.routingservice_routingservice_adapter_h;

package File_Adapter is

   use RTIDDS.Low_Level.routingservice_routingservice_adapter_h;
   use RTIDDS.Low_Level.routingservice_routingservice_infrastructure_h;

   function Create ( Properties : access RTI_RoutingServiceProperties;
                     Env        : access RTI_RoutingServiceEnvironment) return access RTI_RoutingServiceAdapterPlugin  with
     Export => True,
     Link_Name => "RoutingServiceFileAdapterPlugin_create" ,
     Convention => C;
end File_Adapter;
