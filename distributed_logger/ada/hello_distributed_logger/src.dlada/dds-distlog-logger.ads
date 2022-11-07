private with RTIDDS.Low_Level.rti_dl_rti_dl_c_h;
with RTIDDS.Config;
with dds.distlog.options;
package dds.distlog.Logger is
   type ref (<>) is tagged private;
   type ref_access  is access all ref'Class;

   function getInstance return ref_access;

   procedure set_Filter_Level (self     : access ref;
                               newLevel : RTIDDS.Low_Level.ndds_dds_c_dds_c_common_h.DDS_Long);

   procedure set_Options (self     : access ref;
                          options  : dds.distlog.options.ref);

   procedure set_Print_Format (self           : access ref;
                               logPrintFormat : RTIDDS.Config.LogPrintFormat);

   procedure set_Verbosity_By_Category
     (self      : access ref;
      category  : RTIDDS.Config.LogCategory;
      verbosity : RTIDDS.Config.LogVerbosity);

private
   type RTI_DL_DistLogger_Access is access RTIDDS.Low_Level.rti_dl_rti_dl_c_h.RTI_DL_DistLogger with Storage_Size => 0;
   type ref is tagged record
      impl : RTI_DL_DistLogger_Access;
   end record;
end dds.distlog.Logger;
