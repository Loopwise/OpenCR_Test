#include <Dynamixel2Arduino.h>
#include "Utils.h"

#define t1 1000
uint8_t function = -1;

using namespace ControlTableItem;

void getPositions();
void LimitsTest();
void SerialAngles();  
void OneLimitsTest();

void setup() {
  init_Dxl();
  Serial.begin(115200);
}

void loop(){
  if(Serial.available())
    function = Serial.readStringUntil('\n').toInt();
  switch(function){
    case 0:
      getPositions();
      break;
    case 1:
      LimitsTest();
      break;
    case 2:
      SerialAngles();
      break;
    case 3:
      OneLimitsTest();
      break;
    case 4:
      VelocityTest();
      break;
    default:
      return;
  }
  function = -1;
}

void getPositions(){
  for(int i = 0; i < N_Legs; i++){
    Serial << Pos_ids[i] << " Motor Current Position: " << dxl.getPresentPosition(Pos_ids[i], UNIT_DEGREE) << '\n';
    delay(100);
  } 
}

void LimitsTest() {
  for(int i = 0; i < N_Legs; i++){
    Serial << "Sending data to Dynamixel with Id: " << Pos_ids[i] << '\n';
  
    dxl.setGoalPosition(Pos_ids[i], min_pos[i], UNIT_DEGREE);
    delay(2000);

    dxl.setGoalPosition(Pos_ids[i], max_pos[i], UNIT_DEGREE);
    delay(2000);
  }
}

void SerialAngles(){
  Serial << "Motor Id: ";
  uint8_t Id = Serial.parseInt();
  Serial << "Angle: ";
  uint8_t angle = Serial.parseInt();
  dxl.setGoalPosition(Id, angle, UNIT_DEGREE);
  delay(5000);
}

void OneLimitsTest(){
  const uint8_t Id = 6;
  const uint8_t i = Id - 4 - 1;

  Serial << "Current Min Pos: ";
  dxl.setGoalPosition(Id, min_pos[i], UNIT_DEGREE);
  delay(2500);
  Serial << dxl.getPresentPosition(Id, UNIT_DEGREE) << '\n';

  Serial << "Current Max Pos: ";
  dxl.setGoalPosition(Id, max_pos[i], UNIT_DEGREE);
  delay(2500);
  Serial << dxl.getPresentPosition(Id, UNIT_DEGREE) << '\n';
}

void VelocityTest(){
  for(int i = 0; i < N_Legs; i++){
    dxl.setGoalVelocity(Vel_ids[i], 50, UNIT_RPM);
    delay(500);
    dxl.setGoalVelocity(Vel_ids[i], -50, UNIT_RPM);
    delay(500);
    dxl.setGoalVelocity(Vel_ids[i], 0);
  }
}