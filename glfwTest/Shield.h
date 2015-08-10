#pragma once

#include <glfw3.h>
#include <vector>
#include <cmath>

enum shield_type {PROJECTILE, BEAM, PULSE};
enum shield_anim_state {OFF, CHARGING, ON, HIT};

static const double ANIM_TIME = 0.5;	//seconds

class Shield
{
public:
	shield_type type;
	Shield();
	~Shield(void);

	//Engine Interface
	void draw(double time);
	void update(double time);

	//Game Interface
	void addCharge(float delta);
	void hit();
	bool isActive();

private:
	static std::vector<GLfloat> shieldX, shieldY;
	static const int NUM_PTS_IN_SHIELD = 36;
	shield_anim_state state;
	double timeSinceStateChange;
	

	float charge;	//[0,1], increased by addCharge. When full, raise shields.

	static void initialize(void);	//Do one-time math

};
