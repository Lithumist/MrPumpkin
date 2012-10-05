/*
	fps.h

	Declares a class that allows framerate independent movement

	http://www.gamedev.net/page/resources/_/technical/game-programming/frame-rate-independent-movement-r1382
	with modifications
*/

#ifndef FPS_H
#define FPS_H

#include "windows.h"


class fpsCalc
{
public:
  double     	targetfps;
  double     	fps;
  LARGE_INTEGER tickspersecond;
  LARGE_INTEGER currentticks;
  LARGE_INTEGER framedelay;
    
  double     	speedfactor;   		 

  void      	Init(double tfps);
  void      	SetSpeedFactor();
  void			FreeMemory();

  static fpsCalc* GetInstance();
  static fpsCalc* Instance;
};


#endif