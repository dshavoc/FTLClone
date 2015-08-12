#pragma once

#include <cstring>
#include <glfw3.h>
#include "Draw.h"
#include "InteriorTile.h"

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
	

	
	static const float TILE_SIZE;
	static const float TILE_SPACING;
	static const int MAX_INTERIOR_SIZE = 20;
	static const int MAX_NUM_DOORS = 100;

	InteriorTile tiles[MAX_INTERIOR_SIZE][MAX_INTERIOR_SIZE];

	
	enum door_state {CLOSED, OPENING, OPEN, CLOSING};
	
	class Door {
	public:
		Door();
		void update(double);
		void draw(double);
		void open(double);
		void close(double);
		bool isOpen();
	private:
		double timeSinceStateChange;
		door_state doorState;
		static const double DOOR_XITION_TIME;
	} doors[MAX_NUM_DOORS];
	

	void drawTileBg(int, int);
	void drawDoorNorth(int, int);
	void drawDoorWest(int, int);

};