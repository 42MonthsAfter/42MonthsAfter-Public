class CfgMods
{
	class InventoryInCar
	{
		dir="InventoryInCar";
        picture="";
        action="";
        hideName=1;
        hidePicture=1;
        name="InventoryInCar";
        credits="Tim";
        author="Tim";
        authorID="0";
        version="0.1";
        extra=0;
        type="mod";
	    dependencies[]={ "World" };
	    class defs
	    {
	        class worldScriptModule
            {
                value="";
                files[]={ "InventoryInCar/scripts/4_world" };
            };
        };
    };
};

class CfgPatches
{
	class CarUpdate
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};