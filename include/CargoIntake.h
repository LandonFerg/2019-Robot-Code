#pragma once

#include <ctre/Phoenix.h>

#include "ControllerClass.h"

#include <iostream>

using namespace std;
using namespace frc;

class CargoIntake 
{
  public:
  CargoIntake();

  void initCargoIntake();

  double getTicks(double);

  void moveArmUp(); // 90 degrees
  void moveArmDown(); // 0 degrees

  void intakeBall();

  void initTeleopCargoIntake();

  void controlArmPosition();

  void manualArmPosition();

  void testGoUp();

  void setZero();

  private:
  VictorSPX * rollerVictor;

  VictorSPX * positionVictor;
  TalonSRX * positionTalon;

  int iPositionMode;

  int direction;
};
