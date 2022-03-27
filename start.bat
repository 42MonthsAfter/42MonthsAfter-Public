@echo off
:START
DayZServer_x64.exe -cpuCount=2 -mod=@DeerIsleExperimental;@DayZEditorLoader;@CF;@CommunityOnlineTools;@DabsFramework;@AirdropUpgraded;@VanillaPlusPlusMap;@KingoftheHill;@42MonthsAfter;@BuildAnywherev3;@BuilderItems;@BuildingFortifications;@CodeLock;@PartyMe;@StaminaSettings;@CarCover;@Notes;@RepairMyCar;@FlipTransport;@EarPlugs;@eAI;@zSpawnSelection;@ZeroyFishingZ;@IRPLandRoverDefender110;@FOXWEAPONS;@Treasure;@BetterInspect;@RoadTripNG;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START