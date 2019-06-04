#include "ControllerClass.h"

ControllerClass::ControllerClass() 
{
    // Xbox Controllers
    Controller1 = new XboxController(1);
    Controller2 = new XboxController(2);

    // Button Panel
    StickA = new Joystick(3);
    StickB = new Joystick(4);
}
using namespace std;
#include <iostream>
void ControllerClass::ReadController1()
{
    bAButtonRawC1 = Controller1->GetRawButton(A_Button);
    bBButtonRawC1 = Controller1->GetRawButton(B_Button);
    bYButtonRawC1 = Controller1->GetRawButton(Y_Button);
    bXButtonRawC1 = Controller1->GetRawButton(X_Button);

    bAButtonPressedC1 = Controller1->GetAButtonPressed();
    bBButtonPressedC1 = Controller1->GetBButtonPressed();
    bYButtonPressedC1 = Controller1->GetYButtonPressed();
    bXButtonPressedC1 = Controller1->GetXButtonPressed();

    bAButtonReleasedC1 = Controller1->GetAButtonReleased();
    bBButtonReleasedC1 = Controller1->GetBButtonReleased();
    bYButtonReleasedC1 = Controller1->GetYButtonReleased();
    bXButtonReleasedC1 = Controller1->GetXButtonReleased();

    dRightStickXC1 = Controller1->GetX(frc::GenericHID::JoystickHand::kRightHand);
    dRightStickYC1 = Controller1->GetY(frc::GenericHID::JoystickHand::kRightHand);

    dLeftStickXC1 = Controller1->GetX(frc::GenericHID::JoystickHand::kLeftHand);
    dLeftStickYC1 = Controller1->GetY(frc::GenericHID::JoystickHand::kLeftHand);

    dLeftTriggerC1 = Controller1->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand);
    dRightTriggerC1 = Controller1->GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand);
    
    bLeftBumperC1 = Controller1->GetBumper(frc::GenericHID::JoystickHand::kLeftHand);
    bRightBumperC1 = Controller1->GetBumper(frc::GenericHID::JoystickHand::kRightHand);

    bLeftBumperPressedC1 = Controller1->GetBumperPressed(frc::GenericHID::JoystickHand::kLeftHand);
    bRightBumperPressedC1 = Controller1->GetBumperPressed(frc::GenericHID::JoystickHand::kRightHand);

    bLeftBumperReleasedC1 = Controller1->GetBumperReleased(frc::GenericHID::JoystickHand::kLeftHand);
    bRightBumperReleasedC1 = Controller1->GetBumperReleased(frc::GenericHID::JoystickHand::kRightHand);

    bStartButtonC1 = Controller1->GetRawButton(Start_Button);
    bBackButtonC1 = Controller1->GetRawButton(Back_Button);

    bStartButtonPressedC1 = Controller1->GetStartButtonPressed();
    bBackButtonPressedC1 = Controller1->GetBackButtonPressed();

    bStartButtonReleasedC1 = Controller1->GetStartButtonReleased();
    bBackButtonReleasedC1 = Controller1->GetBackButtonReleased();
}

void ControllerClass::ReadController2()
{
    bAButtonRawC2 = Controller2->GetRawButton(A_Button);
    bBButtonRawC2 = Controller2->GetRawButton(B_Button);
    bYButtonRawC2 = Controller2->GetRawButton(Y_Button);
    bXButtonRawC2 = Controller2->GetRawButton(X_Button);

    bAButtonPressedC2 = Controller2->GetAButtonPressed();
    bBButtonPressedC2 = Controller2->GetBButtonPressed();
    bYButtonPressedC2 = Controller2->GetYButtonPressed();
    bXButtonPressedC2 = Controller2->GetXButtonPressed();

    bAButtonReleasedC2 = Controller2->GetAButtonReleased();
    bBButtonReleasedC2 = Controller2->GetBButtonReleased();
    bYButtonReleasedC2 = Controller2->GetYButtonReleased();
    bXButtonReleasedC2 = Controller2->GetXButtonReleased();
    
    dRightStickXC2 = Controller2->GetX(frc::GenericHID::JoystickHand::kRightHand);
    dRightStickYC2 = Controller2->GetY(frc::GenericHID::JoystickHand::kRightHand);
    
    dLeftStickXC2 = Controller2->GetX(frc::GenericHID::JoystickHand::kLeftHand);
    dLeftStickYC2 = Controller2->GetY(frc::GenericHID::JoystickHand::kLeftHand);
    
    dLeftTriggerC2 = Controller2->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand);
    dRightTriggerC2 = Controller2->GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand);
    
    bLeftBumperC2 = Controller2->GetBumper(frc::GenericHID::JoystickHand::kLeftHand);
    bRightBumperC2 = Controller2->GetBumper(frc::GenericHID::JoystickHand::kRightHand);

    bLeftBumperPressedC2 = Controller2->GetBumperPressed(frc::GenericHID::JoystickHand::kLeftHand);
    bRightBumperPressedC2 = Controller2->GetBumperPressed(frc::GenericHID::JoystickHand::kRightHand);

    bLeftBumperReleasedC2 = Controller2->GetBumperReleased(frc::GenericHID::JoystickHand::kLeftHand);
    bRightBumperReleasedC2 = Controller2->GetBumperReleased(frc::GenericHID::JoystickHand::kRightHand);

    bStartButtonC2 = Controller2->GetRawButton(Start_Button);
    bBackButtonC2 = Controller2->GetRawButton(Back_Button);

    bStartButtonPressedC2 = Controller2->GetStartButtonPressed();
    bBackButtonPressedC2 = Controller2->GetBackButtonPressed();

    bStartButtonReleasedC2 = Controller2->GetStartButtonReleased();
    bBackButtonReleasedC2 = Controller2->GetBackButtonReleased();
}

void ControllerClass::GetPanel()
{
    // First 12 Buttons
    bButton1A = StickA->GetRawButton(1);
    bButton2A = StickA->GetRawButton(2);
    bButton3A = StickA->GetRawButton(3);
    bButton4A = StickA->GetRawButton(4);
    bButton5A = StickA->GetRawButton(5);
    bButton6A = StickA->GetRawButton(6);
    bButton7A = StickA->GetRawButton(7);
    bButton8A = StickA->GetRawButton(8);
    bButton9A = StickA->GetRawButton(9);
    bButton10A = StickA->GetRawButton(10);
    bButton11A = StickA->GetRawButton(11);
    bButton12A = StickA->GetRawButton(12);

    // Second 12 Buttons
    bButton1B = StickB->GetRawButton(1);
    bButton2B = StickB->GetRawButton(2);
    bButton3B = StickB->GetRawButton(3);
    bButton4B = StickB->GetRawButton(4);
    bButton5B = StickB->GetRawButton(5);
    bButton6B = StickB->GetRawButton(6);
    bButton7B = StickB->GetRawButton(7);
    bButton8B = StickB->GetRawButton(8);
    bButton9B = StickB->GetRawButton(9);
    bButton10B = StickB->GetRawButton(10);
    bButton11B = StickB->GetRawButton(11);
    bButton12B = StickB->GetRawButton(12);
}

void ControllerClass::Update()
{
    ReadController1();
    ReadController2();
}
