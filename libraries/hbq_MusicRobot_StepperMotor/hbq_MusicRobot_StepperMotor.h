#ifndef hbq_MusicRobot_StepperMotor_H
#define hbq_MusicRobot_StepperMotor_H

#include "AccelStepper.h"
#include "hbq_var_Xylophone.h"
#include "Arduino.h"
#include "kxnTask.h"

CREATE_TASK_STATE(MusicRobot_StepperMotor)

STEPPER_START_RUNNING,
STEPPER_WHILE_RUNNING,
STEPPER_FINISH_RUNNING,
STEPPER_IDLE

END

CREATE_TASK(MusicRobot_StepperMotor)

AccelStepper *p_musicStepper;

float stepSpeedNormal = 1000; // 3500;//SPEED;
float stepSpeedMax = 2000;    // 2200;//497000;//4000;//SPEED;
float stepAccel = 20000;      // 250000;//3500;//SPEED/3        // 20000;//1600;

int stepPos = 1650;
int temp_Position;

void addStepper(AccelStepper *pa_Stepper);

void setup(uint8_t pa_EN_PIN, uint8_t pa_LIMIT_SWITCH);

void start();

int setPosition(int pa_Position);

void loop();

private:

bool finishRunning = 0;

END

#endif