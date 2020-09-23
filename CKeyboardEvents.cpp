#include "CKeyboardEvents.h"
#include "CGame.h"
#include <iostream>

CKeyboardEvents* CKeyboardEvents::s_pInstance = 0;
/*
* ���캯��
* ����ֵ����
* @ľ��
*/
CKeyboardEvents::CKeyboardEvents() : m_keystates(0) {}
CKeyboardEvents::~CKeyboardEvents()
{
    /*ɾ����̬��������������*/
    delete m_keystates;
}

/*
* �жϼ��Ƿ���
* ������key -- Ҫ�жϵļ�
* @ľ��
*/
bool CKeyboardEvents::isKeyDown(SDL_Scancode key) const
{
    if (m_keystates != 0)
    {
        if (m_keystates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

/*
* ���°����¼�
* @ľ��
*/
void CKeyboardEvents::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            onKeyDown();
            break;

        case SDL_KEYUP:
            onKeyUp();
            break;

        default:
            break;
        }
    }
}

/*
* ��ȡ���̰��µļ�ֵ
* @ľ��
*/
void CKeyboardEvents::onKeyDown()
{
    m_keystates = SDL_GetKeyboardState(0);
}

/*
* ��ȡ���̵���ļ�ֵ
* @ľ��
*/
void CKeyboardEvents::onKeyUp()
{
    m_keystates = SDL_GetKeyboardState(0);
}
