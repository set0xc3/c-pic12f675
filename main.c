/*
 * File:   main.c
 * Author: duck
 *
 * Created on May 24, 2023, 2:46 AM
 */

// CONFIG
#pragma config FOSC = INTRCIO
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = OFF
#pragma config BOREN = OFF
#pragma config CP = OFF
#pragma config CPD = OFF

#define _XTAL_FREQ 4000000

#include <xc.h>

#include "defines.h"

#define CLOCK_SPEED 4000000

const u8 time_slot_divider = (1000000 / (CLOCK_SPEED / 64));
const u8 led_pin = 4;

void interrupt
isr()
{
    RP0 = 0;
    T0IE = 0;
    T0IF = 0;
    TMR0 = 0xFF;

    if (INTF)
    {
        GPIO4 = ~GPIO4;
        GPIO2 = 0;
        INTF = 0;
    }
}

void
main()
{
    RP0 = 0;
    GPIO = 0;
    CMCON = 0x07; // Disable comparator

    RP0 = 1;
    ANSEL = 0;  // Set ports as digital I/O, not analog input
    TRISIO = 0; // GP3 input, rest all output

    RP0 = 0;
    TMR0 = 0xFF;
    INTCON = 0;
    GIE = 1;
    T0IE = 1;
    PEIE = 1;
    INTE = 1;

    RP0 = 1;
    OPTION_REG = 0x7;
    INTEDG = 1;

    volatile u32 i = 0;

    while (1)
    {
        //        RP0 = 0;
        //        T0IE = 1;

        for (i = 0; i < 20000; i++)
            ;
        // __delay_ms(500);

        GPIO4 = ~GPIO4;
    }
}
