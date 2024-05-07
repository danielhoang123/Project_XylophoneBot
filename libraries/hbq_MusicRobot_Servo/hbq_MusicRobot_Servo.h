#ifndef hbq_MusicRobot_Servo_H
#define hbq_MusicRobot_Servo_H

#include "hbq_var_Xylophone.h"
#include "Arduino.h"
#include "Servo.h"
#include "kxnTask.h"

CREATE_TASK_STATE(MusicRobot_Servo)

SERVO_STATE_PRESS,
SERVO_STATE_RELEASE,
SERVO_STATE_IDLE

END

CREATE_TASK(MusicRobot_Servo)

Servo * MusicServo;

void addServo(Servo * p_pa_Servo);

void setup(uint8_t pa_ServoPin);

void start();

void loop();

void setServoPosition(uint8_t pa_Servo_PressPosition, uint8_t pa_Servo_standbyPosition);

String splitString(String v_G_motherString, String v_G_Command, String v_G_Start_symbol, String v_G_Stop_symbol, unsigned char v_G_Offset){
	unsigned char lenOfCommand=v_G_Command.length();
    unsigned char posOfCommand=v_G_motherString.indexOf(v_G_Command);
    int PosOfStartSymbol=v_G_motherString.indexOf(v_G_Start_symbol,posOfCommand+lenOfCommand);
	
    while(v_G_Offset>0){
        v_G_Offset--;
        PosOfStartSymbol=v_G_motherString.indexOf(v_G_Start_symbol,PosOfStartSymbol+1);
    }
	
    int PosOfStopSymbol=v_G_motherString.indexOf(v_G_Stop_symbol,PosOfStartSymbol+1);
	
	return v_G_motherString.substring(PosOfStartSymbol+1,PosOfStopSymbol);
}

private:

uint8_t servoPosIdle, servoPosEnd;

END

#endif