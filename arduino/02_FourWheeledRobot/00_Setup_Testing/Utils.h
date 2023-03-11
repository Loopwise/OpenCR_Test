#pragma once

#ifndef UTILS_h
#define UTILS_h

#include <Arduino.h>
#include <Dynamixel2Arduino.h>

// Macros Definition
#define DXL_SERIAL Serial3
#define DEBUG_SERIAL Serial
const int DXL_DIR_PIN = 84;
const float DXL_PROTOCOL_VERSION = 2.0;

extern Dynamixel2Arduino dxl;

#define N_Legs 4
extern const uint8_t Vel_ids[N_Legs];
extern const uint8_t Pos_ids[N_Legs];
extern const uint8_t min_pos[N_Legs];
extern const uint8_t max_pos[N_Legs];

#ifndef t1
#define t1 100
#endif

using namespace ControlTableItem;

// Functions Definition
void init_ids(const uint8_t ids[], uint8_t mode, uint32_t data = 0);
void init_Dxl();

#endif