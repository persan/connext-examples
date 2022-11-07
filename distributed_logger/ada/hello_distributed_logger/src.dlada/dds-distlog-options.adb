pragma Ada_2012;
with RTIDDS.Low_Level.rti_dl_rti_dl_c_h; use RTIDDS.Low_Level.rti_dl_rti_dl_c_h;
with Interfaces.C; use Interfaces.C;
package body dds.distlog.options is

   ----------------------------
   -- get_Domain_Participant --
   ----------------------------

   function get_Domain_Participant
     (self : ref) return DDS.DomainParticipant.ref_access
   is
   begin

      pragma Compile_Time_Warning
        (Standard.True, "get_Domain_Participant unimplemented");
      return
        raise Program_Error
          with "Unimplemented function get_Domain_Participant";
   end get_Domain_Participant;

   ----------------------------
   -- set_Domain_Participant --
   ----------------------------

   procedure set_Domain_Participant
     (self : ref; domainParticipant : DDS.DomainParticipant.ref_access)
   is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Domain_Participant unimplemented");
      raise Program_Error
        with "Unimplemented procedure set_Domain_Participant";
   end set_Domain_Participant;

   -------------------------------------
   -- get_Log_Infrastructure_Messages --
   -------------------------------------

   function get_Log_Infrastructure_Messages (self : ref) return integer is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Log_Infrastructure_Messages unimplemented");
      return
        raise Program_Error
          with "Unimplemented function get_Log_Infrastructure_Messages";
   end get_Log_Infrastructure_Messages;

   -------------------------------------
   -- set_Log_Infrastructure_Messages --
   -------------------------------------

   procedure set_Log_Infrastructure_Messages (self : ref; log : integer) is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Log_Infrastructure_Messages unimplemented");
      raise Program_Error
        with "Unimplemented procedure set_Log_Infrastructure_Messages";
   end set_Log_Infrastructure_Messages;

   --------------------------------------
   -- is_Remote_Administration_Enabled --
   --------------------------------------

   function is_Remote_Administration_Enabled (self : ref) return Boolean is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "is_Remote_Administration_Enabled unimplemented");
      return
        raise Program_Error
          with "Unimplemented function is_Remote_Administration_Enabled";
   end is_Remote_Administration_Enabled;

   ---------------------------------------
   -- set_Remote_Administration_Enabled --
   ---------------------------------------

   procedure set_Remote_Administration_Enabled (self : ref; enabled : Boolean)
   is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Remote_Administration_Enabled unimplemented");
      raise Program_Error
        with "Unimplemented procedure set_Remote_Administration_Enabled";
   end set_Remote_Administration_Enabled;

   ----------------------
   -- get_Filter_Level --
   ----------------------

   function get_Filter_Level (self : ref) return DDS.integer is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Filter_Level unimplemented");
      return
        raise Program_Error with "Unimplemented function get_Filter_Level";
   end get_Filter_Level;

   ----------------------
   -- set_Filter_Level --
   ----------------------

   procedure set_Filter_Level (self : ref; filterLevel : DDS.integer) is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Filter_Level unimplemented");
      raise Program_Error with "Unimplemented procedure set_Filter_Level";
   end set_Filter_Level;

   -------------------
   -- get_Domain_Id --
   -------------------

   function get_Domain_Id (self : ref) return DDS.DomainId_T is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Domain_Id unimplemented");
      return raise Program_Error with "Unimplemented function get_Domain_Id";
   end get_Domain_Id;

   -------------------
   -- set_Domain_Id --
   -------------------

   procedure set_Domain_Id (self : ref; domainId : DDS.DomainId_T) is
   begin
      Ret_Code_To_Exception ( RTI_DL_Options_setDomainId (self.impl, int (domainId)));
   end set_Domain_Id;

   ---------------------
   -- set_Qos_Library --
   ---------------------

   procedure set_Qos_Library (self : ref; qosLibrary : DDS.String) is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Qos_Library unimplemented");
      raise Program_Error with "Unimplemented procedure set_Qos_Library";
   end set_Qos_Library;

   ---------------------
   -- get_Qos_Library --
   ---------------------

   procedure get_Qos_Library (self : ref; qosLibrary : out DDS.String) is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Qos_Library unimplemented");
      raise Program_Error with "Unimplemented procedure get_Qos_Library";
   end get_Qos_Library;

   ---------------------
   -- get_Qos_Library --
   ---------------------

   function get_Qos_Library (self : ref) return Standard.String is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Qos_Library unimplemented");
      return raise Program_Error with "Unimplemented function get_Qos_Library";
   end get_Qos_Library;

   ---------------------
   -- set_Qos_Profile --
   ---------------------

   procedure set_Qos_Profile (self : ref; qosProfile : DDS.String) is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Qos_Profile unimplemented");
      raise Program_Error with "Unimplemented procedure set_Qos_Profile";
   end set_Qos_Profile;

   ---------------------
   -- get_Qos_Profile --
   ---------------------

   procedure get_Qos_Profile (self : ref; qosProfile : out DDS.String) is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Qos_Profile unimplemented");
      raise Program_Error with "Unimplemented procedure get_Qos_Profile";
   end get_Qos_Profile;

   ---------------------
   -- get_Qos_Profile --
   ---------------------

   function get_Qos_Profile (self : ref) return Standard.String is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Qos_Profile unimplemented");
      return raise Program_Error with "Unimplemented function get_Qos_Profile";
   end get_Qos_Profile;

   --------------------
   -- get_Queue_Size --
   --------------------

   function get_Queue_Size (self : ref) return integer is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Queue_Size unimplemented");
      return raise Program_Error with "Unimplemented function get_Queue_Size";
   end get_Queue_Size;

   --------------------
   -- set_Queue_Size --
   --------------------

   procedure set_Queue_Size (self : ref; queueSize : integer) is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Queue_Size unimplemented");
      raise Program_Error with "Unimplemented procedure set_Queue_Size";
   end set_Queue_Size;

   -------------------------
   -- get_Thread_Settings --
   -------------------------

   function get_Thread_Settings (self : ref) return access DDS.ThreadSettings_t
   is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Thread_Settings unimplemented");
      return
        raise Program_Error with "Unimplemented function get_Thread_Settings";
   end get_Thread_Settings;

   -------------------------
   -- set_Thread_Settings --
   -------------------------

   procedure set_Thread_Settings
     (self : ref; threadSettings : DDS.ThreadSettings_t)
   is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Thread_Settings unimplemented");
      raise Program_Error with "Unimplemented procedure set_Thread_Settings";
   end set_Thread_Settings;

   --------------------------
   -- set_Application_Kind --
   --------------------------

   procedure set_Application_Kind (self : ref; applicationKind : DDS.String) is
   begin
      Ret_Code_To_Exception (RTI_DL_Options_setApplicationKind (self.impl, applicationKind.Data));
   end set_Application_Kind;

   --------------------------
   -- set_Application_Kind --
   --------------------------

   procedure set_Application_Kind
     (self : ref; applicationKind : Standard.String)
   is
      temp : DDS.String;
   begin
      copy (temp, applicationKind);
      self.set_Application_Kind (temp);
      Finalize (temp);
   end set_Application_Kind;

   --------------------------
   -- get_Application_Kind --
   --------------------------

   procedure get_Application_Kind
     (self : ref; applicationKind : out Standard.String)
   is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Application_Kind unimplemented");
      raise Program_Error with "Unimplemented procedure get_Application_Kind";
   end get_Application_Kind;

   --------------------------
   -- get_Application_Kind --
   --------------------------

   function get_Application_Kind (self : ref) return Standard.String is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Application_Kind unimplemented");
      return
        raise Program_Error with "Unimplemented function get_Application_Kind";
   end get_Application_Kind;

   ------------------------
   -- set_Echo_To_Stdout --
   ------------------------

   procedure set_Echo_To_Stdout (self : ref; echoToStdout : Boolean) is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Echo_To_Stdout unimplemented");
      raise Program_Error with "Unimplemented procedure set_Echo_To_Stdout";
   end set_Echo_To_Stdout;

   ------------------------
   -- get_Echo_To_Stdout --
   ------------------------

   function get_Echo_To_Stdout (self : ref) return Boolean is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_Echo_To_Stdout unimplemented");
      return
        raise Program_Error with "Unimplemented function get_Echo_To_Stdout";
   end get_Echo_To_Stdout;

   --------------
   -- get_impl --
   --------------

   function get_impl
     (self : ref)
      return access RTIDDS.Low_Level.rti_dl_rti_dl_c_h.RTI_DL_Options
   is
   begin
      return self.impl;
   end get_impl;


   overriding procedure Initialize (self : in out ref) is
   begin
      self.impl := RTI_DL_Options_createDefault.all'access;
   end;

   overriding procedure Finalize (self : in out ref) is
   begin
      self.impl := RTI_DL_Options_delete (self.impl.all'access).all'access;
   end;

   overriding procedure Adjust (self : in out ref) is
      dummy : int;
   begin
      dummy := RTI_DL_Options_copy (self.impl.all'access, self.impl.all'access);
   end;


end dds.distlog.options;
