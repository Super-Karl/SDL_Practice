#pragma once
#include <iostream>
#include <SDL.h>
using namespace std;

class CTimer
{
private:
	//������Ϸ֡�ʣ�FPS��
	double FPS;
	double DELAY_TIME;
	//����ȫ�ֶ���
	//static CTimer* s_pInstance;
	//
	Uint32 start;
	//���ع��캯������������
	
public:
	CTimer();
	~CTimer();
	void TimeContrler();	//����֡��
	int GetRealFPS();		//����ʵ��֡��
	void setFPS();			//������Ϸ֡��
};

