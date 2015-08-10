#include "Interior.h"

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
		{0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 5, 1, 0, 1, 3, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{5, 5, 3, 0, 3, 1, 5, 1, 1, 1, 5, 1, 5, 1, 1, 0, 0, 0, 0, 0},
		{5, 5, 1, 0, 1, 1, 5, 1, 3, 1, 5, 1, 5, 1, 5, 0, 0, 0, 0, 0},
		{0, 1, 3, 5, 3, 0, 1, 1, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	memcpy(tiles, tmp, sizeof(tmp));

	drawOffsetX = 0;
	drawOffsetY = 0;
}

void Interior::draw() {
	glPushMatrix();
	glTranslatef(drawOffsetX, drawOffsetY, 0);



	glPopMatrix();
}

/*
 *  InteriorTile class
 */

Interior::InteriorTile::InteriorTile(bool isPassable, bool isDoorNorth, bool isDoorWest) {
	flags = 0;
	if(isPassable)	flags |= PASSABLE_MASK;
	if(isDoorNorth)	flags |= DOOR_NORTH_MASK;
	if(isDoorWest)	flags |= DOOR_WEST_MASK;
}

Interior::InteriorTile::InteriorTile() {
	InteriorTile(0, 0, 0);
}

Interior::InteriorTile::~InteriorTile(void)
{
}

bool Interior::InteriorTile::isPassable() {
	return flags & PASSABLE_MASK ? true: false;
}

bool Interior::InteriorTile::hasDoorNorth() {
	return flags & DOOR_NORTH_MASK ? true : false;
}

bool Interior::InteriorTile::hasDoorWest() {
	return flags & DOOR_WEST_MASK ? true : false;
}

void Interior::InteriorTile::setPassable(bool x) {
	if(x)
		flags |= PASSABLE_MASK;
	else
		flags &= ~PASSABLE_MASK;
}

void Interior::InteriorTile::setDoorNorth(bool x) {
	if(x)
		flags |= DOOR_NORTH_MASK;
	else
		flags &= ~DOOR_NORTH_MASK; 
}

void Interior::InteriorTile::setDoorWest(bool x) {
	if(x)
		flags |= DOOR_WEST_MASK;
	else
		flags &= ~DOOR_WEST_MASK; 
}
