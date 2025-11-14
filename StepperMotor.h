#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include "Engine.h"

class StepperMotor : public Engine {
private:
    int stepsPerRevolution;

public:
    StepperMotor();
    StepperMotor(const std::string& model, double voltage, double power, int steps);

    int getStepsPerRevolution() const;
    void setStepsPerRevolution(int steps);

    void input() override;
    void print() const override;
};

#endif
