#include "CKeyboardEvents.h"
#include "CGame.h"
#include <iostream>

CKeyboardEvents* CKeyboardEvents::s_pInstance = 0;
/*
* 构造函数
* 将键值清零
* @木笔
*/
CKeyboardEvents::CKeyboardEvents() : m_keystates(0) {}
CKeyboardEvents::~CKeyboardEvents()
{
    /*删除动态创建的所有内容*/
    delete m_keystates;
}

/*
* 判断键是否按下
* 参数：key -- 要判断的键
* @木笔
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
* 更新按键事件
* @木笔
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
* 获取键盘按下的键值
* @木笔
*/
void CKeyboardEvents::onKeyDown()
{
    m_keystates = SDL_GetKeyboardState(0);
}

/*
* 获取键盘弹起的键值
* @木笔
*/
void CKeyboardEvents::onKeyUp()
{
    m_keystates = SDL_GetKeyboardState(0);
}
