pragma Ada_2012;
with Ada.Unchecked_Conversion;
with Interfaces.C;
package body dds.distlog.Logger is
   use RTIDDS.Low_Level.rti_dl_rti_dl_c_h;
   use Interfaces.c;
   pragma Warnings (Off, "reference to obsolescent component*");
   -----------------
   -- getInstance --
   -----------------
   instance : aliased ref;
   function getInstance return ref_access is
   begin
      return instance'Access;
   end getInstance;

   ----------------------
   -- set_Filter_Level --
   ----------------------

   procedure set_Filter_Level (self : access ref; newLevel : DDS.Long) is
   begin
      Ret_Code_To_Exception (RTI_DL_DistLogger_SetFilterLevel (Self.Impl, Int (NewLevel)));
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
   function As_Unsigned is new Ada.Unchecked_Conversion (RTIDDS.Config.LogPrintFormat, Unsigned);
   procedure Set_Print_Format
     (self : access ref; logPrintFormat : RTIDDS.Config.LogPrintFormat)
   is
   begin
      Ret_Code_To_Exception (Unsigned (RTI_DL_DistLogger_SetRTILoggerPrintFormat
                             (Self => Self.Impl,
                              LogPrintFormat => As_Unsigned (LogPrintFormat))));
   end Set_Print_Format;

   -------------------------------
   -- set_Verbosity_By_Category --
   -------------------------------
      function As_Unsigned is new Ada.Unchecked_Conversion (RTIDDS.Config.LogVerbosity, Unsigned);
      function As_LogCategory is new Ada.Unchecked_Conversion (RTIDDS.Config.LogCategory, NDDS_Config_LogCategory);

   procedure set_Verbosity_By_Category
     (self      : access ref;
      category  : RTIDDS.Config.LogCategory;
      verbosity : RTIDDS.Config.LogVerbosity)
   is
   begin
      RTI_DL_DistLogger_SetRTILoggerVerbosityByCategory
                             (Self => Self.Impl,
                              Category => As_LogCategory (category),
                              Verbosity => As_Unsigned (Verbosity));
   end set_Verbosity_By_Category;

   ---------------------------------
   -- logMessageWithLevelCategory --
   ---------------------------------

   procedure log
     (self     : access Ref;
      logLevel : Log_Level;
      message  : DDS.String;
      category : DDS.String)
   is
   begin
      RTI_DL_DistLogger_LogMessageWithLevelCategory (Self.Impl,
                                                     Int (LogLevel),
                                                     Message.Data,
                                                     Category.Data);
   end Log;

   procedure Log
     (Self     : access Ref;
      logLevel : Log_Level;
      Message  : Standard.String;
      Category : Standard.String)
   is
      l_Message  : DDS.String;
      L_Category : DDS.String;

   begin
      Copy (L_Message, Message);
      Copy (L_Category, Category);
      Self.Log (LogLevel,
                L_Message,
                L_Category);

      Finalize (l_Message);
      Finalize (L_Category);
   end Log;

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
     (self : access Ref; logLevel : Log_Level; message : DDS.String)
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

   function get_fatal_log_level (self : access Ref) return Log_Level is
   begin
      return Log_Level (RTI_DL_DistLogger_Get_Fatal_Log_Level);
   end get_fatal_log_level;

   -------------------------
   -- get_error_log_level --
   -------------------------

   function get_error_log_level (self : access Ref) return Log_Level is
   begin
      return Log_Level (RTI_DL_DistLogger_Get_Error_Log_Level);
   end get_error_log_level;

   ---------------------------
   -- get_warning_log_level --
   ---------------------------

   function get_warning_log_level (self : access Ref) return Log_Level is
   begin
      return Log_Level (RTI_DL_DistLogger_Get_Warning_Log_Level);
   end get_warning_log_level;

   --------------------------
   -- get_notice_log_level --
   --------------------------

   function get_notice_log_level (self : access Ref) return Log_Level is
   begin
      return Log_Level (RTI_DL_DistLogger_Get_Notice_Log_Level);
   end get_notice_log_level;

   ------------------------
   -- get_info_log_level --
   ------------------------

   function get_info_log_level (self : access Ref) return Log_Level is
   begin
      return Log_Level (RTI_DL_DistLogger_Get_info_Log_Level);
   end get_info_log_level;

   -------------------------
   -- get_debug_log_level --
   -------------------------

   function get_debug_log_level (self : access Ref) return Log_Level is
   begin
      return Log_Level (RTI_DL_DistLogger_Get_Debug_Log_Level);
   end get_debug_log_level;

   ----------------------
   -- finalizeInstance --
   ----------------------
   procedure Finalize (Self : access Ref) is
   begin
      Ret_Code_To_Exception (RTI_DL_DistLogger_FinalizeInstance);
   end;

end Dds.Distlog.Logger;
