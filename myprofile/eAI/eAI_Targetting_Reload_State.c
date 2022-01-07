class eAI_Targetting_Reload_State extends eAIState {
EntityAI magazine;
EntityAI weapon;
void eAI_Targetting_Reload_State(eAIBase _unit) {
m_Name = "Reload";
m_ClassName = "eAI_Targetting_Reload_State";
}
override void OnEntry(string Event) {
unit.ReloadWeaponAI(weapon, magazine);	
}
override void OnExit(string Event, bool Aborted) {

}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
if (!unit.GetWeaponManager()) return EXIT;
if (unit.GetWeaponManager().IsRunning()) return CONTINUE;
return EXIT; 
}
}
eAIState Create_eAI_Targetting_Reload_State(eAIBase _unit) {
return new eAI_Targetting_Reload_State(_unit);
}
