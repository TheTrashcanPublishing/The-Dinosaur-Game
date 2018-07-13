// TOG.cpp for TOG of DinosaurGame

#include "togi.hpp"

#define MAX_LEVEL 30
#define MARGIN_OF_ERROR 3

#define SPLASHWIDTH  400
#define SPLASHHEIGHT 400

// Set a UInt32 color for renderer from String colorName
UInt32 color(string colorName) {
	UInt32 col = 0x00000000;
	switch (colorName) {
		case "black":     col = 0x00000000; break;
		case "white":     col = 0xffffff00; break;
		case "red" :      col = 0xff000000; break;
		case "green":     col = 0x00ff0000; break;
		case "blue":      col = 0x0000ff00; break;
		case "yellow":    col = 0xffff0000; break;
		case "magenta":   col = 0xff00ff00; break;
		case "cyan":      col = 0x00ffff00; break;
		case "skycol":    col = 0xdfef0080; break;
		case "groundcol": col = 0x9f7f0080; break;
		default: }
	return col;	
}
 
// Wait a set time in seconds
void SecWait(int seconds) {
	Uint32 milliseconds = (Uint32) (seconds * 1000);
	SDL_Delay(milliseconds);
	return;
}

// Wait a set time in milliseconds
void MillisecWait(int millisecs) {
	Uint32 milliseconds = (Uint32) (millisecs);
	SDL_Delay(milliseconds);
	return;
}

void wait(int Level) {
	int t = 410 - (10 * Level);
	MillisecWait(t);
	return; }

Uint16 GetInput(SDL_Window* window) {
	window.getEvents();
		
}

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
            SPLASHWIDTH,                      // width, in pixels
            SPLASHHEIGHT,                     // height, in pixels
            SDL_WINDOW_BORDERLESS             // flags
        );

        // Check that the window was successfully created
        if (window == NULL) {
            // In the case that the window could not be made...
            SDL_Log("Could not create window: %s\n", SDL_GetError());
            failure = true; }
		else {
			// Create Renderer and Load Surface
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
				SecWait(10);	// Pause execution for 10 seconds

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
	return failure; }

gameWindow DisplayStartScreen(bool &fail) {
	fail = false;
	gamewindow* gdow = NULL;
	SDL_Renderer* rend = NULL;
	rend = DrawGameScreen(gdow, &fail);
	if (fail) //...
	else fail = PlaceTitleInfo(gdow);
    if (fail) //...
    else {
		else {
			//    PlayThemeMusic;   SDL_Audio_Function here;
		    bool FireButtonNotPressed;
		    int dinocurf = 0; 	// There are 4 dinosaur figures according to what position
			                	// the Dinosaur's feet are in
			Cartesian dinopos(GROUND, RIGHT_EDGE);
			string dinofile[4] = {"dino0.bmp", "dino1.bmp", "dino2.bmp", "dino3.bmp"};
			movingFigure* dinosaur = new movingFigure(4, dinopos, dinocurf, dinofile);
		    while (FireButtonNotPressed) {
		        while (dinocurf <= 4) {
		            failure = DisplayDinosaur(dinocurf, dinosaur.X()); // <<==
		            dinocurf++;
		            dinosaur.X(x - 5); // <<==
		            if ((FireButtonNotPressed) && (dinosaur.X() <= LEFT_EDGE))
						dinosaur.X(RIGHT_EDGE);
					}
			        dinocurf = 1;   }
			//    StopThemeMusic;
		    return failure;    }
	}
}

bool GamePlay(gameWindow* window) {
	bool failure = FALSE;
	failure = DisplayStoryBackground(window);
	if (failure) return failure;
	else {
    	while (FireButtonNotPressed)
    	    for (int StoryLine = 0; StoryLine <= LastLineOfStory; StoryLine++) {
				failure = DisplayStoryLine(StoryLine); // <<==
				if (failure) return failure; }
		}
    failure = DrawGameScreen(window);
    if (failure) return failure;
    else {
		int Level = 1;  // Initialize new game
		int Score = 0;
		int Lives = 3;
		int XPositionPlayer = LeftEdge;
		int XPositionDinosaur = RightEdge;
		int DinosaurFigure = 1;
		int PlayerFigure = 2; /* There are 3 player figures according to if the player is
		                         standing still (PlayerFigure = 2), moving to the left
								 (PlayerFigure = 1), or moving to the right (PlayerFigure = 3). */
		bool PlayerAlive = true;
		bool DinosaurAlive = true;
		failure = DisplayPlayer(XPositionPlayer, PlayerFigure); // <<==
		if (failure) return failure;
		else while ((Level < MAX_LEVEL) && (Lives > 0)) {
		    while ((DinosaurAlive) && (PlayerAlive)) {
	            if (NoJoystickMovement) || (JoystickUp) || (JoystickDown)) {
	                PlayerAlive = (XPositionPlayer < (XPositionDinosaur - MarginOfError));
	                if (DinosaurFigure <= 4) {
                    DisplayDinosaur(XPositionDinosaur, DinosaurFigure); // <<==
                    DinosaurFigure++;
                    XPositionDinosaur -= 5;
                    if (NoJoystickMovement) wait(Level);  // <<== (Wait)
                    else if (Level < (MAX_LEVEL - 2)) wait(Level + 2);  // <<== (Wait)
                    else wait(MAX_LEVEL);    }  // <<== (Wait)
                else DinosaurFigure = 1;    }
            else if ((JoystickLeft) || (JoystickDiagUpLeft) || (JoystickDiagDownLeft)) {
                PlayerAlive = (XPositionPlayer < (XPositionDinosaur - MarginOfError));
                int InitPlayerPosition = XPlayerPosition;
                int FinalPlayerPosition = XPlayerPosition+ 5;
                if (FinalPlayerPosition < LeftEdge) FinalPlayerPosition = LeftEdge;
                PlayerFigure = 1; // Facing left
                while (XPositionPlayer > FinalPlayerPosition) {
                    XPositionPlayer--;
                    DisplayPlayer(PlayerFigure, XPlayPOsition);    } // <<==
            }
            if ((JoystickRight) || (JoystickDiagUpRight) || (JoystickDiagDownRight)) {
                PlayerAlive = (XPositionPlayer < (XPositionDinosaur - MARGIN_OF_ERROR));
                int InitPlayerPosition = XPlayerPosition;
                int FinalPlayerPosition = XPlayerPosition + 5;
                PlayerFigure = 3; // Facing right
                while (XPositionPlayer < FinalPlayerPosition) {
                    XPositionPlayer++;
                    DisplayPlayer(PlayerFigure, XPlayPOsition);    }
            }
            else if (FireButtonPressed) {
                int YPositionSpear = Ground;
                int XPositionSpear = XPositionPlayer;
                bool DinoHit = FALSE;
                bool SpearFigure = FALSE; // There are 2 spear figures, one for shooting up
				                          // at 45 deg angle and one for going straight down
                for (int YPositionSpear = Ground; YPositionSprear > TopOfScreen;
						YPositionSpear--) {
		            XPositionSpear++;
                    failure = DisplaySpear(SpearFigure, XPositionSpear, YPositionSpear); } // <<==
                SpearFigure = TRUE; // Switch to falling spear
                For (int YPositionSpear = TopOfScreen; YPositionSpear < Ground; YPositionSpear++)
                    failure = DisplaySpear(SpearFigure, XPositionSpear, YPositionSpear); // <<==
                DinoAlive = !(Abs(XPositionSpear - XpositionDinosaur) <= 7); }
            }
        if (PlayerAlive) { // Dinosaur dead
//            KillDinosaur;
            Score += 100;
            Level++;
            GoNewLevel(); } // <<==
        else { // Player dead
//            KillPlayer;
            Lives--; }
        }
    if (Level == MAX_LEVEL) ShowEndGameGraphics(); // <<==
    return failure;    }
