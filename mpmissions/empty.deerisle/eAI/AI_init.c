// Patrol 1 RCFI Swamp Patrol = 
ref array<vector> patrol_1  = {"3777.4 16.2 8945.16", "3733.65 9.31 8793.35", "3733.65 9.37 8853.92"};

// Patrol 2 RCFI Birdsnest = 
ref array<vector> patrol_2  = {"3683.82 22.1 8719.87", "3774.28 11.9 8783.09", "3732.73 8.9 8780.04", "3727.36 9.4 8853.8"};

// Patrol 3 Paris Island SE Loop = 
ref array<vector> patrol_3  = {"2952.79 22.6 3449.59", "2845.37 22.5 3550.21", "2932.26 22.5 3649.68", "3029.17 22.5 3550.31", "2952.79 22.6 3449.59"};

// Patrol 4 Paris Island Roof Top Hospital= 
ref array<vector> patrol_4  = {"3122.89 33.3 4179.01", "3133.81 33.3 4188.21", "3128.5 33.3 4190.83", "3141.14 33.3 4204.12"};

// Patrol 5 Paris Island Roof Top Fire Station= 
ref array<vector> patrol_5  = {"2984.21 31.7 3808.32", "2996.59 31.7 3807.46", "2988.08 31.7 3795.2", "2976.46 31.7 3795.88"};

// Patrol 6 Paris Island NW Loop= 
ref array<vector> patrol_6  = {"2661.05 22.7 4469.74", "2489.97 22.5 4174.84", "2672.34 22.5 4066.23", "2758.96 22.5 4213.64"};

// Patrol 7 Prison Island Entrance Patrol 1= 
ref array<vector> patrol_7  = {"5250.66 18 623.41", "5257.39 14.9 725.65", "5447.25 10.65 788.58"};

// Patrol 8 Prison Island Inner Loop = 
ref array<vector> patrol_8  = {"5547.37 34.9 746.29", "5493.84 34.89 756.61", "5416.05 35.5 711.23", "5372.91 34.9 670.138"};

// Patrol 9 Paris Island Roof Top = 
ref array<vector> patrol_9  = {"5396.74 43.7 714.1", "5401.79 43.7 708.02", "5389.83 43.67 706.20"};

// Patrol 10 Area 42 Entrance Patrol = 
ref array<vector> patrol_10 = {"12824.1 4.32 9849.22", "12825.8 4.2 9984.5", "12911.3 4.2 9981.94"};

// Patrol 11 Area 42 Roof Patrol 01 =
ref array<vector> patrol_11 = {"13269 24 9919.87", "13261.7 23.6 9937.99", "13260 23.6 9902.97", "13278.6 23.46 9900.93", "13277.7 23.6 9936.07"};

// Patrol 12 Area 42 Roof Patrol 02 =
ref array<vector> patrol_12 = {"13605.6 22 9849.95", "13598 22 9851.58", "13597.6 22 9837.25", "13610.6 22 9836.96"};

// Patrol 13 Area 42 Straight and Narrow =
ref array<vector> patrol_13 = {"13485.5 13 10001.3", "13201.8 13 10041.6"};

// Patrol 14 Airfield Patrol 01 =
ref array<vector> patrol_14 = {"5284.81 75 3926.46", "5498.87 74.5 3837.57", "5557.1 74.2 3842.77", "5556.22 74.5 3781.51", "5487.76 74.5 3783.3"};

 // Patrol 15 Airfield Roof Top Patrol =
ref array<vector> patrol_15 = {"5510.73 84 3734.9", "5578.49 84 3726.27", "5579.97 85 3728.27", "5509.06 84 3753.51"};

 // Patrol 16 Base Caravan Patrol 01 =
ref array<vector> patrol_16 = {"4737.14 109 2326.37", "5726.87 109 2340.6", "5728.88 108.8 2346.77", "5740 108.87 2346", "5742.64 108.87 2348.76", "5741.06 108.87 2353.19"};

 // Patrol 17 Base Huts Patrol 01 =
ref array<vector> patrol_17 = {"5706.97 109 2388.04", "5699.56 108.5 2392.16", "5694.02 108.75 2392.99", "5693.32 108.79 2386.73", "5687.93 108.87 2387.42", "5688.12 108.87 2393.96"};

 // Patrol 18 Base Forest Patrol 01 =
ref array<vector> patrol_18 = {"5705.89 108.8 2431.74", "5712.36 108.04 2432.23", "5712.36 108.2 2442.64", "5693.99 108 2445.37", "5684.47 107.95 2450.38", "5686.22 107.8 2464.4", "5694.89 108.1 2475.59", "5697.27 108.2 2485.94"};

ref array<array<vector>> patrol_list = {patrol_1, patrol_2, patrol_3, patrol_4, patrol_5, patrol_6, patrol_7, patrol_8, patrol_9, patrol_10, patrol_11, patrol_12, patrol_13, patrol_14, patrol_15, patrol_16, patrol_17, patrol_17};

// IMPORTANT: If you add an entry to the above list, pick the loadout for it by adding the loadout filename to this list
ref array<string> patrol_loadouts = {"SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json", "SoldierLoadout.json"};

// you may change these quantities
const int NUMBER_PER_PATROL = 2;	// Number of AI per patrol
const int MAXR = 400;				// This is the main spawn radius- how close a player needs to be to spawn them in.
const int MINR = 60;				// If a player is this close to the patrol start point, it is too close for them to spawn
const int DESPAWNR = 400;			// If all players are this far away, they despawn.
const int RESPAWN_SECONDS = 600;	// The amount of seconds before a new patrol will spawn, after they both die

class CustomPatrol : eAIDynamicPatrol {
	override void OnPatrolSpawn(eAIGroup patrol) {
		// Uncomment this line to change the faction of the patrol from Raiders (default)
		// eAIFactionGuards for example is a faction which only kills players who have their weapons out
	    // patrol.SetFaction(new eAIFactionGuards());
		
		// Uncomment this line to slow down or speed up the patrol (1.0 to 3.0)
		patrol.SetSpeedLimit(1.0);
	}
	override void OnUnitSpawn(eAIBase unit) {
		// Uncomment this to give the AI unlimited magazines (new one is added on reload)
		unit.SetUnlimitedMags(true);
		
		// You can also do anything you would do in the StartingEquipSetup() for players here
		
		// These lines will add attachments the same way you would for a player. However, the AI must have the M4A1 class in the Loadout.json file already for it to work.
		// Weapon_Base weapon = Weapon_Base.Cast(unit.GetItemInHands());
		// weapon.GetInventory().CreateAttachment("M4_PlasticHndgrd");
		// weapon.GetInventory().CreateAttachment("M4_OEBttstck");
		// weapon.GetInventory().CreateAttachment("M4_CarryHandleOptic");
	}
};

autoptr array<autoptr eAIDynamicPatrol> patrols = {};

void InitDynamicPatrols() {
	for (int i = 0; i < patrol_list.Count(); i++) {
		string loadout = "SoldierLoadout.json"; // default
		if (i < patrol_loadouts.Count()) loadout = patrol_loadouts[i];
		autoptr CustomPatrol pat = new CustomPatrol(patrol_list[i][0], patrol_list[i], loadout, NUMBER_PER_PATROL, MINR, MAXR, DESPAWNR, RESPAWN_SECONDS);
		patrols.Insert(pat);
		pat.UpdateTriggers();
	}
}

void SpawnSentry(vector pos, string loadout = "SoldierLoadout.json") {
	eAIGame game = MissionServer.Cast(GetGame().GetMission()).GetEAIGame();
	eAIBase ai = game.SpawnAI_Sentry(pos, loadout);
}

modded class CustomMission
{
	void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		m_eaiGame.GetGroupByLeader(player);
		super.StartingEquipSetup(player, clothesChosen);
	}
};