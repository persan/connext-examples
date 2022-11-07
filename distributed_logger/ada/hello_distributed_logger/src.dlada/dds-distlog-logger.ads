private with RTIDDS.Low_Level.rti_dl_rti_dl_c_h;
with RTIDDS.Config;
with dds.distlog.options;
package dds.distlog.Logger is
   type ref (<>) is tagged private;
   type ref_access  is access all ref'Class;

   function getInstance return ref_access;

   procedure set_Filter_Level (self     : access ref;
                               newLevel : DDS.Long);

   procedure set_Options (self     : access ref;
                          options  : dds.distlog.options.ref);

   procedure set_Print_Format (self           : access ref;
                               logPrintFormat : RTIDDS.Config.LogPrintFormat);

   procedure set_Verbosity_By_Category
     (self      : access ref;
      category  : RTIDDS.Config.LogCategory;
      verbosity : RTIDDS.Config.LogVerbosity);


   type MessageParams is record
      log_level : aliased DDS.integer;
      message   : DDS.String;
      category  : DDS.String;
      timestamp : aliased DDS.Time_t;
   end record with Convention => C_Pass_By_Copy;


   PROCEDURE logMessageWithLevelCategory
     (self     : access Ref;
      logLevel : DDS.integer;
      message  : DDS.String;
      category : DDS.String);

   PROCEDURE logMessageWithParams (self : access Ref; params : MessageParams);

   PROCEDURE fatal (self : access Ref; message : DDS.String);
   PROCEDURE severe (self : access Ref; message : DDS.String);
   PROCEDURE error (self : access Ref; message : DDS.String);
   PROCEDURE warning (self : access Ref; message : DDS.String);
   PROCEDURE notice (self : access Ref; message : DDS.String);
   PROCEDURE info (self : access Ref; message : DDS.String);
   PROCEDURE debug (self : access Ref; message : DDS.String);
   PROCEDURE trace (self : access Ref; message : DDS.String);

   PROCEDURE fatal (self : access Ref; message : Standard.String);
   PROCEDURE severe (self : access Ref; message : Standard.String);
   PROCEDURE error (self : access Ref; message : Standard.String);
   PROCEDURE warning (self : access Ref; message : Standard.String);
   PROCEDURE notice (self : access Ref; message : Standard.String);
   PROCEDURE info (self : access Ref; message : Standard.String);
   PROCEDURE debug (self : access Ref; message : Standard.String);
   PROCEDURE trace (self : access Ref; message : Standard.String);


   PROCEDURE log
     (self     : access Ref;
      logLevel : DDS.integer;
      message  : DDS.String);


   FUNCTION get_fatal_log_level (self : access Ref)return DDS.Long;

   FUNCTION get_error_log_level (self : access Ref)return DDS.Long;

   FUNCTION get_warning_log_level (self : access Ref)return DDS.Long;

   FUNCTION get_notice_log_level (self : access Ref)return DDS.Long;

   FUNCTION get_info_log_level (self : access Ref)return DDS.Long;

   FUNCTION get_debug_log_level (self : access Ref)return DDS.Long;

private

   type RTI_DL_DistLogger_Access is access all RTIDDS.Low_Level.rti_dl_rti_dl_c_h.RTI_DL_DistLogger with Storage_Size => 0;
   type ref is tagged record
      impl : RTI_DL_DistLogger_Access;
   end record;
   FUNCTION finalizeInstance return RTIDDS.Low_Level.ndds_dds_c_dds_c_infrastructure_h.DDS_ReturnCode_t;

end dds.distlog.Logger;
