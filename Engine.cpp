#include "Engine.h"

Engine::Engine(std::string model, double voltage, double power)
    : model(model), voltage(voltage), power(power) {}

Engine::~Engine() {
    std::cout << "Деструктор Engine для " << model << std::endl;
}

std::string Engine::getModel() const { return model; }
double Engine::getVoltage() const { return voltage; }
double Engine::getPower() const { return power; }

void Engine::setModel(const std::string& m) { model = m; }

void Engine::setVoltage(double v) {
    if (v <= 0) std::cout << "Помилка: напруга повинна бути > 0\n";
    else voltage = v;
}

void Engine::setPower(double p) {
    if (p <= 0) std::cout << "Помилка: потужність повинна бути > 0\n";
    else power = p;
}

void Engine::inputData() {
    std::cout << "Введіть модель двигуна: ";
    std::cin >> model;
    std::cout << "Введіть напругу (В): ";
    std::cin >> voltage;
    std::cout << "Введіть потужність (Вт): ";
    std::cin >> power;
}

void Engine::showData() const {
    std::cout << "Модель: " << model
              << ", Напруга: " << voltage << " В, Потужність: "
              << power << " Вт";
}
