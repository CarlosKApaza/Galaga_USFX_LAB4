// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_LAB2GameMode.h"
#include "Galaga_USFX_LAB2Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaKamikaze.h"

AGalaga_USFX_LAB2GameMode::AGalaga_USFX_LAB2GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_LAB2Pawn::StaticClass();
}

void AGalaga_USFX_LAB2GameMode::BeginPlay()
{
	Super::BeginPlay();
	//Rotacion de las naves enemigas
	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	//Ubicacion inicial de las naves enemigas
	FVector ubicacionNaveInicial = FVector(-380.0f, -200.0f, 180.0f); //-200 porque quiero que mi primera nave se cree a partir desde el punto medio un poco mas a la izquierda
	FVector ubicacionActual = ubicacionNaveInicial;
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		//spawenado las naves de la clase NaveEnemigaCaza con un ciclo
		for (int i = 0; i < 10; i++) {
			ubicacionActual.Y += 200.0f; // Sumar 200 unidades a la coordenada Y en cada iteración (los espacios por naves)
			ANaveEnemigaCaza* NaveEnemigaCazaActual = World->SpawnActor<ANaveEnemigaCaza>(ubicacionActual, rotacionNave);
			TANavesEnemigasCaza.Add(NaveEnemigaCazaActual);
		}

		// Actualizar la ubicación inicial para las naves de la clase NaveEnemigaTransporte
		ubicacionActual.X = ubicacionNaveInicial.X = -70.0f; // crear un fila por el medio
		ubicacionActual.Y = ubicacionNaveInicial.Y = -200.0f; //(los espacios por naves)

		for (int i = 0; i < 10; i++) {
			ubicacionActual.Y += 200.0f; // Sumar 200 unidades a la coordenada Y en cada iteración (los espacios por naves)
			ANaveEnemigaTransporte* NaveEnemigaTransporteActual = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionActual, rotacionNave);
			TANavesEnemigasTransporte.Add(NaveEnemigaTransporteActual);
		}
		// Actualizar la ubicación inicial para las naves de la clase NaveEnemigaEspia
		ubicacionActual.X = ubicacionNaveInicial.X = 270.0f; // crear un fila más arriba
		ubicacionActual.Y = ubicacionNaveInicial.Y = -200.0f; //(los espacios por naves)

		for (int i = 0; i < 10; i++) {
			ubicacionActual.Y += 200.0f; // Sumar 200 unidades a la coordenada Y en cada iteración (los espacios por naves)
			ANaveEnemigaEspia* NaveEnemigaEspiaActual = World->SpawnActor<ANaveEnemigaEspia>(ubicacionActual, rotacionNave);
			TANavesEnemigasEspia.Add(NaveEnemigaEspiaActual);
		}
	}
}

void AGalaga_USFX_LAB2GameMode::MostrarPosicionesNavesEnemigas()
{
	
}

