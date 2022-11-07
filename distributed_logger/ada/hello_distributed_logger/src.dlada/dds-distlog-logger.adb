pragma Ada_2012;
with RTIDDS.Low_Level.rti_dl_rti_dl_c_h;
with Interfaces.c;
package body dds.distlog.Logger is
   use RTIDDS.Low_Level.rti_dl_rti_dl_c_h;
   use Interfaces.c;

   -----------------
   -- getInstance --
   -----------------
   instance : aliased ref;
   function getInstance return ref_access is
   begin
      return instance'access;
   end getInstance;

   ----------------------
   -- set_Filter_Level --
   ----------------------

   procedure set_Filter_Level (self : access ref; newLevel : DDS.Long) is
      ret : unsigned;
   begin
      ret := RTI_DL_DistLogger_setFilterLevel (self.impl, int(newLevel));
   end set_Filter_Level;

   -----------------
   -- set_Options --
   -----------------

   procedure set_Options (self : access ref; options : dds.distlog.options.ref)
   is
   begin
      if  RTI_DL_DistLogger_setOptions (options.get_impl) = 0 then
         null;
      end if;
      instance.impl := RTI_DL_DistLogger_getInstance;
   end set_Options;

   ----------------------
   -- set_Print_Format --
   ----------------------

   procedure set_Print_Format
     (self : access ref; logPrintFormat : RTIDDS.Config.LogPrintFormat)
   is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Print_Format unimplemented");
      raise Program_Error with "Unimplemented procedure set_Print_Format";
   end set_Print_Format;

   -------------------------------
   -- set_Verbosity_By_Category --
   -------------------------------

   procedure set_Verbosity_By_Category
     (self      : access ref;
      category  : RTIDDS.Config.LogCategory;
      verbosity : RTIDDS.Config.LogVerbosity)
   is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "set_Verbosity_By_Category unimplemented");
      raise Program_Error
        with "Unimplemented procedure set_Verbosity_By_Category";
   end set_Verbosity_By_Category;

   ---------------------------------
   -- logMessageWithLevelCategory --
   ---------------------------------

   procedure logMessageWithLevelCategory
     (self     : access Ref; logLevel : DDS.integer; message : DDS.String;
      category : DDS.String)
   is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "logMessageWithLevelCategory unimplemented");
      raise Program_Error
        with "Unimplemented procedure logMessageWithLevelCategory";
   end logMessageWithLevelCategory;

   --------------------------
   -- logMessageWithParams --
   --------------------------

   procedure logMessageWithParams (self : access Ref; params : MessageParams)
   is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "logMessageWithParams unimplemented");
      raise Program_Error with "Unimplemented procedure logMessageWithParams";
   end logMessageWithParams;

   -----------
   -- fatal --
   -----------

   procedure fatal (self : access Ref; message : DDS.String) is
   begin
      RTI_DL_DistLogger_fatal (self.impl, message.Data);
   end fatal;

   ------------
   -- severe --
   ------------

   procedure severe (self : access Ref; message : DDS.String) is
   begin
      RTI_DL_DistLogger_severe (self.impl, message.Data);
   end severe;

   -----------
   -- error --
   -----------

   procedure error (self : access Ref; message : DDS.String) is
   begin
      RTI_DL_DistLogger_error (self.impl, message.Data);
   end error;

   -------------
   -- warning --
   -------------

   procedure warning (self : access Ref; message : DDS.String) is
   begin
      RTI_DL_DistLogger_warning (self.impl, message.Data);
   end warning;

   ------------
   -- notice --
   ------------

   procedure notice (self : access Ref; message : DDS.String) is
   begin
      RTI_DL_DistLogger_notice (self.impl, message.Data);
   end notice;

   ----------
   -- info --
   ----------

   procedure info (self : access Ref; message : DDS.String) is
   begin
      RTI_DL_DistLogger_info (self.impl, message.Data);
   end info;

   -----------
   -- debug --
   -----------

   procedure debug (self : access Ref; message : DDS.String) is
   begin
      RTI_DL_DistLogger_debug (self.impl, message.Data);
   end debug;

   -----------
   -- trace --
   -----------

   procedure trace (self : access Ref; message : DDS.String) is
   begin
      RTI_DL_DistLogger_trace (self.impl, message.Data);
   end trace;


   -----------
   -- fatal --
   -----------

   procedure fatal (self : access Ref; message : Standard.String) is
      temp_message : dds.String;
   begin
      copy (temp_message, message);
      self.fatal (Temp_message);
      Finalize (temp_message);
   end fatal;

   ------------
   -- severe --
   ------------

   procedure severe (self : access Ref; message : Standard.String) is
      temp_message : dds.String;
   begin
      copy (temp_message, message);
      self.severe (Temp_message);
      Finalize (temp_message);
   end severe;

   -----------
   -- error --
   -----------

   procedure error (self : access Ref; message : Standard.String) is
      temp_message : dds.String;
   begin
      copy (temp_message, message);
      self.error (Temp_message);
      Finalize (temp_message);
   end error;

   -------------
   -- warning --
   -------------

   procedure warning (self : access Ref; message : Standard.String) is
      temp_message : dds.String;
   begin
      copy (temp_message, message);
      self.warning (Temp_message);
      Finalize (temp_message);
   end warning;

   ------------
   -- notice --
   ------------

   procedure notice (self : access Ref; message : Standard.String) is
      temp_message : dds.String;
   begin
      copy (temp_message, message);
      self.notice (Temp_message);
      Finalize (temp_message);
   end notice;

   ----------
   -- info --
   ----------

   procedure info (self : access Ref; message : Standard.String) is
      temp_message : dds.String;
   begin
      copy (temp_message, message);
      self.info (Temp_message);
      Finalize (temp_message);
   end info;

   -----------
   -- debug --
   -----------

   procedure debug (self : access Ref; message : Standard.String) is
      temp_message : dds.String;
   begin
      copy (temp_message, message);
      self.debug (Temp_message);
      Finalize (temp_message);
   end debug;

   -----------
   -- trace --
   -----------

   procedure trace (self : access Ref; message : Standard.String) is
      temp_message : dds.String;
   begin
      copy (temp_message, message);
      self.trace (Temp_message);
      Finalize (temp_message);
   end trace;

   ---------
   -- log --
   ---------

   procedure log
     (self : access Ref; logLevel : DDS.integer; message : DDS.String)
   is
      temp_message : dds.String;
   begin
      copy (temp_message, message);
      self.log (logLevel, temp_message);
      Finalize (temp_message);
   end log;

   -------------------------
   -- get_fatal_log_level --
   -------------------------

   function get_fatal_log_level (self : access Ref) return DDS.Long is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_fatal_log_level unimplemented");
      return
        raise Program_Error with "Unimplemented function get_fatal_log_level";
   end get_fatal_log_level;

   -------------------------
   -- get_error_log_level --
   -------------------------

   function get_error_log_level (self : access Ref) return DDS.Long is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_error_log_level unimplemented");
      return
        raise Program_Error with "Unimplemented function get_error_log_level";
   end get_error_log_level;

   ---------------------------
   -- get_warning_log_level --
   ---------------------------

   function get_warning_log_level (self : access Ref) return DDS.Long is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_warning_log_level unimplemented");
      return
        raise Program_Error
          with "Unimplemented function get_warning_log_level";
   end get_warning_log_level;

   --------------------------
   -- get_notice_log_level --
   --------------------------

   function get_notice_log_level (self : access Ref) return DDS.Long is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_notice_log_level unimplemented");
      return
        raise Program_Error with "Unimplemented function get_notice_log_level";
   end get_notice_log_level;

   ------------------------
   -- get_info_log_level --
   ------------------------

   function get_info_log_level (self : access Ref) return DDS.Long is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_info_log_level unimplemented");
      return
        raise Program_Error with "Unimplemented function get_info_log_level";
   end get_info_log_level;

   -------------------------
   -- get_debug_log_level --
   -------------------------

   function get_debug_log_level (self : access Ref) return DDS.Long is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "get_debug_log_level unimplemented");
      return
        raise Program_Error with "Unimplemented function get_debug_log_level";
   end get_debug_log_level;

   ----------------------
   -- finalizeInstance --
   ----------------------

   function finalizeInstance
      return RTIDDS.Low_Level.ndds_dds_c_dds_c_infrastructure_h
     .DDS_ReturnCode_t
   is
   begin
      pragma Compile_Time_Warning
        (Standard.True, "finalizeInstance unimplemented");
      return
        raise Program_Error with "Unimplemented function finalizeInstance";
   end finalizeInstance;

end dds.distlog.Logger;
