class eAI_Targetting_Reload_Follow_Transition extends eAITransition {
private eAI_Targetting_Reload_State src;
private eAI_Targetting_Follow_State dst;
void eAI_Targetting_Reload_Follow_Transition(eAIBase _unit, eAIHFSM _fsm) {
m_ClassName = "eAI_Targetting_Reload_Follow_Transition";
src = _fsm.GetState("eAI_Targetting_Reload_State");
dst = _fsm.GetState("eAI_Targetting_Follow_State");
}
override int Guard() {
auto group = unit.GetGroup(); 
if (!group) return FAIL;
auto leader = group.GetLeader(); 
if (!leader) return FAIL;
dst.target = group.GetTargetInformation();	
if (leader == unit)	
dst.target = group.GetWaypointTargetInformation(); 
if (!dst.target) return FAIL;
if (m_FSM.GetLastState() == "Follow")	
return SUCCESS;
return FAIL; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return ""; }
}
eAITransition Create_eAI_Targetting_Reload_Follow_Transition(eAIBase _unit, eAIHFSM _fsm) {
return new eAI_Targetting_Reload_Follow_Transition(_unit, _fsm);
}
