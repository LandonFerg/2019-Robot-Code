#pragma once

#define A_Button 1
#define B_Button 2
#define Y_Button 4
#define X_Button 3
#define Right_Bumper 6
#define Left_Bumper 5
#define Right_Trigger 3
#define Left_Trigger 2
#define Start_Button 8
#define Back_Button 7

#include <frc/XboxController.h>
#include <frc/GenericHID.h>
#include <frc/Joystick.h>

using namespace frc;

class ControllerClass {

  private:
  // Xbox Controller
  frc::XboxController * Controller1;
  frc::XboxController * Controller2;

  // Button Panel
  frc::Joystick * StickA;
  frc::Joystick * StickB;

 public:
  ControllerClass();
  void ReadController1();
  void ReadController2();
  void Update();
  void GetPanel();

  // Xbox Controllers
  bool bAButtonRawC1;
  bool bBButtonRawC1;
  bool bXButtonRawC1;
  bool bYButtonRawC1;

  bool bAButtonPressedC1;
  bool bBButtonPressedC1;
  bool bXButtonPressedC1;
  bool bYButtonPressedC1;

  bool bAButtonReleasedC1;
  bool bBButtonReleasedC1;
  bool bXButtonReleasedC1;
  bool bYButtonReleasedC1;

  bool bAButtonPressedC2;
  bool bBButtonPressedC2;
  bool bXButtonPressedC2;
  bool bYButtonPressedC2;

  bool bAButtonReleasedC2;
  bool bBButtonReleasedC2;
  bool bXButtonReleasedC2;
  bool bYButtonReleasedC2;

  bool bAButtonRawC2;
  bool bBButtonRawC2;
  bool bXButtonRawC2;
  bool bYButtonRawC2;

  double dLeftStickXC1;
  double dLeftStickYC1;

  double dLeftStickXC2;
  double dLeftStickYC2;

  double dRightStickXC1;
  double dRightStickYC1;

  double dRightStickXC2;
  double dRightStickYC2;

  double dRightTriggerC1;
  double dLeftTriggerC1;

  double dRightTriggerC2;
  double dLeftTriggerC2;

  bool bRightBumperC1;
  bool bLeftBumperC1;

  bool bRightBumperC2;
  bool bLeftBumperC2;

  bool bRightBumperPressedC1;
  bool bLeftBumperPressedC1;

  bool bRightBumperReleasedC1;
  bool bLeftBumperReleasedC1;

  bool bLeftBumperPressedC2;
  bool bRightBumperPressedC2;
  
  bool bLeftBumperReleasedC2;
  bool bRightBumperReleasedC2;

  bool bStartButtonPressedC2;
  bool bBackButtonPressedC2;

  bool bStartButtonPressedC1;
  bool bBackButtonPressedC1;

  bool bStartButtonReleasedC1;
  bool bBackButtonReleasedC1;

  bool bStartButtonReleasedC2;
  bool bBackButtonReleasedC2;

  bool bStartButtonC1;
  bool bStartButtonC2;

  bool bBackButtonC1;
  bool bBackButtonC2;

  // Panel

  bool bButton1A;
  bool bButton2A;
  bool bButton3A;
  bool bButton4A;
  bool bButton5A;
  bool bButton6A;
  bool bButton7A;
  bool bButton8A;
  bool bButton9A;
  bool bButton10A;
  bool bButton11A;
  bool bButton12A;

  bool bButton1B;
  bool bButton2B;
  bool bButton3B;
  bool bButton4B;
  bool bButton5B;
  bool bButton6B;
  bool bButton7B;
  bool bButton8B;
  bool bButton9B;
  bool bButton10B;
  bool bButton11B;
  bool bButton12B;

};
