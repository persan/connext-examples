with RTIDDS.Low_Level.rti_dl_rti_dl_c_h;
with DDS.DomainParticipant;
with Ada.Finalization;
package dds.distlog.options is
   type ref is tagged private;

   function get_Domain_Participant (self : ref) return DDS.DomainParticipant.ref_access;

   procedure set_Domain_Participant (self : ref; domainParticipant : DDS.DomainParticipant.ref_access);

   function get_Log_Infrastructure_Messages (self : ref) return integer;
   procedure set_Log_Infrastructure_Messages (self : ref; log : integer);

   function is_Remote_Administration_Enabled (self : ref) return Boolean;
   procedure set_Remote_Administration_Enabled (self : ref; enabled : Boolean);

   function get_Filter_Level (self : ref) return DDS.integer;
   procedure set_Filter_Level (self : ref; filterLevel : DDS.integer);

   function get_Domain_Id (self : ref) return DDS.DomainId_T;
   procedure set_Domain_Id (self : ref; domainId : DDS.DomainId_T);


   procedure set_Qos_Library (self : ref; qosLibrary : DDS.String);
   procedure get_Qos_Library (self : ref; qosLibrary : out DDS.String);
   function get_Qos_Library (self : ref) return Standard.String;



   procedure set_Qos_Profile (self : ref; qosProfile : DDS.String);
   procedure get_Qos_Profile (self : ref; qosProfile : out DDS.String);
   function get_Qos_Profile (self : ref) return Standard.String;

   function get_Queue_Size (self : ref) return integer;
   procedure set_Queue_Size (self : ref; queueSize : integer);

   function get_Thread_Settings (self : ref) return access DDS.ThreadSettings_t;
   procedure set_Thread_Settings (self : ref; threadSettings : DDS.ThreadSettings_t);


   procedure set_Application_Kind (self : ref; applicationKind : DDS.String);
   procedure set_Application_Kind (self : ref; applicationKind : Standard.String);
   procedure get_Application_Kind (self : ref; applicationKind : out DDS.String);
   function get_Application_Kind (self : ref) return Standard.String;

   procedure set_Echo_To_Stdout (self : ref; echoToStdout : Boolean);
   function get_Echo_To_Stdout (self : ref) return Boolean;

   -- private stuff.
   --
   function get_impl (self : ref) return access RTIDDS.Low_Level.rti_dl_rti_dl_c_h.RTI_DL_Options;
private
   type RTI_DL_Options_Access is access all RTIDDS.Low_Level.rti_dl_rti_dl_c_h.RTI_DL_Options with Storage_Size => 0;
   type ref is new ada.finalization.Controlled with record
      impl : RTI_DL_Options_Access;
   end record;
   overriding procedure Initialize (self : in out ref);
   overriding procedure Finalize (self : in out ref);
   overriding procedure Adjust (self : in out ref);

end dds.distlog.options;
