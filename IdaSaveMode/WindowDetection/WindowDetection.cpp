#include "WindowDetection.hpp"
#include <vector>

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    if (!IsWindowVisible(hwnd)) return TRUE;

    int length = GetWindowTextLengthW(hwnd);
    if (length == 0) return TRUE;

    std::vector<wchar_t> buffer(length + 1);
    GetWindowTextW(hwnd, buffer.data(), length + 1);
    std::wstring title(buffer.data());

    if (title == L"Program Manager") return TRUE;

    std::vector<WindowInfo>* windows = reinterpret_cast<std::vector<WindowInfo>*>(lParam);
    windows->push_back({ hwnd, title });

    return TRUE;
}

std::vector<WindowInfo> WindowDetection::GetAllVisibleWindows() {
    std::vector<WindowInfo> windows;
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&windows));
    return windows;
}