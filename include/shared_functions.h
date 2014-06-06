/*+===================================================================

   File:      shared_functions.h

   Summary:   definitions for methods shared by entire project

   Classes:   none

   Functions: none

   Origin:    none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

#pragma once

// standard header files

// 3rd party header files
#include <Geometry>
using namespace Eigen;

// project header files
#include "common.h"
#include "SpaceObject.h"

// type definitions

// definitions
#define M_PI 3.14159265358979323846

// enumerations

// variables

// function prototypes
double Degrees2Rads(double);						// converts angle expressed in degrees to radians
quat3D Euler2Quat(double, double, double);		// converts yaw/pitch/roll (in degrees) to quaternion
quat3D Euler2Quat(vect3D);						// converts yaw/pitch/roll (in degrees) to quaternion
vect3D Global2Local(vect3D, quat3D);			// transform global coordinates to local FOR
vect3D Local2Global(vect3D, quat3D);			// transform local coordinates to global FOR
vect3D Quat2Euler(quat3D);						// converts quaternion to yaw/pitch/roll (in degrees)
double Rads2Degrees(double);					// converts angle expressed in radians to degrees
