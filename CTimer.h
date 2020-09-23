#pragma once
#include <iostream>
#include <SDL.h>
using namespace std;

class CTimer
{
private:
	//设置游戏帧率（FPS）
	double FPS;
	double DELAY_TIME;
	//单例全局对象
	//static CTimer* s_pInstance;
	//
	Uint32 start;
	//隐藏构造函数和析构函数
	
public:
	CTimer();
	~CTimer();
	void TimeContrler();	//控制帧数
	int GetRealFPS();		//返回实际帧数
	void setFPS();			//设置游戏帧数
};

