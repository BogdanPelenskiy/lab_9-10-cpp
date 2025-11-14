#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include "Engine.h"

class ServoMotor : public Engine {
private:
    double angle;

public:
    ServoMotor();
    ServoMotor(const std::string& model, double voltage, double power, double angle);

    double getAngle() const;
    void setAngle(double angle);

    void input() override;
    void print() const override;
};

#endif
