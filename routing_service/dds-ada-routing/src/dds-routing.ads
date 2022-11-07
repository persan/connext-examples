package DDS.Routing is
--e @brief Property name  
   type Name_Value is record
      Name  : DDS.String;
      Value : System.Address;
   end record with Convention => C_Pass_By_Copy;

   --e @brief Property value  
   --e @brief Array of configuration properties.  
   type Properties is record
      Properties    : access RTI_RoutingServiceNameValue;
      Count         : aliased DDS.Integer;
      String_Values : aliased DDS.Boolean;
   end record with Convention => C_Pass_By_Copy;  
   

end DDS.Routing;
