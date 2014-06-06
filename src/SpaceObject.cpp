/*+===================================================================

   Class:    SpaceObject

   Summary:  none

   Methods:  none

 ----------------------------------------------------------------------
   Copyright (C) 2014, Stephen Wunschel
 ===================================================================+*/

// standard header files

// project header files
#include "shared_functions.h"
#include "SpaceObject.h"

//3rd party header files

/*************************************************************************************************************************************
 * constructor
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 1xx   xx/xx/2014   SDW   initial coding
 *************************************************************************************************************************************/
SpaceObject::SpaceObject()
{
	//ctor
}

/*************************************************************************************************************************************
 * destructor
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 1xx   xx/xx/2014   SDW   initial coding
 *************************************************************************************************************************************/
SpaceObject::~SpaceObject()
{
	//dtor
}

/*************************************************************************************************************************************
 * getOrientationG - retrieve object's orientation in global FOR
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/04/2014   SDW   initial coding
 *************************************************************************************************************************************/
quat3D SpaceObject::getOrientationG(void)
{
	return objectOrientationG;
}

/*************************************************************************************************************************************
 * getPositionG - retrieve object's position in global FOR
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/04/2014   SDW   initial coding
 *************************************************************************************************************************************/
vect3D SpaceObject::getPositionG(void)
{
	return objectPositionG;
}

/*************************************************************************************************************************************
 * getPositionL - retrieve object's position in local FOR via passed orientation
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/05/2014   BSW   initial coding
 *************************************************************************************************************************************/
vect3D SpaceObject::getPositionL(quat3D orientation)
{
	return orientation._transformVector(objectPositionG);
}

/*************************************************************************************************************************************
 * getVelocityG - retrieve object's velocity in global FOR
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/04/2014   SDW   initial coding
 *************************************************************************************************************************************/
vect3D SpaceObject::getVelocityG(void)
{
	return objectVelocityG;
}

/*************************************************************************************************************************************
 * setOrientationG - set object's orientation in global FOR using Euler angles
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/05/2014   SDW   initial coding
 *************************************************************************************************************************************/
void SpaceObject::setOrientationG(double y, double p, double r)
{
	objectOrientationG = Euler2Quat(y, p, r);
}

/*************************************************************************************************************************************
 * setOrientationG - set object's orientation in global FOR
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/04/2014   SDW   initial coding
 *************************************************************************************************************************************/
void SpaceObject::setOrientationG(quat3D n)
{
	objectOrientationG = n;
}

/*************************************************************************************************************************************
 * setPositionG - set object's position in global FOR using xyz coordinates
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/04/2014   SDW   initial coding
 *************************************************************************************************************************************/
void SpaceObject::setPositionG(double x, double y, double z)
{
	objectPositionG(x_coord) = x;
	objectPositionG(y_coord) = y;
	objectPositionG(z_coord) = z;
}

/*************************************************************************************************************************************
 * setPositionG - set object's position in global FOR
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/04/2014   SDW   initial coding
 *************************************************************************************************************************************/
void SpaceObject::setPositionG(vect3D n)
{
	objectPositionG = n;
}

/*************************************************************************************************************************************
 * setVelocityG - set object's velocity in global FOR
 *
 * VRM      Date      By    Description
 * ===   ==========   ===   ==========================================================================================================
 * 100   06/04/2014   SDW   initial coding
 *************************************************************************************************************************************/
void SpaceObject::setVelocityG(vect3D n)
{
	objectVelocityG = n;
}
