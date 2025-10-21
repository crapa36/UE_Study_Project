// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/WarriorWeaponBase.h"
#include "WarriorDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon) {
    checkf(CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("Weapon with tag %s is already registered!"), *InWeaponTagToRegister.ToString());
    check(InWeaponToRegister);
    CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);
    if (bRegisterAsEquippedWeapon) {
        CurrentEquippedWeaponTag = InWeaponTagToRegister;
    }
    const FString WeaponString = FString::Printf(TEXT("Registered weapon %s with tag %s"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
    Debug::Print(WeaponString);
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTag) const {
    if (CharacterCarriedWeaponMap.Contains(InWeaponTag)) {
        if (AWarriorWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTag)) {
            return *FoundWeapon;
        }
    }
    return nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCurrentEquippedWeapon() const {
    if (!CurrentEquippedWeaponTag.IsValid()) {
        return nullptr;
    }
    return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}