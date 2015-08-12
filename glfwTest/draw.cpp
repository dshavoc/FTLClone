#include "Draw.h"


void Draw::square(float x, float y, float width, float height) {
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x, y);
	glVertex2f(x, y-height);
	glVertex2f(x+width, y);
	glVertex2f(x+width, y-height);
	glEnd();
}