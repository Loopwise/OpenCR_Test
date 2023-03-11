#include <Dynamixel2Arduino.h>

// We're using OpenCR Board
#define DXL_SERIAL   Serial3
#define DEBUG_SERIAL Serial
const int DXL_DIR_PIN = 84; // OpenCR Board's DIR PIN.

#define N_DXL 4
uint8_t DXL_IDs[N_DXL];
const float DXL_PROTOCOL_VERSION = 2.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup() {
  for(int i = 0; i < N_DXL; i++)
    DXL_IDs[i] = i + 5;

  // Use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);
  while(!DEBUG_SERIAL);

  dxl.begin(57600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  for(int i = 0; i < N_DXL; i++){
    // Get DYNAMIXEL information
    dxl.ping(DXL_IDs[i]);

    // Configure mode in EEPROM area
    dxl.torqueOff(DXL_IDs[i]);
    dxl.setOperatingMode(DXL_IDs[i], OP_POSITION);
    dxl.torqueOn(DXL_IDs[i]);

    // Limit the max velocity in Position Control MOde. Use 0 for Max Speed
    dxl.writeControlTableItem(PROFILE_VELOCITY, DXL_IDs[i], 1000);
  }
}

#define N_goals 3
const float goals[N_goals] = {200, 230, 130};

const float tol = 1.0;

void loop() {
  for(int i = 0; i < N_goals; i++){
    for(int j = 0; j < N_DXL; j++){
      const float goal = goals[i];

      dxl.setGoalPosition(DXL_IDs[j], goal, UNIT_DEGREE);

      delay(5000);
      /*
      while(abs(goal - position) > tol){
        position = dxl.getPresentPosition(DXL_IDs[j], UNIT_DEGREE);
        DEBUG_SERIAL.print("Present_Position(degree) : ");
        DEBUG_SERIAL.println(position);
      }
      */     
    }
  }
}
