// main.cpp for TOG of DinosaurGame

#include <iostream>
#include <cmath>
#include "SDL.h"
#include "tog.hpp"
using namespace std;

int main(void) {
    cout << "Testing, testing." << '\n';
    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect rectangle;

    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = 640;
    rectangle.h = 480;
    SDL_RenderFillRect(renderer, &rectangle);

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;



/*    while(1) {
        DisplayStartScreen();
        GamePlay();    }  */
    return 0;
    }
