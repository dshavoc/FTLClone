#include "Ship.h"


Ship::Ship(double x, double y, double angle, double scale)
{
	worldX = x;
	worldY = y;
	this->angle = angle;
	this->scale = scale;
	interior = new Interior(Kestrel);
}

Ship::~Ship(void)
{
}

//Renders the Exterior, and conditionally renders Interior and Shields
void Ship::draw(double time) {

	glLoadIdentity();
	glTranslated(worldX, worldY, 0);
	glRotated(angle, 0.f, 0.f, 1.f);
	glScaled(scale, scale, 1);
	
	
	drawExterior();
	shield.draw(time);
	
}

//Draws self in object-space. Must apply scale before calling this function.
void Ship::drawExterior() {
	glBegin(GL_TRIANGLES);

	//Body
    glColor3f(0.6f, 0.6f, 1.f);
	glVertex3f(-0.6f, -0.4f, 0.f);
	glVertex3f(0.6f, -0.4f, 0.f);
	glVertex3f(0.f, 0.6f, 0.f);
	
	//Left Thruster
	glVertex3f(-0.3f, -0.4f, 0.f);
	glVertex3f(-0.4f, -0.4f, 0.f);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.35f, -0.5f, 0.f);

	//Right Thruster
	glColor3f(0.6f, 0.6f, 1.f);
	glVertex3f(0.4f, -0.4f, 0.f);
	glVertex3f(0.3f, -0.4f, 0.f);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(0.35f, -0.5f, 0.f);
	
	glEnd();
}
