#include "CTimer.h"

CTimer::CTimer()
{
	start = SDL_GetTicks();
}

CTimer::~CTimer()
{

}

void CTimer::TimeContrler()
{
	while (SDL_GetTicks() - start < DELAY_TIME)
	{
		SDL_Delay(SDL_GetTicks() - start);
	}
	start = SDL_GetTicks();
	return;
}

int CTimer::GetRealFPS()
{
	return 1000 / double(SDL_GetTicks() - start);
}

void CTimer::setFPS()
{
	FPS = 60;
	DELAY_TIME = 1000.0 / double(FPS);
}
