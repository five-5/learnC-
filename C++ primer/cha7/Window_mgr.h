#ifndef WINDOW_MGR_H_INCLUDED
#define WINDOW_MGR_H_INCLUDED

#include "Screen.h"
#include <vector>

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    // reset the screen by index
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

#endif // WINDOW_MGR_H_INCLUDED
