// fps.cpp
#include "fps.h"


fpsCalc* fpsCalc::Instance = NULL;


fpsCalc* fpsCalc::GetInstance()
{
   if (!Instance)
      Instance = new fpsCalc;
 
   return Instance;
}

void fpsCalc::Init(double tfps)
{
  targetfps = tfps;
  QueryPerformanceCounter(&framedelay);
  QueryPerformanceFrequency(&tickspersecond);
}
void fpsCalc::SetSpeedFactor()
{
  QueryPerformanceCounter(&currentticks);
  speedfactor = (double)(currentticks.QuadPart-framedelay.QuadPart)/((double)tickspersecond.QuadPart/targetfps);
  fps = targetfps/speedfactor;
  if (speedfactor <= 0)
	speedfactor = 1;

  framedelay = currentticks;
}

void fpsCalc::FreeMemory()
{
	if(Instance != NULL){ delete Instance; }
}