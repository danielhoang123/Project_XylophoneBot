#include "hbq_MusicRobot_StepperMotor.h"

void MusicRobot_StepperMotor::addStepper(AccelStepper *pa_Stepper)
{
    this->p_musicStepper = pa_Stepper;
}

void MusicRobot_StepperMotor::setup(uint8_t pa_EN_PIN, uint8_t pa_LIMIT_SWITCH)
{
    // EN pin go to LOW
    pinMode(pa_EN_PIN, OUTPUT);
    digitalWrite(pa_EN_PIN, LOW);

    // Setup limit switch pin
    pinMode(pa_LIMIT_SWITCH, INPUT_PULLUP);

    // state 1
    this->p_musicStepper->setMaxSpeed(stepSpeedMax / 3);
    this->p_musicStepper->setAcceleration(stepAccel);
    this->p_musicStepper->moveTo(-10000);
    while (digitalRead(Z_ENDSTOP_PIN) != ACTIVE_HOME)
    {
        this->p_musicStepper->run();
    }
    this->p_musicStepper->moveTo(10000);
    while (digitalRead(Z_ENDSTOP_PIN) == ACTIVE_HOME)
    {
        this->p_musicStepper->run();
    }

    // state 2
    this->p_musicStepper->setMaxSpeed(stepSpeedMax);
    this->p_musicStepper->setAcceleration(stepAccel);
    this->p_musicStepper->stop();
    this->p_musicStepper->setCurrentPosition(START_POINT);
}

void MusicRobot_StepperMotor::start()
{
    setState(STEPPER_START_RUNNING);
}

int MusicRobot_StepperMotor::setPosition(int pa_Position)
{
    stepPos = pa_Position;
}

void MusicRobot_StepperMotor::loop()
{
    switch (getState())
    {
    case STEPPER_START_RUNNING:

        this->p_musicStepper->moveTo(stepPos);

        setState(STEPPER_WHILE_RUNNING);

        break;

    case STEPPER_WHILE_RUNNING:

        if (this->p_musicStepper->currentPosition() == stepPos)
        {
            setStateIdle();
        }

        break;
        
    default:
        break;
    }
}
