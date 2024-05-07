#include "hbq_MusicRobot_Servo.h"

void MusicRobot_Servo::addServo(Servo *p_pa_Servo)
{
    MusicServo = p_pa_Servo;
}

void MusicRobot_Servo::setup(uint8_t pa_ServoPin)
{
    MusicServo->attach(pa_ServoPin);
    MusicServo->write(servoPosIdle);
}

void MusicRobot_Servo::start()
{
    setState(SERVO_STATE_PRESS);
}

void MusicRobot_Servo::loop()
{
    switch (getState())
    {
    case SERVO_STATE_PRESS:

        MusicServo->write(servoPosEnd);
        kDelay(PRESSING_TIME);
        setState(SERVO_STATE_RELEASE);

        break;
    case SERVO_STATE_RELEASE:

        MusicServo->write(servoPosIdle);
        kDelay(0);
        setState(SERVO_STATE_IDLE);

        break;
    case SERVO_STATE_IDLE:

        setStateIdle();

    default:
        break;
    }
}

void MusicRobot_Servo::setServoPosition(uint8_t pa_Servo_pressPosition, uint8_t pa_Servo_standbyPosition)
{
    servoPosIdle = pa_Servo_standbyPosition;
    servoPosEnd = pa_Servo_pressPosition;
}