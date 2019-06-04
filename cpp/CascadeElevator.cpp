#include "CascadeElevator.h"

extern ControllerClass * controllerClass;

bool isDriving = false;
CascadeElevator::CascadeElevator() 
{
    elevatorTalon = new TalonSRX(9);
    elevatorVictorOne = new VictorSPX(11);
    elevatorVictorTwo = new VictorSPX(12);
    elevatorVictorThree = new VictorSPX(13);
}

void CascadeElevator::initElevator()
{
    elevatorVictorOne->Follow(*elevatorTalon);
    elevatorVictorTwo->Follow(*elevatorTalon);
    elevatorVictorThree->Follow(*elevatorTalon);

    elevatorTalon->Config_kP(0, 1, 10);
    elevatorTalon->Config_kI(0, 0, 10);
    elevatorTalon->Config_kD(0, 0, 10);
    elevatorTalon->Config_kF(0, 0, 10);

    elevatorTalon->SetInverted(true);
    elevatorVictorOne->SetInverted(true);
    elevatorVictorTwo->SetInverted(true);
    elevatorVictorThree->SetInverted(true);

    elevatorTalon->SetSensorPhase(true);
    elevatorTalon->SetSelectedSensorPosition(0, 0, 10);
    elevatorTalon->ConfigMotionCruiseVelocity(7000, 10);
    elevatorTalon->ConfigMotionAcceleration(7000, 10);

    elevatorTalon->SetSelectedSensorPosition(0, 0, 0);
}

void CascadeElevator::initTeleopElevator()
{
    elevatorTalon->SetSelectedSensorPosition(elevatorTalon->GetSelectedSensorPosition(0),0,0);
    targetSide = none;
}

double CascadeElevator::getTicks(double inches) // 5.667 inches per rotation and 4096 encoder ticks per rotation
{
    double encoderTicksToGo = (inches * 4096.0)/(5.667 * 2.0); 
    return encoderTicksToGo;
}

void CascadeElevator::setElevatorHeightInches(double inches)
{
    elevatorTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, getTicks(inches));
}

void CascadeElevator::goToTopRocketForCargo()
{
    setElevatorHeightInches(64.5); 
}

void CascadeElevator::goToMiddleRocketForCargo()
{
    setElevatorHeightInches(36.5);
}

void CascadeElevator::goToBottomRocketForCargo()
{
    setElevatorHeightInches(8.5);
}

void CascadeElevator::goToTopRocketForHatch()
{
    setElevatorHeightInches(56.0);
}

void CascadeElevator::goToMiddleRocketForHatch()
{
    setElevatorHeightInches(28.0);
}

void CascadeElevator::goToBottomRocketForHatch()
{
    setElevatorHeightInches(0.0);
} 

void CascadeElevator::cargoSideOfRocket()
{
    // C2 is operator control
    if(controllerClass->bYButtonRawC2 == true)
    {
        goToTopRocketForCargo();
        cout << "Going to Top of Rocket for Cargo." << endl;
    }
    if(controllerClass->bBButtonRawC2 == true)
    {
        goToMiddleRocketForCargo();
        cout << "Going to Middle of Rocket for Cargo." << endl;
    }
    if(controllerClass->bAButtonRawC2 == true)
    {
        goToBottomRocketForCargo();
        cout << "Going to Bottom of Rocket for Cargo." << endl;
    }
}

void CascadeElevator::hatchSideOfRocket()
{
    // C2 is operator control
    if(controllerClass->bYButtonRawC2 == true)
    {
        goToTopRocketForHatch();
        cout << "Going to Top of Rocket for Hatch." << endl;
    }
    if(controllerClass->bBButtonRawC2 == true)
    {
        goToMiddleRocketForHatch();
        cout << "Going to Middle of Rocket for Hatch." << endl;
    }
    if(controllerClass->bAButtonRawC2 == true)
    {
        goToBottomRocketForHatch();
        cout << "Going to Bottom of Rocket for Hatch." << endl;
    }
} 

void CascadeElevator::controlElevator()
{
    /* Pressing Start Button = Cargo Heights
       Pressing Back Button = Hatch Heights
    */
    if(controllerClass->bStartButtonC2 == true) // if the start button on operator controller is pressed
    {
        targetSide = cargo; // cargo is defined as 0 in CascadeElevator.h
    }
    if(controllerClass->bBackButtonC2 == true) // if the back button on operator controller is pressed
    {
        targetSide = hatch; // hatch is defined as 1 in CascadeElevator.h
    }
    if(targetSide == cargo)
    {
        cargoSideOfRocket();
        cout << "Cargo mode." << endl;
    }
    if(targetSide == hatch)
    {
        hatchSideOfRocket();
        cout << "Hatch mode." << endl;
    }
} 

void CascadeElevator::manualControlTest()
{
    elevatorTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -1 * controllerClass->dRightStickYC2);
}

void CascadeElevator::testElevator()
{
    if(isDriving == false)
    {
        isDriving = true;
        cout << "doing the thing only once" << endl;
        goToMiddleRocketForHatch();
    }
}
