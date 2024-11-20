// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleShipsGameMode.h"
#include "BattleShipsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABattleShipsGameMode::ABattleShipsGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
