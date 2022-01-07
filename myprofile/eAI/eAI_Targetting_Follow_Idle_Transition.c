class eAI_Targetting_Follow_Idle_Transition extends eAITransition {
private eAI_Targetting_Follow_State src;
private eAI_Targetting_Idle_State dst;
void eAI_Targetting_Follow_Idle_Transition(eAIBase _unit, eAIHFSM _fsm) {
m_ClassName = "eAI_Targetting_Follow_Idle_Transition";
src = _fsm.GetState("eAI_Targetting_Follow_State");
dst = _fsm.GetState("eAI_Targetting_Idle_State");
}
override int Guard() {
auto group = unit.GetGroup(); 
if (!group) return FAIL;
auto leader = group.GetLeader(); 
if (!leader) return SUCCESS;
auto target = group.GetTargetInformation();	
if (leader == unit)	
target = group.GetWaypointTargetInformation(); 
if (!target) return SUCCESS;
if (unit.GetRequestedTransition("Stop"))	
{	
target.RemoveAI(unit);	
return SUCCESS;	
}
return FAIL; 
}
override eAIState GetSource() { return src; }
override eAIState GetDestination() { return dst; }
override string GetEvent() { return "eAI_Stop_Event"; }
}
eAITransition Create_eAI_Targetting_Follow_Idle_Transition(eAIBase _unit, eAIHFSM _fsm) {
return new eAI_Targetting_Follow_Idle_Transition(_unit, _fsm);
}
