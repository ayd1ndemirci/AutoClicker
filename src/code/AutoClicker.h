#ifndef AUTOCLICKER_H
#define AUTOCLICKER_H

#include <windows.h>

class AutoClicker {
public:
    AutoClicker(int maxCPS, char toggleKey);
    void displayMenu();
    void startAutoClicker();

private:
    bool clickEnabled;
    int clickDelay;
    char toggleKey;
};

#endif