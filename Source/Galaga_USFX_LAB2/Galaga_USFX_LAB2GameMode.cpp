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
		for (int i = 0; i < 5; i++) { // Crear 10 naves de la clase NaveEnemigaCaza
			ubicacionNaveActual.Y += 180.0f; // Sumar 190 unidades a la coordenada Y en cada iteración (los espacios por naves)
			ANaveEnemigaCaza* NaveEnemigaCazaActual = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNaveActual, rotacionNave);
			//NaveEnemigaCazaActual->SetNombre("Nave Enemiga Caza" + FString::FromInt(i + 1));
			TANavesEnemigas.Add(NaveEnemigaCazaActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaCazaActual, ubicacionNaveActual);
		}

		// Actualizar la ubicación inicial para las naves de la clase NaveEnemigaTransporte
		ubicacionNaveActual.X = ubicacionNaveInicial.X = -70.0f; // crear un fila por el medio
		ubicacionNaveActual.Y = ubicacionNaveInicial.Y = -200.0f; // actualizo la creacion de la nave desde la ubicacionNaveActual

		for (int j = 0; j < 5; j++) { // Crear 10 naves de la clase NaveEnemigaTransporte
			ubicacionNaveActual.Y += 180.0f; // Sumar 190 unidades a la coordenada Y en cada iteración (los espacios por naves)
			ANaveEnemigaTransporte* NaveEnemigaTransporteActual = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNaveActual, rotacionNave);
			//NaveEnemigaTransporteActual->SetNombre("Nave Enemiga Transporte" + FString::FromInt(j + 1));
			TANavesEnemigas.Add(NaveEnemigaTransporteActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaTransporteActual, ubicacionNaveActual);
		}
		// Actualizar la ubicación inicial para las naves de la clase NaveEnemigaEspia
		ubicacionNaveActual.X = ubicacionNaveInicial.X = 270.0f; // crear un fila más arriba
		ubicacionNaveActual.Y = ubicacionNaveInicial.Y = -200.0f; // actualizo la creacion de la nave desde la ubicacionNaveActual

		for (int k = 0; k < 5; k++) { // Crear 10 naves de la clase NaveEnemigaEspia
			ubicacionNaveActual.Y += 180.0f; // Sumar 190 unidades a la coordenada Y en cada iteración (los espacios por naves)
			ANaveEnemigaEspia* NaveEnemigaEspiaActual = World->SpawnActor<ANaveEnemigaEspia>(ubicacionNaveActual, rotacionNave);
			//NaveEnemigaEspiaActual->SetNombre("Nave Enemiga Espia" + FString::FromInt(k + 1));
			TANavesEnemigas.Add(NaveEnemigaEspiaActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaEspiaActual, ubicacionNaveActual);
		}
		
		// Mostrar las posiciones de las naves enemigas cada segundo
		/*GetWorldTimerManager().SetTimer(FTHVisualizacionPosicionesNavesEnemigas, this, &AGalaga_USFX_LAB2GameMode::MostrarPosicionesNavesEnemigas, 1.0f, true);*/

		// Temporizador para eliminar enemigos aleatorios cada 10 segundos
		GetWorldTimerManager().SetTimer(FTHEliminarEnemigosAleatorios, this, &AGalaga_USFX_LAB2GameMode::EliminarEnemigosAleatoriamente, 5.0f, true, 5.0f);

		// Temporizador para crear enemigos aleatorios después de 10 segundo
		GetWorldTimerManager().SetTimer(FTHCrearEnemigosAleatorios, this, &AGalaga_USFX_LAB2GameMode::CrearEnemigosAleatoriamente, 5.0f, true, 5.0f);

		// Configurar temporizador para detener todas las acciones después de 40 segundos
		GetWorldTimerManager().SetTimer(FTHEndGameActions, this, &AGalaga_USFX_LAB2GameMode::StopGameActions, 40.0f, false);


	}
}

void AGalaga_USFX_LAB2GameMode::EliminarEnemigosAleatoriamente()
{
	// Verificar si hay al menos dos enemigos para eliminar
	if (TANavesEnemigas.Num() >= 2)
	{
		// Eliminar dos enemigos aleatorios
		for (int i = 0; i < 2; i++)
		{
			int32 RandomIndex = FMath::RandRange(0, TANavesEnemigas.Num() - 1);
			ANaveEnemiga* NaveEnemigaAEliminar = TANavesEnemigas[RandomIndex];
			TANavesEnemigas.Remove(NaveEnemigaAEliminar);
			TMPosicionesNavesEnemigas.Remove(NaveEnemigaAEliminar);
			NaveEnemigaAEliminar->Destroy();
		}
	}
}

void AGalaga_USFX_LAB2GameMode::CrearEnemigosAleatoriamente()
{
	// Obtener el mundo
	UWorld* const World = GetWorld();
	if (World == nullptr)
	{
		return;
	}

	// Lista de clases de naves enemigas disponibles
	TArray<TSubclassOf<ANaveEnemiga>> ClasesNavesEnemigas;
	ClasesNavesEnemigas.Add(ANaveEnemigaCaza::StaticClass());
	ClasesNavesEnemigas.Add(ANaveEnemigaTransporte::StaticClass());
	ClasesNavesEnemigas.Add(ANaveEnemigaEspia::StaticClass());

	// Espacio deseado entre las naves en el eje Y
	float EspacioEntreNavesY = 100.0f;

	// Posición Y inicial
	float PosicionY = -50.0f;

	// Incremento en la posición Y para cada fila
	float IncrementoY = EspacioEntreNavesY * ClasesNavesEnemigas.Num();

	// Crear tres nuevas naves enemigas aleatoriamente
	for (int i = 0; i < 6; i++)
	{
		// Obtener una posición aleatoria desde TMPosicionesNavesEnemigas
		int32 RandomIndex = FMath::RandRange(0, TMPosicionesNavesEnemigas.Num() - 1);
		auto It = TMPosicionesNavesEnemigas.CreateIterator();
		for (int32 Index = 0; Index < RandomIndex; ++Index)
		{
			++It;
		}
		FVector PosicionNaveNueva = It->Value;

		// Ajustar la posición Y basada en el índice de iteración
		PosicionNaveNueva.Y = PosicionY + (i * IncrementoY);

		// Obtener una clase de nave enemiga aleatoria
		int32 RandomClassIndex = FMath::RandRange(0, ClasesNavesEnemigas.Num() - 1);
		TSubclassOf<ANaveEnemiga> ClaseNaveEnemiga = ClasesNavesEnemigas[RandomClassIndex];

		// Crear una nueva nave enemiga en la posición aleatoria
		if (ClaseNaveEnemiga)
		{
			ANaveEnemiga* NuevaNaveEnemiga = World->SpawnActor<ANaveEnemiga>(ClaseNaveEnemiga, PosicionNaveNueva, FRotator::ZeroRotator);
			if (NuevaNaveEnemiga)
			{
				// Agregar la nueva nave enemiga al mapa
				TMPosicionesNavesEnemigas.Add(NuevaNaveEnemiga, PosicionNaveNueva);
			}
		}
	}
}

void AGalaga_USFX_LAB2GameMode::StopGameActions()
{
	// Detener todas las acciones
	GetWorldTimerManager().ClearTimer(FTHEliminarEnemigosAleatorios); // Detiene la eliminación de enemigos aleatorios después de 40 segundos
	GetWorldTimerManager().ClearTimer(FTHCrearEnemigosAleatorios); // Detiene la creación de enemigos aleatorios después de 40 segundos

}

void AGalaga_USFX_LAB2GameMode::MostrarPosicionesNavesEnemigas()
{

}
