#pragma once
#include <cstring>
#include <glfw3.h>

enum interior_layout {Kestrel};


class Interior
{
public:
	Interior(interior_layout);
	~Interior(void);

	void draw(void);

private:
	float drawOffsetX, drawOffsetY;
	void layoutKestrel();
	
	
	static const int MAX_INTERIOR_SIZE = 20;
	static const int TILE_SIZE = 1;		//In hundredths of world distance?
	
	class InteriorTile {
	public:
		InteriorTile();
		InteriorTile(bool, bool, bool);
		~InteriorTile(void);

		bool isPassable(void);
		bool hasDoorNorth(void);
		bool hasDoorWest(void);
		void setPassable(bool);
		void setDoorNorth(bool);
		void setDoorWest(bool);

	private:
		int flags;

		static const int PASSABLE_MASK		= 1 << 0;
		static const int DOOR_NORTH_MASK	= 1 << 1;
		static const int DOOR_WEST_MASK		= 1 << 2;

	} tiles[MAX_INTERIOR_SIZE][MAX_INTERIOR_SIZE];


};
