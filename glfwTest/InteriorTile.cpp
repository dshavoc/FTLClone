#include "InteriorTile.h"

InteriorTile::InteriorTile(void) {
	InteriorTile(0, 0, 0, 0, 0);
}

InteriorTile::InteriorTile(bool isPassable, bool isDoorNorth, bool isDoorWest, bool isWallNorth, bool isWallWest) {
	flags = 0;
	if(isPassable)	flags |= PASSABLE_MASK;
	if(isDoorNorth)	flags |= DOOR_NORTH_MASK;
	if(isDoorWest)	flags |= DOOR_WEST_MASK;
	if(isWallNorth) flags |= WALL_NORTH_MASK;
	if(isWallWest) flags  |= WALL_WEST_MASK;
}

bool InteriorTile::isPassable() {
	return flags & PASSABLE_MASK ? true: false;
}

bool InteriorTile::hasDoorNorth() {
	return flags & DOOR_NORTH_MASK ? true : false;
}

bool InteriorTile::hasDoorWest() {
	return flags & DOOR_WEST_MASK ? true : false;
}

void InteriorTile::setPassable(bool x) {
	if(x)
		flags |= PASSABLE_MASK;
	else
		flags &= ~PASSABLE_MASK;
}

void InteriorTile::setDoorNorth(bool x) {
	if(x)
		flags |= DOOR_NORTH_MASK;
	else
		flags &= ~DOOR_NORTH_MASK; 
}

void InteriorTile::setDoorWest(bool x) {
	if(x)
		flags |= DOOR_WEST_MASK;
	else
		flags &= ~DOOR_WEST_MASK; 
}
