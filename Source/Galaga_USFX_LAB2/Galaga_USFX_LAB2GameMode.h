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
	// Contenedores avanzados TArrays para almacenar las naves enemigas
	TArray<ANaveEnemiga*> TANavesEnemigas;
	TArray<ANaveEnemigaCaza*> TANavesEnemigasCaza;
	TArray<ANaveEnemigaTransporte*> TANavesEnemigasTransporte;
	TArray<ANaveEnemigaEspia*> TANavesEnemigasEspia;

	//TArray<FVector> PosicionesNavesEliminadas; // Contenedor avanzado TArray para almacenar las posiciones de las naves eliminadas
	
	// Contenedor avanzado TMap para almacenar las posiciones de las naves enemigas
	UPROPERTY()
	TMap<ANaveEnemiga*, FVector> TMPosicionesNavesEnemigas;


	void MostrarPosicionesNavesEnemigas(); // Funci�n para mostrar las posiciones de las naves enemigas
	void EliminarEnemigosAleatoriamente(); // Funci�n para eliminar enemigos aleatoriamente
	void CrearEnemigosAleatoriamente(); // Funci�n para crear enemigos aleatoriamente
	void EjecutarAcciones(); // Funci�n para ejecutar todas las acciones
	void StopGameActions(); // Funci�n para detener todas las acciones
	

public:
	// Timer para controlar la visualizaci�n de las posiciones de las naves enemigas
	// Declaraciones de FTimerHandle
	FTimerHandle FTHEliminarEnemigosAleatorios; // Timer para eliminar enemigos aleatorios
	FTimerHandle FTHCrearEnemigosAleatorios; // Timer para crear enemigos aleatorios
	FTimerHandle FTHEndGameActions; // Timer para detener todas las acciones

	//FTimerHandle FTHEjecutarAcciones; // Timer para ejecutar todas las acciones
	
};


