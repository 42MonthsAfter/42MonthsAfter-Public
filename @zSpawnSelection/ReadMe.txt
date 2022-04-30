Add the "SpawnSelect" folder to the root of your server PROFILE(Where your Server RPT's are). 

You can also customize the spawns if you want to add your own which is located at the SpawnLocations.txt within the profile folder. 

For example:  Kamenka=892.109985 6.171125 2244.129883=1000   

Make sure you have the "=" in between your location name and location vector. Also between location vector and spawn radius length.

"=1000" From the example above means radius length, lower numbers mean players will spawn closer to your location vector you set in this txt. Opposite can be said if you set the radius higher. 

Also there is a settings file you can customize for example spawn block distances if they died recently close by or even if you want to turn off spawn block or even the time until they can pick the blocked spawn again.

SpawnSettings.txt in server profile SpawnSelect. Make sure you only put one space in this text file specfically for settings.

BodyBlockSpawns 1  Setting this to any int but 1 will turn off the spawn blocker, just a 0 works.
BodyBlockDistance 3000  How far in distance of their dead body they can spawn at before it blocks. it's a float type so you can be specific.
BodyBlockRespawnTimeMinutes 20 How long in minutes until they can get that blocked spawn point back (int only) if you wanted an hour and a half just put 90
