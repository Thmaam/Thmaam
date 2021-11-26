#include <unistd.h>
//#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ARDUINO_WAIT_TIME 2000
#define MAX_DATA_LENGTH 25

#define MIN_SECONDS 1
#define MAX_SECONDS 60
#define MAX_BUSINESS 1


typedef struct
{
	HANDLE handler;
	bool connected;
	COMSTAT status;
	DWORD errors;
}SERIALPORT;

SERIALPORT SerialInit(char* portName);
void SerialReadToNewLine(SERIALPORT port, char* buffer, unsigned int buf_size);
int SerialReadPort(SERIALPORT port, char* buffer, unsigned int buf_size);
bool SerialWritePort(SERIALPORT port, char* buffer, unsigned int buf_size);
bool SerialIsConnected(SERIALPORT port);
void SerialClose(SERIALPORT port);
