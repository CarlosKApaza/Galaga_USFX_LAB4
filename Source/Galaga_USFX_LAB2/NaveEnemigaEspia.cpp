// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"

void ANaveEnemigaEspia::BeginPlay()
{
	Super::BeginPlay();
}

ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	VelocidadYEspia = -400.0f;
}

void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}
void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	//Obtenemos la posición actual del actor
	FVector PosicionActual = GetActorLocation();

	// Generamos nuevas coordenadas X 
	float NuevaX = 0.0f; // No se mueve en el eje X

	// Calculamos la nueva posición en el eje Y
	float NuevaPosicionY = PosicionActual.Y + (VelocidadYEspia * DeltaTime);

	// Verificamos si la nave ha alcanzado el límite superior o inferior
	if (NuevaPosicionY <= -1900.0f)
	{
		// Cambiamos la dirección multiplicando por -1
		VelocidadYEspia *= -1.0f;
	}
	else if (NuevaPosicionY >= 1900.0f)
	{
		// Cambiamos la dirección multiplicando por -1
		VelocidadYEspia *= -1.0f;
	}
	// Establecemos la nueva posición del actor
	SetActorLocation(FVector(PosicionActual.X + NuevaX, NuevaPosicionY, PosicionActual.Z));
}

//void ANaveEnemigaEspia::Mover(float DeltaTime)
//{
//	//Obtenemos la posición actual del actor
//	FVector PosicionActual = GetActorLocation();
//
//	//Genera nuevas coordenadas X e Y aleatorias
//	float NuevaX = 0.0f;
//	//float NuevaX = FMath::RandRange(150.0f, -150.0f) * DeltaTime; // Para que la nave se mueva arriba y abajo
//	float NuevaY = FMath::RandRange(.0f, -200.0f) * DeltaTime;  // Para que la nave se mueva a la izquierda y derecha
//
//	//float Velocidady = 800.0f; // Velocidad constante en el eje X
//	//float Nuevay = Velocidady * DeltaTime;
//
//	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
//	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);
//
//	//Establece la nueva posición del actor
//	SetActorLocation(NuevaPosicion);
//}
