// Copyright ZhygaInv


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystem = WCParams.AbilitySystem;
	AttributeSet = WCParams.AttributeSet;
}
