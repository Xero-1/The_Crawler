#ifndef CAMERA_H
#define CAMERA_H

#include <ncurses.h>

class Camera
{
public:
	Camera();
	~Camera();
	//Functions
	void display();
	//Getters and setters
	inline WINDOW* getWindow(){return this->win;}
	inline void setWindow(WINDOW* w){this->win=w;}
private:
	WINDOW* win;
};

#endif
