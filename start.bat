@echo off
:START
DayZServer_x64.exe -cpuCount=2 -mod=@DeerIsle;@DayZEditorLoader;@CF;@CommunityOnlineTools;@DabsFramework;@AirdropUpgraded;@VanillaPlusPlusMap;@BetterInspect;@KingoftheHill;@42MonthsAfter;@SkyJeep;@JeepCherokee1984;@TeddysWeaponPack;@MuchStuffPack;@BuildAnywherev3;@BuilderItems;@BuildingFortifications;@CodeLock;@MunghardsItempack;@CannabisPlus;@CarCover;@Notes;@RepairMyCar;@FlipTransport;@EarPlugs;@zSpawnSelection;@ZeroyFishingZ;@IRPLandRoverDefender110;@FOXWEAPONS;@BetterInspect;@RoadTripNG;@MasssManyItemOverhaul;@GameLabs;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START