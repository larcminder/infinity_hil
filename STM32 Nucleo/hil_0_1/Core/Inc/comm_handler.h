/*
 * comm_handler.h
 *
 *  Created on: May 13, 2021
 *      Author: larcm
 */

#ifndef INC_COMM_HANDLER_H_
#define INC_COMM_HANDLER_H_

#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void transmit(char[]);
int analyzeCommand(uint8_t[]);
void digital(uint8_t[]);

#endif /* INC_COMM_HANDLER_H_ */


int analyzeCommand(uint8_t command[]) {
	int retValDelay = 1;



	switch(command[1]) {
		case 'a':	//Analog
			transmit("pDo something with the Analog IOs");
			break;

		case 'd':	//Digital
			digital(command);
			break;

		case 't':	//Timer
			transmit("pDo something with the Timer");
			break;

		case 'c':	//CAN
			transmit("pDo something with the CAN Bus");
			break;

		case 'p':	//Print echo
			transmit(command);
			break;

		case 'w':	//Delay answer
		{
			char hexArray[2] = {command[2], command[3]};
			retValDelay = strtol(hexArray, NULL, 16) * 100;
			char msg[30];
			sprintf(msg, "pDelay by %i ms", retValDelay);
			transmit(msg);
			break;
		}

		default:
			transmit("pInvalid Command Identifier");
	}
	return retValDelay;
}

void digital(uint8_t command[]) {
	switch(command[2]) {
		case 'w':	//write
			//Write command[4] to Channel command[3]
			transmit("pWrite to a Digital Pin");
			break;

		case 'r':	//read
			transmit("pRead from a Digital Pin");
			break;

		default:
			transmit("pInvalid Command Identifier");
	}
}
