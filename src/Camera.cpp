#include "Camera.h"

Camera::Camera(){}
Camera::~Camera()
{
	delwin(win);
}

//Functions
void Camera::display()
{
	box(win,0,0);
	wrefresh(win);
}
