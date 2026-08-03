// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenerBase.h"

// Sets default values
AListenerBase::AListenerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AListenerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AListenerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AListenerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

