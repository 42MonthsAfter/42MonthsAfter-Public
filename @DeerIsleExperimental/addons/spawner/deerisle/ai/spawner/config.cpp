////////////////////////////////////////////////////////////////////
//DeRap: spawner\config.bin
//Produced from mikero's Dos Tools Dll version 8.65
//https://mikero.bytex.digital/Downloads
//'now' is Thu Apr 14 14:36:56 2022 : 'file' last modified on Thu Jan 01 01:00:01 1970
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class deerisle_ai_spawner
	{
		units[] = {};
		weapons[] = {};
	};
};
class DeerisleSpawner
{
	class AISpawnerParams
	{
		territoriesFiles[] = {};
		class HerdDeer
		{
			usableTerritories[] = {"red_deer_territories"};
			groupBehaviourTemplateName = "DZDeerGroupBeh";
		};
		class HerdCow
		{
			usableTerritories[] = {"cattle_territories"};
			groupBehaviourTemplateName = "DZdomesticGroupBeh";
		};
		class HerdGoat
		{
			usableTerritories[] = {"sheep_goat_territories"};
			groupBehaviourTemplateName = "DZSheepGroupBeh";
		};
		class HerdSheep
		{
			usableTerritories[] = {"sheep_goat_territories"};
			groupBehaviourTemplateName = "DZSheepGroupBeh";
		};
		class HerdRoeDeer
		{
			usableTerritories[] = {"roe_deer_territories"};
			groupBehaviourTemplateName = "DZDeerGroupBeh";
		};
		class HerdWolf
		{
			usableTerritories[] = {"wolf_territories"};
			groupBehaviourTemplateName = "DZWolfGroupBeh";
		};
		class HerdWildBoar
		{
			usableTerritories[] = {"wild_boar_territories"};
			groupBehaviourTemplateName = "DZDeerGroupBeh";
		};
		class HerdPig
		{
			usableTerritories[] = {"pig_territories"};
			groupBehaviourTemplateName = "DZSheepGroupBeh";
		};
		class AmbientHen
		{
			usableTerritories[] = {"hen_territories"};
			groupBehaviourTemplateName = "DZAmbientLifeGroupBeh";
			globalCountMax = 50;
			zoneCountMin = 1;
			zoneCountMax = 1;
			playerSpawnRadiusNear = 25;
			playerSpawnRadiusFar = 75;
			class AgentTypeMale
			{
				agentConfigName[] = {"Animal_GallusGallusDomesticus"};
				agentSpawnChance[] = {"1"};
			};
			class AgentTypeFemale
			{
				agentConfigName[] = {"Animal_GallusGallusDomesticusF_Brown","Animal_GallusGallusDomesticusF_Spotted","Animal_GallusGallusDomesticusF_White"};
				agentSpawnChance[] = {"1","10","20"};
			};
			agentTypeSpawnChance[] = {"1","3"};
		};
		class AmbientHare
		{
			usableTerritories[] = {"hare_territories"};
			groupBehaviourTemplateName = "DZAmbientLifeGroupBeh";
			globalCountMax = 0;
			zoneCountMin = 3;
			zoneCountMax = 5;
			playerSpawnRadiusNear = 15;
			playerSpawnRadiusFar = 200;
			class AgentTypeMale
			{
				agentConfigName[] = {"Animal_LepusEuropaeus"};
				agentSpawnChance[] = {"1"};
			};
			class AgentTypeFemale
			{
				agentConfigName[] = {"Animal_LepusEuropaeus"};
				agentSpawnChance[] = {"1"};
			};
			agentTypeSpawnChance[] = {"1","3"};
		};
		class HerdZombieTest
		{
			usableTerritories[] = {"zombie_territories"};
			groupBehaviourTemplateName = "DZdomesticGroupBeh";
			herdsCount = 0;
			class AgentTypeMale
			{
				agentConfigName[] = {"ZombieMale3_NewAI"};
				countMin = 0;
				countMax = 0;
			};
			class AgentTypeFemale
			{
				agentConfigName[] = {"ZombieFemale3_NewAI"};
				countMin = 0;
				countMax = 0;
			};
		};
	};
};
