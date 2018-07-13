// The Trashcan Splashscreen Test

#ifndef SPLASH_CPP
#define SPASH_CPP

#include <iostream>
#include "SDL2/SDL.h"

bool ShowSplashScreen(void) {
	bool failure =  false;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
	        
        SDL_Window*        window = NULL;	// Declare a Window pointer
        SDL_Surface* trashcansurf = NULL;	// Declear a Surface pointer
        SDL_Renderer*    renderer = NULL;	// Declear a Renderer pointer

        // Create a borderless window window with the following settings:
        window = SDL_CreateWindow(
            "The Trashcan Presents",		  // window title
            SDL_WINDOWPOS_UNDEFINED,          // initial x position
            SDL_WINDOWPOS_UNDEFINED,          // initial y position
            400,                              // width, in pixels
            400,                              // height, in pixels
            SDL_WINDOW_BORDERLESS             // flags
        );

        // Check that the window was successfully created
        if (window == NULL) {
            // In the case that the window could not be made...
            SDL_Log("Could not create window: %s\n", SDL_GetError());
            failure = true; }
		else {
			// Cretate Renderer and Load Surface
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			trashcansurf = SDL_LoadBMP("TrashcanSplashSm.bmp");
			
			// If surface doesn't load, log error
			if (trashcansurf == NULL) {
				SDL_Log("Could not load splash screen: %s\n", SDL_GetError);
				failure = true; }

	        else {
	        	// Create Texture from Surface, free surface
	        	// copy render from texture, and present render
	        	SDL_Texture* spltexture = NULL;
	        	spltexture = SDL_CreateTextureFromSurface(renderer, trashcansurf);
	        	SDL_FreeSurface(trashcansurf);
	        	SDL_RenderClear(renderer);
	        	SDL_RenderCopy(renderer, spltexture, NULL, NULL);
	        	SDL_RenderPresent(renderer);
				SDL_Delay(10000);  // Pause execution for 10000 milliseconds

	        	// Destroy the texture, renderer, and window
	    	    SDL_DestroyTexture(spltexture);
	    	    SDL_DestroyRenderer(renderer);
	    	    SDL_DestroyWindow(window); } }

	    // Clean up
	    SDL_Quit();
	    failure = false;}
        
	else {
	    SDL_Log("Could NOT initialize SDL: %s\n", SDL_GetError());
		failure = true; }
	return failure; };

#endif // SPLASH_CPP
