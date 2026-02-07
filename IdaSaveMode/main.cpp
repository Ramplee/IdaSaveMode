#include <iostream>
#include <string>
#include "WindowDetection/WindowDetection.hpp"
#include "WindowRename/WindowRename.hpp"

#pragma comment(lib, "User32.lib")

int main() {
    SetConsoleTitleW(L"Window Changer Tool");

    std::string input;
    bool running = true;

    std::cout << "=== IDA UD TOOl ===\n";
    std::cout << "Press 1 to be UD \n";
    std::cout << "Write 'exit' to exit.\n";
    std::cout << "--------------------------------------\n";

    while (running) {
        std::cout << "> ";
        std::cin >> input;

        if (input == "1") {
            std::cout << "Scanning Windows...\n";

            std::vector<WindowInfo> windows = WindowDetection::GetAllVisibleWindows();

            WindowRename::RenameTargetWindows(windows);

        }
        else if (input == "Exit") {
            running = false;
        }
        else {
            std::cout << "Unknown.\n";
        }
    }

    return 0;
}