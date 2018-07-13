// togi.cpp for TOG for DinosaurGame

#include "togi.hpp"

#define TITLECENTX 320
#define TITLECENTY 149
#define TITLEWIDTH 400
#define TITLEHEIGHT 258


SDL_Renderer* DrawGameScreen(gameWindow* dow, bool &fail) {
	fail = false;
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer();
	failure = (renderer == NULL);
	if (failure) {
	    SDL_Log("Could not create renderer: %s\n", SDL_GetError());
	}
	else {
	    SDL_Rect sky;
	    SDL_Rect ground;
	    string skycol = "sky";
	    string groundcol = "ground";

	    sky.x = 0;
	    sky.y = 0;
    	sky.w = 639;
        sky.h = 479;
	    SDL_SetRenderDrawColor(renderer, color(skycol));
	    SDL_RenderFillRect(renderer, &sky);

	    ground.x = 0;
	    ground.y = 360;
	    ground.w = 639;
	    ground.h = 119;
	    SDL_SetRenderDrawColor(renderer, color(groundcol));
	    SDL_RenderFillRect(renderer, &ground);

		SDL_RenderPresent (renderer);  }

	return renderer; }


bool togi::PlaceTitleInfo(gameWindow* dow) {
	bool fail = false;
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	SDL_Rect placetitle;
	placetitle.x = (int)(round((double) TITLECENTX - ((double) TITLEWIDTH/2.0)));
	placetitle.y = (int)(round((double) TITLECENTY - ((double) TITLEHEIGHT/2.0)));
	placetitle.w = TITLEWIDTH;
	placetitle.h = TITLEHEIGHT;
	surface = SDL_LoadBMP("dinotitle1.bmp");
	texture = SDL_CreateTextureFromSurface(dow.Renderer(), surface);
	int error = SDL_RenderCopy(dow.Renderer(), texture, NULL, &placetitle);
	fail = (error != 0);
	if (fail) SDL_Log ("Could not copy renderer. %s", SDL_GetError());
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	return fail; }
