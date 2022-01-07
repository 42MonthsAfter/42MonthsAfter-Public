class eAI_Targetting_Idle_Reload_Transition extends eAITransition {
private eAI_Targetting_Idle_State src;
private eAI_Targetting_Reload_State dst;
void eAI_Targetting_Idle_Reload_Transition(eAIBase _unit, eAIHFSM _fsm) {
m_ClassName = "eAI_Targetting_Idle_Reload_Transition";
src = _fsm.GetState("eAI_Targetting_Idle_State");
dst = _fsm.GetState("eAI_Targetting_Reload_State");
}
override int Guard() {
if (!unit.ShouldReload(dst.magazine, dst.weapon)) return FAIL;
// don't move to the state if the action manager can't be initiated.	
if (!unit.GetActionManager() || unit.GetActionManager().GetRunningAction()) return FAIL;	
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
eAITransition Create_eAI_Targetting_Idle_Reload_Transition(eAIBase _unit, eAIHFSM _fsm) {
return new eAI_Targetting_Idle_Reload_Transition(_unit, _fsm);
}
