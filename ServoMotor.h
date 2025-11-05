#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include "Engine.h"

class ServoMotor : public Engine {
private:
    double angle;

public:
    ServoMotor(std::string model = "Servo", double voltage = 0, double power = 0, double angle = 0);
    ~ServoMotor();

    void inputData() override;
    void showData() const override;
    double efficiency() const override;
};

#endif
