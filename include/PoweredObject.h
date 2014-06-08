/*+===================================================================

   Class:    PowerObject

   Summary:  none

   Methods:  none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

#pragma once

// standard header files

// project header files
#include <SpaceObject.h>

/***************************************************************************************************************
 * symbolic definitions
 ***************************************************************************************************************/

/***************************************************************************************************************
 * class definition
 ***************************************************************************************************************/
class PoweredObject : public SpaceObject
{
	public:
		// public data members
		// public method members
		PoweredObject();
		~PoweredObject();
		vect3D getAcceleration(void);			// retrieve object's acceleration vector
		double getThrust(void);					// retrieve object's thrust
		void setThrust(double);					// set object's thrust
	protected:
		// protected data members
		// protected method members
	private:
		// private data members
		double objectThrust;					// magnitude of thrust vector of object
		// private method members

};

