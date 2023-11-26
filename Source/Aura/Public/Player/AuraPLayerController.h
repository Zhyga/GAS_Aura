#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPLayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IHighlightInterface;

UCLASS()
class AURA_API AAuraPLayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPLayerController();
	
protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContex;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	IHighlightInterface* LastActor;
	IHighlightInterface* ThisActor;
	
	void Move(const FInputActionValue& InputActionValue);

	virtual void Tick(float DeltaSeconds) override;

	void CursorTrace();
};
