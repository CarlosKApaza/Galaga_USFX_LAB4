// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaKamikaze.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB2_API ANaveEnemigaKamikaze : public ANaveEnemiga
{
	GENERATED_BODY()
private:
	float DimensionDestruccion;
	float TiempoVida;
	float TiempoVidaMaximo;
public:
	//getters
	FORCEINLINE float GetDimensionOcuapda() const { return DimensionDestruccion; }
	FORCEINLINE float GetTiempoVida() const { return TiempoVida; }
	FORCEINLINE float GetTiempoVidaMaximo() const { return TiempoVidaMaximo; }
	//setters
	FORCEINLINE void SetDimensionOcuapda(float _dimensionDestruccion) { DimensionDestruccion = _dimensionDestruccion; }
	FORCEINLINE void SetTiempoVida(float tiempo) { TiempoVida = tiempo; }
	FORCEINLINE void SetTiempoVidaMaximo(float _tiempo) { TiempoVidaMaximo = _tiempo; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ANaveEnemigaKamikaze();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Mover(float DeltaTime);
	virtual void Destruirse(float dimension, float tiempo);
};
