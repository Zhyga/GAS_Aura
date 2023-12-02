// Copyright ZhygaInv

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
public:
	UFUNCTION()
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
};
