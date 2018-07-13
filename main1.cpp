// main.cpp for TOG of DinosaurGame

#include <iostream>
#include "SDL2/SDL.h"
#include <cmath>

#define TITLECENTX 320
#define TITLECENTY 149
#define TITLEWIDTH 400
#define TITLEHEIGHT 258
#define WINWIDTH 640
#define WINHEIGHT 480

// #include "tog.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
	    
	    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN); // Debug
    
        SDL_Window *window = NULL;             // Declare a Window pointer
//       SDL_Surface *screenSurface = NULL;     // Declear a Surface pointer
        // Create an application window with the following settings:
        window = SDL_CreateWindow(
            "Pretend This is The Dinosaur Game!",  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            WINWIDTH,                          // width, in pixels
            WINHEIGHT,                         // height, in pixels
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
//    		screenSurface = SDL_GetWindowSurface( window );			
//			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );			
//			SDL_UpdateWindowSurface( window );			

	        SDL_Renderer* renderer = NULL;
	        renderer = SDL_CreateRenderer (window, -1, 0);
	        if (renderer == NULL) {
	        	SDL_Log("Could not create renderer: %s\n", SDL_GetError());
	        	return 1;
			}
			else {
				SDL_Rect border;
	            SDL_Rect sky;
	            SDL_Rect ground;

				border.x = 0;
				border.y = 0;
				border.w = WINWIDTH;
				border.h = WINHEIGHT;
				SDL_SetRenderDrawColor(renderer, 0x7F, 0x7f, 0x7f, 0x80);
				SDL_RenderFillRect(renderer, &border);
            
	            sky.x = 50;
	            sky.y = 20;
    	        sky.w = 540;
        	    sky.h = 430;
	            SDL_SetRenderDrawColor(renderer, 0xDF, 0xEF, 0x00, 0x80);
	            SDL_RenderFillRect(renderer, &sky);

	            ground.x = 50;
	            ground.y = 355;
	            ground.w = 540;
	            ground.h = 105;
	            SDL_SetRenderDrawColor(renderer, 0x9F, 0x7F, 0x00, 0x00);
	            SDL_RenderFillRect(renderer, &ground);
	            
	            SDL_Surface* surface = NULL;
	            SDL_Texture* texture = NULL;
	            SDL_Rect placetitle;
				placetitle.x = (int)(round((double) TITLECENTX - ((double) TITLEWIDTH/2.0)));
				placetitle.y = (int)(round((double) TITLECENTY - ((double) TITLEHEIGHT/2.0)));
				placetitle.w = TITLEWIDTH;
				placetitle.h = TITLEHEIGHT;
	            surface = SDL_LoadBMP("dinotitle1.bmp");
	            texture = SDL_CreateTextureFromSurface(renderer, surface);
	            int error = SDL_RenderCopy(renderer, texture, NULL, &placetitle);
	            if (error) SDL_Log ("Could not copy renderer. %s", SDL_GetError());
	            SDL_DestroyTexture(texture);
	            SDL_FreeSurface(surface);
	            
				SDL_RenderPresent(renderer);  }

	        SDL_Delay(10000);  // Pause execution for 10000 milliseconds, for example

	        // Close and destroy the renderer and window
	        SDL_DestroyRenderer(renderer);
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
