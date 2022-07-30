void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{

    ref array< string > adminMembers = new array< string >;
    ref array< string > modMembers = new array< string >;
    ref array< string > vipMembersSilver = new array< string >;
    ref array< string > vipMembersGold = new array< string >;

    void CustomMission()
    {
        adminMembers = new array< string >;
        modMembers = new array< string >;
        vipMembersSilver = new array< string >;
	vipMembersGold = new array< string >;
        InitPlayerWhitelist();
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{

		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );
		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.25, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	void addMags(PlayerBase player, string mag_type, int count)
	{
		if (count < 1)
			return;

		EntityAI mag;

		for (int i = 0; i < count; i++) {
			mag = player.GetInventory().CreateInInventory(mag_type);
		}

		player.SetQuickBarEntityShortcut(mag, 2, true);
	}

	void InitPlayerWhitelist()
	{
		// Example with Bohemia UID: 	adminMembers.Insert( "JCmXrrt43efttyhfewew7tRLMUCOE6roH2O8SklBB1o=" );
		// Example with Steam64 ID: 	adminMembers.Insert( "76561198040948171" );
				
		// The Shadow Loadout: Can be Steam64 ID or Bohemia UID 76561198036774377
		adminMembers.Insert( "76561198995141505" ); // The Shadow

		// Bunker's Loadout = JacksonRy : Can be Steam64 ID or Bohemia UID
		modMembers.Insert( "" ); // Bunker
				
		// AdminBot = 42MonthsAfter : Can be Steam64 ID or Bohemia UID
		vipMembersSilver.Insert( "76561199112746320" ); // Name		

		// Gold VIP MEMBERS = NomadicSporatic : 76561199376192015 : Can be Steam64 ID or Bohemia UID
		vipMembersGold.Insert( "76561198036774377" ); // Name
	}

// The Shadow Loadout
	EntityAI adminLoadOut(PlayerBase player)
	{
		ref TStringArray hatArray = {"MVS_Shroud_Black"};
		ref TStringArray topArray = {"MVS_CombatShirt_Black"};
		ref TStringArray pantsArray = {"MVS_CombatPants_Black"};	
		ref TStringArray vestArray  = {"MVS_Combat_Vest_Heavy_Black"};	
		ref TStringArray glassesArray = {""};
		ref TStringArray shoesArray = {"High_Knee_Sneakers_Black"};	
		ref TStringArray maskArray = {"MVS_Balaclava_Black"};	
		ref TStringArray glovesArray = {"TacticalGloves_Black"};		
		ref TStringArray foodArray = {"TacticalBaconCan_Opened"};
		ref TStringArray drinkArray = {"MVS_Canteen_Black"};
		ref TStringArray backpackArray = {"MVS_Compact_1_Black"};
		ref TStringArray knifeArray  = {"TWP_SmithWesson_Knife_Black"};
		ref TStringArray meleeArray = {""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(knifeArray.GetRandomElement());
		player.GetInventory().CreateInInventory("TraderPlus_Bitcoin");
		player.GetInventory().CreateInInventory("TWP_Ammo_Arrow");
		player.GetInventory().CreateInInventory("TWP_Ammo_Arrow");
		player.GetInventory().CreateInInventory("TWP_Ammo_Arrow");
		player.GetInventory().CreateInInventory("NVGHeadstrap");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("MVS_Canteen_Black");
		player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
		player.GetInventory().CreateInInventory("HuntingOptic");
		player.GetInventory().CreateInInventory("Msp_WaistPack_Black");
		player.GetInventory().CreateInInventory("MVS_Holster_Black");
		player.GetInventory().CreateInInventory("MVS_Sheath_Black");
		player.GetInventory().CreateInInventory("poncho_mung");
		player.GetInventory().CreateInInventory("HandcuffKeys");
		player.GetInventory().CreateInInventory("Handcuffs");
		player.GetInventory().CreateInInventory("Handcuffs");
		player.GetInventory().CreateInInventory("Handcuffs");
		player.GetInventory().CreateInInventory("Poncho_Black");
		player.GetInventory().CreateInInventory("MassBinocs");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("SalineBagIV");
		player.GetInventory().CreateInInventory("Rope");
		player.GetInventory().CreateInInventory("Rope");
		player.GetInventory().CreateInInventory("Rope");
		player.GetInventory().CreateInInventory("Rope");
		player.GetInventory().CreateInInventory("Rope");
		player.GetInventory().CreateInInventory("Rope");
		player.GetInventory().CreateInInventory("Airsoft_Sniper");
		player.GetInventory().CreateInInventory("HuntingOptic");
		player.GetInventory().CreateInInventory("Ammo_Airsoft308");
		player.GetInventory().CreateInInventory("Ammo_Airsoft308");
		player.GetInventory().CreateInInventory("Ammo_Airsoft308");
		player.GetInventory().CreateInInventory("TWP_Zarya3_StunGrenade");
		player.GetInventory().CreateInInventory("TWP_Zarya3_StunGrenade");
		player.GetInventory().CreateInInventory("TWP_Zarya3_StunGrenade");
		player.GetInventory().CreateInInventory("TWP_Zarya3_StunGrenade");
		player.GetInventory().CreateInInventory("TWP_Zarya3_StunGrenade");
		ItemBase rags = player.GetInventory().CreateInInventory("BandageDressing");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("NVGoggles");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_Airbow");
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());			// Melee
				
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
// Moderator
	EntityAI modLoadOut(PlayerBase player)
	{
		ref TStringArray hatArray = {""};
		ref TStringArray topArray = {"WoolCoat_BlueCheck"};
		ref TStringArray pantsArray = {"CargoPants_Beige"};	
		ref TStringArray vestArray  = {""};	
		ref TStringArray glassesArray = {""};
		ref TStringArray shoesArray = {"HikingBootsLow_Blue"};	
		ref TStringArray maskArray = {""};	
		ref TStringArray glovesArray = {""};		
		ref TStringArray foodArray = {"SpaghettiCan"};
		ref TStringArray drinkArray = {"SodaCan_Cola"};
		ref TStringArray backpackArray = {"simplebackpack_green_mung"};
		ref TStringArray knifeArray  = {"HuntingKnife"};
		ref TStringArray meleeArray = {""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(knifeArray.GetRandomElement());
		player.GetInventory().CreateInInventory("Armband_White");
		player.GetInventory().CreateInInventory("Lockpick");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("CZ75");							// Weapon							//     Add battery to Universal Light
		addMags(player, "Mag_CZ75_15Rnd", 1);										// Magazines
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());			// Melee
				
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

// AdminBot Loadout: Silver = RLF Faction
	EntityAI vipLoadOutSilver(PlayerBase player) 
	{
		ref TStringArray hatArray = {"Head_Admin"};
		ref TStringArray topArray = {"Top_Admin"};
		ref TStringArray pantsArray = {"Pants_Admin"};	
		ref TStringArray vestArray  = {""};	
		ref TStringArray glassesArray = {""};
		ref TStringArray shoesArray = {"Boots_Admin"};	
		ref TStringArray maskArray = {""};	
		ref TStringArray glovesArray = {"Arms_Admin"};		
		ref TStringArray foodArray = {""};
		ref TStringArray drinkArray = {""};
		ref TStringArray backpackArray = {"Backpack_Admin"};
		ref TStringArray knifeArray  = {"TWP_SmithWesson_Knife_Black"};
		ref TStringArray meleeArray = {""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(knifeArray.GetRandomElement());
		ItemBase rags = player.GetInventory().CreateInInventory("");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("");
		light.GetInventory().CreateAttachment("");
		EntityAI gun = player.GetInventory().CreateInInventory("");				// Weapon
		addMags(player, "", 1);								// Magazines
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());	// Melee
		
		player.SetQuickBarEntityShortcut(gun, 0, false);
		player.SetQuickBarEntityShortcut(melee, 0, false);
		return gun;
	}

// VIP Loadout: Gold = Remnants Factions
	EntityAI vipLoadOutGold(PlayerBase player) 
	{
		ref TStringArray hatArray = {"MVS_Cap_Black"};
		ref TStringArray topArray = {"bs_meatloaf","bs_metallica1","bs_nirvana","bs_pantera1","bs_slayer1","bs_tool1","bs_blackflag","bs_joydivision","bs_metalmulisha1","bs_nin","bs_zero","bs_ironmaiden","bs_lateralus","bs_ledzeppelin"};
		ref TStringArray pantsArray = {"Kneepads_Jeans_Base"};	
		ref TStringArray vestArray  = {""};	
		ref TStringArray glassesArray = {"ThickFramesGlasses"};
		ref TStringArray shoesArray = {"High_Knee_Sneakers"};	
		ref TStringArray maskArray = {"MVS_Balaclava_Black"};	
		ref TStringArray glovesArray = {"Fingerless_Gloves_Wool_Grey"};		
		ref TStringArray foodArray = {"TacticalBaconCan"};
		ref TStringArray drinkArray = {"MVS_Canteen_OD"};
		ref TStringArray backpackArray = {"Backpack_Admin"};
		ref TStringArray knifeArray  = {"TWP_SmithWesson_Knife_Black"};
		ref TStringArray meleeArray = {""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(knifeArray.GetRandomElement());
		player.GetInventory().CreateInInventory("MVS_Patch_36");
		player.GetInventory().CreateInInventory("SAK_Mung");
		player.GetInventory().CreateInInventory("Zippo_new");
		player.GetInventory().CreateInInventory("TraderPlus_Wallet");
		player.GetInventory().CreateInInventory("Msp_WaistPack_Black");
		player.GetInventory().CreateInInventory("MVS_Holster_Black");
		player.GetInventory().CreateInInventory("MVS_Sheath_Black");
		player.GetInventory().CreateInInventory("TWP_MK23Light");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("TWP_MP5Silenced");
		player.GetInventory().CreateInInventory("TWP_MP5Silenced_mag_30Rnd");
		player.GetInventory().CreateInInventory("TWP_Optic_Aimdot");
		ItemBase rags = player.GetInventory().CreateInInventory("BandageDressing");
		rags.SetQuantity(2);
		ItemBase light = player.GetInventory().CreateInInventory("maglite_mung");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_MK23Socom");				// Weapon
		addMags(player, "TWP_MK23Socom_mag_12Rnd", 1);								// Magazines
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());	// Melee
		
		player.SetQuickBarEntityShortcut(gun, 0, false);
		player.SetQuickBarEntityShortcut(melee, 0, false);
		return gun;
	}
	
// Non-VIP Loadout (Default Loadout)
	EntityAI randomLoadOut(PlayerBase player) 
	{
		ref TStringArray hatArray = {"BaseballCap_Black","BaseballCap_Camo","BoonieHat_Black","BoonieHat_DPM","Slouch_Hat_Brown","BeanieHat_Blue","BeanieHat_Brown","Msp_Slouchie_Black","Msp_Slouchie_Red","ZmijovkaCap_Red","ZmijovkaCap_Green","RadarCap_Blue","Ushanka_Blue"};
		ref TStringArray topArray = {"Hoodie_Red","Hoodie_Grey","Hoodie_Green","TrackSuitJacket_Black","JumpsuitJacket_Gray","Raincoat_Red","HikingJacket_Blue","WoolCoat_GreyCheck","WoolCoat_Green","QuiltedJacket_Yellow","QuiltedJacket_Grey","Winter_Parka_Green","BomberJacket_Brown","DenimJacket","ParamedicJacket_Crimson","FirefighterJacket_Beige"};
		ref TStringArray pantsArray = {"Jeans_Black","TrackSuitPants_Red","TrackSuitPants_Green","Jeans_BlueDark","Jeans_Brown","Jeans_Green","CanvasPantsMidi_Grey","CargoPants_Beige","CargoPants_Blue"};	
		ref TStringArray vestArray  = {""};	
		ref TStringArray glassesArray = {""};
		ref TStringArray shoesArray = {"AthleticShoes_Blue","JoggingShoes_Blue","Sneakers_Gray","HikingBootsLow_Grey","WorkingBoots_Brown","JungleBoots_Black","MilitaryBoots_Bluerock","CombatBoots_Beige"};	
		ref TStringArray maskArray = {"BandanaMask_BlackPattern","BandanaMask_CamoPattern","BandanaMask_GreenPattern","BandanaMask_RedPattern",};	
		ref TStringArray glovesArray = {""};		
		ref TStringArray foodArray = {"Pate","BrisketSpread","Pajka","Zagorky","ZagorkyChocolate","ZagorkyPeanuts","Lunchmeat","CatFoodCan","DogFoodCan"};
		ref TStringArray drinkArray = {"WaterBottle","SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","SodaCan_Fronta","SodaCan_Kvass"};
		ref TStringArray backpackArray = {"simplebackpack_blue_mung","MassSurvivorBag_Tan","MassSlingBagDesert","Msp_MedicBag_Red","Msp_DuffleBag_Green","MassImprovisedBag_Urban","MassCanvasBag","DryBag_Blue"};
		ref TStringArray knifeArray  = {"SAK_Mung"};
		ref TStringArray meleeArray = {""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(knifeArray.GetRandomElement());
		ItemBase rags = player.GetInventory().CreateInInventory("Bandage");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");		
		EntityAI gun = player.GetInventory().CreateInInventory("Ruger1022");				// Weapon
		addMags(player, "Mag_Ruger1022_15Rnd", 1);								// Magazines
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());	// Melee
		
		player.SetQuickBarEntityShortcut(gun, 0, false);
		player.SetQuickBarEntityShortcut(melee, 0, false);
		return gun;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
					
		if (adminMembers.Find(GetUserID(player)) != -1 || adminMembers.Find(GetUserSteamID(player)) != -1 ) {		
			adminLoadOut(player);
		} else if (modMembers.Find(GetUserID(player)) != -1 || modMembers.Find(GetUserSteamID(player)) != -1 ) { 		
			modLoadOut(player);				
		} else if (vipMembersSilver.Find(GetUserID(player)) != -1 || vipMembersSilver.Find(GetUserSteamID(player)) != -1 ) { 		
			vipLoadOutSilver(player);	
		} else if (vipMembersGold.Find(GetUserID(player)) != -1 || vipMembersGold.Find(GetUserSteamID(player)) != -1 ) { 		
			vipLoadOutGold(player);	
		} else {
			randomLoadOut(player);	
		}
	}
	
	string GetUserID(PlayerBase player)
    {
        if ( player.GetIdentity() )
            return player.GetIdentity().GetPlainId();
        
        return "OFFLINE";
    }

    string GetUserSteamID(PlayerBase player)
    {
        if ( player.GetIdentity() )
            return player.GetIdentity().GetId();
        
        return "OFFLINE";
    }
	
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
