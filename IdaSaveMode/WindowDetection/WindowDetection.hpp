#pragma once
#include <windows.h>
#include <vector>
#include <string>

struct WindowInfo {
    HWND hwnd;
    std::wstring currentTitle;
};

class WindowDetection {
public:
    static std::vector<WindowInfo> GetAllVisibleWindows();
};