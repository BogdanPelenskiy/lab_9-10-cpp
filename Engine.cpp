#include "Engine.h"
#include <limits>
#include <algorithm>

using namespace std;

Engine::Engine() : model(""), voltage(0.0), power(0.0) {}

Engine::Engine(const string& model, double voltage, double power)
    : model(model), voltage(voltage), power(power) {}

Engine::~Engine() {}

string Engine::getModel() const { return model; }
double Engine::getVoltage() const { return voltage; }
double Engine::getPower() const { return power; }

void Engine::setModel(const string& m) { model = m; }
void Engine::setVoltage(double v) { voltage = v; }
void Engine::setPower(double p) { power = p; }

// ===== Ввід =====
void Engine::input() {
    model = getStringInput("Введіть модель двигуна: ", 50);
    power = getDoubleInput("Введіть потужність (Вт, 0.1–10000): ", 0.1, 10000);
    voltage = getDoubleInput("Введіть напругу живлення (В, 1–1000): ", 1, 1000);
}

void Engine::print() const {
    cout << "Модель: " << model
         << ", Потужність: " << power << " Вт"
         << ", Напруга: " << voltage << " В";
}

double Engine::getEfficiency() const {
    double eff = 100.0 - (100.0 / (voltage + power));
    if (eff < 50) eff = 50;
    if (eff > 99.9) eff = 99.9;
    return eff;
}

// ======= Валідація =======

std::string getStringInput(const string& prompt, int maxLength) {
    string input;

    while (true) {
        cout << prompt;
        getline(cin >> ws, input);

        if (input.empty()) {
            cout << "Помилка: поле не може бути порожнім.\n";
            continue;
        }

        bool onlySpaces = all_of(input.begin(), input.end(), [](char c) { return isspace(c); });
        if (onlySpaces) {
            cout << "Помилка: не можна вводити лише пробіли.\n";
            continue;
        }

        if ((int)input.length() > maxLength) {
            cout << "Помилка: максимальна довжина — " << maxLength << " символів.\n";
            continue;
        }

        return input;
    }
}

int getIntInput(const string& prompt, int minValue, int maxValue) {
    int value;

    while (true) {
        cout << prompt;
        if (cin >> value && value >= minValue && value <= maxValue) {
            return value;
        }
        cout << "Помилка: введіть число в межах [" << minValue << "…" << maxValue << "].\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double getDoubleInput(const string& prompt, double minValue, double maxValue) {
    double value;

    while (true) {
        cout << prompt;
        if (cin >> value && value >= minValue && value <= maxValue) {
            return value;
        }
        cout << "Помилка: введіть число в межах [" << minValue << "…" << maxValue << "].\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
