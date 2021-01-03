/*
 * WatchDog.c
 *
 * Created: 3.01.2021 23:30:16
 *  Author: Ahmet Can Varan
 */ 


#include "WatchDog.h"

#define WATCHDOG_ENABLE()			(WDTCR |= (1 << WDCE) | (1 << WDE))

void WatchDog_initialize(uint8_t mode) {
	cli();
	mode = mode;
	if(mode == MODE_16_3_MS) {
		WATCHDOG_ENABLE();
		WDTCR &= ~(1 << WDP2) & ~(1 << WDP1) & ~(1 << WDP0);
	} else if (mode == MODE_32_5_MS) {
		WATCHDOG_ENABLE();
		WDTCR &= ~(1 << WDP2) & ~(1 << WDP1);
		WDTCR |= (1 << WDP0);
	} else if (mode == MODE_65_MS) {
		WATCHDOG_ENABLE();
		WDTCR &= ~(1 << WDP2) & ~(1 << WDP0);
		WDTCR |= (1 << WDP1);
	} else if (mode == MODE_0_13_S) {
		WATCHDOG_ENABLE();
		WDTCR &= ~(1 << WDP2);
		WDTCR |= (1 << WDP1) | (1 << WDP0);
	} else if (mode == MODE_0_26_S) {
		WATCHDOG_ENABLE();
		WDTCR &= ~(1 << WDP1) & ~(1 << WDP0);
		WDTCR |= (1 << WDP2);
	} else if (mode == MODE_0_52_S) {
		WATCHDOG_ENABLE();
		WDTCR &= ~(1 << WDP1);
		WDTCR |= (1 << WDP2) | (1 << WDP0);
	} else if (mode == MODE_1_S) {
		WATCHDOG_ENABLE();
		WDTCR &= ~(1 << WDP0);
		WDTCR |= (1 << WDP2) | (1 << WDP1);
	} else if (mode == MODE_2_1_S) {
		WATCHDOG_ENABLE();
		WDTCR |= (1 << WDP2) | (1 << WDP1) | (1 << WDP0);
	}
	sei();
}

void WatchDog_reset(void) {
	cli();
	MCUCSR &= ~(1 << WDRF);
	sei();
}

void WatchDog_disable(void) {
	cli();
	WATCHDOG_ENABLE();
	WDTCR &= ~(1 << WDE);
	sei();
}

void WatchDog_enable(void) {
	cli();
	WATCHDOG_ENABLE();
	sei();
}