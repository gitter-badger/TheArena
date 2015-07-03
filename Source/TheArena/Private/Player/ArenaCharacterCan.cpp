// Fill out your copyright notice in the Description page of Project Settings.

#include "TheArena.h"
#include "ArenaCharacterCan.h"

bool ArenaCharacterCan::Turn(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::LookUp(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::MoveForward(AArenaCharacter* character, AArenaPlayerController* controller, float Value)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& character->GetPlayerState()->GetPlayerState() != EPlayerState::Covering
		&& Value != 0.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::MoveRight(AArenaCharacter* character, AArenaPlayerController* controller, float Value)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& character->GetPlayerState()->GetPlayerState() != EPlayerState::Running
		&& Value != 0.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Run(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& !character->GetCharacterMovement()->IsFalling()
		&& !character->GetVelocity().IsZero()
		&& character->GetCharacterAttributes()->GetCurrentStamina() > 200
		&& character->GetPlayerState()->GetCombatState() != ECombatState::Passive)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool ArenaCharacterCan::Crouch(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& !character->GetCharacterMovement()->IsFalling()
		&& character->GetPlayerState()->GetPlayerState() != EPlayerState::Jumping
		&& character->GetPlayerState()->GetCombatState() != ECombatState::Passive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Jump(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& character->GetCharacterAttributes()->GetCurrentStamina() >= character->GetPlayerMovement()->GetJumpCost()
		&& !character->GetCharacterMovement()->IsFalling())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Cover(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& !character->GetCharacterMovement()->IsFalling()
		&& character->GetPlayerState()->GetCombatState() != ECombatState::Passive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Vault(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& !character->GetCharacterMovement()->IsFalling()
		&& character->GetPlayerState()->GetCombatState() != ECombatState::Passive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Equip(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& character->GetPlayerState()->GetCombatState() != ECombatState::Passive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Swap(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& character->GetPlayerState()->GetCombatState() == ECombatState::Aggressive
		&& character->GetCharacterEquipment()->GetCurrentWeapon()->GetWeaponState()->GetWeaponState() != EWeaponState::Equipping
		&& character->GetCharacterEquipment()->GetCurrentWeapon() != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Target(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& character->GetPlayerState()->GetCombatState() != ECombatState::Passive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Fire(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& character->GetPlayerState()->GetCombatState() != ECombatState::Passive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Reload(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& character->GetPlayerState()->GetCombatState() != ECombatState::Passive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Melee(AArenaCharacter* character, AArenaPlayerController* controller)
{
	if (controller
		&& controller->IsGameInputAllowed()
		&& character->GetPlayerState()->GetCombatState() != ECombatState::Passive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArenaCharacterCan::Die(AArenaCharacter* character)
{
	if (character->GetCharacterAttributes()->GetCurrentHealth() <= 0
		|| character->IsPendingKill()
		|| character->Role != ROLE_Authority
		|| character->GetWorld()->GetAuthGameMode() == NULL
		|| character->GetWorld()->GetAuthGameMode()->GetMatchState() == MatchState::LeavingMap)
	{
		return false;
	}

	return true;
}