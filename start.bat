@echo off
:START
DayZServer_x64.exe -cpuCount=2 -mod=@DeerIsle;@CF;@CommunityOnlineTools;@AirdropUpgraded;@DabsFramework;@CodeLock;@BaseBuildingPlus;@BuilderItems;@zSpawnSelection;@BuildAnywherev3;@Notifications;@Notes;@CarCover;@DayZEditorLoader;@FlipTransport;@InventoryInCar;@VanillaPlusPlusMap;@EarPlugs;@eAI;@42MonthsAfter;@ZeroyFishingZ;@SNAFUWeapons;@CannabisPlus;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START