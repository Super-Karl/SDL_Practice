#pragma once
#include <iostream>
using namespace std;
class CGame
{
private:
	//����
	static CGame* s_pInstance;
	CGame();
	~CGame();
	bool m_bRunning = true;
public:
	static CGame* Instance()
	{
		if (s_pInstance == NULL)
		{
			s_pInstance = new CGame();
		}
		return s_pInstance;
	}
	bool Init(); //��ʼ��
	void HandleEvents(); //�����¼�����������ꡢ���̡��ֱ���
	void Update();  //���ݲ�ͬ���¼�����Ϸ״̬�����ݽ��и���
	void Render();  //��Ⱦ�����ͼ��Ļ���
	void Close();  //�ͷ��ڴ棬����

	bool Running() { return m_bRunning; }
	void Quit() { m_bRunning = false; }
};

