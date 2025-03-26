#pragma once

#include <Windows.h>

namespace Input
{
    void Update();                  // 키 input 상태 update
    bool IsKeyDown(int vKey);       // 눌려져있는 동안
    bool IsKeyPressed(int vKey);    // 누른 순간
    bool IsKeyReleased(int vKey);   // 떼는 순간
}