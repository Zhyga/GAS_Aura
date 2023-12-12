// Copyright ZhygaInv

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/HighlightInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IHighlightInterface
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
public:
	AAuraEnemy();
	void HighlightActor() override;
	void UnHighlightActor() override;
};
