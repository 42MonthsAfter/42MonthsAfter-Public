@echo off
:START
DayZServer_x64.exe -cpuCount=4 -mod=@GameLabs;@CF;@CommunityOnlineTools;@DabsFramework;@Chiemsee;@SkyZ;@DayZEditorLoader;@MonstersOfChiemsee;@PvZmoDCustomisableZombies;@AdditionalMedicSupplies;@UnlimitedStamina;@42MonthsAfter;@TeddysWeaponPack;@MunghardsItempack;@RUSFormavehicles;@StreetLighting;@KingoftheHill;@DayZDog;@Notifications;@Notes;@BaseBuildingPlus;@BuildAnywherev3;@MuchStuffPack;@BuilderItems;@WindstridesClothingPack;@CannabisPlus;@CarCover;@CodeLock;@EarPlugs;@InventoryInCar;@ZeroyFishingZ;@zSpawnSelection;@RaGHummerArmored;@PVEZ;@SNAFUWeapons;@VanillaPlusPlusMap;@AirdropUpgraded;@AirRaid;@PVEZAirdropZones;@PVEZMarkersOnVPPMap;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START