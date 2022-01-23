@echo off
:START
DayZServer_x64.exe -cpuCount=2 -mod=@DeerIsle;@CF;@CommunityOnlineTools;@BuildAnywherev3;@BuilderItems;@zSpawnSelection;@VanillaPlusPlusMap;@MonstersOfChiemsee;@CodeLock;@BreachingCharge;@ChevyC10Spurgerado;@DingoTruck;@MoreDingo;@NehrPickupLada;@AdditionalMedicSupplies;@MasssManyItemOverhaul;@AirdropUpgraded;@AirRaid;@BaseBuildingPlus;@CannabisPlus;@CarCover;@KindergartenDingoFix;@DabsFramework;@DayZEditorLoader;@EarPlugs;@KingoftheHill;@MonstersOfChiemsee;@MuchStuffPack;@MunghardsItempack;@Notes;@Notifications;@SNAFUWeapons;@TeddysWeaponPack;@WindstridesClothingPack;@ZeroyFishingZ;@FlipTransport;@42MonthsAfter;@eAI;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START