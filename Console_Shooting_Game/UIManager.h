#pragma once
#include "Player.h"

extern const wchar_t* ui_playerHp;
extern const wchar_t* ui_playerPower;
extern const wchar_t* ui_playerSpeed;

void UpdatePlayerHpUi(Player* player);
void UpdatePlayerPowerUi(Player* player);
void UpdatePlayerSpeedUi(Player* player);