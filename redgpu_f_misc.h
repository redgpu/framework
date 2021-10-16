#pragma once

#include "redgpu_f.h"

static inline void redFMiscDearImguiUppercaseInputQueueCharactersIfKeyShiftIsPressed(void) {
  ImGuiIO * io = igGetIO();
  if (io->KeyShift == 1) {
    for (int i = 0; i < io->InputQueueCharacters.Size; i += 1) {
      ImWchar c = io->InputQueueCharacters.Data[i];
      if ((c >= 97) && (c <= 122)) {
        io->InputQueueCharacters.Data[i] = c ^ 0x20;
      }
      else if (c == '`')  { io->InputQueueCharacters.Data[i] = '~'; }
      else if (c == '1')  { io->InputQueueCharacters.Data[i] = '!'; }
      else if (c == '2')  { io->InputQueueCharacters.Data[i] = '@'; }
      else if (c == '3')  { io->InputQueueCharacters.Data[i] = '#'; }
      else if (c == '4')  { io->InputQueueCharacters.Data[i] = '$'; }
      else if (c == '5')  { io->InputQueueCharacters.Data[i] = '%'; }
      else if (c == '6')  { io->InputQueueCharacters.Data[i] = '^'; }
      else if (c == '7')  { io->InputQueueCharacters.Data[i] = '&'; }
      else if (c == '8')  { io->InputQueueCharacters.Data[i] = '*'; }
      else if (c == '9')  { io->InputQueueCharacters.Data[i] = '('; }
      else if (c == '0')  { io->InputQueueCharacters.Data[i] = ')'; }
      else if (c == '-')  { io->InputQueueCharacters.Data[i] = '_'; }
      else if (c == '=')  { io->InputQueueCharacters.Data[i] = '+'; }
      else if (c == '[')  { io->InputQueueCharacters.Data[i] = '{'; }
      else if (c == ']')  { io->InputQueueCharacters.Data[i] = '}'; }
      else if (c == ';')  { io->InputQueueCharacters.Data[i] = ':'; }
      else if (c == '\'') { io->InputQueueCharacters.Data[i] = '"'; }
      else if (c == '\\') { io->InputQueueCharacters.Data[i] = '|'; }
      else if (c == ',')  { io->InputQueueCharacters.Data[i] = '<'; }
      else if (c == '.')  { io->InputQueueCharacters.Data[i] = '>'; }
      else if (c == '/')  { io->InputQueueCharacters.Data[i] = '?'; }
      else if (c == '<')  { io->InputQueueCharacters.Data[i] = '>'; }
    }
  }
}