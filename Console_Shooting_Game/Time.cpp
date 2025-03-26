#include <Windows.h>

namespace Time
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER prevCounter;
    LARGE_INTEGER currentCounter;
    LARGE_INTEGER initCounter;
    float deltaTime;

    void Initialize()
    {
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&initCounter);
        prevCounter = initCounter;
    }

    void UpdateTime()
    {
        QueryPerformanceCounter(&currentCounter);
        deltaTime = static_cast<float>(currentCounter.QuadPart - prevCounter.QuadPart) / frequency.QuadPart;
        prevCounter = currentCounter;
    }

    float GetElapsedTime()
    {
        return deltaTime;
    }

    float GetTotalTime()
    {
        float totalTime = static_cast<float>(currentCounter.QuadPart - initCounter.QuadPart) / frequency.QuadPart;
        return totalTime;
    }
}