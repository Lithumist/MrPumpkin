// graphics.cpp
#include "graphics.h"



// lazyfoo
SDL_Surface* imageLoad(std::string filename)
{
	SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    
    loadedImage = IMG_Load(filename.c_str());
    
    if(loadedImage != NULL)
    {
        optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
        SDL_FreeSurface(loadedImage);
    }
	else
	{
		std::cout << "Error! imageLoad() failed to load image " << filename << std::endl;
	}
    
    return optimizedImage;
}




void imageDraw(SDL_Surface* surface, float xpos, float ypos)
{
	SDL_Rect offset;

	offset.x = (int)xpos;
	offset.y = (int)ypos;

	SDL_BlitSurface(surface,NULL,gbl::S_screen,&offset);
}




void imageFree(SDL_Surface* surface)
{
	SDL_FreeSurface(surface);
}