--*****************************************************************************/
--*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
--*                                                                           */
--*         Permission to modify and use for internal purposes granted.       */
--* This software is provided "as is", without warranty, express or implied.  */
--*                                                                           */
--*****************************************************************************/
with DDS;
with DDS.DomainParticipantFactory;
with DDS.DomainParticipant;
with DDS.Topic;
with DDS.Builtin_String_DataWriter;
with DDS.Builtin_String_TypeSupport;
with Ada.Text_IO;
with Ada.Exceptions;
with DDS.DataWriter;
procedure Hello.Publisher is
   Participant   : DDS.DomainParticipant.Ref_Access          := null;
   Topic         : DDS.Topic.Ref_Access                      := null;
   String_Writer : DDS.Builtin_String_DataWriter.Ref_Access  := null;

   NULL_ENTITY   : exception;

   Wait_Reader_Timeout : constant Duration := 60.0;
   use type DDS.DomainParticipant.Ref_Access;
   use type DDS.Topic.Ref_Access;
   use type DDS.Builtin_String_DataWriter.Ref_Access;
begin
   begin
      -- Set Up ---------------------------------------------------------
      --  Create the domain participant on domain ID 0
      Participant := DDS.DomainParticipantFactory.Get_Instance.Create_Participant
        (Domain_Id  => 0);
      if Participant = null then
         raise NULL_ENTITY with "Unable to create participant";
      end if;

      Topic := Participant.Create_Topic
        (Topic_Name => Topic_Name,
         Type_Name  => DDS.Builtin_String_TypeSupport.Get_Type_Name);
      if Topic = null then
         raise NULL_ENTITY with "Unable to create topic";
      end if;

      String_Writer := DDS.Builtin_String_DataWriter.Narrow
        (Participant.Create_DataWriter
           (A_Topic    => Topic));

      if String_Writer = null then
         raise NULL_ENTITY with "Unable to create datawriter";
      end if;


      Ada.Text_IO.Put_Line ("Ready to write data, tha application will wait" & Wait_Reader_Timeout'Image & " seconds for the subscriber.");
      Ada.Text_IO.Put_Line ("When the subscriber is ready, you can start writing.");
      Ada.Text_IO.Put_Line ("Waiting for reader.");

      String_Writer.Wait (DDS.PUBLICATION_MATCH_STATUS, Wait_reader_Timeout);
      Ada.Text_IO.Put_Line ("Enter an empty line to do a clean shutdown.");
      Ada.Text_IO.Put_Line ("Reader o Writer.");
      loop
         Ada.Text_IO.Put ("Please type a message> ");
         declare
            Message : constant String := Ada.Text_IO.Get_Line;
         begin
            exit when Message'Length = 0;
            declare
               DdsMsg  : DDS.String := DDS.To_DDS_String (Message);
            begin
               String_Writer.Write
                 (Instance_Data => DdsMsg,
                  Handle        => DDS.HANDLE_NIL);
               DDS.Finalize (DdsMsg);
            end;
         end;
      end loop;
   exception
      when E : others =>
         Ada.Text_IO.Put_Line (Ada.Exceptions.Exception_Message (E));
   end;
   --  Clean Up

   if Participant /= null then
      if Topic /= null then
         if String_Writer /= null then
            Participant.Delete_DataWriter (DDS.DataWriter.Ref_Access (String_Writer));
         end if;
         Participant.Delete_Topic (Topic);
      end if;
      DDS.DomainParticipantFactory.Get_Instance.Delete_Participant (Participant);
   end if;

end Hello.Publisher;
