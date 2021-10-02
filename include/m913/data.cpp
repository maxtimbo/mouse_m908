/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

/*
 * This file contains internal constants and lookup tables
 */

#include "../rd_mouse.h"

const std::string mouse_m913::_c_name = "913";

// usb device vars
const uint16_t mouse_m913::_c_mouse_vid = 0x25a7;
std::set< uint16_t > mouse_m913::_c_all_pids = {
	0xfa07, // wireless connection
	0xfa08  // wired connection
};

// Names of the physical buttons
std::map< int, std::string > mouse_m913::_c_button_names = {
	{ 0, "button_1" }, // ok
	{ 1, "button_2" }, // ok
	{ 2, "button_3" },
	{ 3, "button_4" },
	{ 4, "button_5" },
	{ 5, "button_6" },
	{ 6, "button_right" },
	{ 7, "button_left" },
	{ 8, "button_7" },
	{ 9, "button_8" },
	{ 10, "button_middle" },
	{ 11, "button_fire" },
	{ 12, "button_9" },
	{ 13, "button_10" },
	{ 14, "button_11" },
	{ 15, "button_12" }
};

std::map< std::string, std::array<uint8_t, 4> > mouse_m913::_c_keycodes = {
	{ "left", { 0x01, 0x01, 0x00, 0x53 } },
	{ "right", { 0x01, 0x02, 0x00, 0x52 } },
	{ "middle", { 0x01, 0x04, 0x00, 0x50 } },
	{ "back", { 0x01, 0x08, 0x00, 0x4c } },
	{ "forward", { 0x01, 0x10, 0x00, 0x44 } },
	{ "led_toggle", { 0x08, 0x00, 0x00, 0x4d } },
	{ "polling_rate", { 0x08, 0x00, 0x00, 0x4e } },
	{ "none", { 0x05, 0x00, 0x00, 0x50 } }
};

// DPI → bytecode
std::map< int, std::array<uint8_t,3> > mouse_m913::_c_dpi_codes = {
	{ 100,   { 0x00, 0x00, 0x55 } }, // minimum DPI
	{ 200,   { 0x02, 0x02, 0x51 } },
	{ 300,   { 0x03, 0x03, 0x4f } },
	{ 400,   { 0x04, 0x04, 0x4d } },
	{ 500,   { 0x05, 0x05, 0x4b } },
	{ 600,   { 0x06, 0x06, 0x49 } },
	{ 700,   { 0x07, 0x07, 0x47 } },
	{ 800,   { 0x09, 0x09, 0x43 } },
	{ 900,   { 0x0a, 0x0a, 0x41 } },
	{ 1000,  { 0x0b, 0x0b, 0x3f } },
	{ 1100,  { 0x0c, 0x0c, 0x3d } },
	{ 1200,  { 0x0d, 0x0d, 0x3b } },
	{ 1300,  { 0x0e, 0x0e, 0x39 } },
	{ 1400,  { 0x10, 0x10, 0x35 } },
	{ 1500,  { 0x11, 0x11, 0x33 } },
	{ 1600,  { 0x12, 0x12, 0x31 } },
	{ 1700,  { 0x13, 0x13, 0x2f } },
	{ 1800,  { 0x14, 0x14, 0x2d } },
	{ 1900,  { 0x16, 0x16, 0x29 } },
	{ 2000,  { 0x17, 0x17, 0x27 } },
	{ 2100,  { 0x18, 0x18, 0x25 } },
	{ 2200,  { 0x19, 0x19, 0x23 } },
	{ 2300,  { 0x1a, 0x1a, 0x21 } },
	{ 2400,  { 0x1b, 0x1b, 0x1f } },
	{ 2500,  { 0x1d, 0x1d, 0x1b } },
	{ 2600,  { 0x1e, 0x1e, 0x19 } },
	{ 2700,  { 0x1f, 0x1f, 0x17 } },
	{ 2800,  { 0x20, 0x20, 0x15 } },
	{ 2900,  { 0x21, 0x21, 0x13 } },
	{ 3000,  { 0x23, 0x23, 0x0f } },
	{ 3100,  { 0x25, 0x25, 0x0b } },
	{ 3200,  { 0x26, 0x26, 0x09 } },
	{ 3300,  { 0x27, 0x27, 0x07 } },
	{ 3400,  { 0x28, 0x28, 0x05 } },
	{ 3500,  { 0x29, 0x29, 0x03 } },
	{ 3600,  { 0x2a, 0x2a, 0x01 } },
	{ 3700,  { 0x2c, 0x2c, 0xfd } },
	{ 3800,  { 0x2d, 0x2d, 0xfb } },
	{ 3900,  { 0x2e, 0x2e, 0xf9 } },
	{ 4000,  { 0x2f, 0x2f, 0xf7 } },
	{ 4100,  { 0x30, 0x30, 0xf5 } },
	{ 4200,  { 0x32, 0x32, 0xf1 } },
	{ 4300,  { 0x33, 0x33, 0xef } },
	{ 4400,  { 0x34, 0x34, 0xed } },
	{ 4500,  { 0x35, 0x35, 0xeb } },
	{ 4600,  { 0x36, 0x36, 0xe9 } },
	{ 4700,  { 0x38, 0x38, 0xe5 } },
	{ 4800,  { 0x39, 0x39, 0xe3 } },
	{ 4900,  { 0x3a, 0x3a, 0xe1 } },
	{ 5000,  { 0x3b, 0x3b, 0xdf } },
	{ 5100,  { 0x3c, 0x3c, 0xdd } },
	{ 5200,  { 0x3e, 0x3e, 0xd9 } },
	{ 5300,  { 0x3f, 0x3f, 0xd7 } },
	{ 5400,  { 0x40, 0x40, 0xd5 } },
	{ 5500,  { 0x41, 0x41, 0xd3 } },
	{ 5600,  { 0x42, 0x42, 0xd1 } },
	{ 5700,  { 0x44, 0x44, 0xcd } },
	{ 5800,  { 0x45, 0x45, 0xcb } },
	{ 5900,  { 0x46, 0x46, 0xc9 } },
	{ 6000,  { 0x47, 0x47, 0xc7 } },
	{ 6100,  { 0x49, 0x49, 0xc3 } },
	{ 6200,  { 0x4a, 0x4a, 0xc1 } },
	{ 6300,  { 0x4b, 0x4b, 0xbf } },
	{ 6400,  { 0x4c, 0x4c, 0xbd } },
	{ 6500,  { 0x4d, 0x4d, 0xbb } },
	{ 6600,  { 0x4f, 0x4f, 0xb7 } },
	{ 6700,  { 0x50, 0x50, 0xb5 } },
	{ 6800,  { 0x51, 0x51, 0xb3 } },
	{ 6900,  { 0x52, 0x52, 0xb1 } },
	{ 7000,  { 0x53, 0x53, 0xaf } },
	{ 7100,  { 0x55, 0x55, 0xab } },
	{ 7200,  { 0x56, 0x56, 0xa9 } },
	{ 7300,  { 0x57, 0x57, 0xa7 } },
	{ 7400,  { 0x58, 0x58, 0xa5 } },
	{ 7500,  { 0x59, 0x59, 0xa3 } },
	{ 7600,  { 0x5b, 0x5b, 0x9f } },
	{ 7700,  { 0x5c, 0x5c, 0x9d } },
	{ 7800,  { 0x5d, 0x5d, 0x9b } },
	{ 7900,  { 0x5e, 0x5e, 0x99 } },
	{ 8000,  { 0x5f, 0x5f, 0x97 } },
	{ 8100,  { 0x61, 0x61, 0x93 } },
	{ 8200,  { 0x62, 0x62, 0x91 } },
	{ 8300,  { 0x63, 0x63, 0x8f } },
	{ 8400,  { 0x64, 0x64, 0x8d } },
	{ 8500,  { 0x65, 0x65, 0x8b } },
	{ 8600,  { 0x67, 0x67, 0x87 } },
	{ 8700,  { 0x68, 0x68, 0x85 } },
	{ 8800,  { 0x69, 0x69, 0x83 } },
	{ 8900,  { 0x6a, 0x6a, 0x81 } },
	{ 9000,  { 0x6b, 0x6b, 0x7f } },
	{ 9100,  { 0x6d, 0x6d, 0x7b } },
	{ 9200,  { 0x6e, 0x6e, 0x79 } },
	{ 9300,  { 0x6f, 0x6f, 0x77 } },
	{ 9400,  { 0x70, 0x70, 0x75 } },
	{ 9500,  { 0x71, 0x71, 0x73 } },
	{ 9600,  { 0x73, 0x73, 0x6f } },
	{ 9700,  { 0x74, 0x74, 0x6d } },
	{ 9800,  { 0x75, 0x75, 0x6b } },
	{ 9900,  { 0x76, 0x76, 0x69 } },
	{ 10000, { 0x77, 0x77, 0x67 } },
	{ 10100, { 0x79, 0x79, 0x63 } },
	{ 10200, { 0x7a, 0x7a, 0x61 } },
	{ 10300, { 0x7b, 0x7b, 0x5f } },
	{ 10400, { 0x7c, 0x7c, 0x5d } },
	{ 10500, { 0x7d, 0x7d, 0x5b } },
	{ 10600, { 0x7f, 0x7f, 0x57 } },
	{ 10700, { 0x80, 0x80, 0x55 } },
	{ 10800, { 0x81, 0x81, 0x53 } },
	{ 10900, { 0x82, 0x82, 0x51 } },
	{ 11000, { 0x83, 0x83, 0x4f } },
	{ 11100, { 0x85, 0x85, 0x4b } },
	{ 11200, { 0x86, 0x86, 0x49 } },
	{ 11300, { 0x87, 0x87, 0x47 } },
	{ 11400, { 0x88, 0x88, 0x45 } },
	{ 11500, { 0x89, 0x89, 0x43 } },
	{ 11600, { 0x8b, 0x8b, 0x3f } },
	{ 11700, { 0x8c, 0x8c, 0x3d } },
	{ 11800, { 0x8d, 0x8d, 0x3b } },
	{ 11900, { 0x8e, 0x8e, 0x39 } },
	{ 12000, { 0x8f, 0x8f, 0x37 } },
	{ 12100, { 0x91, 0x91, 0x33 } },
	{ 12200, { 0x92, 0x92, 0x31 } },
	{ 12300, { 0x93, 0x93, 0x2f } },
	{ 12400, { 0x94, 0x94, 0x2d } },
	{ 12500, { 0x95, 0x95, 0x2b } },
	{ 12600, { 0x97, 0x97, 0x27 } },
	{ 12700, { 0x98, 0x98, 0x25 } },
	{ 12800, { 0x99, 0x99, 0x23 } },
	{ 12900, { 0x9a, 0x9a, 0x21 } },
	{ 13000, { 0x9b, 0x9b, 0x1f } },
	{ 13100, { 0x9d, 0x9d, 0x1b } },
	{ 13200, { 0x9e, 0x9e, 0x19 } },
	{ 13300, { 0x9f, 0x9f, 0x17 } },
	{ 13400, { 0xa0, 0xa0, 0x15 } },
	{ 13500, { 0xa1, 0xa1, 0x13 } },
	{ 13600, { 0xa3, 0xa3, 0x0f } },
	{ 13700, { 0xa4, 0xa4, 0x0d } },
	{ 13800, { 0xa5, 0xa5, 0x0b } },
	{ 13900, { 0xa6, 0xa6, 0x09 } },
	{ 14000, { 0xa7, 0xa7, 0x07 } },
	{ 14100, { 0xa8, 0xa8, 0x05 } },
	{ 14200, { 0xaa, 0xaa, 0x01 } },
	{ 14300, { 0xab, 0xab, 0xff } },
	{ 14400, { 0xac, 0xac, 0xfd } },
	{ 14500, { 0xad, 0xad, 0xfb } },
	{ 14600, { 0xae, 0xae, 0xf9 } },
	{ 14700, { 0xb0, 0xb0, 0xf5 } },
	{ 14800, { 0xb1, 0xb1, 0xf3 } },
	{ 14900, { 0xb2, 0xb2, 0xf1 } },
	{ 15000, { 0xb3, 0xb3, 0xef } },
	{ 15100, { 0xb4, 0xb4, 0xed } },
	{ 15200, { 0xb5, 0xb5, 0xeb } },
	{ 15300, { 0xb6, 0xb6, 0xe9 } },
	{ 15400, { 0xb7, 0xb7, 0xe7 } },
	{ 15500, { 0xb8, 0xb8, 0xe5 } },
	{ 15600, { 0xb9, 0xb9, 0xe3 } },
	{ 15700, { 0xba, 0xba, 0xe1 } },
	{ 15800, { 0xbb, 0xbb, 0xdf } },
	{ 15900, { 0xbc, 0xbc, 0xdd } },
	{ 16000, { 0xbd, 0xbd, 0xdb } }  // maximum DPI
};

//usb data packets
uint8_t mouse_m913::_c_data_unknown_1[11][17] = {
	{0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49},
	{0x08, 0x07, 0x00, 0x01, 0x20, 0x08, 0x02, 0x80, 0x04, 0x00, 0x40, 0x04, 0x00, 0x8b, 0x00, 0x00, 0xc8},
	{0x08, 0x07, 0x00, 0x01, 0x40, 0x08, 0x02, 0x81, 0x20, 0x00, 0x41, 0x20, 0x00, 0x51, 0x00, 0x00, 0xa8},
	{0x08, 0x07, 0x00, 0x01, 0x80, 0x08, 0x02, 0x81, 0x22, 0x00, 0x41, 0x22, 0x00, 0x4d, 0x00, 0x00, 0x68},
	{0x08, 0x07, 0x00, 0x01, 0xa0, 0x08, 0x02, 0x81, 0x23, 0x00, 0x41, 0x23, 0x00, 0x4b, 0x00, 0x00, 0x48},
	{0x08, 0x07, 0x00, 0x02, 0x00, 0x08, 0x02, 0x81, 0x24, 0x00, 0x41, 0x24, 0x00, 0x49, 0x00, 0x00, 0xe7},
	{0x08, 0x07, 0x00, 0x02, 0x20, 0x08, 0x02, 0x81, 0x25, 0x00, 0x41, 0x25, 0x00, 0x47, 0x00, 0x00, 0xc7},
	{0x08, 0x07, 0x00, 0x02, 0x80, 0x08, 0x02, 0x81, 0x26, 0x00, 0x41, 0x26, 0x00, 0x45, 0x00, 0x00, 0x67},
	{0x08, 0x07, 0x00, 0x02, 0xa0, 0x08, 0x02, 0x81, 0x27, 0x00, 0x41, 0x27, 0x00, 0x43, 0x00, 0x00, 0x47},
	{0x08, 0x07, 0x00, 0x02, 0xc0, 0x08, 0x02, 0x81, 0x57, 0x00, 0x41, 0x57, 0x00, 0xe3, 0x00, 0x00, 0x27},
	{0x08, 0x07, 0x00, 0x02, 0xe0, 0x08, 0x02, 0x81, 0x56, 0x00, 0x41, 0x56, 0x00, 0xe5, 0x00, 0x00, 0x07},
};

uint8_t mouse_m913::_c_data_button_mapping[8][17] = {
	{0x08, 0x07, 0x00, 0x00, 0x60, 0x08, 0x00, 0x00, 0x00, 0x55, 0x05, 0x00, 0x00, 0x50, 0x00, 0x00, 0x34},
	{0x08, 0x07, 0x00, 0x00, 0x68, 0x08, 0x05, 0x00, 0x00, 0x50, 0x01, 0x08, 0x00, 0x4c, 0x00, 0x00, 0x2c},
	{0x08, 0x07, 0x00, 0x00, 0x70, 0x08, 0x05, 0x00, 0x00, 0x50, 0x05, 0x00, 0x00, 0x50, 0x00, 0x00, 0x24},
	{0x08, 0x07, 0x00, 0x00, 0x78, 0x08, 0x01, 0x02, 0x00, 0x52, 0x01, 0x01, 0x00, 0x53, 0x00, 0x00, 0x1c},
	{0x08, 0x07, 0x00, 0x00, 0x80, 0x08, 0x05, 0x00, 0x00, 0x50, 0x05, 0x00, 0x00, 0x50, 0x00, 0x00, 0x14},
	{0x08, 0x07, 0x00, 0x00, 0x88, 0x08, 0x01, 0x04, 0x00, 0x50, 0x04, 0x14, 0x03, 0x3a, 0x00, 0x00, 0x0c},
	{0x08, 0x07, 0x00, 0x00, 0x90, 0x08, 0x05, 0x00, 0x00, 0x50, 0x05, 0x00, 0x00, 0x50, 0x00, 0x00, 0x04},
	{0x08, 0x07, 0x00, 0x00, 0x98, 0x08, 0x05, 0x00, 0x00, 0x50, 0x05, 0x00, 0x00, 0x50, 0x00, 0x00, 0xfc},
};

uint8_t mouse_m913::_c_data_dpi[4][17]= {
	{0x08, 0x07, 0x00, 0x00, 0x0c, 0x08, 0x00, 0x00, 0x00, 0x55, 0x02, 0x02, 0x00, 0x51, 0x00, 0x00, 0x88},
	{0x08, 0x07, 0x00, 0x00, 0x14, 0x08, 0x03, 0x03, 0x00, 0x4f, 0x04, 0x04, 0x00, 0x4d, 0x00, 0x00, 0x80},
	{0x08, 0x07, 0x00, 0x00, 0x1c, 0x04, 0x05, 0x05, 0x00, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd1},
	{0x08, 0x07, 0x00, 0x00, 0x02, 0x02, 0x05, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xed},
};

uint8_t mouse_m913::_c_data_unknown_2[3][17] = {
	{0x08, 0x07, 0x00, 0x00, 0x2c, 0x08, 0xff, 0x00, 0x00, 0x56, 0x00, 0x00, 0xff, 0x56, 0x00, 0x00, 0x68},
	{0x08, 0x07, 0x00, 0x00, 0x34, 0x08, 0x00, 0xff, 0x00, 0x56, 0xff, 0xff, 0x00, 0x57, 0x00, 0x00, 0x60},
	{0x08, 0x07, 0x00, 0x00, 0x3c, 0x04, 0xff, 0x55, 0x7d, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb1},
};

uint8_t mouse_m913::_c_data_led_static[3][17] = {
	{0x08, 0x07, 0x00, 0x00, 0x54, 0x08, 0xff, 0x00, 0x00, 0x57, 0x01, 0x54, 0xff, 0x56, 0x00, 0x00, 0xeb},
	{0x08, 0x07, 0x00, 0x00, 0x00, 0x02, 0x02, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef},
	{0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49},
};

uint8_t mouse_m913::_c_data_led_breathing[3][17] = {
	{0x08, 0x07, 0x00, 0x00, 0x54, 0x08, 0xff, 0x00, 0x00, 0x57, 0x01, 0x54, 0xff, 0x56, 0x00, 0x00, 0xeb},
	{0x08, 0x07, 0x00, 0x00, 0x5c, 0x02, 0x03, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x93},
	{0x08, 0x07, 0x00, 0x00, 0x00, 0x02, 0x01, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef},
};

uint8_t mouse_m913::_c_data_led_off[2][17] = {
	{0x08, 0x07, 0x00, 0x00, 0x58, 0x02, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x97},
	{0x08, 0x07, 0x00, 0x00, 0x00, 0x02, 0x01, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef},
};

uint8_t mouse_m913::_c_data_unknown_3[1][17] = {
	//{0x08, 0x07, 0x00, 0x00, 0x5c, 0x02, 0x03, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x93},
	{0x08, 0x07, 0x00, 0x00, 0x00, 0x02, 0x02, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef},
};

uint8_t mouse_m913::_c_data_read[69][17] = {
	{0x08, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a},
	{0x08, 0x01, 0x00, 0x00, 0x00, 0x04, 0x34, 0x2e, 0x4c, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43},
	{0x08, 0x08, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f},
	{0x08, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49},
	{0x08, 0x08, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b},
	{0x08, 0x08, 0x00, 0x00, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31},
	{0x08, 0x08, 0x00, 0x00, 0x14, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27},
	{0x08, 0x08, 0x00, 0x00, 0x1e, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d},
	{0x08, 0x08, 0x00, 0x00, 0x28, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13},
	{0x08, 0x08, 0x00, 0x00, 0x32, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09},
	{0x08, 0x08, 0x00, 0x00, 0x3c, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff},
	{0x08, 0x08, 0x00, 0x00, 0x46, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf5},
	{0x08, 0x08, 0x00, 0x00, 0x50, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xeb},
	{0x08, 0x08, 0x00, 0x00, 0x5a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe1},
	{0x08, 0x08, 0x00, 0x00, 0x64, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd7},
	{0x08, 0x08, 0x00, 0x00, 0x6e, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcd},
	{0x08, 0x08, 0x00, 0x00, 0x78, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3},
	{0x08, 0x08, 0x00, 0x00, 0x82, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb9},
	{0x08, 0x08, 0x00, 0x00, 0x8c, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaf},
	{0x08, 0x08, 0x00, 0x00, 0x96, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5},
	{0x08, 0x08, 0x00, 0x01, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3a},
	{0x08, 0x08, 0x00, 0x01, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30},
	{0x08, 0x08, 0x00, 0x01, 0x20, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1a},
	{0x08, 0x08, 0x00, 0x01, 0x2a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0x08, 0x08, 0x00, 0x01, 0x40, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfa},
	{0x08, 0x08, 0x00, 0x01, 0x4a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0},
	{0x08, 0x08, 0x00, 0x01, 0x60, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xda},
	{0x08, 0x08, 0x00, 0x01, 0x6a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd0},
	{0x08, 0x08, 0x00, 0x01, 0x80, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xba},
	{0x08, 0x08, 0x00, 0x01, 0x8a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0},
	{0x08, 0x08, 0x00, 0x01, 0xa0, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9a},
	{0x08, 0x08, 0x00, 0x01, 0xaa, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90},
	{0x08, 0x08, 0x00, 0x01, 0xc0, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7a},
	{0x08, 0x08, 0x00, 0x01, 0xca, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70},
	{0x08, 0x08, 0x00, 0x01, 0xe0, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5a},
	{0x08, 0x08, 0x00, 0x01, 0xea, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50},
	{0x08, 0x08, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39},
	{0x08, 0x08, 0x00, 0x02, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f},
	{0x08, 0x08, 0x00, 0x02, 0x20, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19},
	{0x08, 0x08, 0x00, 0x02, 0x2a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f},
	{0x08, 0x08, 0x00, 0x02, 0x40, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf9},
	{0x08, 0x08, 0x00, 0x02, 0x4a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef},
	{0x08, 0x08, 0x00, 0x02, 0x60, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd9},
	{0x08, 0x08, 0x00, 0x02, 0x6a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcf},
	{0x08, 0x08, 0x00, 0x02, 0x80, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb9},
	{0x08, 0x08, 0x00, 0x02, 0x8a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaf},
	{0x08, 0x08, 0x00, 0x02, 0xa0, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x99},
	{0x08, 0x08, 0x00, 0x02, 0xaa, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8f},
	{0x08, 0x08, 0x00, 0x02, 0xc0, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79},
	{0x08, 0x08, 0x00, 0x02, 0xca, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6f},
	{0x08, 0x08, 0x00, 0x02, 0xe0, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x59},
	{0x08, 0x08, 0x00, 0x02, 0xea, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f},
	{0x08, 0x08, 0x00, 0x03, 0x01, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37},
	{0x08, 0x08, 0x00, 0x04, 0x81, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6},
	{0x08, 0x08, 0x00, 0x06, 0x01, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34},
	{0x08, 0x08, 0x00, 0x07, 0x81, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb3},
	{0x08, 0x08, 0x00, 0x09, 0x01, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31},
	{0x08, 0x08, 0x00, 0x0a, 0x81, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0},
	{0x08, 0x08, 0x00, 0x0c, 0x01, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e},
	{0x08, 0x08, 0x00, 0x0d, 0x81, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xad},
	{0x08, 0x08, 0x00, 0x0f, 0x01, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2b},
	{0x08, 0x08, 0x00, 0x10, 0x81, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa},
	{0x08, 0x08, 0x00, 0x12, 0x01, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28},
	{0x08, 0x08, 0x00, 0x13, 0x81, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa7},
	{0x08, 0x08, 0x00, 0x15, 0x01, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25},
	{0x08, 0x08, 0x00, 0x16, 0x81, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa4},
	{0x08, 0x08, 0x00, 0x18, 0x01, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22},
	{0x08, 0x08, 0x00, 0x19, 0x81, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa1},
	{0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49},
};