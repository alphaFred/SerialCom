# SerialCom serial library for Atmega8

Simple and easy to use serial library for Atmega8. The library is based upon 
the printf functionality, mapped onto the UARt of the microcontroller.


# Usage

In order to correctly calculate the baud rate, the macro **F_CPU** must be defined.
Secondly the user has to define his host operating system in order to receive the 
correct line termination. This is done by either defining **UNIX_HOST** or **WINDOWS_HOST**.

# Interface

```
// Initialize serial communication
void SerialInit(uint32_t baud);

// Print text to serial console
void SerialPrint(const char *fmt, ...);

// Print text to serial console and add newline automatically
void SerialPrintln(const char *fmt, ...);
```
