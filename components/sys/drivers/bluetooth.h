/*
 * Copyright (C) 2015 - 2018, IBEROXARXA SERVICIOS INTEGRALES, S.L.
 * Copyright (C) 2015 - 2018, Jaume Olivé Petrus (jolive@whitecatboard.org)
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *     * The WHITECAT logotype cannot be changed, you can remove it, but you
 *       cannot change it in any way. The WHITECAT logotype is:
 *
 *          /\       /\
 *         /  \_____/  \
 *        /_____________\
 *        W H I T E C A T
 *
 *     * Redistributions in binary form must retain all copyright notices printed
 *       to any local or remote output device. This include any reference to
 *       Lua RTOS, whitecatboard.org, Lua, and other copyright notices that may
 *       appear in the future.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Lua RTOS, BT driver
 *
 */

#ifndef BT_H_
#define BT_H_

#include "bluetooth_hci.h"
#include "esp_bt.h"

#include <stdint.h>

#include <sys/driver.h>

// BT modes
typedef enum {
	Idle = 0,
	BLE = 1,
	Classic = 2,
	Dual = 3
} bt_mode_t;

typedef uint8_t bt_adress_t[6];

// BT errors
#define BT_ERR_CANT_INIT			 	 (DRIVER_EXCEPTION_BASE(BT_DRIVER_ID) |  0)
#define BT_ERR_INVALID_MODE   		 	 (DRIVER_EXCEPTION_BASE(BT_DRIVER_ID) |  1)
#define BT_ERR_IS_NOT_SETUP   		 	 (DRIVER_EXCEPTION_BASE(BT_DRIVER_ID) |  2)
#define BT_ERR_NOT_ENOUGH_MEMORY	 	 (DRIVER_EXCEPTION_BASE(BT_DRIVER_ID) |  3)
#define BT_ERR_INVALID_ARGUMENT	 		 (DRIVER_EXCEPTION_BASE(BT_DRIVER_ID) |  4)
#define BT_ERR_INVALID_BEACON	 		 (DRIVER_EXCEPTION_BASE(BT_DRIVER_ID) |  5)

driver_error_t *bt_setup(bt_mode_t mode);
driver_error_t *bt_reset();
driver_error_t *bt_adv_start(bte_advertise_params_t params, uint8_t *adv_data, uint16_t adv_data_len);
driver_error_t *bt_adv_stop();

extern const int bt_errors;
extern const int bt_error_map;

#include "bluetooth_eddystone.h"

#endif /* BT_H_ */
