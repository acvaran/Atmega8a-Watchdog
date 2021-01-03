/*
 * WatchDog.h
 *
 * Created: 3.01.2021 23:30:04
 *  Author: Ahmet Can Varan
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#define MODE_16_3_MS					0x00
#define MODE_32_5_MS					0x01
#define MODE_65_MS						0x02
#define MODE_0_13_S						0x03
#define MODE_0_26_S						0x04
#define MODE_0_52_S						0x05
#define MODE_1_S						0x06
#define MODE_2_1_S						0x07

uint8_t mode;
void WatchDog_initialize(uint8_t mode);
void WatchDog_reset(void);
void WatchDog_disable(void);
void WatchDog_enable(void);

#endif /* WATCHDOG_H_ */