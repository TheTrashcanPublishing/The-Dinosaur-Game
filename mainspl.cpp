// The Trashcan Splashscreen Test

#include <iostream>
#include "SDL2/SDL.h"
#include <cmath>
#include "splash.hpp"

using namespace std;

// bool ShowSplashScreen(void);

int main(int argc, char *argv[]) {
	int fail = 0;
	bool failure = false;
	failure = ShowSplashScreen();
	if (failure) fail = 1;
	return fail; } 

