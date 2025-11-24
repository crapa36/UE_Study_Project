// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilitys/WarriorGameplayAbility.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag) {
    if (!InInputTag.IsValid()) {
        return;
    }

    for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) {
        if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

        TryActivateAbility(AbilitySpec.Handle);
    }
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag) {
}

void UWarriorAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FWarriorHeroAbilitySet>& InDefaultWeponAbilitys, int32 ApllyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles) {
    if(InDefaultWeponAbilitys.IsEmpty()) {
        return;
    }
    for (const FWarriorHeroAbilitySet& AbilitySet : InDefaultWeponAbilitys) {
        if (!AbilitySet.IsValid()) {
            continue;
        }
        FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
        AbilitySpec.SourceObject = GetAvatarActor();
        AbilitySpec.Level = ApllyLevel;
        AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
        GiveAbility(AbilitySpec);

        OutGrantedAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
    }
}
