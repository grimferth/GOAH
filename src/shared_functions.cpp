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
#include "common.h"
#include "shared_functions.h"

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

/*************************************************************************************************************************************
 * Euler2Quat - converts yaw/pitch/roll (in degrees) to quaternion
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/06/2014   SDW   normalize quat before returning
 * 100   06/05/2014   BSW   initial coding
 *************************************************************************************************************************************/
quat3D Euler2Quat(double y, double p, double r)
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
	results.normalize();
	// return results
	return results;
}

/*************************************************************************************************************************************
 * Euler2Quat - converts yaw/pitch/roll (in degrees) to quaternion
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/05/2014   BSW   initial coding
 *************************************************************************************************************************************/
quat3D Euler2Quat(vect3D n)
{
	return Euler2Quat(n(yaw_angle),n(pitch_angle),n(roll_angle));
}

/*************************************************************************************************************************************
 * Global2Local - transform global coordinates to local FOR
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/06/2014   BSW   initial coding
 *************************************************************************************************************************************/
vect3D Global2Local(vect3D globalpos, quat3D orientation)
{
	return orientation._transformVector(globalpos);
}

/*************************************************************************************************************************************
 * Local2Global- transform local coordinates to global FOR
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/06/2014   SDW   initial coding
 *************************************************************************************************************************************/
vect3D Local2Global(vect3D localpos, quat3D orientation)
{
	quat3D inverted = orientation.inverse();
	return inverted._transformVector(localpos);
}

/*************************************************************************************************************************************
 * NormalizeVector - generate unit vector from given vector
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/09/2014   SDW   initial coding
 *************************************************************************************************************************************/
vect3D NormalizeVector(vect3D n)
{
	vect3D results = n;
	if ((n(x_coord) == 0)&&(n(y_coord) == 0)&& (n(z_coord)==0))
        return n;
    else
    {
        results.normalize();
        return results;
    }
}

/*************************************************************************************************************************************
 * Quat2Euler - converts quaternion to yaw/pitch/roll (in degrees)
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/05/2014   BSW   initial coding
 *************************************************************************************************************************************/
vect3D Quat2Euler(quat3D n)
{
	// local variables
	vect3D result(0.0,0.0,0.0);					// yaw, pitch, roll in degrees
	double w = n.w();
	double x = n.x();
	double y = n.y();
	double z = n.z();

	// process
	result(pitch_angle) = asinf(2 * x * y + 2 * z * w);
	if(x * y + z * w == 0.5)
	{
		result(yaw_angle) = Rads2Degrees(2.0 * atan2f(x, w));
		result(roll_angle) = 0.0;
	}
	else if(x * y + z * w == -0.5)
	{
		result(yaw_angle) = Rads2Degrees(-2.0 * atan2f(x, y));
		result(roll_angle) = 0.0;
	}
	else
	{
		result(yaw_angle) = Rads2Degrees(atan2f(((2.0 * y * w) - (2 * x * z)), (1.0 - (2.0 * powf(y, 2.0)) - (2.0 * powf(z, 2.0)))));
		result(roll_angle) = Rads2Degrees(atan2f(((2.0 * x * w) - (2.0 * y * z)) , (1.0 - (2.0 * powf(x, 2.0)) - (2.0 * powf(z, 2.0)))));
	}
	return result;
}


/*************************************************************************************************************************************
 * Rads2Degrees - converts angle expressed in radians to degrees
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/05/2014   BSW   initial coding
 *************************************************************************************************************************************/
double Rads2Degrees(double rad)
{
	return rad * (180.0 / M_PI);
}

/*************************************************************************************************************************************
 * VectorLength - returns length of vector
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/09/2014   SDW   initial coding
 *************************************************************************************************************************************/
double VectorLength(vect3D n)
{
	double results = n.norm();
	return results;
}

