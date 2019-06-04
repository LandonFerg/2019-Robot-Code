#pragma once

#include <ctre/Phoenix.h>
#include "ControllerClass.h"

class Drivetrain 
{
  public:
  Drivetrain();
  void drive(double,double);
  void initMotors();

  private:
  TalonSRX *leftTalon;
  TalonSRX *rightTalon;

  VictorSPX *leftVictor1;
  VictorSPX *rightVictor1;

  VictorSPX *leftVictor2;
  VictorSPX *rightVictor2;
};
