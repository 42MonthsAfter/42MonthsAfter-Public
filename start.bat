@echo off
:START
DayZServer_x64.exe -cpuCount=4 -mod=@CF;@CommunityOnlineTools;@DabsFramework;@Chiemsee;@SkyZ;@DayZEditorLoader;@AdditionalMedicSupplies;@TeddysWeaponPack;@RUSFormavehicles;@Notifications;@Notes;@MunghardsItempack;@BaseBuildingPlus;@BuildAnywherev3;@MuchStuffPack;@BuilderItems;@CannabisPlus;@CarCover;@CodeLock;@EarPlugs;@InventoryInCar;@ZeroyFishingZ;@zSpawnSelection;@RaGHummerArmored;@GameLabs;@MuchCarKey;@PVEZ;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START