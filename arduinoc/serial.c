#include "serial.h"

SERIALPORT SerialInit(char* portName)
{
	SERIALPORT port;
	port.connected = false;

	port.handler = CreateFileA(portName,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (port.handler == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {
			printf("ERROR: Handle was not attached. Reason: %s not available\n", portName);
		}
		else
		{
			printf("ERROR!!!");
		}
	}
	else {
		DCB dcbSerialParameters = { 0 };

		if (!GetCommState(port.handler, &dcbSerialParameters)) {
			printf("failed to get current serial parameters");
		}
		else {
			dcbSerialParameters.BaudRate = CBR_9600;
			dcbSerialParameters.ByteSize = 8;
			dcbSerialParameters.StopBits = ONESTOPBIT;
			dcbSerialParameters.Parity = NOPARITY;
			dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

			if (!SetCommState(port.handler, &dcbSerialParameters))
			{
				printf("ALERT: could not set Serial port parameters\n");
			}
			else {
				port.connected = true;
				PurgeComm(port.handler, PURGE_RXCLEAR | PURGE_TXCLEAR);
				Sleep(ARDUINO_WAIT_TIME);
			}
		}
	}
	return port;
}

void SerialReadToNewLine(SERIALPORT port, char* buffer, unsigned int buf_size)
{
	ClearCommError(port.handler, &port.errors, &port.status);
	int pos = 0;
	while (true)
	{
		char b[10];
		DWORD bytesRead;
		if (ReadFile(port.handler, b, 1, &bytesRead, NULL) == 1)
		{
			if (b[0] == '\n')
			{
				buffer[pos] = 0;
				return;
			}
			buffer[pos] = b[0];
			pos++;
		}
	}
}


int SerialReadPort(SERIALPORT port, char* buffer, unsigned int buf_size)
{
	DWORD bytesRead;
	unsigned int toRead = 0;

	ClearCommError(port.handler, &port.errors, &port.status);

	if (port.status.cbInQue > 0) {
		if (port.status.cbInQue > buf_size) {
			toRead = buf_size;
		}
		else toRead = port.status.cbInQue;
	}

	memset(buffer, 0, buf_size);

	if (ReadFile(port.handler, buffer, toRead, &bytesRead, NULL)) return bytesRead;

	return 0;
}

bool SerialWritePort(SERIALPORT port, char* buffer, unsigned int buf_size)
{
	DWORD bytesSend;

	if (!WriteFile(port.handler, (void*)buffer, buf_size, &bytesSend, 0)) {
		ClearCommError(port.handler, &port.errors, &port.status);
		return false;
	}
	else return true;
}

bool SerialIsConnected(SERIALPORT port)
{

	if (!ClearCommError(port.handler, &port.errors, &port.status))
		port.connected = false;

	return port.connected;
}

void SerialClose(SERIALPORT port)
{
	CloseHandle(port.handler);
}