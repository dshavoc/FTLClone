#include "Interior.h"

const float Interior::TILE_SIZE = 0.5f;
const float Interior::TILE_SPACING = 0.04f;

Interior::Interior(interior_layout layout)
{
	switch(layout) {
	case Kestrel:
		layoutKestrel();
		break;
	}
}

Interior::~Interior(void)
{
}

void Interior::layoutKestrel(void) {

	int tmp[7][MAX_INTERIOR_SIZE] = {
		{ 0, 0, 0, 0, 0, 0,27,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0,25, 9,29, 9, 0, 9,11,29, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{29,29,11, 0,11, 1,21, 1,17, 1,21, 1,21, 1,17, 0, 0, 0, 0, 0},
		{21,21, 1, 0, 1, 1,29, 9,27, 9,29, 9,21, 1,21, 0, 0, 0, 0, 0},
		{ 0, 9,11,21,11, 0, 1, 1,21, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 9,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	memset(tiles, 0, sizeof(tiles));
	memcpy(tiles, tmp, sizeof(tmp));

	drawOffsetX = 0;
	drawOffsetY = 0;
}

void Interior::draw() {
	glPushMatrix();
	glTranslatef(drawOffsetX, drawOffsetY, 0);

	for(int row=0; row<MAX_INTERIOR_SIZE; row++) {
		for(int col=0; col<MAX_INTERIOR_SIZE; col++) {
			if(tiles[row][col].isPassable()) {
				drawTileBg(row, col);
			}
			if(tiles[row][col].hasDoorNorth()) {
				drawDoorNorth(row, col);
			}
			if(tiles[row][col].hasDoorWest()) {
				drawDoorWest(row, col);
			}
		}
	}

	glPopMatrix();
}

void Interior::drawTileBg(int row, int col) {
	glColor3f(0.9f, 0.9f, 0.8f);
	Draw::square(col * (TILE_SIZE+TILE_SPACING), row * (TILE_SIZE+TILE_SPACING), TILE_SIZE, TILE_SIZE);
}

void Interior::drawDoorNorth(int row, int col) {

}

void Interior::drawDoorWest(int row, int col) {

}


/*
 * Door class
 */

const double Interior::Door::DOOR_XITION_TIME = 0.5;		//seconds

Interior::Door::Door() {
	doorState = CLOSED;
}

void Interior::Door::draw(double) {

}

void Interior::Door::open(double time) {
	switch(doorState) {
	case CLOSED:
		timeSinceStateChange = time;
		doorState = OPENING;
		break;

	case CLOSING:
		//Reverse direction with credit for current progress
		timeSinceStateChange = 1 - DOOR_XITION_TIME;
		doorState = OPENING;
	}
}

void Interior::Door::close(double time) {
	switch(doorState) {
	case OPEN:
		timeSinceStateChange = time;
		doorState = CLOSING;
		break;

	case OPENING:
		//Reverse direction with credit for current progress
		timeSinceStateChange = 1 - DOOR_XITION_TIME;
		doorState = OPENING;
	}
}

bool Interior::Door::isOpen() {
	return false;
}
