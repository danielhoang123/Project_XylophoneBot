#ifndef var__HH_
#define var__HH_

#define UNO_AND_CNC_SHIELD

#ifdef UNO_AND_CNC_SHIELD

#define STEP_PIN 2
#define DIR_PIN 5
#define EN_PIN 8
#define MODE_DRIVER 1
#define Z_ENDSTOP_PIN 11
#define ACTIVE_HOME 0

#else

#define STEP_PIN 2
#define DIR_PIN 3
#define EN_PIN 8
#define MODE_DRIVER 1
#define PIN_HOME_SEN 11
#define ACTIVE_HOME_SEN 1

#endif

#define START_POINT 0
#define END 600 * 16   // 400
#define SPEED 800 * 16 // 1200

#define G1_KEY 0
#define A1_KEY 120
#define B1_KEY 240
#define C2_KEY 360
#define D2_KEY 480
#define E2_KEY 600
#define F2_KEY 720
#define G2_KEY 840
#define A2_KEY 960
#define B2_KEY 1080
#define C3_KEY 1200
#define D3_KEY 1320
#define E3_KEY 1440
#define F3_KEY 1560
#define G3_KEY 1680

enum
{

    NOTE_G1 = 0,
    NOTE_A1,
    NOTE_B1,
    NOTE_C2,
    NOTE_D2,
    NOTE_E2,
    NOTE_F2,
    NOTE_G2,
    NOTE_A2,
    NOTE_B2,
    NOTE_C3,
    NOTE_D3,
    NOTE_E3,
    NOTE_F3,
    NOTE_G3,
    LAST_NOTE
};
//***SERVO VARIABES***//

#define SERVO_PIN 9
#define PRESSING_TIME 100
#endif
   