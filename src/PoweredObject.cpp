/*+===================================================================

   Class:    PowerObject

   Summary:  none

   Methods:  none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

// standard header files

// project header files
#include "PoweredObject.h"

//3rd party header files


/*************************************************************************************************************************************
 * constructor
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/08/2014   SDW   initial coding
 *************************************************************************************************************************************/
PoweredObject::PoweredObject()
{

}

/*************************************************************************************************************************************
 * destructor
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 1xx   xx/xx/2014   SDW   initial coding
 *************************************************************************************************************************************/
PoweredObject::~PoweredObject()
{
}

/*************************************************************************************************************************************
 * getAcceleration - retrieve object's acceleration vector
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/xx/2014   SDW   initial coding
 *************************************************************************************************************************************/
vect3D PoweredObject::getAcceleration(void)
{
	// TODO
}

/*************************************************************************************************************************************
 * getThrust - retrieve object's thrust
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/05/2014   BSW   initial coding
 *************************************************************************************************************************************/
double PoweredObject::getThrust(void)
{
	return objectThrust;
}

/*************************************************************************************************************************************
 * setThrust - set object's thrust
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/05/2014   BSW   initial coding
 *************************************************************************************************************************************/
void PoweredObject::setThrust(double magnitude)
{
	objectThrust = magnitude;
}
