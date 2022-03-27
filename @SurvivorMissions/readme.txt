Survivor Misssions v0.85
========================
This mod is a server modification. DO NOT INSTALL IT ON CLIENT!
Online players read the small description on Steam Mod page, how to play and receive missions on a server running SMM. 
Serveramdins, please make sure to indicate that your server is running this mod by adding "Missions" to the server name.
 
Mod Compatibility:
------------------
Survivor Missions Mod is compatible to most common DayZ mods available on Steam Workshop (by Valve Corporation).
SMM was developed under the goal to make it as much adjustable as possible for server admins but cross mod compatibility is not guaranteed in any way. 
Some tips when running it together with other mods:

- Expansion Mod:
Make sure you copied and renamed the EventsWorldData_ChernarusPlus_EXP.c or EventsWorldData_ChernarusPlusGloom_EXP.c file to match the mpmission,
when installing the SMM mission module in the \mpmissions\Expansion.ChernarusPlus or \mpmissions\Expansion.ChernarusPlusGloom server mission directory.
Change also all file includes (#include <filepath>) in the MissionSettings.c file and the Missions.h header file to your <Mission>.<Terrain> 
according to the server installation guide. For example the destination for the EventsWorldData file include could be  
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlusGloom\\SurvivorMissionModule\\EventsWorldData.c"

When running Expansion mod you accept that this mod is changing the way SMM notifications are displayed by the GUI on clients!

- DeerIsle Mod(terrain):
this custom Dayz map is now supported by SMM. There are only some test missions for it at the moment. DeerIsle is still work in progress, so there are 
alot of changes recently to this map. Once it is in a final state, SMM will full support it with numerous mission locations. Feel free to
create your own missions for this map in the meantime!

- Item mods(global):
Individulize your mission rewards by adding new loadouts to the missions. Just use the object names of that specific mod. Most item Mods have a list
of contained object names on their Steam page. 

Server Installation:
--------------------
First read the mod description on the Steam mod page where you subscribed this mod! There is also a video guide for the server installation.
https://steamcommunity.com/sharedfiles/filedetails/?id=1988925918

For the "Server Installation HOWTO" please visit:
https://github.com/Bitverbieger/SurvivorMissions

Backup your changes of your edited mission files and ewd. Make sure you copy the serverfiles to the proper server directories. Copy them even if you just
update your server for SMM because it conains new and edited mission files and EWD data for all 3 terrains supported by SMM at the moment.

If you encounter any issues on running the mod on your server please visit SMM Disord:
https://discord.gg/reP3dq8

License Information:
--------------------
Survivor Missions serverfiles are licensed under the 
*** GNU LESSER GENERAL PUBLIC LICENSE  Version 2.1 ***
wich means you are allowed to create, edit, share mission files, EventsWorldData files, MissionSettings files and SurvivorStory files, all located 
in this mod directory under \serverfiles. If you want to use code from already provided serverfiles, please give credits to Funkdoc or otherwise to the 
creator of the original code in the top comments when creating your own mission files. Also add your name to the credits in this case.

You are not allowed to change or repack the "SurvivorMissions.pbo" or any other packed content located in the \@Surivor Missions\Addons directory 
without the permission of Steam user Funkdoc.

You are not allowed to upload or provide this Mod in any way on Steam except under the Steam account of user Funkdoc.
You are not allowed to upload or provide this Mod on any other location, platform or service application.

With the usage and/or the subscription of this mod you accept these agreement. 
With your acception you also allow other creators to use code from your published files.