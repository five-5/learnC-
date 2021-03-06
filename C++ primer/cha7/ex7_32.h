#ifndef EX7_32_H_INCLUDED
#define EX7_32_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

class Screen;

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};

class Screen{
    friend void Window_mgr::clear(ScreenIndex);
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' '){}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c){}

    char get() const{ return contents[cursor];}
    inline char get(pos ht, pos wd) const;

    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }

private:
    void do_display(std::ostream &os) const { os << contents; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline void Window_mgr::clear(ScreenIndex i)
{
    if ( i >= screens.size()) return;
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline
Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline
Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}

inline
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;	// calculate the position of row
	cursor = row + c;		// move the cursor to pointed col
	return *this;			// return object as left-value
}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

#endif // EX7_32_H_INCLUDED
