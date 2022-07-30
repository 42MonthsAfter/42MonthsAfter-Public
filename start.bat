@echo off
:START
DayZServer_x64.exe -cpuCount=4 -mod=@DeerIsle;@CF;@CommunityOnlineTools;@BuildAnywherev3;@BuilderItems;@BBPItemPack;@SkyJeep;@RedFalcon;@RoadTripNG;@Raft;@CarsForAll;@MoreMaskZ;@KillReward;@JeepCherokee1984;@FOXWEAPONS;@DayZCasinoV2;@BuildingFortifications;@VanillaPlusPlusMap;@IRPLandRoverDefender110;@CodeLock;@AirRaid;@BreachingCharge;@MasssManyItemOverhaul;@AirdropUpgraded;@BaseBuildingPlus;@CannabisPlus;@CarCover;@DabsFramework;@DayZEditorLoader;@EarPlugs;@KingoftheHill;@MuchStuffPack;@MunghardsItempack;@Notifications;@TeddysWeaponPack;@WindstridesClothingPack;@FlipTransport;@gebsfish;@42MonthsAfter;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=profiles -scrAllowFileWrite -adminlog
timeout 10
goto START