#pragma once
#include "Engine.h"

class ServoMotor : public Engine {
    double angle; // кут повороту
public:
    void inputData() override {
        Engine::inputData();
        angle = getValidatedDouble("Введіть кут повороту (0–180°): ", 0, 180);
    }

    void showData() const override {
        std::cout << "Тип: Серводвигун\n";
        Engine::showData();
        std::cout << "Кут повороту: " << angle << "°\n";
    }

    double efficiency() const override {
        // уникнення ділення на 0
        return (voltage != 0) ? (power / voltage) : 0;
    }
};
