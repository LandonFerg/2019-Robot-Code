#include "Manipulator.h"

#include <iostream>
using namespace std;

#include "Manipulator.h"

#define TT 21
#define BT 22

extern ControllerClass * controllerClass;

Manipulator::Manipulator()
{

  // Motors
  isRunningTop = false;
  isRunningBot = false;
  manipTimerTop = new frc::Timer();
  manipTimerBot = new frc::Timer();

  topTalon = new TalonSRX(TT);
  botTalon = new TalonSRX(BT);

  topTalon->SetSelectedSensorPosition(0, 0, 10); // Zero manip
  botTalon->SetSelectedSensorPosition(0, 0, 10);


  topTalon->Config_kP(0,1,10);
  botTalon->Config_kP(0,1,10);

  topTalon->Config_kI(0,0,10);
  botTalon->Config_kI(0,0,10);

  topTalon->Config_kD(0,0,10);
  botTalon->Config_kD(0,0,10);

  topTalon->Config_kF(0,0,10);
  botTalon->Config_kF(0,0,10);
}

void Manipulator::setManipulator(double topTicks, double bottomTicks)
{
  double speed = 7000;
  double accel = 7000;

  topTalon->SetSensorPhase(true);
  botTalon->SetSensorPhase(true);

  // Set speed/accel
  topTalon->ConfigMotionCruiseVelocity(speed, 0);
  botTalon->ConfigMotionCruiseVelocity(speed, 0);

  topTalon->ConfigMotionAcceleration(accel, 0);
  botTalon->ConfigMotionAcceleration(accel, 0);
        
  double sensPos = topTalon->GetSelectedSensorPosition();
  
  // Set positions
  topTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, topTicks);
  botTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, bottomTicks);
}

void Manipulator::manualManip(double U, double B) // For debugging purposes ONLY -LJF
{
  topTalon->Set(ControlMode::PercentOutput, U);
  botTalon->Set(ControlMode::PercentOutput, B);
}

int Manipulator::nativeVelFromVel(int vel)
{
  double x = vel*12.0*(1.0/(6.0*3.14159)*4096.0*(1.0/10.0));
  vel = std::round(x);
  return vel;
}

void Manipulator::betterManual(double val)
{
  topTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, val*0.6);  // Lowered sens. control
  botTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, val*0.6);
}

void Manipulator::manipState()
{
    double TsensPos = topTalon->GetSelectedSensorPosition();
    double BsensPos = botTalon->GetSelectedSensorPosition();

    cout << "TopManip: " << TsensPos << endl;
    cout << "BotManip: " << BsensPos << endl;
}

void Manipulator::runMotors()
{
    double BsensPos = botTalon->GetSelectedSensorPosition();

    if(isRunningTop && manipTimerTop->Get() < topWaitTime) 
    {
      topTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, manipSpeed);
      cout << "top going..." << endl;
    }

    if(isRunningBot && manipTimerBot->Get() < botWaitTime /*&& anipState()*/)     // If bottom is going, go
    {
      botTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, manipSpeed);
    }

    if(manipTimerBot->Get() > botWaitTime)
    {
      botTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
      isRunningBot = false;
    }

    if(manipTimerTop->Get() > topWaitTime && isRunningTop)
    {
      cout << "TURNING OFF" << endl;
      topTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
      isRunningTop = false;
    }
}

void Manipulator::hatchPickup()
{
    this->setManipulator(0,0);
}

void Manipulator::cargoHold()
{
    this->setManipulator(0,-5500);
}

void Manipulator::openManip() //shoot
{
  this->setManipulator(-3500, -8000);
  isRunningTop = true;
  isRunningBot = true;

  manipTimerTop->Reset();
  manipTimerTop->Start();
  manipTimerBot->Reset();
  manipTimerBot->Start();

  manipSpeed = -0.4;

  topWaitTime = 0.08; 
  botWaitTime = 0.13; // All the way to the end

}

void Manipulator::loadCargo()
{
  this->setManipulator(0, 7000);
  isRunningTop = true;
  isRunningBot = true;

  manipTimerTop->Reset();
  manipTimerTop->Start();
  manipTimerBot->Reset();
  manipTimerBot->Start();

  manipSpeed = 0.4;

  topWaitTime = 0.07;
  botWaitTime = 0.13; // 0.13 takes bottom manip to center
} 


void Manipulator::runManip()
{
  if(controllerClass->bLeftBumperPressedC2) // shoot
  {
    this->openManip();
  }

  if(controllerClass->bRightBumperPressedC2) // load
  {
    this->loadCargo();
  }

  if(controllerClass->bYButtonPressedC2) // hold cargo
  {
    this->cargoHold(); // hold cargo
  }

  if(controllerClass->bAButtonPressedC2) // zero
  {
    this->hatchPickup(); 
  }

}


