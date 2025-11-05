#include "ServoMotor.h"
#include <iostream>

ServoMotor::ServoMotor(std::string model, double voltage, double power, double angle)
    : Engine(model, voltage, power), angle(angle) {}

ServoMotor::~ServoMotor() {
    std::cout << "Деструктор ServoMotor для " << model << std::endl;
}

void ServoMotor::inputData() {
    Engine::inputData();
    std::cout << "Введіть максимальний кут повороту (градуси): ";
    std::cin >> angle;
}

void ServoMotor::showData() const {
    Engine::showData();
    std::cout << ", Кут повороту: " << angle << "°" << std::endl;
}

double ServoMotor::efficiency() const {
    return power / (voltage * 10);
}
