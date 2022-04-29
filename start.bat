@echo off
:START
DayZServer_x64.exe -cpuCount=2 -mod=@DeerIsle;@GameLabs;@CF;@CommunityOnlineTools;@DabsFramework;@DayZEditorLoader;@AirdropUpgraded;@VanillaPlusPlusMap;@BuildAnywherev3;@BuilderItems;@BuildingFortifications;@CodeLock;@Notes;@zSpawnSelection;@BetterInspect;@CannabisPlus;@42MonthsAfter;@KingoftheHill;@ZeroyFishingZ;@SkyJeep;@JeepCherokee1984;@IRPLandRoverDefender110;@CarCover;@RepairMyCar;@FlipTransport;@EarPlugs;@RoadTripNG;@TeddysWeaponPack;@FOXWEAPONS;@MuchStuffPack;@MunghardsItempack;@MasssManyItemOverhaul;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START