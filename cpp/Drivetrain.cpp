#include "Drivetrain.h"

#include <iostream>
using namespace std;

#define LTPort 2
#define RTPort 4

#define RV1Port 3
#define LV1Port 5

#define RV2Port 6
#define LV2Port 7

Drivetrain::Drivetrain() 
{
    // Drivers
    leftTalon = new TalonSRX(LTPort);
    rightTalon = new TalonSRX(RTPort);

    // Followers
    leftVictor1 = new VictorSPX(LV1Port);
    rightVictor1 = new VictorSPX(RV1Port);
    
    leftVictor2 = new VictorSPX(LV2Port);
    rightVictor2 = new VictorSPX(RV2Port);
}

void Drivetrain::initMotors()
{
    leftTalon->SetInverted(false);
    leftVictor1->SetInverted(false);
    leftVictor2->SetInverted(false);
    rightTalon->SetInverted(true);
    rightVictor1->SetInverted(true);
    rightVictor2->SetInverted(true);
    
    leftVictor1->Follow(*leftTalon);
    leftVictor2->Follow(*leftTalon);
    
    rightVictor1->Follow(*rightTalon);
    rightVictor2->Follow(*rightTalon);
}

void Drivetrain::drive(double L, double R)
{
    leftTalon->Set(ControlMode::PercentOutput, L);
    rightTalon->Set(ControlMode::PercentOutput, R);
}
