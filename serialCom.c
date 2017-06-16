/*
* serialCom.c
*
* Created: 28.05.2017 11:16:25
*  Author: philipp
*/
#include "serialCom.h"
#include <stdio.h>
#include <stdarg.h>

static int uart_initialized = 0;
static int uart_putchar(char c, FILE *stream) {
    if (c == '\n') {
        uart_putchar('\r', stream);
    }
    /* Wait for empty transmit buffer */
    while (!(UCSRA & (1 << UDRE)));
    /* Put data into buffer, sends the data */
    UDR = (uint8_t) c;
    return 0;
}
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);


void SerialInit(uint32_t baud) {
    if (!uart_initialized) {
        uint16_t baudrate = (uint16_t) (F_CPU / (16 * baud)) - 1;
        UBRRH = (unsigned char) (baudrate >> 8);
        UBRRL = (unsigned char) baudrate;
        /* Enable receiver and transmitter */
        UCSRB = (1 << RXEN) | (1 << TXEN);
        /* Set frame format: 8data, 1stop bit */
        UCSRC = (1 << URSEL) | (3 << UCSZ0);
        //
        stdout = &mystdout;
        //
        uart_initialized = 1;
    }
}

void SerialPrint(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

void SerialPrintln(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
#ifdef UNIX_HOST
    printf("\n");
#endif
#ifdef WINDOWS_HOST
    printf("\r\n");
#endif
}
