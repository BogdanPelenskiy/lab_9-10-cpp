#pragma once
#include "Engine.h"

class StepperMotor : public Engine {
    int steps; // кроків на оберт
public:
    void inputData() override {
        Engine::inputData();
        steps = (int)getValidatedDouble("Введіть кількість кроків на оберт (1–10000): ", 1, 10000);
    }

    void showData() const override {
        std::cout << "Тип: Кроковий двигун\n";
        Engine::showData();
        std::cout << "Кроків на оберт: " << steps << "\n";
    }

    double efficiency() const override {
        return (voltage != 0) ? (power / voltage) : 0;
    }
};
