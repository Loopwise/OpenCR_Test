#include "Utils.h"

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);
const uint8_t Vel_ids[N_Legs] = {1, 2, 3, 4};
const uint8_t Pos_ids[N_Legs] = {5, 6, 7, 8};
const uint16_t min_pos[N_Legs] = {95, 114, 98, 99};
const uint16_t max_pos[N_Legs] = {247, 262, 263, 260};

using namespace ControlTableItem;

void init_ids(const uint8_t ids[], uint8_t mode, uint32_t data){
  for(int i = 0; i < N_Legs;i++){
    dxl.ping(ids[i]);

    dxl.torqueOff(ids[i]);
    dxl.setOperatingMode(ids[i], mode);
    dxl.torqueOn(ids[i]);

    switch(mode){
      case OP_POSITION:
        dxl.writeControlTableItem(PROFILE_VELOCITY, ids[i], data);
        dxl.writeControlTableItem(MIN_POSITION_LIMIT, ids[i], map(min_pos[i], 0, 360, 0, 4095));
        dxl.writeControlTableItem(MAX_POSITION_LIMIT, ids[i], map(max_pos[i], 0, 360, 0, 4095));
        break;
    }
  }
}

void init_Dxl(){
  dxl.begin(57600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

  init_ids(Vel_ids, OP_VELOCITY);
  init_ids(Pos_ids, OP_POSITION, t1);
}