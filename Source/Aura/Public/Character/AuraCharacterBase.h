// Copyright Stephen Auker

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemReplicationProxyInterface.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "AuraCharacterBase.generated.h"

class UGameplayEffect;
class UAttributeSet;
class UAuraAttributeSet;
class UAuraAbilitySystemComponent;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const {return AttributeSet;}

protected:

	virtual void InitAbilityActorInfo();

	UPROPERTY(EditAnywhere, Category = "Combat" )
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;
	
	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float level) const;
	void InitializeDefaultAttributes() const;
	
	
};
