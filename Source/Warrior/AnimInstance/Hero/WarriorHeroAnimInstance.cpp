// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimInstance/Hero/WarriorHeroAnimInstance.h"
#include "Characters/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation() {
    Super::NativeInitializeAnimation();

    if (OwningCharacter) {
        OwningHeroCharacter = Cast<AWarriorHeroCharacter>(OwningCharacter);
    }
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds) {
    Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
    if (HasAcceleration) {
        IdleElapsedTime = 0.f;
        bShoudEnterRelaxState = false;
    }
    else {
        IdleElapsedTime += DeltaSeconds;
        bShoudEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateThreshold);
    }
}