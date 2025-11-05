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
    Engine(std::string model = "Unknown", double voltage = 0, double power = 0);
    virtual ~Engine();

    std::string getModel() const;
    double getVoltage() const;
    double getPower() const;

    void setModel(const std::string& model);
    void setVoltage(double voltage);
    void setPower(double power);

    virtual void inputData();
    virtual void showData() const;
    virtual double efficiency() const = 0;
};

#endif
