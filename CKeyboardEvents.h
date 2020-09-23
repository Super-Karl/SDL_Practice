
#ifndef _CKeyboardEvents_
#define _CKeyboardEvents_

#include "SDL.h"
#include "CInputHandle.h"

class CKeyboardEvents :
    public CInputHandle
{
public:

    static CKeyboardEvents* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new CKeyboardEvents();
            s_pInstance->update();
        }

        return s_pInstance;
    }

    void update();
    bool isKeyDown(SDL_Scancode key) const;

    /*用户调用函数判断是否按下键*/
    static bool ifKeyDown(SDL_Scancode key)
    {
        Instance()->update();
        if (Instance()->isKeyDown(key))
            return true;
        else
            return false;
    }

private:

    CKeyboardEvents();
    ~CKeyboardEvents();
    CKeyboardEvents(const CKeyboardEvents&);
    void onKeyDown();
    void onKeyUp();

    const          Uint8* m_keystates;
    static         CKeyboardEvents* s_pInstance;
};



#endif
