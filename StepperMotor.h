#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include "Engine.h"

class StepperMotor : public Engine {
private:
    int stepsPerRevolution;

public:
    StepperMotor(std::string model = "Stepper", double voltage = 0, double power = 0, int steps = 0);
    ~StepperMotor();

    void inputData() override;
    void showData() const override;
    double efficiency() const override;
};

#endif
