#include <Dynamixel2Arduino.h>
#include "Utils.h"

#define t1 1000

using namespace ControlTableItem;

void setup() {
  init_Dxl();
  DEBUG_SERIAL.begin(115200);
  
  delay(1000);

  for(int i = 0; i < N_Legs; i++){
    float j = dxl.getPresentPosition(Pos_ids[i], UNIT_DEGREE);
    DEBUG_SERIAL.print(Pos_ids[i]);
    DEBUG_SERIAL.print(" Current pos: ");
    DEBUG_SERIAL.println(j);
    delay(1000);
  } 
}

void principal() {
  for(int i = 0; i < N_Legs; i++){
    DEBUG_SERIAL.print("Sending data to Dynamixel with Id: ");
    DEBUG_SERIAL.println(Pos_ids[i]);
  
    dxl.setGoalPosition(Pos_ids[i], min_pos[i], UNIT_DEGREE);
    delay(2000);

    dxl.setGoalPosition(Pos_ids[i], max_pos[i], UNIT_DEGREE);
    delay(2000);
  }
}

void loop(){
  principal();
}