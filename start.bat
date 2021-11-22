@echo off
:START
DayZServer_x64.exe -cpuCount=4 -mod=@GameLabs;@CF;@CommunityOnlineTools;@DabsFramework;@Chiemsee;@SkyZ;@DayZEditorLoader;@ModularVestSystem;@AdditionalMedicSupplies;@TeddysWeaponPack;@RUSFormavehicles;@StreetLighting;@Notifications;@Notes;@MunghardsItempack;@BaseBuildingPlus;@BuildAnywherev3;@MuchStuffPack;@BuilderItems;@CannabisPlus;@CarCover;@CodeLock;@EarPlugs;@InventoryInCar;@ZeroyFishingZ;@zSpawnSelection;@RaGHummerArmored;@PVEZ;@SNAFUWeapons;@MunghardsItempack;@VanillaPlusPlusMap;@AirdropUpgraded;@AirRaid;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START