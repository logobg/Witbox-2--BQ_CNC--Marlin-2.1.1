/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * bq CNC board definition
 */

#define REQUIRE_MEGA2560
#include "env_validate.h"

#define BOARD_INFO_NAME "bq CNC"

//
// Limit Switches
//
#define X_MAX_PIN                             79

// This board has headers for Z-min, Z-max and IND_S_5V *but* as the bq team
// decided to ship the printer only with the probe and no additional Z-min
// endstop and the instruction manual advises the user to connect the probe to
// IND_S_5V the option Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN will not work.
#if ENABLED(Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN)
  #define Z_MIN_PIN                           18  // Z-MIN Label
  #define Z_MAX_PIN                           19  // Z-MAX Label
#endif

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                     18  // Z-MAX Label
#endif

//
// Steppers
//
#define Z_ENABLE_PIN                          77

#define DIGIPOTSS_PIN                         22
#define DIGIPOT_CHANNELS { 4, 5, 3, 0, 1 }

//
// Temperature Sensors
//
#define TEMP_0_PIN                            13  // Analog Input
#define TEMP_BED_PIN                          14  // Analog Input

//
// Heaters / Fans / Light
//
#define MOSFET_A_PIN                           9  // HEATER_0_PIN
#define MOSFET_B_PIN                          12  // FAN_BLOWER_PIN
//#define MOSFET_C_PIN                           2  // FAN_BOX_PIN
//#define MOSFET_D_PIN                           7  // FAN_BLOCK_PIN

//
// Auto fans
//
#ifndef E0_AUTO_FAN_PIN
  #define E0_AUTO_FAN_PIN                     7
#endif

//
// Light
//
#ifndef CASE_LIGHT_PIN
  #define CASE_LIGHT_PIN                      2  // FAN_BOX_PIN
#endif

// Alter timing for graphical display
#if IS_U8GLIB_ST7920                                 
  #define BOARD_ST7920_DELAY_1                 0  // ???
  #define BOARD_ST7920_DELAY_2                 0  // ???
  #define BOARD_ST7920_DELAY_3               189  // ???
#endif

//
// Import RAMPS 1.3 pins
//
#include "pins_RAMPS_13.h" // ... RAMPS

//
// Heated bed
//
 #if ENABLED(WITBOX2_HEATED_BED)
   #undef HEATER_BED_PIN
   #define HEATER_BED_PIN                       10  // HEATER_1_PIN
 #endif
