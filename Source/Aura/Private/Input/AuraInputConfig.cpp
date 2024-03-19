// Copyright Stephen Auker


#include "Input/AuraInputConfig.h"

#include "Serialization/ArchiveReplaceObjectRef.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for(const FAuraInputAction& IA : AbilityInputActions)
	{
		if (IA.InputAction && IA.InputTag.MatchesTagExact(InputTag))
		{
			return IA.InputAction;
		}
	}
	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("AbilityInputAction not found for InputTag [%s] on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	}
	return nullptr;
}
