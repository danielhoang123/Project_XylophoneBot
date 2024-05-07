#ifndef hbq_MusicRobot_Controller__H
#define hbq_MusicRobot_Controller__H

#include "hbq_MusicRobot_StepperMotor.h"
#include "hbq_MusicRobot_Servo.h"
#include "hbq_MusicRobot_StepperServo_Controller.h"
#include "hbq_QueueKeyValue_Xylophone.h"
#include "kxnTask.h"

AccelStepper mainStepper(MODE_DRIVER, STEP_PIN, DIR_PIN);

MusicRobot_StepperMotor myStepperController;

Servo mainServo;

MusicRobot_Servo myServoController;

StepperServo_Controller myController;

DECLARE_QUEUE(Schedule, uint16_t, float, 100)

DEFINE_QUEUE(Schedule, uint16_t, float, 100)

STRUCT_QUEUE(Schedule) kv;

CREATE_TASK(MusicRobot)

void setup()
{

    myServoController.addServo(&mainServo);

    myServoController.setup(SERVO_PIN);

    myStepperController.addStepper(&mainStepper);

    myStepperController.setup(EN_PIN, Z_ENDSTOP_PIN);

    myStepperController.start();

    myController.begin(&myStepperController, &myServoController);
}

void play()
{
    unsigned long currentMillis = millis();

    myStepperController.run(currentMillis);

    myServoController.run(currentMillis);

    myController.run(currentMillis);

    mainStepper.run();

    runQueue();
}

// void Serial_Testing()
// {
//     if (Serial.available())
//     {
//         String kk = Serial.readStringUntil('\n');
//         Serial.println(kk);

//         if (kk.indexOf("RC") > -1) // RC*90#40.
//         {
//             uint8_t pressPosition = myServoController.splitString(kk, "RC", " ", " ", 0).toInt();

//             uint8_t standbyPosition = myServoController.splitString(kk, "RC", " ", " ", 1).toInt();

//             uint8_t servoDelay = myServoController.splitString(kk, "RC", " ", " ", 2).toInt();

//             myServoController.setServoPosition(pressPosition, standbyPosition);
//         }
//     }
// }

void addMusicNote(uint16_t key, float time)
{
    ENQUEUE(Schedule, key, time * oneNote);
}

void runQueue()
{
    unsigned long queueMillis = millis();

    if (myController.isStateIdle())
    {
        if (queueMillis - queueStartMillis >= queueInterval)
        {
            queueStartMillis = queueMillis;

            if (GETQUEUESIZE(Schedule) > 0)
            {
                kv = DEQUEUE(Schedule);

                queueInterval = kv.value;

                myController.musicStart(kv.key);
            }
        }
    }
}

void setServoPlayingAngle(uint8_t readyAngle, uint8_t pressedAngle)
{
    myServoController.setServoPosition(pressedAngle, readyAngle);
}

private:

unsigned long queueStartMillis = 0;

long queueInterval = 500;

float oneNote = 1200.0;

END

#endif