with Ada.Text_IO; use Ada.Text_IO;
with Dds.DomainParticipantFactory;
with Dds.DomainParticipant;
procedure Main is
   F : Dds.DomainParticipantFactory.Ref_Access := Dds.DomainParticipantFactory.Get_Instance;
   QoS : aliased Dds.DomainParticipantFactoryQos;
begin
   F.Get_Qos (Qos);
   Put_Line (QoS.Resource_Limits.Max_Objects_Per_Thread'Img);
end Main;
