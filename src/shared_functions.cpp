/*+===================================================================

   File:      shared_functions.cpp

   Summary:   methods shared by entire project

   Classes:   none

   Functions: none

   Origin:    none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

// standard header files
#include <math.h>

// 3rd party header files

// project header files
#include "shared_functions.h"

/*************************************************************************************************************************************
 * Angles2Quat - converts yaw/pitch/roll (in degrees) to quaternion
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/05/2014   BSW   initial coding
 *************************************************************************************************************************************/
quat3D Angles2Quat(double y, double p, double r)
{
	// local variables
	quat3D results;
	double yaw, pitch, roll;

	// convert angles to radians
	yaw = Degrees2Rads(y);
	pitch = Degrees2Rads(p);
	roll = Degrees2Rads(y);
	// calculate values of quaternion
	results.w() = cosf(yaw / 2) * cosf(pitch / 2) * cosf(roll / 2) - sinf(yaw / 2) * sinf(pitch / 2) * sinf(roll / 2);
	results.x() = sinf(yaw / 2) * sinf(pitch / 2) * cosf(roll / 2) - cosf(yaw / 2) * cosf(pitch / 2) * sinf(roll / 2);
	results.y() = sinf(yaw / 2) * cosf(pitch / 2) * cosf(roll / 2) - cosf(yaw / 2) * sinf(pitch / 2) * sinf(roll / 2);
	results.z() = cosf(yaw / 2) * sinf(pitch / 2) * cosf(roll / 2) - sinf(yaw / 2) * cosf(pitch / 2) * sinf(roll / 2);
	// return results
	return results;
}

/*************************************************************************************************************************************
 * Angles2Quat - converts yaw/pitch/roll (in degrees) to quaternion
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/05/2014   BSW   initial coding
 *************************************************************************************************************************************/
quat3D Angles2Quat(vect3D n)
{
	return Angles2Quat(n(yaw_angle),n(pitch_angle),n(roll_angle));
}

/*************************************************************************************************************************************
 * Degrees2Rads - convert degrees to radians
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/05/2014   BSW   initial coding
 *************************************************************************************************************************************/
double Degrees2Rads(double degree)
{
	return degree * (M_PI / 180.0);
}



