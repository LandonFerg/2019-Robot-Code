#pragma once

#include <frc/DigitalInput.h>

using namespace frc;
using namespace std;

class LimitSwitch {
  private:
  frc::DigitalInput * limitSwitch;
  bool isNormallyOpen;

  public:
  LimitSwitch(int, bool);
  bool isPressed();
};
