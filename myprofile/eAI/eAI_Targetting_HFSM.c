class eAI_Targetting_HFSM extends eAIHFSM {
void eAI_Targetting_HFSM(eAIBase unit, eAIState parentState) {
m_Name = "Targetting";
m_DefaultState = "eAI_Targetting_Idle_State";
Setup();
SortTransitions();
}
void Setup() {
AddState(new eAI_Targetting_Idle_State(m_Unit));
AddState(new eAI_Targetting_Follow_State(m_Unit));
AddState(new eAI_Targetting_Reload_State(m_Unit));
AddState(new eAI_Targetting_Combat_State(m_Unit));
AddTransition(new eAI_Targetting_Idle_Follow_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Follow_Idle_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Follow_Reload_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Idle_Reload_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Reload_Combat_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Reload_Follow_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Reload_Idle_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Idle_Combat_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Follow_Combat_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Combat_Reload_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Combat_Follow_Transition(m_Unit, this));
AddTransition(new eAI_Targetting_Combat_Idle_Transition(m_Unit, this));
}
}
eAIHFSM Create_eAI_Targetting_HFSM(eAIBase unit, eAIState parentState) {
return new eAI_Targetting_HFSM(unit, parentState);
}
