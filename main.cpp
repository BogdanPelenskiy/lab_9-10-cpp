#include <iostream>
#include <vector>
#include <limits>
#include "Engine.h"
#include "ServoMotor.h"
#include "StepperMotor.h"
#include <climits>


int getIntInput(const std::string& prompt, int minValue = INT_MIN, int maxValue = INT_MAX) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value < minValue || value > maxValue) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Помилка! Введіть число";
            if (minValue != INT_MIN && maxValue != INT_MAX)
                std::cout << " (" << minValue << "–" << maxValue << ")";
            std::cout << ".\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}


int getIntInput(const std::string& prompt, int minValue = INT_MIN, int maxValue = INT_MAX) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value < minValue || value > maxValue) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Помилка! Введіть коректне число";
            if (minValue != INT_MIN && maxValue != INT_MAX)
                std::cout << " (" << minValue << "–" << maxValue << ")";
            std::cout << ".\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    std::vector<Engine*> engines;
    int n = getIntInput("Скільки двигунів додати? ", 1);

    for (int i = 0; i < n; ++i) {
        std::cout << "\n1 - Серводвигун\n2 - Кроковий двигун\n";
        int choice = getIntInput("Ваш вибір: ", 1, 2);

        Engine* e = nullptr;
        if (choice == 1)
            e = new ServoMotor();
        else
            e = new StepperMotor();

        e->inputData();
        engines.push_back(e);
    }

    std::cout << "\n--- Інформація про двигуни ---\n";
    for (auto e : engines) {
        e->showData();
        std::cout << "ККД: " << e->efficiency() << "\n";
        std::cout << "-----------------------------\n";
    }

    
    for (auto e : engines)
        delete e;

    std::cout << "\nКінець програми.\n";
    return 0;
}
