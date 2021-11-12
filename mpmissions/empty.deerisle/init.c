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
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	//MODDED LOADOUTS - BEGIN--------------------------------------
	// ------------------------------------------------------------
	// Override StartingEquipSetup
	// ------------------------------------------------------------
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
	
	EntityAI randomClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin","PowderedMilk","Rice","BakedBeansCan_Opened","PeachesCan_Opened","SpaghettiCan_Opened","SardinesCan_Opened","TunaCan_Opened","Apple","Tomato","GreenBellPepper","Zucchini","SlicedPumpkin","Potato","SambucusBerry","CaninaBerry","Plum","Pear","AgaricusMushroom","AmanitaMushroom","MacrolepiotaMushroom","LactariusMushroom","PsilocybeMushroom","AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","SodaCan_Kvass","WaterBottle"};
		ref TStringArray hatArray = {"BaseballCap_Blue","MassCowboyHat_White","MVS_BoonieHat","Massurbancamohat","BaseballCap_Beige","MVS_FlatCap","MVS_Cap_OD","MVS_Cap_ERDL","BaseballCap_Black","MVS_Cap_Multicam_Black","BaseballCap_Blue","BaseballCap_CMMG_Pink","BaseballCap_Olive","FlatCap_BrownCheck","RadarCap_Black","RadarCap_Brown","BaseballCap_Pink","ZmijovkaCap_Blue","ZmijovkaCap_Red","BeanieHat_Beige","BaseballCap_Red","BeanieHat_Brown","BeanieHat_Green","","BaseballCap_Camo","","","","BaseballCap_CMMG_Black","","","","BaseballCap_CMMG_Pink","","","","BeanieHat_Beige","","","","BeanieHat_Black","","","","BeanieHat_Blue","","","","BeanieHat_Brown","","","","BeanieHat_Green","","","","BeanieHat_Grey","","","","BeanieHat_Pink","","","","BeanieHat_Red","","","","Ushanka_Black","","","","Ushanka_Blue","","","","Ushanka_Green","","","","RadarCap_Black","","","","RadarCap_Blue","","","","RadarCap_Brown","","","","RadarCap_Green","","","","RadarCap_Red","","","","FlatCap_Black","","","","FlatCap_Blue","","","","FlatCap_Red","","","","FlatCap_Brown","","","","FlatCap_Grey","","","","FlatCap_BrownCheck","","","","FlatCap_GreyCheck","","","","FlatCap_BlackCheck","","","","ZmijovkaCap_Black","","","","ZmijovkaCap_Blue","","","","ZmijovkaCap_Brown","","","","ZmijovkaCap_Green","","","","ZmijovkaCap_Red","","","","CowboyHat_Brown","","","","CowboyHat_black","","","","CowboyHat_darkBrown","","","","CowboyHat_green","","","","SkateHelmet_Black","","","","SkateHelmet_Blue","","","","SkateHelmet_Gray","","","","SkateHelmet_Green","","","","SkateHelmet_Red","","","","WeldingMask","","","","LeatherHat_Natural","","","","LeatherHat_Beige","","","","LeatherHat_Brown","","","","LeatherHat_Black","","","","GreatHelm","","",""};
		ref TStringArray topArray = {"Sweater_Gray","Sweater_Blue","Sweater_Green","Sweater_Red","Shirt_BlueCheck","Shirt_BlueCheckBright","Shirt_GreenCheck","Shirt_RedCheck","Shirt_WhiteCheck","Shirt_PlaneBlack","TacticalShirt_Grey","TacticalShirt_Black","M65Jacket_Black","TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_OrangeWhiteStripes","TShirt_Red","TShirt_RedBlackStripes","TShirt_White","TShirt_Grey","Hoodie_Blue","Hoodie_Black","Hoodie_Brown","Hoodie_Green","Hoodie_Grey","Hoodie_Red","HikingJacket_Black","HikingJacket_Blue","HikingJacket_Red","HikingJacket_Green","Raincoat_Orange","Raincoat_Green","Raincoat_Yellow","Raincoat_Pink","Raincoat_Red","Raincoat_Blue","Raincoat_Black","TrackSuitJacket_Black","TrackSuitJacket_Blue","TrackSuitJacket_Green","TrackSuitJacket_LightBlue","TrackSuitJacket_Red","QuiltedJacket_Black","QuiltedJacket_Green","QuiltedJacket_Blue","QuiltedJacket_Red","QuiltedJacket_Grey","QuiltedJacket_Orange","QuiltedJacket_Yellow","QuiltedJacket_Violet","BomberJacket_Black","BomberJacket_Brown","BomberJacket_Blue","BomberJacket_Grey","BomberJacket_Maroon","BomberJacket_Olive","BomberJacket_SkyBlue","GorkaEJacket_PautRev","HuntingJacket_Spring","USMCJacket_Desert","USMCJacket_Woodland","QuiltedJacket_Orange","QuiltedJacket_Blue","QuiltedJacket_Black","M65Jacket_Khaki","LeatherJacket_Black","LeatherJacket_Beige","HuntingJacket_Spring","HuntingJacket_Brown"};
		ref TStringArray pantsArray = {"Jeans_Black","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey","Jeans_BlueDark","CargoPants_Beige","CargoPants_Black","CargoPants_Blue","CargoPants_Green","CargoPants_Grey","CanvasPants_Beige","CanvasPants_Blue","CanvasPants_Grey","CanvasPants_Red","CanvasPants_Violet","CanvasPantsMidi_Beige","CanvasPantsMidi_Blue","CanvasPantsMidi_Grey","CanvasPantsMidi_Red","CanvasPantsMidi_Violet","TrackSuitPants_Black","TrackSuitPants_Blue","TrackSuitPants_Green","TrackSuitPants_Red","TrackSuitPants_LightBlue","SlacksPants_Beige","SlacksPants_Black","SlacksPants_Blue","SlacksPants_Brown","SlacksPants_DarkGrey","SlacksPants_Khaki","SlacksPants_LightGrey","SlacksPants_White","Breeches_Pink","Breeches_Red","Breeches_White","Breeches_Green","Breeches_Browncheck","Breeches_Blue","Breeches_Blackcheck","Breeches_Black","Breeches_Beige","Breeches_Beetcheck","MassWinterHunterPants","HunterPants_Autumn","HunterPants_Brown","HunterPants_Spring","HunterPants_Summer","HunterPants_Winter"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","","SportGlasses_Black","","","","SportGlasses_Green","","","","SportGlasses_Orange","","","","AviatorGlasses","","","","ThickFramesGlasses","","","","ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"Sneakers_Black","Sneakers_Gray","Sneakers_Green","Sneakers_Red","Sneakers_White","JungleBoots_Beige","JungleBoots_Green","MilitaryBoots_Black","TTSKOBoots","WorkingBoots_Beige","WorkingBoots_Green","HikingBoots_Black","HikingBootsLow_Blue","HikingBootsLow_Grey","JoggingShoes_Blue","JoggingShoes_Violet","MilitaryBoots_Beige","JoggingShoes_White","WorkingBoots_Yellow","WorkingBoots_Grey"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","","","BandanaMask_BlackPattern","","","","","","BandanaMask_PolkaPattern","","","","","","BandanaMask_GreenPattern","","","","","","BandanaMask_CamoPattern","","","","","","NioshFaceMask","","","","","","HockeyMask","","","","","","BalaclavaMask_Black","","","","","","BalaclavaMask_Blackskull","","","","","","BalaclavaMask_Beige","","","","","","BalaclavaMask_Blue","","","","","","BalaclavaMask_Green","","","","","","BalaclavaMask_Pink","","","","","","BalaclavaMask_White","","","","","","GP5GasMask","","","","",""};
		ref TStringArray lightArray = {"Chemlight_White","Chemlight_Blue","Chemlight_Green","Chemlight_White","Chemlight_Red","Chemlight_Yellow","Roadflare","Chemlight_White"};
		ref TStringArray meleeArray = {"HuntingKnife","KukriKnife","TWP_SmithWesson_Knife_Green","sushiknife_mung","SteakKnife","KitchenKnife","CombatKnife","bowieknife_mung"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		player.GetInventory().CreateInInventory("Matchbox");
		player.GetInventory().CreateInInventory("TaloonBag_Blue");
		player.GetInventory().CreateInInventory("SAK_Mung");
		player.GetInventory().CreateInInventory("PersonalRadio");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("TunaCan");
		player.GetInventory().CreateInInventory("PurificationTablets");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());
		
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return melee;
	}
	
	EntityAI ninjaClass(PlayerBase player)
	{
		player.GetInventory().CreateInInventory("MVS_CombatPants_Black");
		player.GetInventory().CreateInInventory("MVS_CombatShirt_Black");
		player.GetInventory().CreateInInventory("Balaclava3Holes_Black");
		player.GetInventory().CreateInInventory("JungleBoots_Black");
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("WaterBottle");
		player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
		player.GetInventory().CreateInInventory("WorkingGloves_Black");
		player.GetInventory().CreateInInventory("VS_SlingPack_Black");
		player.GetInventory().CreateInInventory("Pen_Black");
		player.GetInventory().CreateInInventory("TacSatRadio");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("NVGHeadstrap");
		ItemBase light = player.GetInventory().CreateInInventory("NVGoggles");
		light.GetInventory().CreateAttachment("Battery9V");
		ItemBase melee = player.GetInventory().CreateInInventory("katana_Mung");
		
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return melee;
	}
	
	EntityAI policeClass(PlayerBase player)
	{
		ref TStringArray hatArray = {"DirtBikeHelmet_Police","PoliceCap","PoliceCap","PoliceCap"};
		ref TStringArray topArray = {"PoliceJacket","PoliceJacketOrel"};
		ref TStringArray pantsArray = {"PolicePants","PolicePantsOrel"};
		ref TStringArray vestArray  = {"PoliceVest","PoliceVest"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","AviatorGlasses","SportGlasses_Black","SportGlasses_Green","SportGlasses_Orange","AviatorGlasses","AviatorGlasses","AviatorGlasses",""};
		ref TStringArray shoesArray = {"DressShoes_Black","WorkingBoots_Grey"};
		ref TStringArray glovesArray = {"OMNOGloves_Brown","OMNOGloves_Gray","OMNOGloves_Brown","OMNOGloves_Gray","SurgicalGloves_Blue"};
		ref TStringArray extraArray = {"Megaphone","DisinfectantAlcohol","Lockpick"};
		ref TStringArray extra2Array = {"Roadflare","Flashlight","Chemlight_Blue"};
				
		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(extraArray.GetRandomElement());
		player.GetInventory().CreateInInventory(extra2Array.GetRandomElement());
		player.GetInventory().CreateInInventory("CombatKnife");
		player.GetInventory().CreateInInventory("Handcuffs");
		player.GetInventory().CreateInInventory("HandcuffKeys");
		player.GetInventory().CreateInInventory("PersonalRadio");
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("SodaCan_Pipsi");
		player.GetInventory().CreateInInventory("Pen_Black");
		player.GetInventory().CreateInInventory("TacSatRadio");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("Potato");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_MP443");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("TWP_PistolLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "TWP_MP443_mag_18Rnd", 2);
		ItemBase melee = player.GetInventory().CreateInInventory("StunBaton");
		melee.GetInventory().CreateAttachment("Battery9V");
		
		player.SetQuickBarEntityShortcut(gun, 1, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	
	EntityAI soldierClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"TacticalBaconCan_Opened", "TacticalBaconCan_Opened"};
		ref TStringArray drinkArray = {"Canteen", "MVS_Canteen_OD","MVS_Canteen_Snow","MVS_Canteen_ERDL","MVS_Canteen_Multicam","MVS_Canteen_Tan","MVS_Canteen_Multicam_Tropic"};
		ref TStringArray hatArray = {"BallisticHelmet_Green", "BallisticHelmet_Black", "BallisticHelmet_UN", "ZSh3PilotHelmet", "ZSh3PilotHelmet_Green", "ZSh3PilotHelmet_Black", "MilitaryBeret_Red", "MilitaryBeret_UN", "MilitaryBeret_NZ", "MilitaryBeret_ChDKZ", "MilitaryBeret_CDF", "OfficerHat", "PilotkaCap", "TankerHelmet", "GorkaHelmet", "GorkaHelmet_Green", "GorkaHelmet_Black", "GorkaHelmetComplete", "GorkaHelmetComplete_Green", "GorkaHelmetComplete_Black", "Ssh68Helmet"};
		ref TStringArray topArray = {"TacticalShirt_Olive", "TacticalShirt_Tan", "M65Jacket_Khaki", "M65Jacket_Tan", "M65Jacket_Olive", "TTsKOJacket_Camo", "GorkaEJacket_Summer", "GorkaEJacket_Flat", "GorkaEJacket_Autumn", "GorkaEJacket_PautRev", "USMCJacket_Desert", "USMCJacket_Woodland"};
		ref TStringArray pantsArray = {"TTSKOPants", "GorkaPants_Summer", "GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "USMCPants_Desert", "USMCPants_Woodland", "BDUPants"};
		ref TStringArray vestArray  = {"SmershVest","", "BallisticVest","", "UKAssVest_Black","", "UKAssVest_Camo","", "UKAssVest_Khaki","", "UKAssVest_Olive","", "HighCapacityVest_Black","", "HighCapacityVest_Olive",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","",""};
		ref TStringArray shoesArray = {"JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"TacticalGloves_Beige","", "TacticalGloves_Black","", "TacticalGloves_Green","", "OMNOGloves_Brown","", "OMNOGloves_Gray",""};
		ref TStringArray maskArray = {"BandanaMask_CamoPattern","MVS_Facemask_OD","MVS_Facemask_Tan"," MVS_Facemask_Snow","MVS_Balaclava_Wraith", "BalaclavaMask_Green","MVS_Balaclava_OD","MVS_Balaclava_Tan","MVS_Balaclava_Wraith_Comtacs","MVS_Balaclava_Black", "GP5GasMask"};
		ref TStringArray backpackArray = {"AssaultBag_Ttsko","CoyoteBag_Brown", "AssaultBag_Black","TortillaBag", "AssaultBag_Green","CoyoteBag_Green", "CoyoteBag_Brown","AliceBag_Green", "CoyoteBag_Green","AliceBag_Camo"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("Zippo_new");
		player.GetInventory().CreateInInventory("OrienteeringCompass");
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("VitaminBottle");
		player.GetInventory().CreateInInventory("Hatchet");
		player.GetInventory().CreateInInventory("WeaponCleaningKit");
		player.GetInventory().CreateInInventory("Pen_Black");
		player.GetInventory().CreateInInventory("TacSatRadio");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("AmmoBox");
		player.GetInventory().CreateInInventory("M67Grenade");
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_Famas");
		addMags(player, "TWP_Famas_mag_35Rnd", 2);
		ItemBase melee = player.GetInventory().CreateInInventory("CombatKnife");
		
		player.SetQuickBarEntityShortcut(gun, 1, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	EntityAI hunterClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"PigSteakMeat", "DeerSteakMeat", "Rice", "BakedBeansCan_Opened", "SheepSteakMeat", "WolfSteakMeat", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "CowSteakMeat", "Potato", "SambucusBerry", "CaninaBerry", "Plum", "Pear", "BoarSteakMeat", "GoatSteakMeat", "AgaricusMushroom", "AmanitaMushroom", "MacrolepiotaMushroom", "LactariusMushroom", "PsilocybeMushroom", "AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "Canteen", "WaterBottle"};
		ref TStringArray hatArray = {"Ushanka_Black","", "Ushanka_Blue","", "Ushanka_Green","", "RadarCap_Black","", "RadarCap_Blue","", "RadarCap_Brown","", "RadarCap_Green","", "RadarCap_Red","", "ZmijovkaCap_Black","", "ZmijovkaCap_Blue","", "ZmijovkaCap_Brown","", "ZmijovkaCap_Green","", "ZmijovkaCap_Red","", "BoonieHat_Black","", "BoonieHat_Blue","", "BoonieHat_DPM","", "BoonieHat_Dubok","", "BoonieHat_Flecktran","", "BoonieHat_NavyBlue","", "BoonieHat_Olive","", "BoonieHat_Orange","", "BoonieHat_Red","", "BoonieHat_Tan","", "LeatherHat_Natural","", "LeatherHat_Beige","", "LeatherHat_Brown","", "LeatherHat_Black",""};
		ref TStringArray topArray = {"HuntingJacket_Autumn", "HuntingJacket_Brown", "HuntingJacket_Spring", "HuntingJacket_Summer", "HuntingJacket_Winter", "HuntingJacket_Autumn", "HuntingJacket_Brown", "HuntingJacket_Spring", "HuntingJacket_Summer", "HuntingJacket_Winter"};
		ref TStringArray pantsArray = {"HunterPants_Autumn", "HunterPants_Brown", "HunterPants_Spring", "HunterPants_Summer", "HunterPants_Winter"};
		ref TStringArray vestArray  = {"LeatherStorageVest_Natural","","", "LeatherStorageVest_Beige","","", "LeatherStorageVest_Brown","","", "LeatherStorageVest_Black","",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","", "SportGlasses_Black","","","", "SportGlasses_Green","","","", "SportGlasses_Orange","","","", "AviatorGlasses","","","", "ThickFramesGlasses","","","", "ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"HikingBoots_Brown", "HikingBoots_Black", "HikingBootsLow_Black", "HikingBootsLow_Beige", "HikingBootsLow_Grey", "Wellies_Black", "Wellies_Brown", "Wellies_Green", "Wellies_Grey", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Green", "WorkingBoots_Beige"};
		ref TStringArray glovesArray = {"WorkingGloves_Black","","", "WorkingGloves_Beige","","", "WorkingGloves_Brown","",""};
		ref TStringArray backpackArray = {"HuntingBag","MVS_Rucksack_ERDL","","", "HuntingBag","","","", "HuntingBag","","","", "HuntingBag","","","", "HuntingBag","","","", "LeatherSack_Natural","","","", "LeatherSack_Black","","","", "LeatherSack_Beige","","","", "LeatherSack_Brown","","",""};
		ref TStringArray lightArray = {"Chemlight_White","Chemlight_Blue","Chemlight_Green","Chemlight_White","Chemlight_Red","Chemlight_Yellow","Roadflare","Chemlight_White"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		player.GetInventory().CreateInInventory("Binoculars");
		player.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
		player.GetInventory().CreateInInventory("Matchbox");
		player.GetInventory().CreateInInventory("Rangefinder");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("FishingRod");
		player.GetInventory().CreateInInventory("PurificationTablets");
		player.GetInventory().CreateInInventory("Pen_Black");
		player.GetInventory().CreateInInventory("TacSatRadio");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("SAK_Mung");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_Remington700");
		gun.GetInventory().CreateAttachment("TWP_LongRangeOptic_Black");
		addMags(player, "Ammo_308Win", 2);
		ItemBase melee = player.GetInventory().CreateInInventory("HuntingKnife");
		
		player.SetQuickBarEntityShortcut(gun, 1, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	EntityAI bikerClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin", "PowderedMilk", "Rice", "BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "SlicedPumpkin", "Potato", "Plum", "Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"MotoHelmet_Black", "MotoHelmet_Grey", "MotoHelmet_Green", "MotoHelmet_Lime", "MotoHelmet_Blue", "MotoHelmet_Red", "MotoHelmet_White", "DarkMotoHelmet_Black", "DarkMotoHelmet_Grey", "DarkMotoHelmet_Green", "DarkMotoHelmet_Lime", "DarkMotoHelmet_Blue", "DarkMotoHelmet_Red", "DarkMotoHelmet_White", "DirtBikeHelmet_Green", "DirtBikeHelmet_Chernarus", "DirtBikeHelmet_Khaki", "DirtBikeHelmet_Red", "DirtBikeHelmet_Black", "DirtBikeHelmet_Blue"};
		ref TStringArray topArray = {"RidersJacket_Black","BomberJacket_Maroon","BomberJacket_Blue","BomberJacket_Grey","BomberJacket_Black","RidersJacket_Black"};
		ref TStringArray pantsArray = {"Jeans_Black", "Jeans_Blue", "Jeans_Brown", "Jeans_Green", "Jeans_Grey", "Jeans_BlueDark", "CargoPants_Beige", "CargoPants_Black", "CargoPants_Blue", "CargoPants_Green", "CargoPants_Grey", "TTSKOPants", "HunterPants_Autumn", "HunterPants_Brown", "HunterPants_Spring", "HunterPants_Summer", "HunterPants_Winter", "GorkaPants_Summer", "GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "USMCPants_Desert", "USMCPants_Woodland", "BDUPants"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","", "SportGlasses_Black","", "SportGlasses_Green","", "SportGlasses_Orange","", "AviatorGlasses",""};
		ref TStringArray shoesArray = {"HikingBoots_Brown", "HikingBoots_Black", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"WorkingGloves_Black", "WorkingGloves_Brown", "TacticalGloves_Black", "TacticalGloves_Green", "OMNOGloves_Brown", "OMNOGloves_Gray"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","", "BandanaMask_BlackPattern","", "BandanaMask_PolkaPattern","", "BandanaMask_GreenPattern","", "BandanaMask_CamoPattern","", "HockeyMask","", "BalaclavaMask_Black","", "BalaclavaMask_Blackskull","", "BalaclavaMask_Green",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("AliceBag_Black");
		player.GetInventory().CreateInInventory("AmmoBox_00buck_10rnd");
		player.GetInventory().CreateInInventory("Ammo_12gaPellets");
		player.GetInventory().CreateInInventory("bowieknife_mung");
		player.GetInventory().CreateInInventory("Vodka");
		player.GetInventory().CreateInInventory("SLockpick");
		player.GetInventory().CreateInInventory("Pen_Black");
		player.GetInventory().CreateInInventory("TacSatRadio");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("Zippo_new");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("maglite_mung");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_KSG");
		ItemBase melee = player.GetInventory().CreateInInventory("BrassKnuckles_Shiny");
		
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return melee;
	}
	
	EntityAI nbcClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin","PowderedMilk","Rice","BakedBeansCan_Opened","PeachesCan_Opened","SpaghettiCan_Opened","SardinesCan_Opened","TunaCan_Opened","Apple","Tomato","GreenBellPepper","Zucchini","SlicedPumpkin","Potato","Plum","Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","WaterBottle"};
		ref TStringArray hatArray = {"NBCHoodGray","ToxicZoneSuits_Hood_yellow","ToxicZoneSuits_Hood_green","ToxicZoneSuits_Hood_black","NBCHoodGray"};
		ref TStringArray topArray = {"NBCJacketGray","ToxicZoneSuits_Jacket_yellow","ToxicZoneSuits_Jacket_green","ToxicZoneSuits_Jacket_black","NBCJacketGray"};
		ref TStringArray pantsArray = {"NBCPantsGray","ToxicZoneSuits_Pants_yellow","ToxicZoneSuits_Pants_green","ToxicZoneSuits_Pants_black","NBCPantsGray"};
		ref TStringArray shoesArray = {"NBCBootsGray","ToxicZoneSuits_Boots_yellow","ToxicZoneSuits_Boots_green","ToxicZoneSuits_Boots_black","NBCBootsGray"};
		ref TStringArray glovesArray = {"NBCGlovesGray","ToxicZoneSuits_Gloves_black","ToxicZoneSuits_Gloves_green","ToxicZoneSuits_Gloves_yellow","NBCGlovesGray"};
		ref TStringArray maskArray = {"GP5GasMask","MVS_S10Respirator_Tan","MVS_S10Respirator_Black","MVS_S10Respirator_Snow","MVS_M50Respirator_OD","MVS_M50Respirator_Black","MVS_M50Respirator_Snow,","MVS_PMK2Respirator_Black","MVS_PMK2Respirator_Tan","MVS_PMK2Respirator_OD","MVS_PMK2Respirator_Snow","ToxicZoneGP5GasMask_black","ToxicZoneGP5GasMask_green","GP5GasMask","GP5GasMask"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("MVS_Assault_Pack_Black");
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("SAK_Mung");
		player.GetInventory().CreateInInventory("Zippo_new");
		player.GetInventory().CreateInInventory("ToxicCure");
		player.GetInventory().CreateInInventory("Pen_Black");
		player.GetInventory().CreateInInventory("TacSatRadio");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("GP5GasMask_Filter");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_AR15");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("TWP_Weaponlight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "TWP_AR15_mag_30Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_545x39");
		player.GetInventory().CreateInInventory("Ammo_545x39Tracer");
		ItemBase melee = player.GetInventory().CreateInInventory("CombatKnife");
		
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return melee;
	}
	
	EntityAI mercenaryClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin","PowderedMilk","Rice","BakedBeansCan_Opened","PeachesCan_Opened","SpaghettiCan_Opened","SardinesCan_Opened","TunaCan_Opened","Apple","Tomato","GreenBellPepper","Zucchini","SlicedPumpkin","Potato","Plum","Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","SodaCan_Kvass","WaterBottle"};
		ref TStringArray hatArray = {"MVS_WarriorHelmet_Tan", "MVS_WarriorHelmet_OD", "MVS_WarriorHelmet_Black", "MVS_WarriorHelmet_Snow", "MVS_WarriorHelmet_ERDL", "MVS_WarriorHelmet_Multicam", "MVS_WarriorHelmet_Multicam_Tropic", "MVS_WarriorHelmet_Multicam_Black", "MVS_OpsCore_Tan", "MVS_OpsCore_OD", "MVS_OpsCore_Black", "MVS_OpsCore_Snow", "MVS_OpsCore_ERDL", "MVS_OpsCore_Multicam", "MVS_OpsCore_Multicam_Tropic", "MVS_OpsCore_Multicam_Black"};
		ref TStringArray topArray = {"MVS_CombatShirt_OD", "MVS_CombatShirt_Tan", "MVS_CombatShirt_Black", "MVS_CombatShirt_Snow", "MVS_CombatShirt_ERDL", "MVS_CombatShirt_Multicam_Black", "MVS_CombatShirt_Multicam_Tropic", "MVS_CombatShirt_Multicam"};
		ref TStringArray pantsArray = {"MVS_GorkaPants", "MVS_GorkaPants_Multicam", "MVS_GorkaPants_Multicam_Tropic", "MVS_CombatPants_Tan", "MVS_CombatPants_Black", "MVS_CombatPants_Snow", "MVS_CombatPants_ERDL", "MVS_CombatPants_Multicam"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","",""};
		ref TStringArray shoesArray = {"JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"TacticalGloves_Beige","", "TacticalGloves_Black","", "TacticalGloves_Green","", "OMNOGloves_Brown","", "OMNOGloves_Gray",""};
		ref TStringArray backpackArray = {"MVS_Assault_Pack_OD","MVS_Assault_Pack_Tan", "MVS_Assault_Pack_Black","MVS_Assault_Pack_Snow", "MVS_Assault_Pack_ERDL","MVS_Assault_Pack_Multicam", "MVS_Assault_Pack_Multicam_Tropic","MVS_Assault_Pack_Multicam_Black", "MVS_Compact_1_OD","MVS_Compact_2_Tan","MVS_SlingPack_Tan","MVS_Pack_ERDL","MVS_Pack_Multicam_Black","MVS_Assault_Pack_Black","MVS_Assault_Pack_Snow","MVS_Rucksack_Black","MVS_SlingPack_ERDL","MVS_Compact_1_Black","MVS_Rucksack_Multicam"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("DuctTape");
		player.GetInventory().CreateInInventory("TWP_G3A3_Suppressor");
		player.GetInventory().CreateInInventory("TWP_TrijiconACOG");
		player.GetInventory().CreateInInventory("Zippo_new");
		player.GetInventory().CreateInInventory("SAK_Mung");
		player.GetInventory().CreateInInventory("cigarette_mung");
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("Pen_Black");
		player.GetInventory().CreateInInventory("TacSatRadio");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("TetracyclineAntibiotics");
		player.GetInventory().CreateInInventory("VitaminBottle");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("NVGoggles");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_G3A3");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("TWP_Weaponlight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "TWP_G3A3_mag_20Rnd", 2);
		ItemBase melee = player.GetInventory().CreateInInventory("TWP_SmithWesson_Knife_Black");
		
		player.SetQuickBarEntityShortcut(gun, 1, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI sniperClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"TacticalBaconCan_Opened", "TacticalBaconCan_Opened"};
		ref TStringArray drinkArray = {"Canteen", "Canteen"};
		ref TStringArray hatArray = {"GhillieHood_Tan", "GhillieHood_Woodland", "GhillieHood_Mossy", ""};
		ref TStringArray topArray = {"TacticalShirt_Olive", "TacticalShirt_Tan", "M65Jacket_Khaki", "M65Jacket_Tan", "M65Jacket_Olive", "TTsKOJacket_Camo", "GorkaEJacket_Summer", "GorkaEJacket_Flat", "GorkaEJacket_Autumn", "GorkaEJacket_PautRev", "USMCJacket_Desert", "USMCJacket_Woodland"};
		ref TStringArray pantsArray = {"TTSKOPants", "GorkaPants_Summer", "GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "USMCPants_Desert", "USMCPants_Woodland", "BDUPants"};
		ref TStringArray vestArray  = {"SmershVest","", "BallisticVest","", "UKAssVest_Black","", "UKAssVest_Camo","", "UKAssVest_Khaki","", "UKAssVest_Olive","", "HighCapacityVest_Black","", "HighCapacityVest_Olive",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","",""};
		ref TStringArray shoesArray = {"JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"TacticalGloves_Beige","", "TacticalGloves_Black","", "TacticalGloves_Green","", "OMNOGloves_Brown","", "OMNOGloves_Gray",""};
		ref TStringArray maskArray = {"BandanaMask_CamoPattern","","","","", "BalaclavaMask_Green","","","","", "GP5GasMask","","","",""};
		ref TStringArray backpackArray = {"GhillieTop_Woodland","", "GhillieSuit_Woodland","", "GhillieBushrag_Tan","", "GhillieTop_Tan","", "GhillieSuit_Tan","", "GhillieTop_Mossy","", "GhillieSuit_Mossy",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("Pen_Black");
		player.GetInventory().CreateInInventory("TacSatRadio");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("NVGHeadstrap");
		ItemBase light = player.GetInventory().CreateInInventory("NVGoggles");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("TWP_AWMBlack");
		ItemBase optics = gun.GetInventory().CreateAttachment("TWP_LongRangeOptic_Black");
		addMags(player, "TWP_AWM_mag_5Rnd", 2);
		player.GetInventory().CreateInInventory("TWP_AWM_mag_5Rnd");
		ItemBase melee = player.GetInventory().CreateInInventory("CombatKnife");
		
		player.SetQuickBarEntityShortcut(gun, 1, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI cowhandClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"CowSteakMeat","GoatSteakMeat","DeerSteakMeat","Carp","Potato"};
		ref TStringArray drinkArray = {"SodaCan_Kvass","SodaCan_Kvass"};
		ref TStringArray hatArray = {"CowboyHat_Brown","CowboyHat_black","CowboyHat_darkBrown","CowboyHat_green"};
		ref TStringArray topArray = {"Shirt_BlueCheck","Shirt_BlueCheckBright","Shirt_GreenCheck","Shirt_RedCheck","Shirt_WhiteCheck","Shirt_PlaneBlack"};
		ref TStringArray pantsArray = {"Jeans_Blue","Jeans_BlueDark"};
		ref TStringArray vestArray  = {"LeatherStorageVest_Natural","", "LeatherStorageVest_Beige","", "LeatherStorageVest_Brown","", "LeatherStorageVest_Black","","ChestHolster","ChestHolster","ChestHolster","ChestHolster"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","","SportGlasses_Black","","","","SportGlasses_Green","","","","SportGlasses_Orange","","","","AviatorGlasses","","","",""};
		ref TStringArray shoesArray = {"Wellies_Black","Wellies_Brown","Wellies_Green","Wellies_Grey","WorkingBoots_Grey","WorkingBoots_Brown","WorkingBoots_Green","WorkingBoots_Beige"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","","","BandanaMask_BlackPattern","","","","","","BandanaMask_PolkaPattern","","","","","","BandanaMask_GreenPattern","","","","","",""};
		ref TStringArray lightArray = {"Roadflare","Roadflare"};
		ref TStringArray meleeArray = {"BaseballBat","BaseballBat"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		player.GetInventory().CreateInInventory("HuntingKnife");
		player.GetInventory().CreateInInventory("HuntingBag");
		player.GetInventory().CreateInInventory("HuntingKnife");
		player.GetInventory().CreateInInventory("Rope");
		player.GetInventory().CreateInInventory("Pen_Black");
		player.GetInventory().CreateInInventory("TacSatRadio");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("Zippo_new");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		EntityAI gun = player.GetInventory().CreateInInventory("Repeater");
		addMags(player, "Ammo_357", 5);
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());
		
		player.SetQuickBarEntityShortcut(gun, 1, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		
		if(player.IsMale())
		{
			EntityAI male;
			switch (Math.RandomInt(0, 40)) 
			{
				case 0: male = mercenaryClass(player); break;
				case 1: male = nbcClass(player); break;
				case 2: male = soldierClass(player); break;
				case 3: male = ninjaClass(player); break;
				case 4: male = policeClass(player); break;
				case 5: male = cowhandClass(player); break;
				case 6: male = bikerClass(player); break;
				case 7: male = sniperClass(player); break;
				case 8: male = hunterClass(player); break;
				case 9: male = randomClass(player); break;
				case 10: male = randomClass(player); break;
				case 11: male = randomClass(player); break;
				case 12: male = randomClass(player); break;
				case 13: male = randomClass(player); break;
				case 14: male = randomClass(player); break;
				case 15: male = randomClass(player); break;
				case 16: male = randomClass(player); break;
				case 17: male = randomClass(player); break;
				case 18: male = randomClass(player); break;
				case 19: male = randomClass(player); break;
				case 20: male = randomClass(player); break;
				case 21: male = randomClass(player); break;
				case 22: male = randomClass(player); break;
				case 23: male = randomClass(player); break;
				case 24: male = randomClass(player); break;
				case 25: male = randomClass(player); break;
				case 26: male = randomClass(player); break;
				case 27: male = randomClass(player); break;
				case 28: male = randomClass(player); break;
				case 29: male = randomClass(player); break;
				case 30: male = randomClass(player); break;
				case 31: male = randomClass(player); break;
				case 32: male = randomClass(player); break;
				case 33: male = randomClass(player); break;
				case 34: male = randomClass(player); break;
				case 35: male = randomClass(player); break;
				case 36: male = randomClass(player); break;
				case 37: male = randomClass(player); break;
				case 38: male = randomClass(player); break;
				case 39: male = randomClass(player); break;
			}
		}
		
		else
		{
			EntityAI female;
			switch (Math.RandomInt(0, 40)) 
			{
				case 0: female = mercenaryClass(player); break;
				case 1: female = nbcClass(player); break;
				case 2: female = soldierClass(player); break;
				case 3: female = ninjaClass(player); break;
				case 4: female = policeClass(player); break;
				case 5: female = cowhandClass(player); break;
				case 6: female = bikerClass(player); break;
				case 7: female = sniperClass(player); break;
				case 8: female = hunterClass(player); break;
				case 9: female = randomClass(player); break;
				case 10: female = randomClass(player); break;
				case 11: female = randomClass(player); break;
				case 12: female = randomClass(player); break;
				case 13: female = randomClass(player); break;
				case 14: female = randomClass(player); break;
				case 15: female = randomClass(player); break;
				case 16: female = randomClass(player); break;
				case 17: female = randomClass(player); break;
				case 18: female = randomClass(player); break;
				case 19: female = randomClass(player); break;
				case 20: female = randomClass(player); break;
				case 21: female = randomClass(player); break;
				case 22: female = randomClass(player); break;
				case 23: female = randomClass(player); break;
				case 24: female = randomClass(player); break;
				case 25: female = randomClass(player); break;
				case 26: female = randomClass(player); break;
				case 27: female = randomClass(player); break;
				case 28: female = randomClass(player); break;
				case 29: female = randomClass(player); break;
				case 30: female = randomClass(player); break;
				case 31: female = randomClass(player); break;
				case 32: female = randomClass(player); break;
				case 33: female = randomClass(player); break;
				case 34: female = randomClass(player); break;
				case 35: female = randomClass(player); break;
				case 36: female = randomClass(player); break;
				case 37: female = randomClass(player); break;
				case 38: female = randomClass(player); break;
				case 39: female = randomClass(player); break;
			}
		}
	}
	//MODDED LOADOUTS - END-------------------------------------
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}