#ifndef WINDOW_MGR_H_INCLUDED
#define WINDOW_MGR_H_INCLUDED

#include "Screen.h"
#include <vector>

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    // reset the screen by index
    void clear(ScreenIndex);
    // add a screen and return the index
    ScreenIndex addScreen(const Screen&);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}

#endif // WINDOW_MGR_H_INCLUDED
