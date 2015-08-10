#pragma once
#include <glfw3.h>
#include "Shield.h"
#include "Interior.h"
#include <cmath>

class Ship
{
public:
	Ship(double x, double y, double angle, double scale);
	~Ship(void);

	double worldX, worldY;			//Location in world coordinates
	double angle;					//At zero deg, front should be in +x direction
	double scale;					//object-to-world
	
	Shield shield;
	Interior *interior;
	
	void draw(double time);				//Public method that incorporates all transforms

private:
	static void drawExterior(void);		//Object reference frame, no transform.
	
};

