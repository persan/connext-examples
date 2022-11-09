pragma Ada_2022;
with DDS.Builtin_String_DataReader;
with Ada.Text_IO.Unbounded_IO;
with Ada.Strings.Unbounded;
with DDS.Images;
with GNAT.Source_Info;
package body Hello.Listener is
   use Ada.Text_IO.Unbounded_IO;
   use Ada.Strings.Unbounded;
   use DDS;
   use DDS.Images;
   use GNAT.Source_Info;
   procedure On_Data_Available
     (Self       : not null access Ref;
      The_Reader : in DDS.DataReaderListener.DataReader_Access)
   is
      Data_Reader : constant access DDS.Builtin_String_DataReader.Ref :=
                      DDS.Builtin_String_DataReader.Ref_Access (The_Reader);
   begin
      for I of Data_Reader.Read  loop
         if I.Sample_Info.Valid_Data then
            Ada.Text_IO.Put_Line (DDS.To_Standard_String (I.Data.all));
         end if;
      end loop;
   end On_Data_Available;

   overriding procedure On_Requested_Deadline_Missed
     (Self       : not null access Ref;
      The_Reader : in DDS.DataReaderListener.DataReader_Access;
      Status     : in DDS.RequestedDeadlineMissedStatus) is
   begin
      Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
   end On_Requested_Deadline_Missed;

   overriding procedure On_Requested_Incompatible_Qos
     (Self       : not null access Ref;
      The_Reader : in DDS.DataReaderListener.DataReader_Access;
      Status     : in DDS.RequestedIncompatibleQosStatus) is
   begin
      Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
   end On_Requested_Incompatible_Qos;

   overriding procedure On_Sample_Rejected
     (Self       : not null access Ref;
      The_Reader : in DDS.DataReaderListener.DataReader_Access;
      Status     : in DDS.SampleRejectedStatus) is
   begin
      Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
   end On_Sample_Rejected;

   overriding procedure On_Liveliness_Changed
     (Self       : not null access Ref;
      The_Reader : in DDS.DataReaderListener.DataReader_Access;
      Status     : in DDS.LivelinessChangedStatus) is
   begin
      Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
   end On_Liveliness_Changed;


   overriding procedure On_Subscription_Matched
     (Self       : not null access Ref;
      The_Reader : in DDS.DataReaderListener.DataReader_Access;
      Status     : in DDS.SubscriptionMatchedStatus) is
   begin
      if Status.Current_Count = 0 then
         Self.Receiving := False;
      end if;
      Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
   end On_Subscription_Matched;

   overriding procedure On_Sample_Lost
     (Self       : not null access Ref;
      The_Reader : in DDS.DataReaderListener.DataReader_Access;
      Status     : in DDS.SampleLostStatus) is
   begin
      Put_Line (Enclosing_Entity & "(" & Image (Status) & ")");
   end On_Sample_Lost;
end Hello.Listener;
