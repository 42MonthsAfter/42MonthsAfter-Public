class eAI_Targetting_Follow_State extends eAIState {
float time;
eAITargetInformation target;
void eAI_Targetting_Follow_State(eAIBase _unit) {
m_Name = "Follow";
m_ClassName = "eAI_Targetting_Follow_State";
}
override void OnEntry(string Event) {

}
override void OnExit(string Event, bool Aborted) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
time += DeltaTime; 
if (time > 0.25)	
{	
target.Update(unit.GetGroup());	
time = 0;	
}
return EXIT; 
}
}
eAIState Create_eAI_Targetting_Follow_State(eAIBase _unit) {
return new eAI_Targetting_Follow_State(_unit);
}
