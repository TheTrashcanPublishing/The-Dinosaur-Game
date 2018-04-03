// main.cpp for TOG of DinosaurGame

#include <iostream>
#include "SDL2/SDL.h"
#include <cmath>

// #include "tog.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
	    
	    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN); // Debug
    
        SDL_Window *window = NULL;             // Declare a Window pointer
        SDL_Surface *screenSurface = NULL;     // Declear a Surface pointer
        // Create an application window with the following settings:
        window = SDL_CreateWindow(
            "Pretend This is The Dinosaur Game!",  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            640,                               // width, in pixels
            480,                               // height, in pixels
            0                                  // flags
        );

        // Check that the window was successfully created
        if (window == NULL) {
            // In the case that the window could not be made...
            SDL_Log("Could not create window: %s\n", SDL_GetError());
            return 1;
        }
		else {
            // The window is open: could enter program loop here (see SDL_PollEvent())
            // Make Dinosaur Game Screen
    		screenSurface = SDL_GetWindowSurface( window );			
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );			
			SDL_UpdateWindowSurface( window );			

	        SDL_Renderer* renderer = NULL;
	        renderer = SDL_CreateRenderer (window, -1, 0);
	        if (renderer == NULL) {
	        	SDL_Log("Could not create renderer: %s\n", SDL_GetError());
	        	return 1;
			}
			else {
	            SDL_Rect sky;
	            SDL_Rect ground;
            
	            sky.x = 0;
	            sky.y = 0;
    	        sky.w = 639;
        	    sky.h = 479;
	            SDL_SetRenderDrawColor(renderer, 0xDF, 0xEF, 0x00, 0x80);
	            SDL_RenderFillRect(renderer, &sky);

	            ground.x = 0;
	            ground.y = 360;
	            ground.w = 639;
	            ground.h = 119;
	            SDL_SetRenderDrawColor(renderer, 0x9F, 0x7F, 0x00, 0x80);
	            SDL_RenderFillRect(renderer, &ground);

				SDL_RenderPresent (renderer);  }

	        SDL_Delay(6000);  // Pause execution for 6000 milliseconds, for example

	        // Close and destroy the window
	        SDL_DestroyWindow(window); }

	    // Clean up
	    SDL_Quit();
	    return 0;}
        
	else {
	    SDL_Log("Could NOT initialize SDL: %s\n", SDL_GetError());
		return 1; } 
    }

/*    while(1) {
        DisplayStartScreen();
        GamePlay();    } 
    return 0;   */ /*
    }   */
