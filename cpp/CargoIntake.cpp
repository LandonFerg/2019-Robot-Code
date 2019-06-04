#include "CargoIntake.h"

extern ControllerClass * controllerClass;

CargoIntake::CargoIntake() 
{
    rollerVictor = new VictorSPX(21); 

    positionVictor = new VictorSPX(23);
    positionTalon = new TalonSRX(49); 

   positionTalon->ConfigFactoryDefault();
}

void CargoIntake::initCargoIntake()
{
    positionVictor->Follow(*positionTalon);
    positionVictor->SetInverted(true); // changed to true

    positionTalon->SetInverted(false);
    positionTalon->SetNeutralMode(NeutralMode::Brake);

    positionVictor->SetNeutralMode(NeutralMode::Brake);
    rollerVictor->SetNeutralMode(NeutralMode::Brake);

    positionTalon->Config_kP(0, 1, 10); // was (0, 1, 10)
    positionTalon->Config_kI(0, 0, 10);
    positionTalon->Config_kD(0, 0, 10);
    positionTalon->Config_kF(0, 0, 10); // was (0, 0, 10)

    int r = positionTalon->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    cout << "r: " << r << endl;

    positionTalon->SetSensorPhase(true);
    positionTalon->SetSelectedSensorPosition(0, 0, 10);

    positionTalon->SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);

 /*  positionTalon->ConfigNominalOutputForward(0, 10);
    positionTalon->ConfigNominalOutputReverse(0, 10);
    positionTalon->ConfigPeakOutputForward(1, 10);
    positionTalon->ConfigPeakOutputReverse(-1, 10);  */

    positionTalon->SelectProfileSlot(0, 0);

}

double CargoIntake::getTicks(double degrees)
{
    double ticksToGo = (degrees * 4096 * 9)/(360); // Mr. McAmis said times it by 1/9. 360 degrees in a rotation, and 4096 ticks in a rotation
    return ticksToGo;
}

void CargoIntake::moveArmUp()
{
    positionTalon->ConfigMotionCruiseVelocity(700, 0); // was (1500, 10) // was (1500, 0)
    positionTalon->ConfigMotionAcceleration(700, 0); // was (1500, 10) // was (1500, 0)

    positionTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, -1 * getTicks(60.0)); // moving arm 90 degrees up
    cout << "Arm is supposed to go up." << -1 *  getTicks(90.0) << endl;
}

void CargoIntake::moveArmDown()
{
    positionTalon->ConfigMotionCruiseVelocity(1000, 0); // was (1500, 10) // was (1500, 0)
    positionTalon->ConfigMotionAcceleration(1000, 0); // was (1500, 10) // was (1500, 0)

    positionTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, -1 * getTicks(-60.0)); // moving arm back to 90 degrees
    cout << "Arm is supposed to go down." << -1 * getTicks(-90.0) << endl;
}

void CargoIntake::intakeBall()
{
    if(controllerClass->dLeftTriggerC1 > 0.0) // Intake Ball
    {
        rollerVictor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, controllerClass->dLeftTriggerC1);
    }
    else if(controllerClass->dRightTriggerC1 > 0.0) // Shoot Out Ball
    {
        rollerVictor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -1 * controllerClass->dRightTriggerC1);
    }
    else
    {
        rollerVictor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    }
}

void CargoIntake::initTeleopCargoIntake()
{
    positionTalon->SetSelectedSensorPosition(0, 0, 10);
 //   positionTalon->SetSelectedSensorPosition(positionTalon->GetSelectedSensorPosition(0), 0, 10);
    iPositionMode = -1;
    direction = 0;
}

void CargoIntake::controlArmPosition()
{
    iPositionMode = -1;
    if(controllerClass->bLeftBumperPressedC1 == true)
    {
        iPositionMode = 0;
        direction = 1; // going down
    }
    if(controllerClass->bRightBumperPressedC1 == true)
    {
        iPositionMode = 1;
        direction = 2; // going up
    }
    if(iPositionMode == 0)
    {
        moveArmDown();
        cout << "Moving arm down." << endl;
    }
    if(iPositionMode == 1)
    {
        moveArmUp();
        cout << "Moving arm up." << endl;
    }
    if(positionTalon->GetSelectedSensorPosition(0) > 3000 && direction == 1)
    {
        positionTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    }
    if(positionTalon->GetSelectedSensorPosition(0) < 200 && direction == 2)
    {
        positionTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        positionTalon->SetSelectedSensorPosition(0, 0, 10);
    }
}

void CargoIntake::manualArmPosition()
{
    positionTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.5 * controllerClass->dRightStickYC2);
}

void CargoIntake::testGoUp()
{
    positionTalon->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, 1000); // 1024 ticks (4096/4) * (1/9)
}

void CargoIntake::setZero()
{
    positionTalon->SetSelectedSensorPosition(0, 0, 10);
}
