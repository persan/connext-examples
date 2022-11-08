with Ada.Exceptions;
with Ada.Text_IO; 
with Ada.Command_Line;

with DDS.DomainParticipant;
with DDS.DomainParticipantFactory;
with DDS.Publisher;
with DDS.Topic;
with DDS.DataWriter;

with Hello.HelloWorld_DataWriter;
with Hello.HelloWorld_TypeSupport;
with RTIDDS.Config;

procedure HelloWorld_Publisher is
   Factory : DDS.DomainParticipantFactory.Ref_Access := DDS.DomainParticipantFactory.Get_Instance;
   use type DDS.DomainParticipant.Ref_Access;
   use type DDS.Publisher.Ref_Access;
   use type DDS.Topic.Ref_Access;
   use type DDS.DataWriter.Ref_Access;
   use type Hello.HelloWorld_DataWriter.Ref_Access;
   use type Hello.HelloWorld_Access;
   use Ada.Text_IO;
   
   procedure Publisher_Main (DomainId : DDS.DomainId_T; Sample_Count : Integer) is
      Participant       : DDS.DomainParticipant.Ref_Access;
      Publisher         : DDS.Publisher.Ref_Access;
      Topic             : DDS.Topic.Ref_Access;
      Topic_Name        : constant DDS.String := DDS.To_DDS_String ("Example HelloWorld");      
      HelloWorld_Writer : Hello.HelloWorld_DataWriter.Ref_Access;
      Instance          : Hello.HelloWorld_Access;
      
      Instance_Handle   : DDS.InstanceHandle_T := DDS.Null_InstanceHandle_T;

      Send_Period     : Duration := 4.0;
      Participant_Qos : DDS.DomainParticipantQos;
      Publisher_Qos   : DDS.PublisherQos;
      Topic_Qos       : DDS.TopicQos;
      DataWriter_Qos  : DDS.DataWriterQos;
      
   begin
      begin
         Factory.Get_Default_Participant_Qos (Participant_Qos);            
         Participant := Factory.Create_Participant ( DomainId, PARTICIPANT_QOS);
      
         if Participant = null then
            raise Program_Error with "create_participant error";
         end if;
      
         Participant.Get_Default_Publisher_Qos (Publisher_Qos);      
         Publisher := Participant.Create_Publisher (PUBLISHER_QOS);
         if Publisher = null then
            raise Program_Error with "create_publisher error";
         end if;
      
         Participant.Get_Default_Topic_Qos (Topic_Qos);
         Topic := Participant.Create_Topic (Topic_Name => Topic_Name, 
                                            Type_Name  => Hello.HelloWorld_TypeSupport.Get_Type_Name , 
                                            Qos        => Topic_QOS);
         if Topic = null then
            raise Program_Error with "create_topic error";
         end if;

         Participant.Get_Default_DataWriter_Qos (DataWriter_Qos);
         HelloWorld_Writer := Hello.HelloWorld_DataWriter.Narrow (Publisher.Create_DataWriter (A_Topic => Topic, Qos => DataWriter_Qos));

         Instance := Hello.HelloWorld_TypeSupport.Create_Data;
      
         if Instance = null then
            raise Program_Error with "HelloWorldTypeSupport_create_data error";
         end if;
         --  For data type that has key, if the same instance is going to be
         --  written multiple times, initialize the key here
         --  and register the keyed instance prior to writing.
      
         --  Instance_Handle := HelloWorld_Writer.Register_Instance (Instance);

         --  
         --  Main loop
         for Count in 0 .. (if Sample_Count = 0 then Integer'Last else Sample_Count) loop
            Put_Line ("Writing HelloWorld, count" & Count'Img);
      
            --  Modify the data to be written here
            Instance.Data := DDS.Long (Count);

            --  Write data
            HelloWorld_Writer.Write (Instance, Instance_Handle);
            delay Send_Period;
         end loop;
      
         -- HelloWorld_Writer.Unregister_Instance (Instance, Instance_Handle);
         Hello.HelloWorld_TypeSupport.Delete_Data (Instance);
      exception
         when E : others =>
            Put_Line (Ada.Exceptions.Exception_Information (E));
      end;
      Participant.Delete_Contained_Entities;
      Factory.Delete_Participant (Participant);
      Factory.Finalize_Instance;
   end; 

   DomainId     : DDS.Domainid_T  := 0;
   Sample_Count : Integer  := 0;
begin
   if Ada.Command_Line.Argument_Count >= 1 then
      DomainId := DDS.Domainid_T'Value (Ada.Command_Line.Argument (1));
   end if;

   if Ada.Command_Line.Argument_Count >= 2 then
      Sample_Count := Integer'Value (Ada.Command_Line.Argument (2));
   end if;

   -- Uncomment this to turn on additional logging
   -- RTIDDS.Config.Logger.Get_Instance.Set_Verbosity (RTIDDS.Config.Category_API,
   --                                                  RTIDDS.CONFIG.VERBOSITY_ALL);
   
   Publisher_Main (DomainId, Sample_Count);
end HelloWorld_Publisher;
