#include "acllib.h"
#include <iostream>
#include "BasicObject.h"

int Setup() {
	initConsole();
	initWindow("Test", 0, 0, 1000, 800);
	loadImage("Default.jpg", &Default);
	Actor d;

	ACL_Image tt;
	tt = d.GetImage();
	beginPaint();
	//putImage(&Default, 0, 0);
	endPaint();
	Actor a;
	std::cout << a.GetPosition().GetX() << " " << a.GetPosition().GetY() << std::endl;
	a.SetSpeed(Speed(5, 5));
	a.MoveSelf();
	std::cout << a.GetPosition().GetX() << " " << a.GetPosition().GetY() << std::endl;
	return 0;
}