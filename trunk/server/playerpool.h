//----------------------------------------------------
//
// GPL code license:
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
//----------------------------------------------------
//
// VC:MP Multiplayer Modification For GTA:VC
// Copyright 2004-2005 SA:MP team
//
// File Author: kyeman
//
//----------------------------------------------------

#pragma once

#define INVALID_PLAYER_ID 255

#define VALID_KILL		  1
#define TEAM_KILL		  2
#define SELF_KILL		  3

//----------------------------------------------------

class CPlayerPool
{
private:
	
	BOOL	m_bPlayerSlotState[MAX_PLAYERS];
	CPlayer *m_pPlayers[MAX_PLAYERS];
	CHAR	m_szPlayerName[MAX_PLAYERS][MAX_PLAYER_NAME+1];
	int		m_iPlayerScore[MAX_PLAYERS];
	BOOL	m_bIsAnAdmin[MAX_PLAYERS];
public:
	
	CPlayerPool();
	~CPlayerPool();

	void Process();

	BOOL New(BYTE byteSystemAddress, PCHAR szPlayerName);
	BOOL Delete(BYTE byteSystemAddress, BYTE byteReason);
		
	// Retrieve a player
	CPlayer* GetAt(BYTE byteSystemAddress) {
		if(byteSystemAddress > MAX_PLAYERS) { return NULL; }
		return m_pPlayers[byteSystemAddress];
	};

	// Find out if the slot is inuse.
	BOOL GetSlotState(BYTE byteSystemAddress) {
		if(byteSystemAddress > MAX_PLAYERS) { return FALSE; }
		return m_bPlayerSlotState[byteSystemAddress];
	};

	PCHAR GetPlayerName(BYTE byteSystemAddress) { return m_szPlayerName[byteSystemAddress]; };

	BYTE AddResponsibleDeath(BYTE byteWhoKilled, BYTE byteWhoDied);
	float GetDistanceFromPlayerToPlayer(BYTE bytePlayer1, BYTE bytePlayer2);

	void SetAdmin(BYTE byteSystemAddress) { m_bIsAnAdmin[byteSystemAddress] = TRUE; };
	BOOL IsAdmin(BYTE byteSystemAddress) { return m_bIsAnAdmin[byteSystemAddress]; };

	int GetScore(BYTE byteSystemAddress) { return m_iPlayerScore[byteSystemAddress]; };

	BOOL IsNickInUse(PCHAR szNick);
	BOOL IsConnected(BYTE byteSystemAddress);

	int GetPlayerCount() {
		BYTE x=0,count=0;
		while(x!=MAX_PLAYERS) {
			if(GetSlotState(x)) count++;
			x++;
		}
		return (int)count;
	};
};

//----------------------------------------------------
