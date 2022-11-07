--  #include "rti_dl/rti_dl_c.h"
--  
--  /*****************************************************************************/
--  /* Local constants & macros                                                  */
--  /*****************************************************************************/
--  
--  /* Command line defaults */
--  /* Change here the default domain ID or pass it as a parameter when calling to
--   * the executable. For example, to run it in domain 115 do:
--   *  Hello 115
--   */
--  #define DEFAULT_DOMAIN_ID       0
--  #define DEFAULT_MESSAGE         "This is an example of RTI Distributed Logger"
--  #define MAX_STRING_SIZE         1024
--  
--  /* The maximum value for Domain ID. The effective value depends on the QoS,
--   * in particular to the value of the field:
--   *              DDS_RtpsWellKnownPorts_t.domainId_gain
--   * The default value is 250, so we just limit to that statically so we can
--   * check the validity before attempting to create the domain participant.
--   */
--  #define DOMAIN_ID_MAX               250
--  
--  /*****************************************************************************/
--  /* main                                                                      */
--  /*                                                                           */
--  /* Application main entry point                                              */
--  /*****************************************************************************/
with dds.distlog.Logger;
procedure main is
   procedure hello_main ( domainId : DDS.Domain_id_T)is 
   --  int hello_main(int domainId) {
   --      
   --      char message[MAX_STRING_SIZE];
   --      int main_result = 1; /* error by default */
   --      RTI_DL_DistLogger *dl = NULL;
      dl : dds.distlog.Logger.ref;
      dlOptions : aliased dds.distlog.options.ref;
      
   --      RTI_DL_Options *dlOptions = NULL;
   --      DDS_ReturnCode_t retcode = DDS_RETCODE_OK;
   --      RTIBool ok = RTI_FALSE;
   --      int i;
   begin
      --  --- Set Up ---------------------------------------------------------
      --  
      put_Line ("RTI Distributed Logger Example Application");
      put_Line ("Copyright 2011 Real-Time Innovations, Inc.");
      --  
      --  First we need to create the options If no options are provided,
      --  RTI DL creates default ones and work with them.
      put_Line ("Creating default options");
      
      --      dlOptions = RTI_DL_Options_createDefault();
      --  
      --      /* We can personalize RTI DL using the Options */
      put_Line ("Configuring options");
      --      retcode = RTI_DL_Options_setDomainId(dlOptions, domainId);
      --      if (retcode != DDS_RETCODE_OK){
      --          printf("Error setting domain ID");
      --          goto clean_exit;
      --      }
      --      retcode = RTI_DL_Options_setApplicationKind(dlOptions,
      --              "Hello Distributed Logger C Example");
      --      if (retcode != DDS_RETCODE_OK){
      --          printf("Error setting application kind");
      --          goto clean_exit;
      --      }
      --  
      --      /* Before using the RTI DL, we set the Options
      --       otherwise, default options are created */
      put_Line ("Setting options");
      --      ok = RTI_DL_DistLogger_setOptions(dlOptions);
      --      if(!ok){
      --          printf("Error setting options");
      --          goto clean_exit;
      --      }
      --  
      --      /* instantiate the logger instance */
      put_Line ("Getting Distributed Logger");
      --      dl = RTI_DL_DistLogger_getInstance();
      --      if (dl == NULL) {
      --          printf("Error: Unable to get RTI Distributed Logger Instance");
      --          goto clean_exit;
      --      }
      --  
      put_Line ("Ready to use RTI DL in domain:" & domainId'Img);
      put_Line ("We are going to send messages with different error levels.");
      put_Line ("Press CTRL+C to terminate or wait until # reaches 99.");
      --      
      --      /* RTI provides APIs for detecting when data readers and data writers
      --       * join the network. You can also configure data durability so that data
      --       * readers can receive data that were written before they started.
      --       * However, for the sake of keeping this example as simple as possible,
      --       * it asks you to use RTI Monitor.
      --       */
      --  
      --      /* Sending error messages */
      --      /*If you want to make this example an infinit loop, 
      --       comment out the for loop and use a while loop instead.
      --       */
      --      for (i = 0; i < 100; i++) {
      --          RTI_SNPRINTF(message, MAX_STRING_SIZE, "%s #%d", DEFAULT_MESSAGE, i);
      --          printf("%s\n", message);
      --          fflush(stdout);
      --          RTI_DL_DistLogger_error(dl, message);
      --          RTI_DL_DistLogger_debug(dl, message);
      --          RTI_DL_DistLogger_warning(dl, message);
      --  
      --          RTI_DL_Utility_sleep(1000);
      --      }
      --  
      --      /* --- Clean Up ------------------------------------------------------- */
      --  
      --      main_result = 0;
      --      clean_exit: printf("Exiting...");
      --  
      --      if (dlOptions != NULL) {
      --          RTI_DL_Options_delete(dlOptions);
      --      }
      --  
      --      if (dl != NULL) {
      --          /* If we don't finalize it, it will forward all the log messages */
      --          retcode = RTI_DL_DistLogger_finalizeInstance();
      --          if (retcode != DDS_RETCODE_OK) {
      --              printf(
      --                      "Error: Unable to finalize RTI Distributed Logger instance");
      --              main_result = 1;
      --          }
      --          /*Remember to finalize the factory once your DDS program is finished */
      --          DDS_DomainParticipantFactory_finalize_instance();
      --  
      --      }
      --  
      --      return main_result;
      --  }
   end hello_main;
   domainId :  DDS.DomainId_T := 0;
begin
   if Ada.Command_Line.Argument_Count > 0 then
      domainId := DDS.DomainId_T'Value (Ada.Command_Line.Argument (1));
   end if;

   --      /* Uncomment this to turn on additional logging
   --   *     NDDS_Config_Logger_set_verbosity_by_category(
   --   *             NDDS_Config_Logger_get_instance(),
   --   *                     NDDS_CONFIG_LOG_CATEGORY_API, 
   --   *                             NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
   --   *                                 */
   --  
   hello_main (domainId);
end main;
