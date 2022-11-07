private with RTIDDS.Low_Level.rti_dl_rti_dl_c_h;
with RTIDDS.Config;
with dds.distlog.options;
package dds.distlog.Logger is
   type ref (<>) is tagged private;
   type ref_access  is access all ref'Class;
   type Log_Level is range 0 .. 258;
   function getInstance return ref_access;
   procedure Finalize (Self : access Ref);
   procedure set_Filter_Level (self     : access ref;
                               newLevel : DDS.Long);

   procedure set_Options (self     : access ref;
                          options  : dds.distlog.options.ref);
   --  Note options must be set before any call is done to the logger.

   procedure set_Print_Format (self           : access ref;
                               logPrintFormat : RTIDDS.Config.LogPrintFormat);

   procedure set_Verbosity_By_Category
     (self      : access ref;
      category  : RTIDDS.Config.LogCategory;
      verbosity : RTIDDS.Config.LogVerbosity);

   procedure Log
     (self     : access Ref;
      logLevel : Log_Level;
      message  : DDS.String;
      category : DDS.String);

   procedure Log
     (self     : access Ref;
      logLevel : Log_Level;
      Message  : Standard.String;
      Category : Standard.String);

   procedure fatal (self : access Ref; message : DDS.String);
   procedure severe (self : access Ref; message : DDS.String);
   procedure error (self : access Ref; message : DDS.String);
   procedure warning (self : access Ref; message : DDS.String);
   procedure notice (self : access Ref; message : DDS.String);
   procedure info (self : access Ref; message : DDS.String);
   procedure debug (self : access Ref; message : DDS.String);
   procedure trace (self : access Ref; message : DDS.String);

   procedure fatal (self : access Ref; message : Standard.String);
   procedure severe (self : access Ref; message : Standard.String);
   procedure error (self : access Ref; message : Standard.String);
   procedure warning (self : access Ref; message : Standard.String);
   procedure notice (self : access Ref; message : Standard.String);
   procedure info (self : access Ref; message : Standard.String);
   procedure debug (self : access Ref; message : Standard.String);
   procedure trace (self : access Ref; message : Standard.String);

   procedure log
     (self     : access Ref;
      logLevel : Log_Level;
      message  : DDS.String);

   function get_fatal_log_level (self : access Ref) return Log_Level;

   function get_error_log_level (self : access Ref) return Log_Level;

   function get_warning_log_level (self : access Ref) return Log_Level;

   function get_notice_log_level (self : access Ref) return Log_Level;

   function get_info_log_level (self : access Ref) return Log_Level;

   function get_debug_log_level (self : access Ref) return Log_Level;

private

   type RTI_DL_DistLogger_Access is access all RTIDDS.Low_Level.rti_dl_rti_dl_c_h.RTI_DL_DistLogger with Storage_Size => 0;
   type ref is tagged record
      impl : RTI_DL_DistLogger_Access;
   end record;

end dds.distlog.Logger;
