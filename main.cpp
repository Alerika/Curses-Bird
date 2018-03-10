#include <ncurses.h>
#include <cstring>
#include <string>
#include <unistd.h>
#include "bird.h"
using namespace std;
Bird* bird;
void setup()
{
	initscr();
	cbreak();
	keypad(stdscr,TRUE);
	noecho();
	curs_set(0);
	box(stdscr, 0,0);
	bird=new Bird((int)LINES,(int)COLS);
}

void draw()
{
	while(true)
	{
		bird->show();
		refresh();
	}
}

int main()
{
	setup();
	draw();
	getch();
	endwin();
}
void Bird::show()
{
    //printw("show");
	this->update();
	usleep(2e5+1e4);
    mvprintw(this->y,this->x,this->shape.c_str());
}