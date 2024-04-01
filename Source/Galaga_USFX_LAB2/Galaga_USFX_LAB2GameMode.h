// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_LAB2GameMode.generated.h"

class ANaveEnemiga;
class ANaveEnemigaCaza;
class ANaveEnemigaTransporte;
class ANaveEnemigaEspia;
class ANaveEnemigaReabastecimiento;
class ANaveEnemigaNodriza;
class ANaveEnemigaKamikaze;

UCLASS(MinimalAPI)
class AGalaga_USFX_LAB2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_LAB2GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

//public:
//	ANaveEnemiga* NaveEnemiga01;
//	
//	//Instanciamos de las clases de la cual crearemos objetos guardando sus direcciones de memoria
//	ANaveEnemigaCaza* NaveEnemigaCaza01; 
//	ANaveEnemigaCaza* NaveEnemigaCaza02; 
//	ANaveEnemigaTransporte* NaveEnemigaTransporte01;
//	ANaveEnemigaTransporte* NaveEnemigaTransporte02;
//	ANaveEnemigaEspia* NaveEnemigaEspia01;
//	ANaveEnemigaEspia* NaveEnemigaEspia02;
//	ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimiento01;
//	ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimiento02;
//	ANaveEnemigaNodriza* NaveEnemigaNodriza01;
//	ANaveEnemigaNodriza* NaveEnemigaNodriza02;
//	ANaveEnemigaKamikaze* NaveEnemigaKamikaze01;
//	ANaveEnemigaKamikaze* NaveEnemigaKamikaze02;

public:
	TArray<ANaveEnemiga*> TANavesEnemigas;
	TArray<ANaveEnemigaCaza*> TANavesEnemigasCaza;
	TArray<ANaveEnemigaTransporte*> TANavesEnemigasTransporte;
	TArray<ANaveEnemigaEspia*> TANavesEnemigasEspia;
	/*TArray<ANaveEnemigaReabastecimiento*> TANavesEnemigasReabastecimiento;
	TArray<ANaveEnemigaNodriza*> TANavesEnemigasNodriza;
	TArray<ANaveEnemigaKamikaze*> TANavesEnemigasKamikaze;*/
	UPROPERTY()
	TMap<ANaveEnemiga*, FVector> TMPosicionesNavesEnemigas;

	void MostrarPosicionesNavesEnemigas();
};


