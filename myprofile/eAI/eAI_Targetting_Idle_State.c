class eAI_Targetting_Idle_State extends eAIState {
float time;
void eAI_Targetting_Idle_State(eAIBase _unit) {
m_Name = "Idle";
m_ClassName = "eAI_Targetting_Idle_State";
}
override void OnEntry(string Event) {

}
override void OnExit(string Event, bool Aborted) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
time += DeltaTime; 
if (time > 0.25) {	
time = 0;	
return EXIT;	
} 
return CONTINUE; // We don't want to eval the transitions every frame, it takes time for some 
}
}
eAIState Create_eAI_Targetting_Idle_State(eAIBase _unit) {
return new eAI_Targetting_Idle_State(_unit);
}
