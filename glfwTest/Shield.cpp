#include "Shield.h"

std::vector<GLfloat> Shield::shieldX, Shield::shieldY;	//Resolve stupid "external symbol" error

Shield::Shield(void)
{
	state = OFF;
	charge = 0;

	//If this is the first instance of ship, then initialize.
	if(shieldX.size() == 0) {
		initialize();
	}
}

Shield::~Shield(void)
{
}

void Shield::initialize() {
	int i;
	float radPerPt = 2 * 3.14159f / NUM_PTS_IN_SHIELD;
	for(i=0; i < NUM_PTS_IN_SHIELD; i++) {
		Shield::shieldX.push_back(cos(radPerPt * i));
		Shield::shieldY.push_back(sin(radPerPt * i));
	}
	printf("Initialized shield vertices\r\n");
}

double lerp(double time, double duration, double x1, double x2) {
	if(time <= 0) {
		return x1;
	}
	else if(time < duration) {
		return time/duration * (x2-x1) + x1;
	}
	else {
		return x2;
	}
}

double nlerp(double time, double duration) {
	return lerp(time, duration, 0, 1);
}

void Shield::update(double time) {
	double t = time - timeSinceStateChange;
	switch(state) {
	case CHARGING:

		break;
	}
}

void Shield::draw(double time) {
	unsigned int i;
	double t = time - timeSinceStateChange;
	float A = 0;

	glLineWidth(1.);

	switch(state) {
	case ON:
		glBegin(GL_LINE_LOOP);
		glColor3f(0.5, 0.5, 1.0);
		for(i=0; i<shieldX.size(); i++) {
			glVertex2f(shieldX[i], shieldY[i]);
		}
		glEnd();
		break;
	
	case CHARGING:
		if(t <= ANIM_TIME) {
			A = (float)lerp(t, ANIM_TIME, 0, 1);
			glBegin(GL_LINE_LOOP);
			glColor3f(A * 0.5, A * 0.5, A * 1.0);
			for(i=0; i<shieldX.size(); i++) {
				glVertex2f(shieldX[i], shieldY[i]);
			}
			glEnd();
		}
		else {
			state = ON;
		}
		break;
	
	case HIT:
		if(t < ANIM_TIME) {
			A = (float)lerp(t, ANIM_TIME, 1, 0);
			glBegin(GL_LINE_LOOP);
			glColor3f(A * 0.5, A * 0.5, A * 1.0);
			for(i=0; i<shieldX.size(); i++) {
				glVertex2f(shieldX[i], shieldY[i]);
			}
			glEnd();
		}
		else {
			state = OFF;
		}
		break;
	}

}

void Shield::addCharge(float delta) {
	if(!isActive()) {
		charge += delta;
		if(charge >= 1) {
			charge = 1;
			state = CHARGING;
			timeSinceStateChange = glfwGetTime();
		}
		else if(charge < 0) {
			charge = 0;
		}
	}
}

void Shield::hit() {
	//CHARGING is still considered active
	if(isActive()) {
		charge = 0;
		state = HIT;
		timeSinceStateChange = glfwGetTime();
	}
}

bool Shield::isActive() {
	return (state == ON || state == CHARGING);
}
