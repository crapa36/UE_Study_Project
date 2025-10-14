// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"
class UWarriorGameplayAbility;
class UWarriorAbilitySystemComponent;
/**
 *
 */
UCLASS()
class WARRIOR_API UDataAsset_StartUpDataBase : public UDataAsset {
    GENERATED_BODY()
public:
    virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
    UPROPERTY(EditAnywhere, Category = "StartUpData")
    TArray<TSubclassOf <UWarriorGameplayAbility>> ActivateOnGivenAbilities;
    UPROPERTY(EditAnywhere, Category = "StartUpData")
    TArray<TSubclassOf <UWarriorGameplayAbility>> ReactiveAbilities;

    void GrantAbilities(TArray<TSubclassOf <UWarriorGameplayAbility>>& InAbilitiesToGive, UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
