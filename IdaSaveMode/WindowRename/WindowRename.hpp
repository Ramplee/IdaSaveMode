#pragma once
#include <string>
#include <vector>
#include "../WindowRename/WindowRename.hpp"
#include "../WindowDetection/WindowDetection.hpp"

class WindowRename {
public:
    static void RenameTargetWindows(const std::vector<WindowInfo>& windows);

private:
    static std::wstring GenerateRandomString(int length);
};