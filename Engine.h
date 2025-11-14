#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <iostream>

class Engine {
protected:
    std::string model;
    double voltage;
    double power;

public:
    Engine();
    Engine(const std::string& model, double voltage, double power);
    virtual ~Engine();

    // Гетери
    std::string getModel() const;
    double getVoltage() const;
    double getPower() const;

    // Сетери
    void setModel(const std::string& model);
    void setVoltage(double voltage);
    void setPower(double power);

    // Віртуальні методи
    virtual void input();
    virtual void print() const;

    // Розрахунок ККД
    double getEfficiency() const;
};

// Глобальні функції валідованого вводу
int getIntInput(const std::string& prompt, int minValue, int maxValue);
double getDoubleInput(const std::string& prompt, double minValue, double maxValue);
std::string getStringInput(const std::string& prompt, int maxLength);

#endif
