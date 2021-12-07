## REDGPU Framework

```c
// REDGPU Framework "Hello, World!" Program

// cl main.c /link framework/redgpu_fdll.lib

#include "framework/redgpu_f.h"

RedFHandleFirstPersonCamera * gCamera;

void setup(void) {
  gCamera = redFCreateFirstPersonCamera(1);
  redFFirstPersonCameraControlEnable(gCamera[0]);
}

void draw(void) {
  redFFirstPersonCameraBegin(gCamera[0]);
  redFNoFill();
  redFSetColor(255, 0, 0, 255);
  redFDrawSphere(0, 0, 0, 25.f);
  redFFirstPersonCameraEnd(gCamera[0]);
}

int main() {
  RedFEvents events = {0};
  events.setup = setup;
  events.draw  = draw;
  redFMain(&events, 600, 600, REDF_WINDOW_MODE_WINDOW, 0, 1, 0, 1, 0, 0);
}
```

## Tips:

* Prefer to call `redFDisableArbTex` at setup event to enable normalized texture coordinates and disable the default use of rectangle textures that don't support different texture wrap modes.
* Prefer to call `redFEnableFramebufferSRGBGammaCorrection` at setup event to enable gamma-correct rendering. Images loaded from disk will likely be in the wrong gamma, so convert their 0 to 255 8-bit RGB pixel values to 0.0 to 1.0 float values, apply `r *= r; g *= g; b *= b;` and set the modified float values back to image pixels as 0 to 255 8-bit values.
* REDGPU Framework doesn't call `glfwPollEvents` or `glfwWaitEvents` anywhere internally, so prefer to call `glfwPollEvents` each frame at the beginning of update event to get correct input events.
* Many draw procedures are affected by the currently set `redFSetColor` color.
