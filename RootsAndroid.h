/* ----------------------------------------------------------------------------

File:	RootsAndroid.h
Author:	Guiilherme Gomes
Date:	01/Oct/2016

Description:
  An API to communicate with the sensors of an Android device.


Commands:

 - "Snn" -> set speed to nn
 - "D1"	-> Drive
 - "D0"	-> Stop

---------------------------------------------------------------------------- */

#ifndef __ANDROID_API
#define __ANDROID_API

#define __BUFFER_LENGTH 5

#include "Arduino.h"

class RootsAndroid {
	
	public:
	  RootsAndroid();
      void readAndroidData();
	  int getDegreeAngle();
	  byte getSpeed();
	  char * getDataBuffer();
	  
	private:
	  char streamBuffer[__BUFFER_LENGTH];
	  int angle;
	  byte speed;	  
};

#endif
