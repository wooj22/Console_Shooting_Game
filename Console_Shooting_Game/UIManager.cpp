#include "UIManager.h"

const wchar_t* ui_playerHp = { L"⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" }; 
const wchar_t* ui_playerPower = { L"⬛" };
const wchar_t* ui_playerSpeed = { L"⬛" };
const wchar_t* ui_bossHpBar = { L"▂▂▂▂" };
const wchar_t* ui_currentLevel = { L"▂▂▂▂" };

///  player hpUI update
void UpdatePlayerHpUi(Player* player) {
	int hpBox = player->hp / 10;

	switch (hpBox)
	{
	case 10:
		ui_playerHp = { L"⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" };
		break;
	case 9:
		ui_playerHp = { L"⬛⬛⬛⬛⬛⬛⬛⬛⬛" };
		break;
	case 8:
		ui_playerHp = { L"⬛⬛⬛⬛⬛⬛⬛⬛" };
		break;
	case 7:
		ui_playerHp = { L"⬛⬛⬛⬛⬛⬛⬛" };
		break;
	case 6:
		ui_playerHp = { L"⬛⬛⬛⬛⬛⬛" };
		break;
	case 5:
		ui_playerHp = { L"⬛⬛⬛⬛⬛" };
		break;
	case 4:
		ui_playerHp = { L"⬛⬛⬛⬛" };
		break;
	case 3:
		ui_playerHp = { L"⬛⬛⬛" };
		break;
	case 2:
		ui_playerHp = { L"⬛⬛" };
		break;
	case 1:
		ui_playerHp = { L"⬛" };
		break;
	case 0:
		ui_playerHp = { L"" };
		break;
	default:
		break;
	}
}

///  player powerUI update
void UpdatePlayerPowerUi(Player* player) {
	int powerBox = player->attackDamege / 10;

	switch (powerBox)
	{
	case 1:
		ui_playerPower = { L"⬛" };
		break;
	case 2:
		ui_playerPower = { L"⬛⬛" };
		break;
	case 3:
		ui_playerPower = { L"⬛⬛⬛" };
		break;
	case 4:
		ui_playerPower = { L"⬛⬛⬛⬛" };
		break;
	case 5:
		ui_playerPower = { L"⬛⬛⬛⬛⬛" };
		break;
	case 6:
		ui_playerPower = { L"⬛⬛⬛⬛⬛⬛" };
		break;
	case 7:
		ui_playerPower = { L"⬛⬛⬛⬛⬛⬛⬛" };
		break;
	case 8:
		ui_playerPower = { L"⬛⬛⬛⬛⬛⬛⬛⬛" };
		break;
	case 9:
		ui_playerPower = { L"⬛⬛⬛⬛⬛⬛⬛⬛⬛" };
		break;
	case 10:
		ui_playerPower = { L"⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" };
		break;
	default:
		break;
	}
}

///  player speedUI update
void UpdatePlayerSpeedUi(Player* player) {
	int speedBox = player->moveCycle * 100;

	switch (speedBox)
	{
	case 10:
		ui_playerSpeed = { L"⬛" };
		break;
	case 9:
		ui_playerSpeed = { L"⬛⬛" };
		break;
	case 8:
		ui_playerSpeed = { L"⬛⬛⬛" };
		break;
	case 7:
		ui_playerSpeed = { L"⬛⬛⬛⬛" };
		break;
	case 6:
		ui_playerSpeed = { L"⬛⬛⬛⬛⬛" };
		break;
	case 5:
		ui_playerSpeed = { L"⬛⬛⬛⬛⬛⬛" };
		break;
	case 4:
		ui_playerSpeed = { L"⬛⬛⬛⬛⬛⬛⬛" };
		break;
	case 3:
		ui_playerSpeed = { L"⬛⬛⬛⬛⬛⬛⬛⬛" };
		break;
	case 2:
		ui_playerSpeed = { L"⬛⬛⬛⬛⬛⬛⬛⬛⬛" };
		break;
	case 1:
		ui_playerSpeed = { L"⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" };
		break;
	default:
		break;
	}
}

///  boss hpBar update
void UpdateBossHpBar(Boss* boss) {
	// boss hp max : 10000
	if(boss->hp >= 7500)
		ui_bossHpBar = { L"▂▂▂▂" };
	else if (boss->hp >= 5000)
		ui_bossHpBar = { L"▂▂▂" };
	else if (boss->hp >= 2500)
		ui_bossHpBar = { L"▂▂" };
	else if (boss->hp > 0)
		ui_bossHpBar = { L"▂" };
	else
		ui_bossHpBar = { L"" };
}