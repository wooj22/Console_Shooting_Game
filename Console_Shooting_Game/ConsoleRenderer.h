#pragma once

#include <Windows.h>

// Foreground
#define FG_BLACK		0
//FG_BLACK 강조는 없음

#define FG_RED			FOREGROUND_RED|FOREGROUND_INTENSITY
#define FG_GREEN		FOREGROUND_GREEN|FOREGROUND_INTENSITY
#define FG_BLUE			FOREGROUND_BLUE|FOREGROUND_INTENSITY

#define FG_RED_DARK		FOREGROUND_RED
#define FG_GREEN_DARK	FOREGROUND_GREEN 
#define FG_BLUE_DARK	FOREGROUND_BLUE

#define FG_YELLOW		FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY
#define FG_SKY			FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define FG_PINK			FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY

#define FG_YELLOW_DARK	FOREGROUND_RED|FOREGROUND_GREEN
#define FG_SKY_DARK		FOREGROUND_GREEN|FOREGROUND_BLUE
#define FG_PINK_DARK	FOREGROUND_RED|FOREGROUND_BLUE

#define FG_GRAY			FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE
#define FG_WHITE		FG_GRAY|FOREGROUND_INTENSITY

// Background
#define BG_BLACK		0
//FG_BLACK 강조는 없음

#define BG_RED			BACKGROUND_RED|BACKGROUND_INTENSITY
#define BG_GREEN		BACKGROUND_GREEN|BACKGROUND_INTENSITY
#define BG_BLUE			BACKGROUND_BLUE|BACKGROUND_INTENSITY

#define BG_RED_DARK		BACKGROUND_RED
#define BG_GREEN_DARK	BACKGROUND_GREEN
#define BG_BLUE_DARK	BACKGROUND_BLUE

#define BG_YELLOW		BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY
#define BG_SKY			BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY
#define BG_PINK			BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_INTENSITY

#define BG_YELLOW_DARK	BACKGROUND_RED|BACKGROUND_GREEN
#define BG_SKY_DARK		BACKGROUND_GREEN|BACKGROUND_BLUE
#define BG_PINK_DARK	BACKGROUND_RED|BACKGROUND_BLUE

#define BG_GRAY			BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE
#define BG_WHITE		BG_GRAY|BACKGROUND_INTENSITY

// 더블버퍼링을 활용한 콘솔 출력 기능

namespace ConsoleRenderer
{
	void ScreenInit();	    // 콘솔 화면 초기화 (버퍼 2개 생성)
	void ScreenRelease();   // 버퍼 해제

	void ScreenFlipping();  // 콘솔 화면 갱신 (버퍼 전환)
	void ScreenClear();     // 콘솔 화면 지우기

	// x, y위치에 문자 ch를 출력하고 속성을 설정
	bool ScreenDrawChar(int x, int y, char ch, WORD attr);

	bool ScreenDrawStringW(int x, int y, const wchar_t* pStr, WORD attr);
	bool ScreenDrawChar(int x, int y, wchar_t ch, WORD attr);

	// 특정 위치 (x, y)에 문자열 pStr을 출력하고 속성을 설정
	bool ScreenDrawString(int x, int y, const char* pStr, WORD attr);

	// 콘솔 화면 전체의 속성을 attr 값으로 변경
	bool ScreenSetAttributes(WORD attr);

	// 콘솔 사이즈 get
	int ScreenWidth();
	int ScreenHeight();
};