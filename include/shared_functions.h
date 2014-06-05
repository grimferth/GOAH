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
quat3D Angles2Quat(double, double, double);		// converts yaw/pitch/roll (in degrees) to quaternion
quat3D Angles2Quat(vect3D);						// converts yaw/pitch/roll (in degrees) to quaternion
double Degrees2Rads(double);						// converts angle expressed in degrees to radians
