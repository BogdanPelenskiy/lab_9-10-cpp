#include "StepperMotor.h"
#include <iostream>

StepperMotor::StepperMotor(std::string model, double voltage, double power, int steps)
    : Engine(model, voltage, power), stepsPerRevolution(steps) {}

StepperMotor::~StepperMotor() {
    std::cout << "Деструктор StepperMotor для " << model << std::endl;
}

void StepperMotor::inputData() {
    Engine::inputData();
    std::cout << "Введіть кількість кроків на один оберт: ";
    std::cin >> stepsPerRevolution;
}

void StepperMotor::showData() const {
    Engine::showData();
    std::cout << ", Кроків на оберт: " << stepsPerRevolution << std::endl;
}

double StepperMotor::efficiency() const {
    return power / (voltage * stepsPerRevolution / 1000.0);
}
