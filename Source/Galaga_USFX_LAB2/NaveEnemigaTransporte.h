// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB2_API ANaveEnemigaTransporte : public ANaveEnemiga
{
	GENERATED_BODY()
//private:
//	float Velocidad;
//	//FVector DireccionEscape;
//public:
//	//getters
//	FORCEINLINE float GetVelocidad() const { return Velocidad; }
//	//FORCEINLINE FVector GetDireccionEscape() const { return DireccionEscape; }
//	//setters
//	FORCEINLINE void SetVelocidad(float _velocidad) { Velocidad = _velocidad; }
//	//FORCEINLINE void SetDireccionEscape(FVector _direccion) { DireccionEscape = _direccion; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ANaveEnemigaTransporte();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Mover(float DeltaTime);
	//virtual void Escapar(float velocidadY, float posicion);
protected:
	UPROPERTY(EditAnywhere, Category = "Nave Transporte")
	float VelocidadYTransporte;
};

