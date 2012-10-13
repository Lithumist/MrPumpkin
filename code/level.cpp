// level.cpp
#include "level.h"





tile makeTile(int ID, int ENTITY_ID, bool IS_PLAYER_START, bool IS_PLAYER_END, int X, int Y)
{
	tile new_tile;

	new_tile.id = ID;
	new_tile.entity_id = ENTITY_ID;
	new_tile.is_player_start = IS_PLAYER_START;
	new_tile.is_player_end = IS_PLAYER_END;
	new_tile.x = X;
	new_tile.y = Y;

	return new_tile;
}









PumpkinMap::PumpkinMap()
{
	widthInTiles = 25;
	startingSpeed = 1; // second

	backgroundRed = 0xFF;
	backgroundGreen = 0xFF; // white
	backgroundBlue = 0xFF;

	// load the default wall texture
	S_mapWall = NULL;
	wallSurfaceFilename = "res/wallDefault.png";
	S_mapWall = imageLoad(wallSurfaceFilename);

	// create the vector of tiles
	_makeTiles();
}

void PumpkinMap::clearMap()
{
	// reset
	widthInTiles = 25;
	startingSpeed = 1; // second

	backgroundRed = 0xFF;
	backgroundGreen = 0xFF; // white
	backgroundBlue = 0xFF;

	// free wall texture if needed
	if(S_mapWall != NULL)
		SDL_FreeSurface(S_mapWall);
	S_mapWall = NULL;

	// set wall to default wall texture
	wallSurfaceFilename = "res/wallDefault.png";
	S_mapWall = imageLoad(wallSurfaceFilename);

	_makeTiles();
}

void PumpkinMap::_resetTiles()
{
	for(int x=0; x<widthInTiles; x++)
	{
		for(int y=0; y<(cnst::WINDOW_HEIGHT/32); y++)
		{
			*getTileFast(x,y) = makeTile(0,0,false,false,x,y); // air with eid 0 (no entity)
		}
	}
}

void PumpkinMap::_makeTiles()
{
	tiles.clear();
	for(int x=0; x<widthInTiles; x++)
	{
		for(int y=0; y<(cnst::WINDOW_HEIGHT/32); y++)
		{
			tiles.push_back(makeTile(0,0,false,false,x,y));
		}
	}
}

void PumpkinMap::freeAllMemory()
{
	if(S_mapWall != NULL)
		SDL_FreeSurface(S_mapWall);
	S_mapWall = NULL;
}

void PumpkinMap::updateWall()
{
	if(S_mapWall != NULL)
		SDL_FreeSurface(S_mapWall);
	S_mapWall = NULL;

	S_mapWall = imageLoad(wallSurfaceFilename);
}

void PumpkinMap::updateWidth(int newWidthInTiles)
{
	if(newWidthInTiles == widthInTiles)
		return;

	if(newWidthInTiles > widthInTiles)
	{
		// new width is greater than old
		// so just add the new tiles on the end


		int dif = newWidthInTiles - widthInTiles;

		dif *= (cnst::WINDOW_HEIGHT/32);
		for(int t=0; t<dif; t++)
		{
			tiles.push_back(makeTile(0,0,false,false,0,0));
		}


	}
	else
	{
		// new width is less then old
		// make the new tiles vector and copy old data until impossible


		std::vector<tile> tilesCopy = tiles;
		tiles.clear();

		for(int x=0; x<newWidthInTiles; x++)
		{
			for(int y=0; y<(cnst::WINDOW_HEIGHT/32); y++)
			{
				tiles.push_back(tilesCopy[x * (cnst::WINDOW_HEIGHT/32) + y]);
			}
		}

		tilesCopy.clear(); // not sure if this is neccessary




	}

	widthInTiles = newWidthInTiles;
}

tile* PumpkinMap::getTile(int tileX, int tileY)
{
	if(tileY >= 0 && tileY < (cnst::WINDOW_HEIGHT/32)-1)
	{
		if(tileX >= 0 && tileX < widthInTiles)
		{
			return &tiles[tileX * (cnst::WINDOW_HEIGHT/32) + tileY];
		}
	}

	std::cout << "Warning! getTile() returned NULL.\n";
	return NULL;
}

void PumpkinMap::setTile(tile new_tile, int tileX, int tileY)
{
	new_tile.x = tileX;
	new_tile.y = tileY;

	if(tileY >= 0 && tileY < (cnst::WINDOW_HEIGHT/32))
	{
		if(tileX >= 0 && tileX < widthInTiles)
		{
			tiles[tileX * (cnst::WINDOW_HEIGHT/32) + tileY] = new_tile;
		}
	}

}

void PumpkinMap::setBackgroundColour(Uint8 r, Uint8 g, Uint8 b)
{
	backgroundRed = r;
	backgroundGreen = g;
	backgroundBlue = b;
}

void PumpkinMap::setWallTexture(std::string Filename)
{
	wallSurfaceFilename = Filename;
	S_mapWall = imageLoad(Filename);

	if(S_mapWall == NULL)
		std::cout << "Error changing wall texture to " << Filename << std::endl;
}




void PumpkinMap::drawTile(int ID, int ENTITY_ID, int X, int Y)
{
	// Dont draw air or bad ID's
	if(ID <= 0)
		return;

	if(ID == 1)
		imageDraw(S_mapWall,X,Y);
}

void PumpkinMap::draw()
{
	SDL_FillRect(gbl::S_screen, &gbl::S_screen->clip_rect, SDL_MapRGB(gbl::S_screen->format, backgroundRed, backgroundGreen, backgroundBlue));

	for(int t=0; t<tiles.size(); t++)
	{


		if(tiles[t].id == 1)
			imageDraw(S_mapWall,tiles[t].x*32,tiles[t].y*32);


	}
}














/* Save */
void PumpkinMap::saveMap(std::string filename)
{

	/* Open the file for writing */
	std::ofstream saveFile;
	saveFile.open(filename.c_str());

	if(!saveFile.is_open())
	{
		std::cout << "Error! saveMap() Error openeing file " << filename << " for writing.\n";
		return;
	}
	

	/* Write the file header */
	saveFile << cnst::FILE_HEADER << " ";


	/* Write the background colour */
	saveFile << (unsigned int)backgroundRed << " " << (unsigned int)backgroundGreen << " " << (unsigned int)backgroundBlue << " ";


	/* Write wall image filename */
	saveFile << wallSurfaceFilename << " ";


	/* Write starting speed */
	saveFile << startingSpeed << " ";


	/* Write the width in tiles */
	saveFile << widthInTiles << " ";


	/* Write the tile data */
	for(int t=0; t<tiles.size(); t++)
	{

		// ID
		saveFile << tiles[t].id << " ";

		// EID
		saveFile << tiles[t].entity_id << " ";

		// START
		if(tiles[t].is_player_start)
			saveFile << "1 ";
		else
			saveFile << "0 ";

		// END
		if(tiles[t].is_player_end)
			saveFile << "1 ";
		else
			saveFile << "0 ";

		// X
		saveFile << tiles[t].x << " ";

		// Y
		saveFile << tiles[t].y << " ";

	}


	saveFile.close();


}


















/* Load */
bool PumpkinMap::loadMap(std::string filename)
{

	/* LOAD DAT BITCH */


	/* Open the file for reading */
	std::ifstream saveFile;
	saveFile.open(filename.c_str());

	if(!saveFile.is_open())
	{
		std::cout << "Error! loadMap() Error openeing file " << filename << " for reading.\n";
		return false;
	}


	/* Read header */
	std::string fileHeader;
	saveFile >> fileHeader;

	if(fileHeader != cnst::FILE_HEADER)
	{
		std::cout << "Error! loadMap() File " << filename << " is not a Pumpkin Map File (.pkm).\n";
		saveFile.close();
		return false;
	}


	/* Read background colour */
	unsigned int bgr, bgg, bgb;

	saveFile >> bgr >> bgg >> bgb;
	backgroundRed = (Uint8)bgr;
	backgroundGreen = (Uint8)bgg;
	backgroundBlue = (Uint8)bgb;


	/* Read wall filename */
	saveFile >> wallSurfaceFilename;
	updateWall();


	/* Read starting speed */
	saveFile >> startingSpeed;


	/* Read width in tiles */
	saveFile >> widthInTiles;


	/* Read tiles */
	tiles.clear();

	while(!saveFile.eof())
	{
		tile newTile;
		int convert;

		saveFile >> newTile.id;
		saveFile >> newTile.entity_id;

		saveFile >> convert;
		if(convert == 0)
			newTile.is_player_start = false;
		else
			newTile.is_player_start = true;

		saveFile >> convert;
		if(convert == 0)
			newTile.is_player_end = false;
		else
			newTile.is_player_end = true;

		saveFile >> newTile.x;
		saveFile >> newTile.y;

		tiles.push_back(newTile);

	}


	/* FINISHED BITCH! */

	saveFile.close();
	return true;
	


}