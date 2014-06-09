/*+===================================================================

   Class:    SpaceObject

   Summary:  none

   Methods:  none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

#pragma once

// standard header files

// project header files
#include "common.h"								// definitions shared by entire project

/***************************************************************************************************************
 * symbolic definitions
 ***************************************************************************************************************/

/***************************************************************************************************************
 * class definition
 ***************************************************************************************************************/
class SpaceObject
{
	public:
		// public data members
		// public method members
		SpaceObject();
		~SpaceObject();
		vect3D getFacingG(void);				// retrieve unit vector pointing in direction of +x axis in global FOR
		vect3D getFacingL(void);				// retrieve unit vector pointing in direction of +x axis in local FOR
		vect3D getHeadingG(void);				// retrieve unit vector pointing in direction of velocity in global FOR
		vect3D getHeadingL(void);				// retrieve unit vector pointing in direction of velocity in local FOR
		quat3D getOrientationG(void);			// retrieve object's orientation in global FOR
		vect3D getPositionG(void);				// retrieve object's position in global FOR
		vect3D getPositionL(void);				// retrieve object's position in local FOR via passed orientation
		vect3D getVelocityG(void);				// retrieve object's velocity in global FOR
		double getVelocityMag(void);			// retrieve object's magnitude of velocity
		void setOrientationG(double, double, double);		// set object's orientation in global FOR using Euler angles
		void setOrientationG(quat3D);			// set object's orientation in global FOR
		void setPositionG(double, double, double);	// set object's position in global FOR using xyz coordinates
		void setPositionG(vect3D);				// set object's position in global FOR
		void setVelocityG(vect3D);				// set object's velocity in global FOR
	protected:
		// protected data members
		// protected method members
	private:
		// private data members
		quat3D objectOrientationG;				// orientation of object in global FOR
		vect3D objectPositionG;					// xyz coordinates of object in global FOR
		vect3D objectVelocityG;					// velocity vector in global FOR
		// private method members
};
