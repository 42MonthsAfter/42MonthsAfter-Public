@echo off
:START
DayZServer_x64.exe -cpuCount=2 -mod=@DeerIsle;@CF;@CommunityOnlineTools;@GameLabs;@BandShirts;@BuildAnywherev3;@BuilderItems;@zSpawnSelection;@VanillaPlusPlusMap;@MoreDoors;@ForeverLights;@CodeLock;@BreachingCharge;@ChevyC10Spurgerado;@DingoTruck;@MoreDingo;@NehrPickupLada;@42MonthsAfter;@AdditionalMedicSupplies;@MasssManyItemOverhaul;@AirdropUpgraded;@AirRaid;@BaseBuildingPlus;@CannabisPlus;@CarCover;@DabsFramework;@DayZEditorLoader;@EarPlugs;@InventoryInCar;@KingoftheHill;@MonstersOfChiemsee;@MuchStuffPack;@MunghardsItempack;@Notes;@Notifications;@PVEZ;@PVEZAirdropZones;@PVEZMarkersOnVPPMap;@PvZmoDCustomisableZombies;@Raft;@RaGHummerArmored;@RaGLandroverDefender110;@SkyZ;@SNAFUWeapons;@TeddysWeaponPack;@WindstridesClothingPack;@ZeroyFishingZ;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START