#pragma once

class InteriorTile
{
public:
	InteriorTile();
	InteriorTile(bool, bool, bool, bool, bool);

	bool isPassable(void);
	bool hasDoorNorth(void);
	bool hasDoorWest(void);
	void setPassable(bool);
	void setDoorNorth(bool);
	void setDoorWest(bool);

private:
	int flags;
	
	static const int PASSABLE_MASK		= 1;
	static const int DOOR_NORTH_MASK	= 2;
	static const int DOOR_WEST_MASK		= 4;
	static const int WALL_NORTH_MASK	= 8;
	static const int WALL_WEST_MASK		= 16;
};
