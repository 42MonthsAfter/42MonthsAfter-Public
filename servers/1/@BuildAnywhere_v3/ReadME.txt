BuildAnywhere version 3.4.23.07.2021.5

Allows ghosts to be set anywhere for placing objects and building of components where the vanilla
game normally would not. There are some limitations, for example if you cannot see the trigger
points (ie putting a fence completely inside a wall, you will not be able to actually build it as
the wall will obstruct your view of the fence).

===========================================================================

WARNING!
Mod not allows placing GardenPlot on roads, stones, in houses and builds stairs from it.
Mod not allows placing tents on water, trees and much higher or lower than player.
Mod not affect to holograms, zombies, animals, players, buildings etc.
Mod affects only to collisions checks on client and server side!

===========================================================================

Server Owners:
Install the mod on your client to download.
Right click on the mod in Launcher and Browse Files
Copy the @BuildAnywhere_v3 directory to your DayZServer directory root
add -mod=@BuildAnywhere_v3 to your launch parameter -mod= or ;@BuildAnywhere_v3 after all other mods.

Copy BorizzK.bikey from inside @BuildAnywhere_v3/Key to the Keys difrectory in the root of your DayZ Server.

===========================================================================

After first run mod makes config file BuildAnywhere.json in your server profile folder with default values:

 {
    "TENT_CAN_PLACE_ANYWHERE_MODE": 0,
    "PLACEMENT_HEIGHT_DIFF_MAX": 1.64,
    "PLACEMENT_HEIGHT_DIFF_MIN": -1.24,
    "PLACEMENT_PITCH_LIMIT_FACTOR": 2.5,
    "PLACEMENT_ROLL_LIMIT_FACTOR": 2.5
 }

Yo can change values to:

 TENT_CAN_PLACE_ANYWHERE_MODE:
  0 - Soft restrictions for placing tents, default restrictions for Garden Plot and no restrictions for others.
     BuildAnywhere V3 Default. Recommended.
  1 - No restrictions for all (Like in old BuildAnywhere), but little resrictions for placing tents. 
  2 - Default game restrictions.
 
 PLACEMENT_HEIGHT_DIFF_MAX	  = 1.61;  	- Maximum positive height difference between player and placement position - only for tents
 PLACEMENT_HEIGHT_DIFF_MIN	  = -1.21; 	- Maximum negative height difference between player and placement position - only for tents
 PLACEMENT_PITCH_LIMIT_FACTOR = 2.43;	- Maximum pitch angle factor - only for tents and gardenplots - can be placed on a slope
 PLACEMENT_ROLL_LIMIT_FACTOR  = 2.43;	- Maximum roll angle factor - only for tents and gardenplots - can be placed on a slope


 P.S. See logs on server side about load config file. Also see log on client side about received parameters.

===========================================================================

NOTE: This is required on both client and server to function. Requires verifySignatures=3; to be set in server config file.
Be sure to copy the provided .bikey from key to your keys folder.

Mod co-Author: Cleetus.
https://steamcommunity.com/sharedfiles/filedetails/?id=1574054508

ThanX to: MusTanG, Wardog and Equadro.

License:
ADPL-SA [url=http://bistudio.com]Bohemia Interactive[/url]

===========================================================================
