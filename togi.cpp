// togi.cpp for TOG for DinosaurGame

#include "togi.hpp"

bool togi::DrawGameScreen(gameWindow* window) {
	bool failure = FALSE;
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer (window, -1, 0);
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

	return failure;}


void togi::DrawTitleInfo(gameWindow* window) {}
