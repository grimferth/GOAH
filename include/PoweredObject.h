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
		void applyThrust(double);				// modify objectVelocity using facing and thrust
		void applyThrust(void);				// modify objectVelocity using facing and thrust
		vect3D getAccelerationG(void);			// retrieve object's acceleration vector in global FOR
		vect3D getAccelerationL(void);			// retrieve object's acceleration vector in local FOR
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

