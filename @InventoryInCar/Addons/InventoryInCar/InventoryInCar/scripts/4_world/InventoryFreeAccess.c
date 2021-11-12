modded class PlayerBase
{
	override void OnCommandVehicleStart()
	{
		super.OnCommandVehicleStart();
		
		if ( GetInventory() ) { GetInventory().UnlockInventory(LOCK_FROM_SCRIPT); }
		//if ( GetItemInHands() ) { GetItemAccessor().HideItemInHands(false); }
	}
	
	override void OnCommandVehicleFinish()
	{
		if ( GetInventory() ) { GetInventory().LockInventory(LOCK_FROM_SCRIPT); }
		//if ( GetItemInHands() ) { GetItemAccessor().HideItemInHands(true); }
		
		super.OnCommandVehicleFinish();
	}
	
	override bool CanReceiveItemIntoHands (EntityAI item_to_hands)
	{
		if( IsInVehicle() ) { return true; }
		return super.CanReceiveItemIntoHands(item_to_hands);
	}
}