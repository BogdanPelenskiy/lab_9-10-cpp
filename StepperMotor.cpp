#include "StepperMotor.h"
#include <iostream>

using namespace std;

StepperMotor::StepperMotor()
    : Engine(), stepsPerRevolution(0) {}

StepperMotor::StepperMotor(const string& model, double voltage, double power, int steps)
    : Engine(model, voltage, power), stepsPerRevolution(steps) {}

int StepperMotor::getStepsPerRevolution() const {
    return stepsPerRevolution;
}

void StepperMotor::setStepsPerRevolution(int steps) {
    stepsPerRevolution = steps;
}

void StepperMotor::input() {
    cout << "\n=== Ввід даних для крокового двигуна ===\n";
    Engine::input();
    stepsPerRevolution = getIntInput("Введіть кількість кроків на оберт (1–50000): ", 1, 50000);
}

void StepperMotor::print() const {
    cout << "\n--- Інформація про двигун ---\n";
    Engine::print();
    cout << ", Кроків на оберт: " << stepsPerRevolution << "\n";
    cout << "ККД: " << getEfficiency() << " %\n";
}
