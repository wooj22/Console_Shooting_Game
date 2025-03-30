#include "UIManager.h"

const wchar_t* ui_playerHp = { L"⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" }; 
const wchar_t* ui_playerPower = { L"⬛" };

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