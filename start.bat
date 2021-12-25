@echo off
:START
DayZServer_x64.exe -cpuCount=2 -mod=@Chiemsee;@DayZEditorLoader;@CF;@CommunityOnlineTools;@DabsFramework;@BuilderItems;@Notifications;@VanillaPlusPlusMap;@zSpawnSelection;@SkyZ;@PvZmoDCustomisableZombies;@AirdropUpgraded;@PVEZ;@PVEZAirdropZones;@PVEZMarkersOnVPPMap;@StreetLighting;@NoVehicleDamage;@Notes;@KingoftheHill;@InventoryInCar;@EarPlugs;@BuildAnywherev3;@MonstersOfChiemsee;@DayZDog;@AirRaid;@CodeLock;@CarCover;@CannabisPlus;@BaseBuildingPlus;@42MonthsAfter;@AdditionalMedicSupplies;@MuchStuffPack;@MunghardsItempack;@RaGHummerArmored;@RUSFormavehicles;@SNAFUWeapons;@TeddysWeaponPack;@WindstridesClothingPack;@ZeroyFishingZ;@GameLabs;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START