// Fill out your copyright notice in the Description page of Project Settings.

#include "TheArena.h"

AArena_TeamDeathMatch::AArena_TeamDeathMatch(const class FObjectInitializer& PCIP) 
	: Super(PCIP)
{
	NumTeams = 2;
	bDelayedStart = true;
}

void AArena_TeamDeathMatch::InitNewPlayer(APlayerController* NewPlayer, const TSharedPtr<FUniqueNetId>& UniqueId, const FString& Options)
{
	Super::InitNewPlayer(NewPlayer, UniqueId, Options);

	// assign to team
	AArenaPlayerState* NewPlayerState = CastChecked<AArenaPlayerState>(NewPlayer->PlayerState);
	const int32 TeamNum = ChooseTeam(NewPlayerState);
	NewPlayerState->SetTeamNum(TeamNum);
}

void AArena_TeamDeathMatch::InitGameState()
{
	Super::InitGameState();

	AArenaGameState* const MyGameState = Cast<AArenaGameState>(GameState);
	if (MyGameState)
	{
		MyGameState->NumTeams = NumTeams;
	}
}

bool AArena_TeamDeathMatch::CanDealDamage(class AArenaPlayerState* DamageInstigator, class AArenaPlayerState* DamagedPlayer) const
{
	return DamageInstigator && DamagedPlayer && (DamagedPlayer == DamageInstigator || DamagedPlayer->GetTeamNum() != DamageInstigator->GetTeamNum());
}

int32 AArena_TeamDeathMatch::ChooseTeam(AArenaPlayerState* ForPlayerState) const
{
	TArray<int32> TeamBalance;
	TeamBalance.AddZeroed(NumTeams);

	// get current team balance
	for (int32 i = 0; i < GameState->PlayerArray.Num(); i++)
	{
		AArenaPlayerState const* const TestPlayerState = Cast<AArenaPlayerState>(GameState->PlayerArray[i]);
		if (TestPlayerState && TestPlayerState != ForPlayerState && TeamBalance.IsValidIndex(TestPlayerState->GetTeamNum()))
		{
			TeamBalance[TestPlayerState->GetTeamNum()]++;
		}
	}

	// find least populated one
	int32 BestTeamScore = TeamBalance[0];
	for (int32 i = 1; i < TeamBalance.Num(); i++)
	{
		if (BestTeamScore > TeamBalance[i])
		{
			BestTeamScore = TeamBalance[i];
		}
	}

	// there could be more than one...
	TArray<int32> BestTeams;
	for (int32 i = 0; i < TeamBalance.Num(); i++)
	{
		if (TeamBalance[i] == BestTeamScore)
		{
			BestTeams.Add(i);
		}
	}

	// get random from best list
	const int32 RandomBestTeam = BestTeams[FMath::RandHelper(BestTeams.Num())];
	return RandomBestTeam;
}

void AArena_TeamDeathMatch::DetermineMatchWinner()
{
	AArenaGameState const* const MyGameState = Cast<AArenaGameState>(GameState);
	int32 BestScore = MAX_uint32;
	int32 BestTeam = -1;
	int32 NumBestTeams = 1;

	for (int32 i = 0; i < MyGameState->TeamScores.Num(); i++)
	{
		const int32 TeamScore = MyGameState->TeamScores[i];
		if (BestScore < TeamScore)
		{
			BestScore = TeamScore;
			BestTeam = i;
			NumBestTeams = 1;
		}
		else if (BestScore == TeamScore)
		{
			NumBestTeams++;
		}
	}

	WinnerTeam = (NumBestTeams == 1) ? BestTeam : NumTeams;
}

bool AArena_TeamDeathMatch::IsWinner(class AArenaPlayerState* PlayerState) const
{
	return PlayerState && PlayerState->GetTeamNum() == WinnerTeam;
}

bool AArena_TeamDeathMatch::IsSpawnpointAllowed(APlayerStart* SpawnPoint, AController* Player) const
{
	if (Player)
	{
		AArenaTeamStart* TeamStart = Cast<AArenaTeamStart>(SpawnPoint);
		AArenaPlayerState* PlayerState = Cast<AArenaPlayerState>(Player->PlayerState);

		if (PlayerState && TeamStart && TeamStart->SpawnTeam != PlayerState->GetTeamNum())
		{
			return false;
		}
	}

	return Super::IsSpawnpointAllowed(SpawnPoint, Player);
}



