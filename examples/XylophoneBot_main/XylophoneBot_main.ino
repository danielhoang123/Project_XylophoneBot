#include "hbq_MusicRobot_Controller.h"

MusicRobot mainMusicRobot;

void setup()
{

  mainMusicRobot.setServoPlayingAngle(35, 21);
  mainMusicRobot.setup();

  // Thêm nốt ở đây
  mainMusicRobot.addMusicNote(G1_KEY, 1);
  mainMusicRobot.addMusicNote(A1_KEY, 1);
  mainMusicRobot.addMusicNote(B1_KEY, 0.5);
  mainMusicRobot.addMusicNote(C2_KEY, 0.5);
  mainMusicRobot.addMusicNote(D2_KEY, 0.25);
  mainMusicRobot.addMusicNote(E2_KEY, 0.25);
  mainMusicRobot.addMusicNote(F2_KEY, 1);
  mainMusicRobot.addMusicNote(G2_KEY, 1);
  mainMusicRobot.addMusicNote(A2_KEY, 0.5);
  mainMusicRobot.addMusicNote(B2_KEY, 0.5);
  mainMusicRobot.addMusicNote(C3_KEY, 0.25);
  mainMusicRobot.addMusicNote(D3_KEY, 0.25);
  mainMusicRobot.addMusicNote(E3_KEY, 1);
  mainMusicRobot.addMusicNote(F3_KEY, 1);
  mainMusicRobot.addMusicNote(G3_KEY, 0.5);
}

void loop()
{
  // MusicRobot chạy
  mainMusicRobot.play();
}