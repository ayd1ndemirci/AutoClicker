#include <iostream>
#include "AutoClicker.h"

int main() {
    char toggleKey;
    int maxCPS;

    std::cout << "Enter the key to toggle AutoClicker: ";
    std::cin >> toggleKey;
    std::cout << "Enter maximum CPS (click per second): ";
    std::cin >> maxCPS;

    AutoClicker autoClicker(maxCPS, std::toupper(toggleKey));

    std::cout << "AutoClicker started with maximum CPS: " << maxCPS << std::endl;
    autoClicker.startAutoClicker();

    return 0;
}
