
#include "OperatingModes.h"
#include "ui_drawing.hpp"

OperatingMode gui_CustomUI(const ButtonState buttons, guiContext *cxt) {

  currentTempTargetDegC = 0; // ensure tip is off

  // Draw custom screen
  OLED::setCursor(0, 0);
  OLED::print(DebugMenu[4], FontStyle::SMALL);

  // Display input voltage
  OLED::setCursor(0, 8);
  OLED::print(DebugMenu[4], FontStyle::SMALL);
  printVoltage();
  OLED::print(SmallSymbolVolts, FontStyle::SMALL);

  // Ignore button press if it was held when entering this mode
  if (buttons != BUTTON_NONE && cxt->scratch_state.state1 == 0) {
    return OperatingMode::CustomUI;
  } else {
    cxt->scratch_state.state1 = 1;
  }

  // Modify button assignments based on display orientation
  ButtonState buttonPress = buttons;

  if (OLED::getRotation()) {
    switch (buttons) {
    case BUTTON_F_SHORT:
      buttonPress = BUTTON_B_SHORT;
      break;
    case BUTTON_B_SHORT:
      buttonPress = BUTTON_F_SHORT;
      break;
    case BUTTON_F_LONG:
      buttonPress = BUTTON_B_LONG;
      break;
    case BUTTON_B_LONG:
      buttonPress = BUTTON_F_LONG;
      break;
    default:
      break;
    }
  }

  // Now handle user button input
  switch (buttonPress) {

  case BUTTON_NONE:
    // Do nothing
    break;

  case BUTTON_BOTH:
    // Do nothing
    break;

  case BUTTON_B_LONG:
    cxt->transitionMode = TransitionAnimation::Down;
    return OperatingMode::DebugMenuReadout;

  case BUTTON_B_SHORT:
    cxt->transitionMode = TransitionAnimation::Right;
    return OperatingMode::SettingsMenu;

  case BUTTON_F_LONG:
    // Unmapped
    break;

  case BUTTON_F_SHORT:
    // Unmapped
    break;

  default:
    break;
  }

  return OperatingMode::CustomUI;
}
