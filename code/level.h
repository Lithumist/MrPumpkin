/*
	level.h

	Declares a class that can load, manipulate and draw a Pumpkin Map File
	Also declares a tile structure that represents a tile
*/

#ifndef LEVEL_H
#define LEVEL_H

#include "constant.h"
#include "global.h"
#include "graphics.h"
#include "resources.h"
#include <vector>
#include <fstream>






struct tile
{
	int id;
	int entity_id;
	bool is_player_start;
	bool is_player_end;
	int x;
	int y;
};
tile makeTile(int ID, int ENTITY_ID, bool IS_PLAYER_START, bool IS_PLAYER_END, int X, int Y);








class PumpkinMap
{

	public:


		PumpkinMap();

		bool loadMap(std::string filename);
		void saveMap(std::string filename);

		void clearMap();
			void _resetTiles();
			void _makeTiles();

		void freeAllMemory();

		void updateWall();

		void updateWidth(int newWidthInTiles);

		void setTile(tile new_tile, int tileX, int tileY);
		tile* getTile(int tileX, int tileY);

		inline tile* getTileFast(int tileX, int tileY) // unsafe
		{
			return &tiles[tileX * (cnst::WINDOW_HEIGHT/32) + tileY];
		}

		void setBackgroundColour(Uint8 r, Uint8 g, Uint8 b); // 0-255 only
		void setWallTexture(std::string Filename); // loads the new image


		void draw();
		void drawTile(int ID, int ENTITY_ID, int X, int Y);



		///////////////////////////////////////////////




		std::vector<tile> tiles;
		int widthInTiles;

		Uint8 backgroundRed;
		Uint8 backgroundGreen;
		Uint8 backgroundBlue;

		std::string wallSurfaceFilename;
		SDL_Surface* S_mapWall;

		float startingSpeed;




};




#endif