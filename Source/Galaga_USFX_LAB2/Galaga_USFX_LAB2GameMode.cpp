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
	FVector ubicacionNaveActual = ubicacionNaveInicial;
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		//spawenado las naves de la clase NaveEnemigaCaza con un ciclo
		for (int i = 0; i < 10; i++) { // Crear 10 naves de la clase NaveEnemigaCaza
			ubicacionNaveActual.Y += 190.0f; // Sumar 190 unidades a la coordenada Y en cada iteración (los espacios por naves)
			ANaveEnemigaCaza* NaveEnemigaCazaActual = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNaveActual, rotacionNave);
			NaveEnemigaCazaActual->SetNombre("Nave Enemiga Caza" + FString::FromInt(i + 1));
			TANavesEnemigasCaza.Add(NaveEnemigaCazaActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaCazaActual, ubicacionNaveActual);
		}

		// Actualizar la ubicación inicial para las naves de la clase NaveEnemigaTransporte
		ubicacionNaveActual.X = ubicacionNaveInicial.X = -70.0f; // crear un fila por el medio
		ubicacionNaveActual.Y = ubicacionNaveInicial.Y = -200.0f; // actualizo la creacion de la nave desde la ubicacionNaveActual

		for (int j = 0; j < 10; j++) { // Crear 10 naves de la clase NaveEnemigaTransporte
			ubicacionNaveActual.Y += 190.0f; // Sumar 190 unidades a la coordenada Y en cada iteración (los espacios por naves)
			ANaveEnemigaTransporte* NaveEnemigaTransporteActual = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNaveActual, rotacionNave);
			NaveEnemigaTransporteActual->SetNombre("Nave Enemiga Transporte" + FString::FromInt(j + 1));
			TANavesEnemigasTransporte.Add(NaveEnemigaTransporteActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaTransporteActual, ubicacionNaveActual);
		}
		// Actualizar la ubicación inicial para las naves de la clase NaveEnemigaEspia
		ubicacionNaveActual.X = ubicacionNaveInicial.X = 270.0f; // crear un fila más arriba
		ubicacionNaveActual.Y = ubicacionNaveInicial.Y = -200.0f; // actualizo la creacion de la nave desde la ubicacionNaveActual

		for (int k = 0; k < 10; k++) { // Crear 10 naves de la clase NaveEnemigaEspia
			ubicacionNaveActual.Y += 190.0f; // Sumar 190 unidades a la coordenada Y en cada iteración (los espacios por naves)
			ANaveEnemigaEspia* NaveEnemigaEspiaActual = World->SpawnActor<ANaveEnemigaEspia>(ubicacionNaveActual, rotacionNave);
			NaveEnemigaEspiaActual->SetNombre("Nave Enemiga Espia" + FString::FromInt(k + 1));
			TANavesEnemigasEspia.Add(NaveEnemigaEspiaActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaEspiaActual, ubicacionNaveActual);
		}
		
		// Mostrar las posiciones de las naves enemigas cada segundo
		GetWorldTimerManager().SetTimer(FTHVisualizacionPosicionesNavesEnemigas, this, &AGalaga_USFX_LAB2GameMode::MostrarPosicionesNavesEnemigas, 1.0f, true);
	}
}

void AGalaga_USFX_LAB2GameMode::MostrarPosicionesNavesEnemigas()
{
	for (auto ElementoActual : TMPosicionesNavesEnemigas)
	{
		ANaveEnemiga* NaveEnemigaActual = ElementoActual.Key;
		FVector PosicionNaveActualEnemiga = ElementoActual.Value;
		FString mensaje = "Posicion de la " + NaveEnemigaActual->GetNombre() + ": " + PosicionNaveActualEnemiga.ToString();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, mensaje);

		}
		TMPosicionesNavesEnemigas[NaveEnemigaActual] = NaveEnemigaActual->GetActorLocation();
	}
}

