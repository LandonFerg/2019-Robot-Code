#pragma once

#include <ctre/Phoenix.h>
#include <frc/Timer.h>
#include "ControllerClass.h"

class Manipulator 
{
 public:
  Manipulator();
  frc::Timer* manipTimerTop;
  frc::Timer* manipTimerBot;
  void setManipulator(double, double);
  void manualManip(double, double);
  void runMotors();
  void runManip();
  void betterManual(double);
  void manipState();
  int nativeVelFromVel(int);

  void openManip();
  void loadCargo();
  void hatchPickup();
  void cargoHold();
  double manipSpeed;

  double topWaitTime;
  double botWaitTime;

  bool isRunningTop;
  bool isRunningBot;
 private:
  TalonSRX *topTalon;
  TalonSRX *botTalon;

};
