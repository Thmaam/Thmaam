
#include "serial.h"
//#define _CRT_SECURE_NO_WARNINGS 
typedef struct advertising
{
	char adTxt[50];
	int payment;
	int sum;
};

int main() {

	SERIALPORT port = SerialInit  ("\\\\.\\COM5");
	//SERIALPORT port6 = SerialInit ("\\\\.\\COM6");
	if (!SerialIsConnected(port))
	{
		printf("Error");
		return;
	}
	struct advertising arr_advertising[MAX_BUSINESS];
	int i;

	for (i = 0; i < MAX_BUSINESS; i++)
	{
		printf("\nEnter details of advertising %d\n\n", i + 1);

		printf("Enter name: ");
		scanf("%s", &arr_advertising[i].adTxt);

		printf("Enter how much do you want to pay   : ");
		scanf("%d", &arr_advertising[i].payment);

		arr_advertising[i].sum = arr_advertising[i].payment / 60;


	}



	for (i = 0; i < MAX_BUSINESS; i++)
	{
		printf(" %s\nYou have got %d\n", arr_advertising[i].adTxt, arr_advertising[i].sum);



		int count = strlen(arr_advertising[i].adTxt);

		//SerialWritePort(port, count, sizeof(count));
		SerialWritePort(port, arr_advertising[i].adTxt, count);
		//printf("%s, %d\n", arr_advertising[i].adTxt, count);

		//SerialWritePort(port6, count, sizeof(count));
		//SerialWritePort(port6, arr_advertising[i].adTxt, count);
		//SerialWritePort(port, "<CLEARALL>", strlen("<CLEARALL>"));
	}
	

	printf("Write success");

	//SerialClose(port);
	//SerialClose(port6);


	return 0;
}



