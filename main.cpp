/*+===================================================================

   File:      main.cpp

   Summary:   entry point into the SCS project

   Classes:   none

   Functions: none

   Origin:    none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

// standard header files
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

// project header files
#include "common.h"								// definitions shared by entire project
#include "global.h"								// definitions for global variables
#include "main.h"								// definitions for main program
#include "PoweredObject.h"						// definitions for PowerObject class

// declarations
PoweredObject myShip;

/*************************************************************************************************************************************
 * main - project entry point
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/08/2014   SDW   initial coding
 *************************************************************************************************************************************/
int main()
{
    std::cout << PROJECT_VERSION << std::endl;		// display project copyright notice
    readCommands();								// enter command loop
    return 0;									// exit
}

/*************************************************************************************************************************************
 * doCommand - console command processor
 *
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   SDW   initial coding
 *************************************************************************************************************************************/
bool doCommand(const char *input_buffer)
{
	// local variables
	int token;									// token for switch structure

	// return when command buffer is empty
	if (!strcmp(input_buffer, ""))
		return true;

	// parse command if possible
	token = parseCommand(input_buffer);

	// act on command
	switch (token)
	{
		// defined commands
		case quit:
			return false;
		case display:
			handle_display();
			return true;
		case resetvalues:
			handle_reset();
			return true;
		case setposition:
			handle_setposition(input_buffer);
			return true;
		case setthrust:
			handle_setthrust(input_buffer);
			return true;
		// unknown commands
		case unknown:
		default:
			std::cout << "    command not implemented: " << input_buffer << std::endl;
			return true;
	}
}

/*************************************************************************************************************************************
 * handle_display - execute display command
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/07/2014   SDW   initial coding
 *************************************************************************************************************************************/
bool handle_display(void)
{
	// local variables
	vect3D tempVector;

	// display ship status
	tempVector = myShip.getPositionG();
	std::cout << "Position [G] = (" << tempVector(x_coord) << "," << tempVector(y_coord) << "," << tempVector(z_coord) << ")" << std::endl;
	tempVector = myShip.getPositionL();
	std::cout << "Position [L] = (" << tempVector(x_coord) << "," << tempVector(y_coord) << "," << tempVector(z_coord) << ")" << std::endl;
	tempVector = myShip.getFacingG();
	std::cout << "Facing [G] = (" << tempVector(x_coord) << "," << tempVector(y_coord) << "," << tempVector(z_coord) << ")" << std::endl;
	tempVector = myShip.getFacingL();
	std::cout << "Facing [L] = (" << tempVector(x_coord) << "," << tempVector(y_coord) << "," << tempVector(z_coord) << ")" << std::endl;
	tempVector = myShip.getHeadingG();
	std::cout << "Heading [G] = (" << tempVector(x_coord) << "," << tempVector(y_coord) << "," << tempVector(z_coord) << ")" << std::endl;
	tempVector = myShip.getHeadingL();
	std::cout << "Heading [L] = (" << tempVector(x_coord) << "," << tempVector(y_coord) << "," << tempVector(z_coord) << ")" << std::endl;
	std::cout << "Velocity amount = " << myShip.getVelocityMag() << std::endl;
	std::cout << "Thrust amount = " << myShip.getThrust() << std::endl;
	return true;
}

/*************************************************************************************************************************************
 * handle_reset - execute reset command
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/09/2014   SDW   initial coding
 *************************************************************************************************************************************/
bool handle_reset(void)
{
	myShip.setOrientationG(0, 0, 0);			// set orientation to x=y=z=0
	myShip.setPositionG(0, 0, 0);				// set Position to x=y=z=0
	myShip.setThrust(0);						// set thrust to 0
	myShip.setVelocityG(myShip.getPositionG());		// set Velocity vector to null
	std::cout << "complete " << std::endl;
	return true;
}

/*************************************************************************************************************************************
 * handle_setposition - execute setposition command
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/07/2014   SDW   initial coding
 *************************************************************************************************************************************/
bool handle_setposition(const char *buf)
{
	// local variables
	stringstream ss (stringstream::in | stringstream::out);		// parsing stringstream
	string command;
	double x, y, z;
	vect3D checkpos;

	// process
	ss << buf;									// parse coordinates
	ss >> command >> x >> y >> z;
	std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
	myShip.setPositionG(x, y, z);				// set position
	checkpos = myShip.getPositionG();			// get position
	if ((x == checkpos(x_coord))&&				// compare current position to requested position
		(y == checkpos(y_coord))&&
		(z == checkpos(z_coord)))
	{
		std::cout << "confirmed " << std::endl;
		return true;
	}

	// TODO reset velocity vector

	return true;
}

/*************************************************************************************************************************************
 * handle_setthrust - execute setthrust command
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/08/2014   SDW   initial coding
 *************************************************************************************************************************************/
bool handle_setthrust(const char *buf)
{
	// local variables
	stringstream ss (stringstream::in | stringstream::out);		// parsing stringstream
	string command;
	int thrustAmount, checkAmount;

	// process
	ss << buf;									// parse thrust amount
	ss >> command >> thrustAmount;
	std::cout << "thrust = " << thrustAmount << std::endl;
	myShip.setThrust(thrustAmount);				// set thrust amount
	checkAmount = myShip.getThrust();			// get thrust amount
	if (thrustAmount == checkAmount)			// compare current thrust to requested thrust
	{
		std::cout << "confirmed " << std::endl;
		return true;
	}
	return true;
}

/*************************************************************************************************************************************
 * parseCommand - return switch token for command received
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/09/2014   SDW   initial coding
 *************************************************************************************************************************************/
int parseCommand(const char *buf)
{
	if ((!strcmp(buf, "quit")) || (!strcmp(buf, "exit"))) return quit;
	if (!strcmp(buf, "reset")) return resetvalues;
	if (!strcmp(buf, "display")) return display;
	if (!strncmp(buf, "setposition ", 12)) return setposition;
	if (!strncmp(buf, "setthrust ", 10)) return setthrust;
	return unknown;
}

/*************************************************************************************************************************************
 * readCommands - console command loop
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   05/08/2014   SDW   initial coding
 *************************************************************************************************************************************/
void readCommands()
{
	//local variables
	int next_char;								// next character
	char cmd_buffer[MAX_CMD_BUFF];				// command buffer
	int count = 0;								// index into command buffer

	// setup command prompt
    std::cout << "wt> ";						// send prompt
    std::cout.flush();							// flush the cout buffer

	// read a command and call doCommand:
	while ((next_char=getc(stdin)) != EOF)		// read characters until end of file
	{
		if (next_char == '\n')					// if next char is a newline then -
		{
			cmd_buffer[count] = '\0';				// write end of string
			if (!doCommand(cmd_buffer))				// execute the command, if returns false
				return;									// return to caller
			count = 0;								// reset index
			std::cout << "wt> ";					// resend prompt
			std::cout.flush();						// flush the cout buffer
		}
		else									// else - handle next character
		{
			if (count >= MAX_CMD_BUFF-1)			// check to see if command buffer will be overrun
			{
				std::cout << "Warning: command buffer full !! " << std::endl;	// yes - send error message
				count = 0;								// and reset index into command buffer
			}
			cmd_buffer[count++] = next_char;		// copy char into buffer and increment pointer
		}
	}
}

