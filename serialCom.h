/*
 * serialCom.h
 *
 * Created: 28.05.2017 11:16:49
 *  Author: philipp
 */ 

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define UNIX_HOST // WINDOWS_HOST

#ifndef SERIALCOM_H_
#define SERIALCOM_H_

#include <avr/io.h>
#include <stdio.h>
#include <stdarg.h>

void SerialInit(uint32_t baud);

void SerialPrint(const char *fmt, ...);  // works like printf
void SerialPrintln(const char *fmt, ...);  // works like printf always adds newline

#endif /* SERIALCOM_H_ */
