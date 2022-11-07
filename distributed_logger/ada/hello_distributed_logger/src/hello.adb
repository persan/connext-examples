with Ada.Command_Line;
with Ada.Exceptions;
with Ada.Text_IO; use Ada.Text_IO;
with dds.distlog.Logger;
with dds.distlog.options;
with DDS.DomainParticipantFactory;

procedure hello is
   procedure hello_main ( domainId : DDS.DomainId_T)is 
      dl        : dds.distlog.Logger.ref_access := dds.distlog.Logger.getInstance;
      dlOptions : aliased dds.distlog.options.ref;
      
   begin
      begin
         --  Set Up 
         --  
         put_Line ("RTI Distributed Logger Example Application");
         put_Line ("Copyright 2011 Real-Time Innovations, Inc.");
         
         --  First we need to create the options If no options are provided,
         --  RTI DL creates default ones and work with them.
         put_Line ("Creating default options");      
         put_Line ("Configuring options");
         dlOptions.set_domain_id (domainId);
         dlOptions.set_Application_Kind ("Hello Distributed Logger C Example");

         --   Before using the RTI DL, we set the Options
         --   otherwise, default options are created */
         put_Line ("Setting options");
         dl.set_Options (dlOptions);
         
                  
         put_Line ("Ready to use RTI DL in domain:" & domainId'Img);
         put_Line ("We are going to send messages with different error levels.");
         put_Line ("Press CTRL+C to terminate or wait until # reaches 99.");

         --  RTI provides APIs for detecting when data readers and data writers
         --  join the network. You can also configure data durability so that data
         --  readers can receive data that were written before they started.
         --  However, for the sake of keeping this example as simple as possible,
         --  it asks you to use RTI Monitor.
         
         --  Sending error messages
         --  If you want to make this example an infinit loop, 
         --  comment out the for loop and use a while loop instead.
         
         for i in 1 .. 100 loop
            declare
               message : constant string := "My message #" & i'img;
            begin
               put_line (message);
               dl.error (message);
               dl.debug (message);
               dl.warning (message);
               delay 1.0;
            end;
         end loop;
      exception
         when E : others =>
            Put_Line (Ada.exceptions.Exception_Information (e));
      end;

      --  Clean Up
      --
      Put_Line ("Exiting...");
      Dl.Finalize;      
      DDS.DomainParticipantFactory.Get_Instance.Finalize_Instance;      
   end hello_main;
   
   domainId  :  DDS.DomainId_T := 0;
begin
   if Ada.Command_Line.Argument_Count > 0 then
      domainId := DDS.DomainId_T'Value (Ada.Command_Line.Argument (1));
   end if;
   
   --  Uncomment this to turn on additional logging
   --  RTIDDS.Config.Logger.Get_Instance.Set_Verbosity (RTIDDS.Config.Category_API, 
   --                                                  RTIDDS.Config.VERBOSITY_ALL);
   
   hello_main (domainId);
end hello;
