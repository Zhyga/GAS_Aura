// Copyright ZhygaInv


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter()
{
	UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement();
	check(CharacterMovementComponent);
	CharacterMovementComponent->bOrientRotationToMovement = true;
	CharacterMovementComponent->RotationRate = FRotator(0.f, 400.f, 0.f);
	CharacterMovementComponent->bConstrainToPlane = true;
	CharacterMovementComponent->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	IniAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	IniAbilityActorInfo();
}

void AAuraCharacter::IniAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = Cast<AAuraPlayerState>(GetPlayerState());
	check(AuraPlayerState);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
	AttributeSet = AuraPlayerState->GetAttributeSet();
}