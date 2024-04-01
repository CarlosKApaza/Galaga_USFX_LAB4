// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB2/NaveEnemigaTransporte.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveEnemigaTransporte() {}
// Cross Module References
	GALAGA_USFX_LAB2_API UClass* Z_Construct_UClass_ANaveEnemigaTransporte_NoRegister();
	GALAGA_USFX_LAB2_API UClass* Z_Construct_UClass_ANaveEnemigaTransporte();
	GALAGA_USFX_LAB2_API UClass* Z_Construct_UClass_ANaveEnemiga();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB2();
// End Cross Module References
	void ANaveEnemigaTransporte::StaticRegisterNativesANaveEnemigaTransporte()
	{
	}
	UClass* Z_Construct_UClass_ANaveEnemigaTransporte_NoRegister()
	{
		return ANaveEnemigaTransporte::StaticClass();
	}
	struct Z_Construct_UClass_ANaveEnemigaTransporte_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VelocidadYTransporte_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VelocidadYTransporte;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANaveEnemigaTransporte_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANaveEnemiga,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB2,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANaveEnemigaTransporte_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "NaveEnemigaTransporte.h" },
		{ "ModuleRelativePath", "NaveEnemigaTransporte.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANaveEnemigaTransporte_Statics::NewProp_VelocidadYTransporte_MetaData[] = {
		{ "Category", "Nave Transporte" },
		{ "ModuleRelativePath", "NaveEnemigaTransporte.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANaveEnemigaTransporte_Statics::NewProp_VelocidadYTransporte = { "VelocidadYTransporte", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANaveEnemigaTransporte, VelocidadYTransporte), METADATA_PARAMS(Z_Construct_UClass_ANaveEnemigaTransporte_Statics::NewProp_VelocidadYTransporte_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANaveEnemigaTransporte_Statics::NewProp_VelocidadYTransporte_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANaveEnemigaTransporte_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANaveEnemigaTransporte_Statics::NewProp_VelocidadYTransporte,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANaveEnemigaTransporte_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANaveEnemigaTransporte>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANaveEnemigaTransporte_Statics::ClassParams = {
		&ANaveEnemigaTransporte::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANaveEnemigaTransporte_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANaveEnemigaTransporte_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ANaveEnemigaTransporte_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANaveEnemigaTransporte_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANaveEnemigaTransporte()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANaveEnemigaTransporte_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANaveEnemigaTransporte, 3107760881);
	template<> GALAGA_USFX_LAB2_API UClass* StaticClass<ANaveEnemigaTransporte>()
	{
		return ANaveEnemigaTransporte::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANaveEnemigaTransporte(Z_Construct_UClass_ANaveEnemigaTransporte, &ANaveEnemigaTransporte::StaticClass, TEXT("/Script/Galaga_USFX_LAB2"), TEXT("ANaveEnemigaTransporte"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANaveEnemigaTransporte);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
