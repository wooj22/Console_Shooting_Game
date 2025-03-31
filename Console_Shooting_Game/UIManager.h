#pragma once
#include "Player.h"
#include "Boss.h"

extern const wchar_t* ui_playerHp;
extern const wchar_t* ui_playerPower;
extern const wchar_t* ui_playerSpeed;
extern const wchar_t* ui_bossHpBar;

void UpdatePlayerHpUi(Player* player);
void UpdatePlayerPowerUi(Player* player);
void UpdatePlayerSpeedUi(Player* player);
void UpdateBossHpBar(Boss* boss);

void UpdateAdviceLable();