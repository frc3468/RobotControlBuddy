/*    
  FRC Robot Control Buddy - Send FRC Driverstation Shortcuts on Pin Input
  Copyright (C) 2021  Gustave Michel III

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "Keyboard.h"

const uint8_t estop_pin = 9;
const uint8_t disable_pin = 7;
const uint8_t enable_pin = 8;

const char estop_key = ' ';
const char disable_key = KEY_RETURN;
const char enable_keys[] = { '[', ']', '\\' };

bool estop_prev = false;
bool disable_prev = false;
bool enable_prev = false;

void setup() {
  // make the button pins inputs with pullups
  pinMode(estop_pin, INPUT_PULLUP);
  pinMode(disable_pin, INPUT_PULLUP);
  pinMode(enable_pin, INPUT_PULLUP);
  
  // initialize keyboard interface
  Keyboard.begin();
}

void loop() {
  //TODO: Debounce? May not be needed
  
  if(!digitalRead(estop_pin)) {
    Keyboard.press(estop_key);
    estop_prev =  true;
  } else {
    if(estop_prev) {
      Keyboard.release(estop_key);
      estop_prev = false;
    }
  }

  if(!digitalRead(disable_pin)) {
    Keyboard.press(disable_key);
    disable_prev =  true;
  } else {
    if(disable_prev) {
      Keyboard.release(disable_key);
      disable_prev = false;
    }
  }

  if(!digitalRead(enable_pin)) {
    for(int i = 0; i < 3; i++) {
      Keyboard.press(enable_keys[i]);
    }
    enable_prev = true;
  } else {
    if(enable_prev) {
      for(int i = 0; i < 3; i++) {
        Keyboard.release(enable_keys[i]);
      }
      enable_prev = false;
    }
  }
}
