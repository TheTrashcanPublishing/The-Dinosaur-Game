// main.cpp for TOG of DinosaurGame

#include <iostream>
#include "SDL2/SDL.h"
#include <cmath>

#include "gameWindow.hpp"
#include "tog.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	gameWindow* win = new gameWindow();
	if (win->failure) return 1;
	else {
		win->failure = DisplayStartScreen(window);
		if (win->failure) return 1;
		else {
			while (!window.isClosed()) {
				window.pollEvents();
			}
			delete win;
			return 0; }
	}
}

/*    while(1) {
        DisplayStartScreen();
        GamePlay();    } 
    return 0;   */ /*
    }   */
