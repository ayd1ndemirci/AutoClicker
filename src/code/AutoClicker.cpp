#include "AutoClicker.h"
#include <iostream>

AutoClicker::AutoClicker(int maxCPS, char toggleKey) {
    this->clickEnabled = false;
    this->toggleKey = toggleKey;
    this->clickDelay = 1000 / maxCPS;
}

void AutoClicker::displayMenu() {
    std::cout << "Enter the key to toggle AutoClicker: ";
}

void AutoClicker::startAutoClicker() {
    POINT p;
    while (true) {
        if (!clickEnabled && GetAsyncKeyState(static_cast<int>(toggleKey)) & 0x8000) {
            clickEnabled = true;
            Sleep(200);
        }

        if (clickEnabled && GetAsyncKeyState(static_cast<int>(toggleKey)) & 0x8000) {
            clickEnabled = false;
            Sleep(200);
        }

        GetCursorPos(&p);
        if (clickEnabled && p.x < 20 && p.y < 20) {
            clickEnabled = false;
        }

        if (clickEnabled) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(clickDelay);
        }
    }
}