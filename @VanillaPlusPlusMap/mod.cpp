class CfgMods
{
	class VanillaPPMap
	{
		dir="VanillaPPMap";
		hideName=0;
		hidePicture=0;
		name="Vanilla++ Map";
		credits="DaOne,GravityWolf & MrMaffen";
		author="DaOne,GravityWolf & MrMaffen";
		authorID="420420";
		inputs="VanillaPPMap/data/modded_Inputs.xml";
		version="version 1.0";
		extra=0;
		type="mod";
		picture = "VanillaPPMap/scripts/data/vpp_logo_m.paa";			// picture in expanded description
		logoSmall = "VanillaPPMap/scripts/data/vpp_logo_ss.paa";	// icon next to mod name when description is not expanded
		logo = "VanillaPPMap/scripts/data/vpp_logo_s.paa";				// logo below game menu
		logoOver = "VanillaPPMap/scripts/data/vpp_logo_s.paa";	// on mouse hover over logo
		tooltip = "This mod works with any custom map on the workshop!";							// tool tip on mouse hover
		overview = "V++ Map Mod. Making your life easy for free! Features: -See your position on the map -Satellite view map -Place custom markers (2D & 3D) +MORE!"; 						// overview
		action = "https://discord.gg/bkf3u7M";			// link
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"VanillaPPMap/GUI/Textures/map_ui_icons.imageset"
				};
			};
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"VanillaPPMap/3_Game"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"VanillaPPMap/5_Mission"
				};
			};
		};
	};
};