// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef THEARENA_BTTask_HasLosTo_generated_h
#error "BTTask_HasLosTo.generated.h already included, missing '#pragma once' in BTTask_HasLosTo.h"
#endif
#define THEARENA_BTTask_HasLosTo_generated_h

#define UBTTask_HasLosTo_EVENTPARMS
#define UBTTask_HasLosTo_RPC_WRAPPERS
#define UBTTask_HasLosTo_CALLBACK_WRAPPERS
#define UBTTask_HasLosTo_INCLASS \
	private: \
	static void StaticRegisterNativesUBTTask_HasLosTo(); \
	friend THEARENA_API class UClass* Z_Construct_UClass_UBTTask_HasLosTo(); \
	public: \
	DECLARE_CLASS(UBTTask_HasLosTo, UBTDecorator, COMPILED_IN_FLAGS(0), 0, TheArena, NO_API) \
	/** Standard constructor, called after all reflected properties have been initialized */    NO_API UBTTask_HasLosTo(const class FPostConstructInitializeProperties& PCIP); \
	DECLARE_SERIALIZER(UBTTask_HasLosTo) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME UBTTask_HasLosTo


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
UBTTask_HasLosTo_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
public: \
	UBTTask_HasLosTo_RPC_WRAPPERS \
	UBTTask_HasLosTo_CALLBACK_WRAPPERS \
	UBTTask_HasLosTo_INCLASS \
public:


