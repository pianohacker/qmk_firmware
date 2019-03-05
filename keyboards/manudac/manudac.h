/* Copyright 2019 %YOUR_NAME%
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    kl00, kl01, kl02, kl03, kl04, kl05,                kr00, kr01, kr02, kr03, kr04, kr05, \
    kl10, kl11, kl12, kl13, kl14, kl15,                kr10, kr11, kr12, kr13, kr14, kr15, \
    kl20, kl21, kl22, kl23, kl24, kl25,                kr20, kr21, kr22, kr23, kr24, kr25, \
    kl30, kl31, kl32, kl33, kl34, kl35,                kr30, kr31, kr32, kr33, kr34, kr35, \
                kl40, kl41,    kl42, kl43,          kr40, kr41,    kr42, kr43, \
                                  kl50, kl53,     kr50, kr53, \
                                  kl51, kl52,     kr51, kr52  \
) \
{ \
	{ kl00, kl01, kl02, kl03, kl04, kl05 }, \
	{ kl10, kl11, kl12, kl13, kl14, kl15 }, \
	{ kl20, kl21, kl22, kl23, kl24, kl25 }, \
	{ kl30, kl31, kl32, kl33, kl34, kl35 }, \
	{ KC_NO, KC_NO, kl40, kl41, kl42, kl43 }, \
	{ KC_NO, KC_NO, kl50, kl51, kl52, kl53 }, \
	{ kr00, kr01, kr02, kr03, kr04, kr05 }, \
	{ kr10, kr11, kr12, kr13, kr14, kr15 }, \
	{ kr20, kr21, kr22, kr23, kr24, kr25 }, \
	{ kr30, kr31, kr32, kr33, kr34, kr35 }, \
	{ kr40, kr41, kr42, kr43, KC_NO, KC_NO }, \
	{ kr50, kr51, kr52, kr53, KC_NO, KC_NO }, \
}
