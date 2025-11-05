#include <iostream>
#include <vector>
#include "Engine.h"
#include "ServoMotor.h"
#include "StepperMotor.h"

int main() {
    std::vector<Engine*> engines;
    int n;

    std::cout << "Скільки двигунів додати? ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int choice;
        std::cout << "\n1 - Серводвигун\n2 - Кроковий двигун\nВаш вибір: ";
        std::cin >> choice;

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
        std::cout << "ККД: " << e->efficiency() << std::endl;
        std::cout << "-----------------------------\n";
    }

    for (auto e : engines)
        delete e;

    return 0;
}
