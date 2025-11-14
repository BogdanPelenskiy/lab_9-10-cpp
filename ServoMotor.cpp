#include "ServoMotor.h"
#include <iostream>

using namespace std;

ServoMotor::ServoMotor() : Engine(), angle(0) {}

ServoMotor::ServoMotor(const string& model, double voltage, double power, double angle)
    : Engine(model, voltage, power), angle(angle) {}

double ServoMotor::getAngle() const { return angle; }

void ServoMotor::setAngle(double a) { angle = a; }

void ServoMotor::input() {
    cout << "\n=== Ввід даних для серводвигуна ===\n";
    Engine::input();
    angle = getDoubleInput("Введіть кут повороту (0–180): ", 0, 180);
}

void ServoMotor::print() const {
    cout << "\n--- Інформація про двигун ---\n";
    Engine::print();
    cout << ", Кут повороту: " << angle << "°\n";
    cout << "ККД: " << getEfficiency() << " %\n";
}
