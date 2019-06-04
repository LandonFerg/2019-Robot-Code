#include "Robot.h"
#include "WPILib.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>

#include  "Drivetrain.h"
#include "LimitSwitch.h"
#include "ControllerClass.h"
#include "CascadeElevator.h"
#include "CargoIntake.h"

#include "Manipulator.h"

using namespace std;
using namespace frc; 

LimitSwitch * limit;
ControllerClass * controllerClass; 
CascadeElevator * elevator;
Drivetrain * drivetrainClass;

CargoIntake * cargoIntake;

Manipulator * manipulator;


void Robot::RobotInit() 
{
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  
  Compressor *c = new Compressor(0); // turn on compressor
  c->SetClosedLoopControl(true);

  controllerClass = new ControllerClass();
  elevator = new CascadeElevator();
  drivetrainClass = new Drivetrain();
 
  cargoIntake = new CargoIntake();

  manipulator = new Manipulator();

// elevator->initElevator();
  drivetrainClass->initMotors();
  cargoIntake->initCargoIntake();
  cargoIntake->setZero();
  elevator->initElevator(); // Initialize elevator
}

void Robot::RobotPeriodic() {
}

bool b = false;
void Robot::AutonomousInit() 
{
  m_autoSelected = m_chooser.GetSelected();
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
  } else {
  } 
}


void Robot::AutonomousPeriodic() 
{
    controllerClass->Update(); // Sandstorm
    drivetrainClass->drive(controllerClass->dLeftStickYC1, controllerClass->dRightStickYC1);
}

void Robot::TeleopInit() 
{
  cargoIntake->initCargoIntake();
  cargoIntake->initTeleopCargoIntake();
}  

void Robot::TeleopPeriodic() 
{
  controllerClass->Update();
  drivetrainClass->drive(controllerClass->dLeftStickYC1, controllerClass->dRightStickYC1);

  cargoIntake->intakeBall();
  cargoIntake->controlArmPosition();
  
  manipulator->runManip();

}

void Robot::TestPeriodic() 
{

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
