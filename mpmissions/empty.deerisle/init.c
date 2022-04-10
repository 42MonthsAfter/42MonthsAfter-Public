#include "$CurrentDir:mpmissions/empty.deerisle/eAI/AI_init.c"

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
	
	InitDynamicPatrols();
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
				
		// ADMIN MEMBERS: Can be Steam64 ID or Bohemia UID
		adminMembers.Insert( "76561198036774377" ); // Bunker

		// MODERATOR MEMBERS = Free Folk : Can be Steam64 ID or Bohemia UID
		modMembers.Insert( "ReplaceWithUniqueID" ); // Moderators Name
		modMembers.Insert( "ReplaceWithUniqueID" ); // Moderators Name		
				
		// Silver VIP MEMBERS = RLF Faction : Can be Steam64 ID or Bohemia UID
		vipMembersSilver.Insert( "ReplaceWithUniqueID" ); // Name		

		// Gold VIP MEMBERS = Remnants Faction : Can be Steam64 ID or Bohemia UID
		vipMembersGold.Insert( "ReplaceWithUniqueID" ); // Name
	}

// Admin Loadout
	EntityAI adminLoadOut(PlayerBase player)
	{
		ref TStringArray hatArray = {"MVS_Cap_Black"};
		ref TStringArray topArray = {"Shirt_PlaneBlack"};
		ref TStringArray pantsArray = {"Jeans_Blue"};	
		ref TStringArray vestArray  = {""};	
		ref TStringArray glassesArray = {"ThickFramesGlasses"};
		ref TStringArray shoesArray = {"CombatBoots_Beige"};	
		ref TStringArray maskArray = {""};	
		ref TStringArray glovesArray = {"TacticalGloves_Black"};		
		ref TStringArray foodArray = {"TacticalBaconCan"};
		ref TStringArray drinkArray = {"MVS_Canteen_Tan"};
		ref TStringArray knifeArray  = {"HuntingKnife"};
		ref TStringArray meleeArray = {"TWP_SmithWesson_Knife_Black"};
		ref TStringArray backpackArray = {"Msp_WaistPack_Black"};

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
		player.GetInventory().CreateInInventory("TWP_WinchesterRifle");
		player.GetInventory().CreateInInventory("MVS_Holster_Black");
		player.GetInventory().CreateInInventory("TWP_OldRifle_Optic");
		player.GetInventory().CreateInInventory("MVS_Sheath_Black");
		player.GetInventory().CreateInInventory("SAK_Mung");
		player.GetInventory().CreateInInventory("Zippo_mung");
		player.GetInventory().CreateInInventory("MVS_Patch_36");
		ItemBase rags = player.GetInventory().CreateInInventory("BandageDressing");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("maglite_mung");
		light.GetInventory().CreateAttachment("Battery9V");							
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

// VIP Loadout: Silver = RLF Faction
	EntityAI vipLoadOutSilver(PlayerBase player) 
	{
		ref TStringArray hatArray = {"MVS_Cap_Black"};
		ref TStringArray topArray = {"MVS_CombatShirt_Black"};
		ref TStringArray pantsArray = {"MVS_CombatPants_Black"};	
		ref TStringArray vestArray  = {""};	
		ref TStringArray glassesArray = {""};
		ref TStringArray shoesArray = {"MilitaryBoots_Black"};	
		ref TStringArray maskArray = {"GasMask"};	
		ref TStringArray glovesArray = {"WorkingGloves_Black"};		
		ref TStringArray foodArray = {"TacticalBaconCan"};
		ref TStringArray drinkArray = {"MVS_Canteen_OD"};
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
		player.GetInventory().CreateInInventory("MVS_Patch_33");
		player.GetInventory().CreateInInventory("MVS_Patch_29");
		player.GetInventory().CreateInInventory("MVS_Patch_29");
		player.GetInventory().CreateInInventory("MVS_Patch_29");
		player.GetInventory().CreateInInventory("SAK_Mung");
		player.GetInventory().CreateInInventory("Zippo_new");
		player.GetInventory().CreateInInventory("TraderPlus_Wallet");
		ItemBase rags = player.GetInventory().CreateInInventory("BandageDressing");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Headtorch_Black");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_BerettaPX4");				// Weapon
		addMags(player, "TWP_BerettaPX4_mag_17Rnd", 1);								// Magazines
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());	// Melee
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

// VIP Loadout: Gold = Remnants Factions
	EntityAI vipLoadOutGold(PlayerBase player) 
	{
		ref TStringArray hatArray = {"MVS_Cap_Multicam"};
		ref TStringArray topArray = {"MVS_CombatShirt_Multicam"};
		ref TStringArray pantsArray = {"MVS_CombatPants_Multicam"};	
		ref TStringArray vestArray  = {""};	
		ref TStringArray glassesArray = {""};
		ref TStringArray shoesArray = {"MilitaryBoots_Brown"};	
		ref TStringArray maskArray = {"GasMask"};	
		ref TStringArray glovesArray = {"WorkingGloves_Black"};		
		ref TStringArray foodArray = {"TacticalBaconCan"};
		ref TStringArray drinkArray = {"MVS_Canteen_OD"};
		ref TStringArray backpackArray = {"MVS_Compact_1_OD"};
		ref TStringArray knifeArray  = {"TWP_SmithWesson_Knife_Green"};
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
		player.GetInventory().CreateInInventory("MVS_Patch_35");
		player.GetInventory().CreateInInventory("MVS_Patch_35");
		player.GetInventory().CreateInInventory("MVS_Patch_35");
		player.GetInventory().CreateInInventory("MVS_Patch_35");
		player.GetInventory().CreateInInventory("SAK_Mung");
		player.GetInventory().CreateInInventory("Zippo_new");
		player.GetInventory().CreateInInventory("TraderPlus_Wallet");
		ItemBase rags = player.GetInventory().CreateInInventory("BandageDressing");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_Glock17");				// Weapon
		addMags(player, "TWP_Glock17_mag_19Rnd", 1);								// Magazines
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());	// Melee
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
// Non-VIP Loadout (Default Loadout)
	EntityAI randomLoadOut(PlayerBase player) 
	{
		ref TStringArray hatArray = {"BaseballCap_Black","BaseballCap_Camo","BoonieHat_Black","BoonieHat_DPM","Slouch_Hat_Brown","BeanieHat_Blue","BeanieHat_Brown","Msp_Slouchie_Black","Msp_Slouchie_Red","ZmijovkaCap_Red","ZmijovkaCap_Green","RadarCap_Blue","Ushanka_Blue","strawhat_mung","jesterhat_mung"};
		ref TStringArray topArray = {"Hoodie_Red","Hoodie_Grey","Hoodie_Green","TrackSuitJacket_Black","JumpsuitJacket_Gray","Raincoat_Red","HikingJacket_Blue","WoolCoat_GreyCheck","WoolCoat_Green","QuiltedJacket_Yellow","QuiltedJacket_Grey","Winter_Parka_Green","BomberJacket_Brown","DenimJacket","ParamedicJacket_Crimson","FirefighterJacket_Beige"};
		ref TStringArray pantsArray = {"Adidas_Leggings","TrackSuitPants_Red","TrackSuitPants_Green","ShortJeans_Red","Kneepads_Jeans_Base","Skinny_Jeans_Blue","Jeans_Brown","Jeans_Green","CanvasPantsMidi_Grey","Breeches_Blue","Breeches_Black"};	
		ref TStringArray vestArray  = {"HuntingVest","ReflexVest","bikervest_mung","UKAssVest_Khaki"};	
		ref TStringArray glassesArray = {""};
		ref TStringArray shoesArray = {"AthleticShoes_Blue","JoggingShoes_Blue","Sneakers_Gray","High_Knee_Sneakers_Black","HikingBootsLow_Grey","WorkingBoots_Brown","JungleBoots_Black","MilitaryBoots_Bluerock","CombatBoots_Beige"};	
		ref TStringArray maskArray = {"SurgicalMask","Balaclava3Holes_Beige","BalaclavaMask_Pink","BalaclavaMask_Blackskull","Balaclava3Holes_Green","BalaclavaMask_Blue"};	
		ref TStringArray glovesArray = {"LeatherGloves_Beige","LeatherGloves_Black","SurgicalGloves_White","Fingerless_Gloves","Fingerless_Gloves_Wool","WorkingGloves_Yellow","WorkingGloves_Brown"};		
		ref TStringArray foodArray = {"Pate","BrisketSpread","Pajka","Zagorky","ZagorkyChocolate","ZagorkyPeanuts","Lunchmeat","CatFoodCan","DogFoodCan"};
		ref TStringArray drinkArray = {"WaterBottle","SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","SodaCan_Fronta","SodaCan_Kvass","Canteen"};
		ref TStringArray backpackArray = {"simplebackpack_blue_mung","simplebackpack_redpink_mung","Canvas_Backpack_Base","Canvas_Backpack_White","TaloonBag_Orange","TaloonBag_Blue","MountainBag_Orange","MountainBag_Blue","bag_6B38_camo_mung","bag_6B38_black_mung"};
		ref TStringArray knifeArray  = {"HuntingKnife","bowieknife_mung"};
		ref TStringArray meleeArray = {"Pipe","cricket_bat_mung","BaseballBat","Msp_BeanBasher","CrudeMachete","NailedBaseballBat","Broom"};

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
		player.GetInventory().CreateInInventory("Matchbox");
		player.GetInventory().CreateInInventory("SAK_Mung");
		player.GetInventory().CreateInInventory("TraderPlus_Wallet");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");		
		EntityAI gun = player.GetInventory().CreateInInventory("MKII");				// Weapon
		addMags(player, "Mag_MKII_10Rnd", 2);								// Magazines
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());	// Melee
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 0, true);
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