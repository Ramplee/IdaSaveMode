#include <iostream>
#include <random>
#include <algorithm>
#include "../WindowRename/WindowRename.hpp"

void WindowRename::RenameTargetWindows(const std::vector<WindowInfo>& windows) {
    int count = 0;
    std::wstring searchString = L"IDA";

    for (const auto& win : windows) {
        if (win.currentTitle.find(searchString) != std::wstring::npos) {

            std::wstring newRandomTitle = GenerateRandomString(15);

            BOOL result = SetWindowTextW(win.hwnd, newRandomTitle.c_str());

            if (result) {
                std::wcout << L"[MATCH] '" << win.currentTitle
                    << L"' Got renamed to -> '" << newRandomTitle << L"'\n";
                count++;
            }
        }
    }

    if (count == 0) {
        std::wcout << L"No Matches '" << searchString << L"'  Titel Found.\n";
    }
    else {
        std::wcout << L"Done! " << count << L" Window hidden.\n";
    }
}

std::wstring WindowRename::GenerateRandomString(int length) {
    static const wchar_t charset[] =
        L"0123456789"
        L"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        L"abcdefghijklmnopqrstuvwxyz";

    static std::mt19937 rg{ std::random_device{}() };
    static std::uniform_int_distribution<size_t> pick(0, sizeof(charset) / sizeof(wchar_t) - 2);

    std::wstring s;
    s.reserve(length);
    for (int i = 0; i < length; ++i) {
        s += charset[pick(rg)];
    }
    return s;
}