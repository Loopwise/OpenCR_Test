#include <Dynamixel2Arduino.h>
#include "Utils.h"

#define t1 1000
uint8_t function = -1;

using namespace ControlTableItem;

float v = 50;

// Max 57 rev/min -> 
float velocity[6][4] = {{0, 0, 0, 0},
{v, v, v, v},
{-v, -v, -v, -v},
{0, v, v, 0},
{0, -v, -v, 0},
{v, -v, v, -v}
};

void setup() {
  init_Dxl();
  Serial.begin(115200);

  delay(500);
}

void loop() {
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < N_Legs; j++)
      dxl.setGoalVelocity(Vel_ids[j], velocity[i][j], UNIT_RPM);
    
    delay(500);
  } 
}
