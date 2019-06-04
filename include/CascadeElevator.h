#pragma once

#include <ctre/Phoenix.h>
#include <frc/Victor.h>

#include <iostream>

#include "ControllerClass.h"

#define cargo 0
#define hatch 1
#define none -1

using namespace std;

class CascadeElevator {
  private:
  TalonSRX * elevatorTalon;
  VictorSPX * elevatorVictorOne;
  VictorSPX * elevatorVictorTwo;
  VictorSPX * elevatorVictorThree; 
  
  int targetSide;

  public:
  CascadeElevator();
  void initElevator();
  void initTeleopElevator();
  double getTicks(double);
  void setElevatorHeightInches(double);

  void goToTopRocketForCargo(); // 64.5 inches from start position
  void goToMiddleRocketForCargo(); // 36.5 inches from start position
  void goToBottomRocketForCargo(); // 8.5 inches from start position
  
  void goToTopRocketForHatch(); // 56.0 inches from start position
  void goToMiddleRocketForHatch(); // 28.0 inches from start position
  void goToBottomRocketForHatch(); // 0 inches because we start there

  void cargoSideOfRocket();
  void hatchSideOfRocket();

  void controlElevator();

  void manualControlTest();

  void testElevator();
};
