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
