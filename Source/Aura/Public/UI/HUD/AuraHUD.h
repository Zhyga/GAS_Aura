#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "UI/Widgets/AuraUserWidget.h"
#include "AuraHUD.generated.h"

class UOverlayWidgetController;

UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	UFUNCTION()
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& Params);

	UFUNCTION()
	void InitOverlay(APlayerController* IniPlayerController, APlayerState* IniPlayerState, UAbilitySystemComponent* IniAbilitySystem, UAttributeSet* IniAttributeSet);
	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
