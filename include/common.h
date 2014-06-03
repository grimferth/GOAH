/*+====================================================================================================================

   File:		common.h

   Summary:		definitions shared by entire project

   Classes:		none

   Functions:	none

   Origin:		none

   Notes:		makes use of the Eigen template library (http://eigen.tuxfamily.org/index.php?title=Main_Page)

 ----------------------------------------------------------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================================================================+*/

#pragma once

// standard header files

// 3rd party header files
#include <Core>
using namespace Eigen;

// project header files

// definitions
#define MAX_CMD_BUFF 256						// console command input buffer

// type definitions
typedef Matrix< double , 3 , 1> coords3D;		// coordinates in 3D space

// enumerations
enum COORDS										// offset into vector for each coordinate
{
	x_coord=0,
	y_coord,
	z_coord
};
