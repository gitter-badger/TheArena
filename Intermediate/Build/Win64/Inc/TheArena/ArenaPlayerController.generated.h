// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef THEARENA_ArenaPlayerController_generated_h
#error "ArenaPlayerController.generated.h already included, missing '#pragma once' in ArenaPlayerController.h"
#endif
#define THEARENA_ArenaPlayerController_generated_h

extern THEARENA_API FName THEARENA_ClientEndOnlineGame;
extern THEARENA_API FName THEARENA_ClientGameStarted;
extern THEARENA_API FName THEARENA_ClientStartOnlineGame;
extern THEARENA_API FName THEARENA_ServerSuicide;
#define AArenaPlayerController_EVENTPARMS
#define AArenaPlayerController_RPC_WRAPPERS \
	DECLARE_FUNCTION(execSuicide) \
	{ \
		P_FINISH; \
		this->Suicide(); \
	} \
	DECLARE_FUNCTION(execSetGodMode) \
	{ \
		P_GET_UBOOL(bEnable); \
		P_FINISH; \
		this->SetGodMode(bEnable); \
	} \
	 virtual bool ServerSuicide_Validate(); \
	virtual void ServerSuicide_Implementation(); \
 \
	DECLARE_FUNCTION(execServerSuicide) \
	{ \
		P_FINISH; \
		if (!this->ServerSuicide_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerSuicide_Validate")); \
			return; \
		} \
		this->ServerSuicide_Implementation(); \
	} \
	DECLARE_FUNCTION(execGetOpenMenu) \
	{ \
		P_FINISH; \
		*(bool*)Result=this->GetOpenMenu(); \
	} \
	virtual void ClientStartOnlineGame_Implementation(); \
 \
	DECLARE_FUNCTION(execClientStartOnlineGame) \
	{ \
		P_FINISH; \
		this->ClientStartOnlineGame_Implementation(); \
	} \
	virtual void ClientGameStarted_Implementation(); \
 \
	DECLARE_FUNCTION(execClientGameStarted) \
	{ \
		P_FINISH; \
		this->ClientGameStarted_Implementation(); \
	} \
	virtual void ClientEndOnlineGame_Implementation(); \
 \
	DECLARE_FUNCTION(execClientEndOnlineGame) \
	{ \
		P_FINISH; \
		this->ClientEndOnlineGame_Implementation(); \
	}


#define AArenaPlayerController_CALLBACK_WRAPPERS
#define AArenaPlayerController_INCLASS \
	private: \
	static void StaticRegisterNativesAArenaPlayerController(); \
	friend THEARENA_API class UClass* Z_Construct_UClass_AArenaPlayerController(); \
	public: \
	DECLARE_CLASS(AArenaPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TheArena, NO_API) \
	/** Standard constructor, called after all reflected properties have been initialized */    NO_API AArenaPlayerController(const class FPostConstructInitializeProperties& PCIP); \
	DECLARE_SERIALIZER(AArenaPlayerController) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual void GetLifetimeReplicatedProps( TArray< FLifetimeProperty > & OutLifetimeProps ) const override;


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME AArenaPlayerController


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
AArenaPlayerController_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
public: \
	AArenaPlayerController_RPC_WRAPPERS \
	AArenaPlayerController_CALLBACK_WRAPPERS \
	AArenaPlayerController_INCLASS \
public:


