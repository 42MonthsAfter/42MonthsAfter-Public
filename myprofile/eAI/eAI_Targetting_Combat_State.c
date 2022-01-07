class eAI_Targetting_Combat_State extends eAIState {
float time;
bool melee;
void eAI_Targetting_Combat_State(eAIBase _unit) {
m_Name = "Combat";
m_ClassName = "eAI_Targetting_Combat_State";
}
override void OnEntry(string Event) {
melee = false	
// we assume the targets have been cleaned and sorted in the transition	
if (!unit.ReloadingInADS) {	
unit.RaiseWeapon(true);	
unit.RefreshAimArbitration();	
unit.DelayFiring(1000, 2000);	
} else unit.ReloadingInADS = false; // if we just came from an ADS reload	
}
override void OnExit(string Event, bool Aborted) {
if (!unit.ReloadingInADS && !melee) {	
unit.StopAimArbitration();	
unit.RaiseWeapon(false);	
}	
}
override int OnUpdate(float DeltaTime, int SimulationPrecision) {
time += DeltaTime;	
if (time < 0.08) {	
return CONTINUE;	
} time = 0;
if (unit.threats.Count() < 1) return EXIT;
if (false){//vector.Distance(unit.threats[0].GetPosition(), unit.GetPosition()) < 2.0) {	
if (!melee) {	
melee = true	
unit.StopAimArbitration();	
unit.RaiseWeapon(false);	
unit.DelayPunching(1500, 0);	
} else {	
unit.TryPunching(unit.threats[0])	
//target.DecreaseHealth(0.25);	
}
} else {	
if (melee) {	
melee = false	
unit.RaiseWeapon(true);	
unit.RefreshAimArbitration();	
unit.DelayFiring(1000, 2000);	
}	
EntityAI mag, weap; // these are unused here	
if (unit.ShouldReload(mag, weap)) {	
unit.ReloadingInADS = true;	
return EXIT;	
}	
if (unit.ShouldFire())	
unit.FireHeldWeapon();	
}
return CONTINUE; 
}
}
eAIState Create_eAI_Targetting_Combat_State(eAIBase _unit) {
return new eAI_Targetting_Combat_State(_unit);
}
