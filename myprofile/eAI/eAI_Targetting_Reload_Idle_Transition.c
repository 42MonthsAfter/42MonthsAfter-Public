class eAI_Targetting_Reload_Idle_Transition extends eAITransition {
private eAI_Targetting_Reload_State src;
private eAI_Targetting_Idle_State dst;
void eAI_Targetting_Reload_Idle_Transition(eAIBase _unit, eAIHFSM _fsm) {
m_ClassName = "eAI_Targetting_Reload_Idle_Transition";
src = _fsm.GetState("eAI_Targetting_Reload_State");
dst = _fsm.GetState("eAI_Targetting_Idle_State");
}
override int Guard() {
// previous state is assumed to have succeeded first, if it failed, then we must always assume this succeeds to perform a reset 
return SUCCESS; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
eAITransition Create_eAI_Targetting_Reload_Idle_Transition(eAIBase _unit, eAIHFSM _fsm) {
return new eAI_Targetting_Reload_Idle_Transition(_unit, _fsm);
}
