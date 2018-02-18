/* ----------------------------------------------------------------------------

File:	RootsAndroid.cpp
Author:	Guiilherme Gomes
Date:	01/Oct/2016

---------------------------------------------------------------------------- */
#include <Arduino.h>
#include <RootsAndroid.h>


RootsAndroid::RootsAndroid() {
  speed = 0;
  angle = 0;
};

void RootsAndroid::readAndroidData () {

  byte i;
  char character;

  i = 0;
  
  if(Serial.available()) {
	
	while(Serial.available() > 0) {
    
      character = Serial.read();
	  
	  if(i < __BUFFER_LENGTH - 1) {
        streamBuffer[i++] = character;
        streamBuffer[i] = '\0';
      }
	  
	}
	
	if(streamBuffer[0] == 'S') {
		
	  for(i=0;i<__BUFFER_LENGTH-1;i++) {
		streamBuffer[i] = streamBuffer[i+1];  
	  }
	  
	  speed = atoi(streamBuffer);
	}
	else {
      angle = atoi(streamBuffer);
	}
	  
  }
      
}

int RootsAndroid::getDegreeAngle() {
  return angle;
}

byte RootsAndroid::getSpeed() {
  return speed;
}

char * RootsAndroid::getDataBuffer() {
	return streamBuffer;
}