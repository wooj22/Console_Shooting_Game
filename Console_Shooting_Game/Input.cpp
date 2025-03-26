#include "Input.h"

namespace Input
{
    SHORT prevState[256] = { 0 };
    SHORT currState[256] = { 0 };

    // 키 input 상태 update
    void Update() {
        memcpy_s(prevState, sizeof(prevState), currState, sizeof(currState));
        for (int i = 0; i < 256; i++) {
            currState[i] = GetAsyncKeyState(i);
        }
    }

    // 눌려져있는 동안
    bool IsKeyDown(int vKey) {
        return (currState[vKey] & 0x8000) != 0;
    }

    // 누른 순간
    bool IsKeyPressed(int vKey) {
        return (!(prevState[vKey] & 0x8000) && (currState[vKey] & 0x8000));
    }

    // 떼는 순간
    bool IsKeyReleased(int vKey) {
        return ((prevState[vKey] & 0x8000) && !(currState[vKey] & 0x8000));
    }
}