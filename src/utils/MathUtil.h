//
//  MathUtil.h
//
//  Created by Colin Duffy on 10/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#pragma once

#include <math.h>

#define RESOLVE_ANGLE(a)						( (fmod(a, 360.) ) < 0 ? 360. + fmod(a, 360.) : fmod(a, 360.) )
#define TO_DEGREES(a)							( RESOLVE_ANGLE(a  * 57.29577951308232) )
#define TO_RADIANS(a)							( RESOLVE_ANGLE(a) * 0.017453292519943295 )
#define GET_ANGLE_RAD(x1,y1,x2,y2)				( atan2( y2-y1, x2-x1 ) )
#define GET_ANGLE_DEG(x1,y1,x2,y2)				( TO_DEGREES( GET_ANGLE_RAD(x1,y1,x2,y2) ) )
#define RANGE(min,max,per)						( (float)( min + ((max - min) * per) ) )
#define RAND_RANGE(min,max)						( RANGE( min,max, (float)rand() / RAND_MAX ) )
#define RANDOM()								( RAND_RANGE(0, 1) )
#define ROUND(value, ordinal)					( roundf( value * (float)ordinal ) * ( 1. / (float)ordinal ) )
#define distance(a,b)                           sqrtf((a-b) * (a-b))
#define distance2D(x1,y1,x2,y2)					( distance(x1,x2) + distance(y1,y2) )
#define distance3D(x1,y1,z1,x2,y2,z2)			( distance(z1,z2) + distance2D(x1,y1,x2,y2) )