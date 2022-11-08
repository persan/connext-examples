with Ada.Exceptions;
with Ada.Text_IO; 
with Ada.Text_IO.Unbounded_IO;
with Ada.Command_Line;
with Ada.Strings.Unbounded;
with DDS.DomainParticipant;
with DDS.DomainParticipantFactory;
with DDS.Subscriber;
with DDS.Topic;
with DDS.DataReader;
with DDS.DataReaderListener;
with DDS.Images;
      
with GNAT.Source_Info;

with Hello.HelloWorld_DataReader;
with Hello.HelloWorld_TypeSupport;
with RTIDDS.Config;
procedure HelloWorld_Subscriber is
   
   Factory : DDS.DomainParticipantFactory.Ref_Access := DDS.DomainParticipantFactory.Get_Instance;
   use type DDS.DomainParticipant.Ref_Access;
   use type DDS.Subscriber.Ref_Access;
   use type DDS.Topic.Ref_Access;
   use type DDS.DataReader.Ref_Access;
   use type Hello.HelloWorld_DataReader.Ref_Access;
   use type Hello.HelloWorld_Access;
   use Ada.Text_IO;
   
   package Listners is
      type Ref is new DDS.DataReaderListener.Ref with null record;
      overriding procedure On_Requested_Deadline_Missed
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.RequestedDeadlineMissedStatus);

      overriding procedure On_Requested_Incompatible_Qos
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.RequestedIncompatibleQosStatus);

      overriding procedure On_Sample_Rejected
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.SampleRejectedStatus);

      overriding procedure On_Liveliness_Changed
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.LivelinessChangedStatus);
      
      overriding procedure On_Data_Available
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access);
      
      overriding procedure On_Subscription_Matched
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.SubscriptionMatchedStatus);
      
      overriding procedure On_Sample_Lost
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.SampleLostStatus);
      
   end Listners;
   package body Listners is
      use Ada.Strings.Unbounded;
      use GNAT.Source_Info;
      use Dds.Images;
      use Ada.Text_IO.Unbounded_IO;
      overriding procedure On_Requested_Deadline_Missed
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.RequestedDeadlineMissedStatus) is
      begin
         Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
      end;

      overriding procedure On_Requested_Incompatible_Qos
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.RequestedIncompatibleQosStatus) is
      begin
         Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
      end;

      overriding procedure On_Sample_Rejected
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.SampleRejectedStatus) is
      begin
         Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
      end;

      overriding procedure On_Liveliness_Changed
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.LivelinessChangedStatus) is
      begin
         Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
      end;
      
      overriding procedure On_Data_Available
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access) is
         HelloWorld_Reader : Hello.HelloWorld_DataReader.Ref_Access := Hello.HelloWorld_DataReader.Narrow (The_Reader);
      begin
         for S of HelloWorld_Reader.Take loop
            Hello.HelloWorld_TypeSupport.Print_Data (S.Data);
         end loop;
      end;
      
      overriding procedure On_Subscription_Matched
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.SubscriptionMatchedStatus) is
      begin
         Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
      end;
      
      overriding procedure On_Sample_Lost
        (Self       : not null access Ref;
         The_Reader : in DDS.DataReaderListener.DataReader_Access;
         Status     : in DDS.SampleLostStatus) is
      begin
         Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
      end;
      

   end Listners;
   
   procedure Subscriber_Main (DomainId : DDS.DomainId_T; Sample_Count : Integer) is
      Participant       : DDS.DomainParticipant.Ref_Access;
      Subscriber        : DDS.Subscriber.Ref_Access;
      Topic             : DDS.Topic.Ref_Access;
      Topic_Name        : constant DDS.String := DDS.To_DDS_String ("Example HelloWorld");      
      HelloWorld_Reader : Hello.HelloWorld_DataReader.Ref_Access;
      Participant_Qos   : DDS.DomainParticipantQos;
      Subscriber_Qos    : DDS.SubscriberQos;
      Topic_Qos         : DDS.TopicQos;
      DataReader_Qos    : DDS.DataReaderQos;
      Listner           : aliased Listners.Ref;
      Poll_Period       : constant Duration := 4.0;
   begin

      begin
       Factory.Get_Default_Participant_Qos (Participant_Qos);            
         Participant := Factory.Create_Participant ( DomainId, PARTICIPANT_QOS);
      
         if Participant = null then
            raise Program_Error with "create_participant error";
         end if;
      
         Participant.Get_Default_Subscriber_Qos (Subscriber_Qos);      
         subscriber := Participant.Create_subscriber (subscriber_QOS);
         if subscriber = null then
            raise Program_Error with "create_subscriber error";
         end if;
      
         Participant.Get_Default_Topic_Qos (Topic_Qos);
         Topic := Participant.Create_Topic (Topic_Name => Topic_Name, 
                                            Type_Name  => Hello.HelloWorld_TypeSupport.Get_Type_Name , 
                                            Qos        => Topic_QOS);
         if Topic = null then
            raise Program_Error with "create_topic error";
         end if;

         HelloWorld_Reader := Hello.HelloWorld_DataReader.Narrow
           (Subscriber.Create_DataReader
              (Topic      =>  Topic.As_TopicDescription, 
               Qos        =>  DataReader_Qos, 
               A_Listener =>   Listner'Unchecked_Access, 
               Mask       =>  Dds.STATUS_MASK_ALL));
         if HelloWorld_Reader = null then
            raise Program_Error with "data reader error";
         end if;

         --  Main loop
      
         for Count in 0 .. (if Sample_Count = 0 then Integer'Last else Sample_Count) loop
            Put_Line ("HelloWorld subscriber sleeping for " & Poll_Period'Img & " sec...");
            delay Poll_Period;
         end loop;
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
   Subscriber_Main (DomainId, Sample_Count);
end;
