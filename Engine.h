#pragma once
#include <iostream>
#include <string>
#include <limits>

class Engine {
protected:
    std::string model;
    double power;   // потужність, Вт
    double voltage; // напруга, В
public:
    virtual ~Engine() {}

    // універсальна функція для безпечного введення чисел
    double getValidatedDouble(const std::string& prompt, double minVal = 0.0, double maxVal = 1e6) {
        double val;
        while (true) {
            std::cout << prompt;
            std::cin >> val;
            if (std::cin.fail() || val < minVal || val > maxVal) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Помилка! Введіть число в діапазоні [" << minVal << ", " << maxVal << "].\n";
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return val;
            }
        }
    }

    virtual void inputData() {
        std::cout << "Введіть модель двигуна: ";
        std::getline(std::cin >> std::ws, model); // дозволяє багатослівні назви

        power = getValidatedDouble("Введіть потужність (Вт): ", 0.1);
        voltage = getValidatedDouble("Введіть напругу (В): ", 0.1);
    }

    virtual void showData() const {
        std::cout << "Модель: " << model << "\n"
                  << "Потужність: " << power << " Вт\n"
                  << "Напруга: " << voltage << " В\n";
    }

    virtual double efficiency() const = 0;
};
