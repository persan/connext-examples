pragma Warnings (Off);
pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b__main.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b__main.adb");
pragma Suppress (Overflow_Check);

with System.Restrictions;
with Ada.Exceptions;

package body ada_main is

   E079 : Short_Integer; pragma Import (Ada, E079, "system__os_lib_E");
   E006 : Short_Integer; pragma Import (Ada, E006, "ada__exceptions_E");
   E011 : Short_Integer; pragma Import (Ada, E011, "system__soft_links_E");
   E023 : Short_Integer; pragma Import (Ada, E023, "system__exception_table_E");
   E046 : Short_Integer; pragma Import (Ada, E046, "ada__containers_E");
   E074 : Short_Integer; pragma Import (Ada, E074, "ada__io_exceptions_E");
   E030 : Short_Integer; pragma Import (Ada, E030, "ada__numerics_E");
   E061 : Short_Integer; pragma Import (Ada, E061, "ada__strings_E");
   E063 : Short_Integer; pragma Import (Ada, E063, "ada__strings__maps_E");
   E066 : Short_Integer; pragma Import (Ada, E066, "ada__strings__maps__constants_E");
   E051 : Short_Integer; pragma Import (Ada, E051, "interfaces__c_E");
   E024 : Short_Integer; pragma Import (Ada, E024, "system__exceptions_E");
   E088 : Short_Integer; pragma Import (Ada, E088, "system__object_reader_E");
   E056 : Short_Integer; pragma Import (Ada, E056, "system__dwarf_lines_E");
   E019 : Short_Integer; pragma Import (Ada, E019, "system__soft_links__initialize_E");
   E045 : Short_Integer; pragma Import (Ada, E045, "system__traceback__symbolic_E");
   E029 : Short_Integer; pragma Import (Ada, E029, "system__img_int_E");
   E069 : Short_Integer; pragma Import (Ada, E069, "system__img_uns_E");
   E310 : Short_Integer; pragma Import (Ada, E310, "ada__assertions_E");
   E104 : Short_Integer; pragma Import (Ada, E104, "ada__strings__utf_encoding_E");
   E110 : Short_Integer; pragma Import (Ada, E110, "ada__tags_E");
   E102 : Short_Integer; pragma Import (Ada, E102, "ada__strings__text_buffers_E");
   E343 : Short_Integer; pragma Import (Ada, E343, "gnat_E");
   E163 : Short_Integer; pragma Import (Ada, E163, "interfaces__c__strings_E");
   E118 : Short_Integer; pragma Import (Ada, E118, "ada__streams_E");
   E130 : Short_Integer; pragma Import (Ada, E130, "system__file_control_block_E");
   E129 : Short_Integer; pragma Import (Ada, E129, "system__finalization_root_E");
   E127 : Short_Integer; pragma Import (Ada, E127, "ada__finalization_E");
   E126 : Short_Integer; pragma Import (Ada, E126, "system__file_io_E");
   E278 : Short_Integer; pragma Import (Ada, E278, "system__storage_pools_E");
   E276 : Short_Integer; pragma Import (Ada, E276, "system__finalization_masters_E");
   E284 : Short_Integer; pragma Import (Ada, E284, "system__storage_pools__subpools_E");
   E148 : Short_Integer; pragma Import (Ada, E148, "ada__strings__wide_maps_E");
   E327 : Short_Integer; pragma Import (Ada, E327, "system__task_info_E");
   E134 : Short_Integer; pragma Import (Ada, E134, "ada__calendar_E");
   E138 : Short_Integer; pragma Import (Ada, E138, "ada__calendar__time_zones_E");
   E116 : Short_Integer; pragma Import (Ada, E116, "ada__text_io_E");
   E280 : Short_Integer; pragma Import (Ada, E280, "system__pool_global_E");
   E263 : Short_Integer; pragma Import (Ada, E263, "system__img_llli_E");
   E334 : Short_Integer; pragma Import (Ada, E334, "system__img_lli_E");
   E321 : Short_Integer; pragma Import (Ada, E321, "system__task_primitives__operations_E");
   E312 : Short_Integer; pragma Import (Ada, E312, "ada__real_time_E");
   E451 : Short_Integer; pragma Import (Ada, E451, "system__tasking__initialization_E");
   E461 : Short_Integer; pragma Import (Ada, E461, "system__tasking__protected_objects_E");
   E463 : Short_Integer; pragma Import (Ada, E463, "system__tasking__protected_objects__entries_E");
   E459 : Short_Integer; pragma Import (Ada, E459, "system__tasking__queuing_E");
   E467 : Short_Integer; pragma Import (Ada, E467, "system__tasking__stages_E");
   E445 : Short_Integer; pragma Import (Ada, E445, "gnat__threads_E");
   E274 : Short_Integer; pragma Import (Ada, E274, "rtidds__obj_E");
   E273 : Short_Integer; pragma Import (Ada, E273, "rtidds__obj_impl_E");
   E340 : Short_Integer; pragma Import (Ada, E340, "dds_support__sequences_generic_E");
   E161 : Short_Integer; pragma Import (Ada, E161, "rtidds__config_E");
   E424 : Short_Integer; pragma Import (Ada, E424, "rtidds__low_level__ndds_dds_c_dds_c_trust_plugins_h_E");
   E132 : Short_Integer; pragma Import (Ada, E132, "dds_E");
   E376 : Short_Integer; pragma Import (Ada, E376, "dds__condition_E");
   E396 : Short_Integer; pragma Import (Ada, E396, "dds__condition_impl_E");
   E390 : Short_Integer; pragma Import (Ada, E390, "dds__internal_conversions_E");
   E386 : Short_Integer; pragma Import (Ada, E386, "dds__listener_E");
   E368 : Short_Integer; pragma Import (Ada, E368, "dds__datareaderlistener_E");
   E411 : Short_Integer; pragma Import (Ada, E411, "dds__datawriterlistener_E");
   E476 : Short_Integer; pragma Import (Ada, E476, "dds__domainparticipantlistener_E");
   E412 : Short_Integer; pragma Import (Ada, E412, "dds__metptypesupport_E");
   E415 : Short_Integer; pragma Import (Ada, E415, "dds__publisherlistener_E");
   E378 : Short_Integer; pragma Import (Ada, E378, "dds__readcondition_E");
   E377 : Short_Integer; pragma Import (Ada, E377, "dds__querycondition_E");
   E374 : Short_Integer; pragma Import (Ada, E374, "dds__statuscondition_E");
   E372 : Short_Integer; pragma Import (Ada, E372, "dds__entity_E");
   E371 : Short_Integer; pragma Import (Ada, E371, "dds__domain_entity_E");
   E408 : Short_Integer; pragma Import (Ada, E408, "dds__statuscondition_impl_E");
   E406 : Short_Integer; pragma Import (Ada, E406, "dds__entity_impl_E");
   E435 : Short_Integer; pragma Import (Ada, E435, "dds__domain_entity_impl_E");
   E384 : Short_Integer; pragma Import (Ada, E384, "dds__subscriberlistener_E");
   E385 : Short_Integer; pragma Import (Ada, E385, "dds__topicdescription_E");
   E370 : Short_Integer; pragma Import (Ada, E370, "dds__datareader_E");
   E382 : Short_Integer; pragma Import (Ada, E382, "dds__datareaderseq_E");
   E381 : Short_Integer; pragma Import (Ada, E381, "dds__datareaderseq_E");
   E527 : Short_Integer; pragma Import (Ada, E527, "dds__multitopic_E");
   E380 : Short_Integer; pragma Import (Ada, E380, "dds__subscriber_E");
   E531 : Short_Integer; pragma Import (Ada, E531, "dds__subscriberseq_E");
   E530 : Short_Integer; pragma Import (Ada, E530, "dds__subscriberseq_E");
   E418 : Short_Integer; pragma Import (Ada, E418, "dds__topiclistener_E");
   E388 : Short_Integer; pragma Import (Ada, E388, "dds__datareaderlistener__low_level_E");
   E439 : Short_Integer; pragma Import (Ada, E439, "dds__datawriterlistener__low_level_E");
   E478 : Short_Integer; pragma Import (Ada, E478, "dds__domainparticipantlistener__low_level_E");
   E402 : Short_Integer; pragma Import (Ada, E402, "dds__subscriberlistener__low_level_E");
   E417 : Short_Integer; pragma Import (Ada, E417, "dds__topic_E");
   E352 : Short_Integer; pragma Import (Ada, E352, "dds__contentfilteredtopic_E");
   E367 : Short_Integer; pragma Import (Ada, E367, "dds__datareader_impl_E");
   E410 : Short_Integer; pragma Import (Ada, E410, "dds__datawriter_E");
   E497 : Short_Integer; pragma Import (Ada, E497, "dds__metptypesupport_none_E");
   E414 : Short_Integer; pragma Import (Ada, E414, "dds__publisher_E");
   E437 : Short_Integer; pragma Import (Ada, E437, "dds__datawriter_impl_E");
   E441 : Short_Integer; pragma Import (Ada, E441, "dds__publisher_impl_E");
   E529 : Short_Integer; pragma Import (Ada, E529, "dds__publisherseq_E");
   E528 : Short_Integer; pragma Import (Ada, E528, "dds__publisherseq_E");
   E350 : Short_Integer; pragma Import (Ada, E350, "dds__domainparticipant_E");
   E358 : Short_Integer; pragma Import (Ada, E358, "dds__domainparticipant_impl_E");
   E365 : Short_Integer; pragma Import (Ada, E365, "dds__domainparticipantfactory_E");
   E394 : Short_Integer; pragma Import (Ada, E394, "dds__readcondition_impl_E");
   E392 : Short_Integer; pragma Import (Ada, E392, "dds__querycondition_impl_E");
   E399 : Short_Integer; pragma Import (Ada, E399, "dds__subscriber_impl_E");
   E533 : Short_Integer; pragma Import (Ada, E533, "dds__topiclistener__low_level_E");
   E419 : Short_Integer; pragma Import (Ada, E419, "dds__typesupport_E");
   E480 : Short_Integer; pragma Import (Ada, E480, "dds__keyedoctets_typesupport_E");
   E500 : Short_Integer; pragma Import (Ada, E500, "dds__keyedstring_typesupport_E");
   E491 : Short_Integer; pragma Import (Ada, E491, "dds__octets_typesupport_E");
   E506 : Short_Integer; pragma Import (Ada, E506, "dds__participantbuiltintopicdata_typesupport_E");
   E510 : Short_Integer; pragma Import (Ada, E510, "dds__publicationbuiltintopicdata_typesupport_E");
   E514 : Short_Integer; pragma Import (Ada, E514, "dds__string_typesupport_E");
   E520 : Short_Integer; pragma Import (Ada, E520, "dds__subscriptionbuiltintopicdata_typesupport_E");
   E524 : Short_Integer; pragma Import (Ada, E524, "dds__topicbuiltintopicdata_typesupport_E");
   E485 : Short_Integer; pragma Import (Ada, E485, "dds__typed_datareader_generic_E");
   E482 : Short_Integer; pragma Import (Ada, E482, "dds__keyedoctets_datareader_E");
   E481 : Short_Integer; pragma Import (Ada, E481, "dds__keyedoctets_datareader_E");
   E502 : Short_Integer; pragma Import (Ada, E502, "dds__keyedstring_datareader_E");
   E501 : Short_Integer; pragma Import (Ada, E501, "dds__keyedstring_datareader_E");
   E493 : Short_Integer; pragma Import (Ada, E493, "dds__octets_datareader_E");
   E492 : Short_Integer; pragma Import (Ada, E492, "dds__octets_datareader_E");
   E508 : Short_Integer; pragma Import (Ada, E508, "dds__participantbuiltintopicdata_datareader_E");
   E507 : Short_Integer; pragma Import (Ada, E507, "dds__participantbuiltintopicdata_datareader_E");
   E512 : Short_Integer; pragma Import (Ada, E512, "dds__publicationbuiltintopicdata_datareader_E");
   E511 : Short_Integer; pragma Import (Ada, E511, "dds__publicationbuiltintopicdata_datareader_E");
   E516 : Short_Integer; pragma Import (Ada, E516, "dds__string_datareader_E");
   E515 : Short_Integer; pragma Import (Ada, E515, "dds__string_datareader_E");
   E522 : Short_Integer; pragma Import (Ada, E522, "dds__subscriptionbuiltintopicdata_datareader_E");
   E521 : Short_Integer; pragma Import (Ada, E521, "dds__subscriptionbuiltintopicdata_datareader_E");
   E526 : Short_Integer; pragma Import (Ada, E526, "dds__topicbuiltintopicdata_datareader_E");
   E525 : Short_Integer; pragma Import (Ada, E525, "dds__topicbuiltintopicdata_datareader_E");
   E489 : Short_Integer; pragma Import (Ada, E489, "dds__typed_datawriter_generic_E");
   E487 : Short_Integer; pragma Import (Ada, E487, "dds__keyedoctets_datawriter_E");
   E486 : Short_Integer; pragma Import (Ada, E486, "dds__keyedoctets_datawriter_E");
   E504 : Short_Integer; pragma Import (Ada, E504, "dds__keyedstring_datawriter_E");
   E503 : Short_Integer; pragma Import (Ada, E503, "dds__keyedstring_datawriter_E");
   E495 : Short_Integer; pragma Import (Ada, E495, "dds__octets_datawriter_E");
   E494 : Short_Integer; pragma Import (Ada, E494, "dds__octets_datawriter_E");
   E518 : Short_Integer; pragma Import (Ada, E518, "dds__string_datawriter_E");
   E517 : Short_Integer; pragma Import (Ada, E517, "dds__string_datawriter_E");
   E409 : Short_Integer; pragma Import (Ada, E409, "dds__typesupport_impl_E");
   E404 : Short_Integer; pragma Import (Ada, E404, "dds__topicdescription_impl_E");
   E354 : Short_Integer; pragma Import (Ada, E354, "dds__contentfilteredtopic_impl_E");
   E356 : Short_Integer; pragma Import (Ada, E356, "dds__topic_impl_E");

   Sec_Default_Sized_Stacks : array (1 .. 1) of aliased System.Secondary_Stack.SS_Stack (System.Parameters.Runtime_Default_Sec_Stack_Size);

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure finalize_library is
   begin
      E417 := E417 - 1;
      E399 := E399 - 1;
      declare
         procedure F1;
         pragma Import (Ada, F1, "dds__domainparticipantfactory__finalize_body");
      begin
         E365 := E365 - 1;
         F1;
      end;
      declare
         procedure F2;
         pragma Import (Ada, F2, "dds__domainparticipant_impl__finalize_body");
      begin
         E358 := E358 - 1;
         F2;
      end;
      E437 := E437 - 1;
      E367 := E367 - 1;
      E354 := E354 - 1;
      E356 := E356 - 1;
      declare
         procedure F3;
         pragma Import (Ada, F3, "dds__topic_impl__finalize_spec");
      begin
         F3;
      end;
      E352 := E352 - 1;
      declare
         procedure F4;
         pragma Import (Ada, F4, "dds__contentfilteredtopic_impl__finalize_spec");
      begin
         F4;
      end;
      E404 := E404 - 1;
      declare
         procedure F5;
         pragma Import (Ada, F5, "dds__topicdescription_impl__finalize_spec");
      begin
         F5;
      end;
      declare
         procedure F6;
         pragma Import (Ada, F6, "dds__typesupport_impl__finalize_spec");
      begin
         E409 := E409 - 1;
         F6;
      end;
      E514 := E514 - 1;
      E491 := E491 - 1;
      E500 := E500 - 1;
      E480 := E480 - 1;
      E524 := E524 - 1;
      E520 := E520 - 1;
      E510 := E510 - 1;
      E506 := E506 - 1;
      declare
         procedure F7;
         pragma Import (Ada, F7, "dds__topicbuiltintopicdata_typesupport__finalize_spec");
      begin
         F7;
      end;
      declare
         procedure F8;
         pragma Import (Ada, F8, "dds__subscriptionbuiltintopicdata_typesupport__finalize_spec");
      begin
         F8;
      end;
      declare
         procedure F9;
         pragma Import (Ada, F9, "dds__string_typesupport__finalize_spec");
      begin
         F9;
      end;
      declare
         procedure F10;
         pragma Import (Ada, F10, "dds__publicationbuiltintopicdata_typesupport__finalize_spec");
      begin
         F10;
      end;
      declare
         procedure F11;
         pragma Import (Ada, F11, "dds__participantbuiltintopicdata_typesupport__finalize_spec");
      begin
         F11;
      end;
      declare
         procedure F12;
         pragma Import (Ada, F12, "dds__octets_typesupport__finalize_spec");
      begin
         F12;
      end;
      declare
         procedure F13;
         pragma Import (Ada, F13, "dds__keyedstring_typesupport__finalize_spec");
      begin
         F13;
      end;
      declare
         procedure F14;
         pragma Import (Ada, F14, "dds__keyedoctets_typesupport__finalize_spec");
      begin
         F14;
      end;
      declare
         procedure F15;
         pragma Import (Ada, F15, "dds__typesupport__finalize_spec");
      begin
         E419 := E419 - 1;
         F15;
      end;
      declare
         procedure F16;
         pragma Import (Ada, F16, "dds__subscriber_impl__finalize_spec");
      begin
         F16;
      end;
      E392 := E392 - 1;
      declare
         procedure F17;
         pragma Import (Ada, F17, "dds__querycondition_impl__finalize_spec");
      begin
         F17;
      end;
      E394 := E394 - 1;
      declare
         procedure F18;
         pragma Import (Ada, F18, "dds__readcondition_impl__finalize_spec");
      begin
         F18;
      end;
      E441 := E441 - 1;
      declare
         procedure F19;
         pragma Import (Ada, F19, "dds__domainparticipantfactory__finalize_spec");
      begin
         F19;
      end;
      declare
         procedure F20;
         pragma Import (Ada, F20, "dds__domainparticipant_impl__finalize_spec");
      begin
         F20;
      end;
      declare
         procedure F21;
         pragma Import (Ada, F21, "dds__domainparticipant__finalize_body");
      begin
         E350 := E350 - 1;
         F21;
      end;
      declare
         procedure F22;
         pragma Import (Ada, F22, "dds__domainparticipant__finalize_spec");
      begin
         F22;
      end;
      declare
         procedure F23;
         pragma Import (Ada, F23, "dds__publisher_impl__finalize_spec");
      begin
         F23;
      end;
      declare
         procedure F24;
         pragma Import (Ada, F24, "dds__datawriter_impl__finalize_spec");
      begin
         F24;
      end;
      declare
         procedure F25;
         pragma Import (Ada, F25, "dds__publisher__finalize_body");
      begin
         E414 := E414 - 1;
         F25;
      end;
      declare
         procedure F26;
         pragma Import (Ada, F26, "dds__publisher__finalize_spec");
      begin
         F26;
      end;
      E497 := E497 - 1;
      declare
         procedure F27;
         pragma Import (Ada, F27, "dds__metptypesupport_none__finalize_spec");
      begin
         F27;
      end;
      declare
         procedure F28;
         pragma Import (Ada, F28, "dds__datawriter__finalize_spec");
      begin
         E410 := E410 - 1;
         F28;
      end;
      declare
         procedure F29;
         pragma Import (Ada, F29, "dds__datareader_impl__finalize_spec");
      begin
         F29;
      end;
      declare
         procedure F30;
         pragma Import (Ada, F30, "dds__contentfilteredtopic__finalize_spec");
      begin
         F30;
      end;
      declare
         procedure F31;
         pragma Import (Ada, F31, "dds__topic__finalize_spec");
      begin
         F31;
      end;
      declare
         procedure F32;
         pragma Import (Ada, F32, "dds__topiclistener__finalize_spec");
      begin
         E418 := E418 - 1;
         F32;
      end;
      declare
         procedure F33;
         pragma Import (Ada, F33, "dds__subscriber__finalize_body");
      begin
         E380 := E380 - 1;
         F33;
      end;
      declare
         procedure F34;
         pragma Import (Ada, F34, "dds__subscriber__finalize_spec");
      begin
         F34;
      end;
      declare
         procedure F35;
         pragma Import (Ada, F35, "dds__multitopic__finalize_spec");
      begin
         E527 := E527 - 1;
         F35;
      end;
      E370 := E370 - 1;
      declare
         procedure F36;
         pragma Import (Ada, F36, "dds__datareader__finalize_spec");
      begin
         F36;
      end;
      declare
         procedure F37;
         pragma Import (Ada, F37, "dds__topicdescription__finalize_spec");
      begin
         E385 := E385 - 1;
         F37;
      end;
      declare
         procedure F38;
         pragma Import (Ada, F38, "dds__subscriberlistener__finalize_spec");
      begin
         E384 := E384 - 1;
         F38;
      end;
      declare
         procedure F39;
         pragma Import (Ada, F39, "dds__domain_entity_impl__finalize_spec");
      begin
         E435 := E435 - 1;
         F39;
      end;
      E406 := E406 - 1;
      declare
         procedure F40;
         pragma Import (Ada, F40, "dds__entity_impl__finalize_spec");
      begin
         F40;
      end;
      E408 := E408 - 1;
      declare
         procedure F41;
         pragma Import (Ada, F41, "dds__statuscondition_impl__finalize_spec");
      begin
         F41;
      end;
      E374 := E374 - 1;
      declare
         procedure F42;
         pragma Import (Ada, F42, "dds__entity__finalize_spec");
      begin
         E372 := E372 - 1;
         F42;
      end;
      declare
         procedure F43;
         pragma Import (Ada, F43, "dds__statuscondition__finalize_spec");
      begin
         F43;
      end;
      declare
         procedure F44;
         pragma Import (Ada, F44, "dds__querycondition__finalize_spec");
      begin
         E377 := E377 - 1;
         F44;
      end;
      declare
         procedure F45;
         pragma Import (Ada, F45, "dds__readcondition__finalize_spec");
      begin
         E378 := E378 - 1;
         F45;
      end;
      declare
         procedure F46;
         pragma Import (Ada, F46, "dds__publisherlistener__finalize_spec");
      begin
         E415 := E415 - 1;
         F46;
      end;
      declare
         procedure F47;
         pragma Import (Ada, F47, "dds__metptypesupport__finalize_spec");
      begin
         E412 := E412 - 1;
         F47;
      end;
      declare
         procedure F48;
         pragma Import (Ada, F48, "dds__domainparticipantlistener__finalize_spec");
      begin
         E476 := E476 - 1;
         F48;
      end;
      declare
         procedure F49;
         pragma Import (Ada, F49, "dds__datawriterlistener__finalize_spec");
      begin
         E411 := E411 - 1;
         F49;
      end;
      declare
         procedure F50;
         pragma Import (Ada, F50, "dds__datareaderlistener__finalize_spec");
      begin
         E368 := E368 - 1;
         F50;
      end;
      declare
         procedure F51;
         pragma Import (Ada, F51, "dds__listener__finalize_spec");
      begin
         E386 := E386 - 1;
         F51;
      end;
      E396 := E396 - 1;
      declare
         procedure F52;
         pragma Import (Ada, F52, "dds__condition_impl__finalize_spec");
      begin
         F52;
      end;
      E376 := E376 - 1;
      declare
         procedure F53;
         pragma Import (Ada, F53, "dds__condition__finalize_spec");
      begin
         F53;
      end;
      E132 := E132 - 1;
      declare
         procedure F54;
         pragma Import (Ada, F54, "dds__finalize_spec");
      begin
         F54;
      end;
      declare
         procedure F55;
         pragma Import (Ada, F55, "rtidds__config__finalize_body");
      begin
         E161 := E161 - 1;
         F55;
      end;
      declare
         procedure F56;
         pragma Import (Ada, F56, "rtidds__config__finalize_spec");
      begin
         F56;
      end;
      E273 := E273 - 1;
      declare
         procedure F57;
         pragma Import (Ada, F57, "rtidds__obj_impl__finalize_spec");
      begin
         F57;
      end;
      declare
         procedure F58;
         pragma Import (Ada, F58, "rtidds__obj__finalize_spec");
      begin
         E274 := E274 - 1;
         F58;
      end;
      E463 := E463 - 1;
      declare
         procedure F59;
         pragma Import (Ada, F59, "system__tasking__protected_objects__entries__finalize_spec");
      begin
         F59;
      end;
      E280 := E280 - 1;
      declare
         procedure F60;
         pragma Import (Ada, F60, "system__pool_global__finalize_spec");
      begin
         F60;
      end;
      E116 := E116 - 1;
      declare
         procedure F61;
         pragma Import (Ada, F61, "ada__text_io__finalize_spec");
      begin
         F61;
      end;
      E148 := E148 - 1;
      declare
         procedure F62;
         pragma Import (Ada, F62, "ada__strings__wide_maps__finalize_spec");
      begin
         F62;
      end;
      E284 := E284 - 1;
      declare
         procedure F63;
         pragma Import (Ada, F63, "system__storage_pools__subpools__finalize_spec");
      begin
         F63;
      end;
      E276 := E276 - 1;
      declare
         procedure F64;
         pragma Import (Ada, F64, "system__finalization_masters__finalize_spec");
      begin
         F64;
      end;
      declare
         procedure F65;
         pragma Import (Ada, F65, "system__file_io__finalize_body");
      begin
         E126 := E126 - 1;
         F65;
      end;
      declare
         procedure Reraise_Library_Exception_If_Any;
            pragma Import (Ada, Reraise_Library_Exception_If_Any, "__gnat_reraise_library_exception_if_any");
      begin
         Reraise_Library_Exception_If_Any;
      end;
   end finalize_library;

   procedure adafinal is
      procedure s_stalib_adafinal;
      pragma Import (Ada, s_stalib_adafinal, "system__standard_library__adafinal");

      procedure Runtime_Finalize;
      pragma Import (C, Runtime_Finalize, "__gnat_runtime_finalize");

   begin
      if not Is_Elaborated then
         return;
      end if;
      Is_Elaborated := False;
      Runtime_Finalize;
      s_stalib_adafinal;
   end adafinal;

   type No_Param_Proc is access procedure;
   pragma Favor_Top_Level (No_Param_Proc);

   procedure adainit is
      Main_Priority : Integer;
      pragma Import (C, Main_Priority, "__gl_main_priority");
      Time_Slice_Value : Integer;
      pragma Import (C, Time_Slice_Value, "__gl_time_slice_val");
      WC_Encoding : Character;
      pragma Import (C, WC_Encoding, "__gl_wc_encoding");
      Locking_Policy : Character;
      pragma Import (C, Locking_Policy, "__gl_locking_policy");
      Queuing_Policy : Character;
      pragma Import (C, Queuing_Policy, "__gl_queuing_policy");
      Task_Dispatching_Policy : Character;
      pragma Import (C, Task_Dispatching_Policy, "__gl_task_dispatching_policy");
      Priority_Specific_Dispatching : System.Address;
      pragma Import (C, Priority_Specific_Dispatching, "__gl_priority_specific_dispatching");
      Num_Specific_Dispatching : Integer;
      pragma Import (C, Num_Specific_Dispatching, "__gl_num_specific_dispatching");
      Main_CPU : Integer;
      pragma Import (C, Main_CPU, "__gl_main_cpu");
      Interrupt_States : System.Address;
      pragma Import (C, Interrupt_States, "__gl_interrupt_states");
      Num_Interrupt_States : Integer;
      pragma Import (C, Num_Interrupt_States, "__gl_num_interrupt_states");
      Unreserve_All_Interrupts : Integer;
      pragma Import (C, Unreserve_All_Interrupts, "__gl_unreserve_all_interrupts");
      Detect_Blocking : Integer;
      pragma Import (C, Detect_Blocking, "__gl_detect_blocking");
      Default_Stack_Size : Integer;
      pragma Import (C, Default_Stack_Size, "__gl_default_stack_size");
      Default_Secondary_Stack_Size : System.Parameters.Size_Type;
      pragma Import (C, Default_Secondary_Stack_Size, "__gnat_default_ss_size");
      Bind_Env_Addr : System.Address;
      pragma Import (C, Bind_Env_Addr, "__gl_bind_env_addr");

      procedure Runtime_Initialize (Install_Handler : Integer);
      pragma Import (C, Runtime_Initialize, "__gnat_runtime_initialize");

      Finalize_Library_Objects : No_Param_Proc;
      pragma Import (C, Finalize_Library_Objects, "__gnat_finalize_library_objects");
      Binder_Sec_Stacks_Count : Natural;
      pragma Import (Ada, Binder_Sec_Stacks_Count, "__gnat_binder_ss_count");
      Default_Sized_SS_Pool : System.Address;
      pragma Import (Ada, Default_Sized_SS_Pool, "__gnat_default_ss_pool");

   begin
      if Is_Elaborated then
         return;
      end if;
      Is_Elaborated := True;
      Main_Priority := -1;
      Time_Slice_Value := -1;
      WC_Encoding := 'b';
      Locking_Policy := ' ';
      Queuing_Policy := ' ';
      Task_Dispatching_Policy := ' ';
      System.Restrictions.Run_Time_Restrictions :=
        (Set =>
          (False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, True, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False),
         Value => (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
         Violated =>
          (False, False, False, False, True, True, False, False, 
           True, False, False, True, True, True, True, False, 
           False, False, False, True, False, False, True, True, 
           False, True, True, False, True, True, True, True, 
           False, False, False, False, False, False, True, False, 
           False, True, False, True, False, True, True, False, 
           False, False, True, False, False, False, True, False, 
           True, False, True, False, False, False, False, False, 
           True, False, True, True, True, True, True, True, 
           False, True, True, True, False, True, True, False, 
           True, True, True, True, False, False, False, False, 
           False, False, False, False, False, False, False, True, 
           False, True, False),
         Count => (0, 0, 0, 0, 0, 0, 1, 0, 1, 0),
         Unknown => (False, False, False, False, False, False, True, False, True, False));
      Priority_Specific_Dispatching :=
        Local_Priority_Specific_Dispatching'Address;
      Num_Specific_Dispatching := 0;
      Main_CPU := -1;
      Interrupt_States := Local_Interrupt_States'Address;
      Num_Interrupt_States := 0;
      Unreserve_All_Interrupts := 0;
      Detect_Blocking := 0;
      Default_Stack_Size := -1;

      ada_main'Elab_Body;
      Default_Secondary_Stack_Size := System.Parameters.Runtime_Default_Sec_Stack_Size;
      Binder_Sec_Stacks_Count := 1;
      Default_Sized_SS_Pool := Sec_Default_Sized_Stacks'Address;

      Runtime_Initialize (1);

      Finalize_Library_Objects := finalize_library'access;

      Ada.Exceptions'Elab_Spec;
      System.Soft_Links'Elab_Spec;
      System.Exception_Table'Elab_Body;
      E023 := E023 + 1;
      Ada.Containers'Elab_Spec;
      E046 := E046 + 1;
      Ada.Io_Exceptions'Elab_Spec;
      E074 := E074 + 1;
      Ada.Numerics'Elab_Spec;
      E030 := E030 + 1;
      Ada.Strings'Elab_Spec;
      E061 := E061 + 1;
      Ada.Strings.Maps'Elab_Spec;
      E063 := E063 + 1;
      Ada.Strings.Maps.Constants'Elab_Spec;
      E066 := E066 + 1;
      Interfaces.C'Elab_Spec;
      E051 := E051 + 1;
      System.Exceptions'Elab_Spec;
      E024 := E024 + 1;
      System.Object_Reader'Elab_Spec;
      E088 := E088 + 1;
      System.Dwarf_Lines'Elab_Spec;
      System.Os_Lib'Elab_Body;
      E079 := E079 + 1;
      System.Soft_Links.Initialize'Elab_Body;
      E019 := E019 + 1;
      E011 := E011 + 1;
      System.Traceback.Symbolic'Elab_Body;
      E045 := E045 + 1;
      System.Img_Int'Elab_Spec;
      E029 := E029 + 1;
      E006 := E006 + 1;
      System.Img_Uns'Elab_Spec;
      E069 := E069 + 1;
      E056 := E056 + 1;
      Ada.Assertions'Elab_Spec;
      E310 := E310 + 1;
      Ada.Strings.Utf_Encoding'Elab_Spec;
      E104 := E104 + 1;
      Ada.Tags'Elab_Spec;
      Ada.Tags'Elab_Body;
      E110 := E110 + 1;
      Ada.Strings.Text_Buffers'Elab_Spec;
      E102 := E102 + 1;
      Gnat'Elab_Spec;
      E343 := E343 + 1;
      Interfaces.C.Strings'Elab_Spec;
      E163 := E163 + 1;
      Ada.Streams'Elab_Spec;
      E118 := E118 + 1;
      System.File_Control_Block'Elab_Spec;
      E130 := E130 + 1;
      System.Finalization_Root'Elab_Spec;
      E129 := E129 + 1;
      Ada.Finalization'Elab_Spec;
      E127 := E127 + 1;
      System.File_Io'Elab_Body;
      E126 := E126 + 1;
      System.Storage_Pools'Elab_Spec;
      E278 := E278 + 1;
      System.Finalization_Masters'Elab_Spec;
      System.Finalization_Masters'Elab_Body;
      E276 := E276 + 1;
      System.Storage_Pools.Subpools'Elab_Spec;
      E284 := E284 + 1;
      Ada.Strings.Wide_Maps'Elab_Spec;
      E148 := E148 + 1;
      System.Task_Info'Elab_Spec;
      E327 := E327 + 1;
      Ada.Calendar'Elab_Spec;
      Ada.Calendar'Elab_Body;
      E134 := E134 + 1;
      Ada.Calendar.Time_Zones'Elab_Spec;
      E138 := E138 + 1;
      Ada.Text_Io'Elab_Spec;
      Ada.Text_Io'Elab_Body;
      E116 := E116 + 1;
      System.Pool_Global'Elab_Spec;
      System.Pool_Global'Elab_Body;
      E280 := E280 + 1;
      System.Img_Llli'Elab_Spec;
      E263 := E263 + 1;
      System.Img_Lli'Elab_Spec;
      E334 := E334 + 1;
      System.Task_Primitives.Operations'Elab_Body;
      E321 := E321 + 1;
      Ada.Real_Time'Elab_Spec;
      Ada.Real_Time'Elab_Body;
      E312 := E312 + 1;
      System.Tasking.Initialization'Elab_Body;
      E451 := E451 + 1;
      System.Tasking.Protected_Objects'Elab_Body;
      E461 := E461 + 1;
      System.Tasking.Protected_Objects.Entries'Elab_Spec;
      E463 := E463 + 1;
      System.Tasking.Queuing'Elab_Body;
      E459 := E459 + 1;
      System.Tasking.Stages'Elab_Body;
      E467 := E467 + 1;
      Gnat.Threads'Elab_Body;
      E445 := E445 + 1;
      RTIDDS.OBJ'ELAB_SPEC;
      E274 := E274 + 1;
      RTIDDS.OBJ_IMPL'ELAB_SPEC;
      E273 := E273 + 1;
      E340 := E340 + 1;
      RTIDDS.CONFIG'ELAB_SPEC;
      RTIDDS.CONFIG'ELAB_BODY;
      E161 := E161 + 1;
      RTIDDS.LOW_LEVEL.NDDS_DDS_C_DDS_C_TRUST_PLUGINS_H'ELAB_SPEC;
      E424 := E424 + 1;
      DDS'ELAB_SPEC;
      DDS'ELAB_BODY;
      E132 := E132 + 1;
      DDS.CONDITION'ELAB_SPEC;
      E376 := E376 + 1;
      DDS.CONDITION_IMPL'ELAB_SPEC;
      DDS.CONDITION_IMPL'ELAB_BODY;
      E396 := E396 + 1;
      E390 := E390 + 1;
      DDS.LISTENER'ELAB_SPEC;
      E386 := E386 + 1;
      DDS.DATAREADERLISTENER'ELAB_SPEC;
      E368 := E368 + 1;
      DDS.DATAWRITERLISTENER'ELAB_SPEC;
      E411 := E411 + 1;
      DDS.DOMAINPARTICIPANTLISTENER'ELAB_SPEC;
      E476 := E476 + 1;
      DDS.METPTYPESUPPORT'ELAB_SPEC;
      E412 := E412 + 1;
      DDS.PUBLISHERLISTENER'ELAB_SPEC;
      E415 := E415 + 1;
      DDS.READCONDITION'ELAB_SPEC;
      E378 := E378 + 1;
      DDS.QUERYCONDITION'ELAB_SPEC;
      E377 := E377 + 1;
      DDS.STATUSCONDITION'ELAB_SPEC;
      DDS.ENTITY'ELAB_SPEC;
      E372 := E372 + 1;
      E374 := E374 + 1;
      DDS.DOMAIN_ENTITY'ELAB_SPEC;
      E371 := E371 + 1;
      DDS.STATUSCONDITION_IMPL'ELAB_SPEC;
      DDS.STATUSCONDITION_IMPL'ELAB_BODY;
      E408 := E408 + 1;
      DDS.ENTITY_IMPL'ELAB_SPEC;
      DDS.ENTITY_IMPL'ELAB_BODY;
      E406 := E406 + 1;
      DDS.DOMAIN_ENTITY_IMPL'ELAB_SPEC;
      E435 := E435 + 1;
      DDS.SUBSCRIBERLISTENER'ELAB_SPEC;
      E384 := E384 + 1;
      DDS.TOPICDESCRIPTION'ELAB_SPEC;
      E385 := E385 + 1;
      DDS.DATAREADER'ELAB_SPEC;
      E370 := E370 + 1;
      DDS.DATAREADERSEQ'ELAB_SPEC;
      DDS.DATAREADERSEQ'ELAB_BODY;
      E382 := E382 + 1;
      DDS.MULTITOPIC'ELAB_SPEC;
      E527 := E527 + 1;
      DDS.SUBSCRIBER'ELAB_SPEC;
      DDS.SUBSCRIBER'ELAB_BODY;
      E380 := E380 + 1;
      DDS.SUBSCRIBERSEQ'ELAB_SPEC;
      DDS.SUBSCRIBERSEQ'ELAB_BODY;
      E531 := E531 + 1;
      DDS.TOPICLISTENER'ELAB_SPEC;
      E418 := E418 + 1;
      DDS.TOPIC'ELAB_SPEC;
      DDS.CONTENTFILTEREDTOPIC'ELAB_SPEC;
      DDS.DATAREADER_IMPL'ELAB_SPEC;
      E388 := E388 + 1;
      DDS.DATAWRITER'ELAB_SPEC;
      E410 := E410 + 1;
      DDS.METPTYPESUPPORT_NONE'ELAB_SPEC;
      DDS.METPTYPESUPPORT_NONE'ELAB_BODY;
      E497 := E497 + 1;
      DDS.PUBLISHER'ELAB_SPEC;
      DDS.PUBLISHER'ELAB_BODY;
      E414 := E414 + 1;
      DDS.DATAWRITER_IMPL'ELAB_SPEC;
      E439 := E439 + 1;
      DDS.PUBLISHER_IMPL'ELAB_SPEC;
      DDS.PUBLISHERSEQ'ELAB_SPEC;
      DDS.PUBLISHERSEQ'ELAB_BODY;
      E529 := E529 + 1;
      DDS.DOMAINPARTICIPANT'ELAB_SPEC;
      DDS.DOMAINPARTICIPANT'ELAB_BODY;
      E350 := E350 + 1;
      DDS.DOMAINPARTICIPANT_IMPL'ELAB_SPEC;
      DDS.DOMAINPARTICIPANTFACTORY'ELAB_SPEC;
      DDS.PUBLISHER_IMPL'ELAB_BODY;
      E441 := E441 + 1;
      DDS.READCONDITION_IMPL'ELAB_SPEC;
      DDS.READCONDITION_IMPL'ELAB_BODY;
      E394 := E394 + 1;
      DDS.QUERYCONDITION_IMPL'ELAB_SPEC;
      DDS.QUERYCONDITION_IMPL'ELAB_BODY;
      E392 := E392 + 1;
      DDS.SUBSCRIBER_IMPL'ELAB_SPEC;
      E402 := E402 + 1;
      DDS.TYPESUPPORT'ELAB_SPEC;
      E419 := E419 + 1;
      DDS.KEYEDOCTETS_TYPESUPPORT'ELAB_SPEC;
      DDS.KEYEDSTRING_TYPESUPPORT'ELAB_SPEC;
      DDS.OCTETS_TYPESUPPORT'ELAB_SPEC;
      DDS.PARTICIPANTBUILTINTOPICDATA_TYPESUPPORT'ELAB_SPEC;
      DDS.PUBLICATIONBUILTINTOPICDATA_TYPESUPPORT'ELAB_SPEC;
      DDS.STRING_TYPESUPPORT'ELAB_SPEC;
      DDS.SUBSCRIPTIONBUILTINTOPICDATA_TYPESUPPORT'ELAB_SPEC;
      DDS.TOPICBUILTINTOPICDATA_TYPESUPPORT'ELAB_SPEC;
      E485 := E485 + 1;
      DDS.KEYEDOCTETS_DATAREADER'ELAB_SPEC;
      DDS.KEYEDOCTETS_DATAREADER'ELAB_BODY;
      E482 := E482 + 1;
      DDS.KEYEDSTRING_DATAREADER'ELAB_SPEC;
      DDS.KEYEDSTRING_DATAREADER'ELAB_BODY;
      E502 := E502 + 1;
      DDS.OCTETS_DATAREADER'ELAB_SPEC;
      DDS.OCTETS_DATAREADER'ELAB_BODY;
      E493 := E493 + 1;
      DDS.PARTICIPANTBUILTINTOPICDATA_DATAREADER'ELAB_SPEC;
      DDS.PARTICIPANTBUILTINTOPICDATA_DATAREADER'ELAB_BODY;
      E508 := E508 + 1;
      DDS.PARTICIPANTBUILTINTOPICDATA_TYPESUPPORT'ELAB_BODY;
      E506 := E506 + 1;
      DDS.PUBLICATIONBUILTINTOPICDATA_DATAREADER'ELAB_SPEC;
      DDS.PUBLICATIONBUILTINTOPICDATA_DATAREADER'ELAB_BODY;
      E512 := E512 + 1;
      DDS.PUBLICATIONBUILTINTOPICDATA_TYPESUPPORT'ELAB_BODY;
      E510 := E510 + 1;
      DDS.STRING_DATAREADER'ELAB_SPEC;
      DDS.STRING_DATAREADER'ELAB_BODY;
      E516 := E516 + 1;
      DDS.SUBSCRIPTIONBUILTINTOPICDATA_DATAREADER'ELAB_SPEC;
      DDS.SUBSCRIPTIONBUILTINTOPICDATA_DATAREADER'ELAB_BODY;
      E522 := E522 + 1;
      DDS.SUBSCRIPTIONBUILTINTOPICDATA_TYPESUPPORT'ELAB_BODY;
      E520 := E520 + 1;
      DDS.TOPICBUILTINTOPICDATA_DATAREADER'ELAB_SPEC;
      DDS.TOPICBUILTINTOPICDATA_DATAREADER'ELAB_BODY;
      E526 := E526 + 1;
      DDS.TOPICBUILTINTOPICDATA_TYPESUPPORT'ELAB_BODY;
      E524 := E524 + 1;
      E489 := E489 + 1;
      DDS.KEYEDOCTETS_DATAWRITER'ELAB_SPEC;
      DDS.KEYEDOCTETS_DATAWRITER'ELAB_BODY;
      E487 := E487 + 1;
      DDS.KEYEDOCTETS_TYPESUPPORT'ELAB_BODY;
      E480 := E480 + 1;
      DDS.KEYEDSTRING_DATAWRITER'ELAB_SPEC;
      DDS.KEYEDSTRING_DATAWRITER'ELAB_BODY;
      E504 := E504 + 1;
      DDS.KEYEDSTRING_TYPESUPPORT'ELAB_BODY;
      E500 := E500 + 1;
      DDS.OCTETS_DATAWRITER'ELAB_SPEC;
      DDS.OCTETS_DATAWRITER'ELAB_BODY;
      E495 := E495 + 1;
      DDS.OCTETS_TYPESUPPORT'ELAB_BODY;
      E491 := E491 + 1;
      DDS.STRING_DATAWRITER'ELAB_SPEC;
      DDS.STRING_DATAWRITER'ELAB_BODY;
      E518 := E518 + 1;
      DDS.STRING_TYPESUPPORT'ELAB_BODY;
      E514 := E514 + 1;
      DDS.TYPESUPPORT_IMPL'ELAB_SPEC;
      E409 := E409 + 1;
      DDS.TOPICDESCRIPTION_IMPL'ELAB_SPEC;
      DDS.TOPICDESCRIPTION_IMPL'ELAB_BODY;
      E404 := E404 + 1;
      DDS.CONTENTFILTEREDTOPIC_IMPL'ELAB_SPEC;
      E352 := E352 + 1;
      DDS.TOPIC_IMPL'ELAB_SPEC;
      DDS.TOPIC_IMPL'ELAB_BODY;
      E356 := E356 + 1;
      DDS.CONTENTFILTEREDTOPIC_IMPL'ELAB_BODY;
      E354 := E354 + 1;
      DDS.DATAREADER_IMPL'ELAB_BODY;
      E367 := E367 + 1;
      DDS.DATAWRITER_IMPL'ELAB_BODY;
      E437 := E437 + 1;
      DDS.DOMAINPARTICIPANT_IMPL'ELAB_BODY;
      E358 := E358 + 1;
      DDS.DOMAINPARTICIPANTFACTORY'ELAB_BODY;
      E365 := E365 + 1;
      E478 := E478 + 1;
      DDS.SUBSCRIBER_IMPL'ELAB_BODY;
      E399 := E399 + 1;
      E417 := E417 + 1;
      E533 := E533 + 1;
   end adainit;

   procedure Ada_Main_Program;
   pragma Import (Ada, Ada_Main_Program, "_ada_main");

   function main
     (argc : Integer;
      argv : System.Address;
      envp : System.Address)
      return Integer
   is
      procedure Initialize (Addr : System.Address);
      pragma Import (C, Initialize, "__gnat_initialize");

      procedure Finalize;
      pragma Import (C, Finalize, "__gnat_finalize");
      SEH : aliased array (1 .. 2) of Integer;

      Ensure_Reference : aliased System.Address := Ada_Main_Program_Name'Address;
      pragma Volatile (Ensure_Reference);

   begin
      if gnat_argc = 0 then
         gnat_argc := argc;
         gnat_argv := argv;
      end if;
      gnat_envp := envp;

      Initialize (SEH'Address);
      adainit;
      Ada_Main_Program;
      adafinal;
      Finalize;
      return (gnat_exit_status);
   end;

--  BEGIN Object file/option list
   --   /home/per/rti_workspace/7.0.0/examples/connext_dds/ada/x/obj/main.o
   --   -L/home/per/rti_workspace/7.0.0/examples/connext_dds/ada/x/obj/
   --   -L/home/per/rti_workspace/7.0.0/examples/connext_dds/ada/x/obj/
   --   -L/usr/dds/lib/x86_64-pc-linux-gnu/static/release/ali/
   --   -L/usr/dds/lib/x86_64-pc-linux-gnu/
   --   -L/home/gnat/lib/gcc/x86_64-pc-linux-gnu/11.3.1/adalib/
   --   -static
   --   -lgnarl
   --   -lgnat
   --   -lrt
   --   -lpthread
   --   -ldl
--  END Object file/option list   

end ada_main;
