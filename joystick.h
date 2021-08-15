#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int                   glfwJoystickPresent    (int joystickId0to15);
const char *          glfwGetJoystickName    (int joystickId0to15);
const float *         glfwGetJoystickAxes    (int joystickId0to15, int * outCount);
const unsigned char * glfwGetJoystickButtons (int joystickId0to15, int * outCount);

#ifdef __cplusplus
}
#endif
