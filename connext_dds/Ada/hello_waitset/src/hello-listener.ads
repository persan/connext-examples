with DDS;
with DDS.DataReaderListener;

package Hello.Listener is

   type Ref is new DDS.DataReaderListener.Ref with record
      receiving : Boolean := True;
   end record;

   type Ref_Access is access all Ref'Class;

   overriding procedure On_Data_Available
     (Self       : not null access Ref;
      The_Reader : in DDS.DataReaderListener.DataReader_Access);

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


   overriding procedure On_Subscription_Matched
     (Self       : not null access Ref;
      The_Reader : in DDS.DataReaderListener.DataReader_Access;
      Status     : in DDS.SubscriptionMatchedStatus);

   overriding procedure On_Sample_Lost
     (Self       : not null access Ref;
      The_Reader : in DDS.DataReaderListener.DataReader_Access;
      Status     : in DDS.SampleLostStatus);

end Hello.Listener;
