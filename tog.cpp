// TOG.cpp for TOG of DinosaurGame

#include "togi.hpp"

#define MAX_LEVEL 30
#define MARGIN_OF_ERROR 3

// Set a UInt32 color for renderer from String colorName
UInt32 tog::color(string colorName) {
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
void tog::SecWait(int seconds) {
	Uint32 milliseconds = (Uint32) (seconds * 1000);
	SDL_Delay(milliseconds);
	return;
}

// Wait a set time in milliseconds
void tog::MillisecWait(int millisecs) {
	Uint32 milliseconds = (Uint32) (millisecs);
	SDL_Delay(milliseconds);
	return;
}

void tog::wait(int Level) {
	int t = 410 - (10 * Level);
	MillisecWait(t);
	return; }

Uint16 tog::GetInput(SDL_Window* window) {
	window.getEvents();
		
}

bool tog::DisplayStartScreen(gameWindow window) {
	bool failure = FALSE;
    failure = DrawGameScreen(window);
    if (failure) return failure;
    else {
		failure = DrawTitleInfo(window);
		if (failure) return failure;
		else {
			//    PlayThemeMusic;   SDL_Audio_Function here;
		    bool FireButtonNotPressed;
		    int XPositionDinosaur = RightEdge;
		    int DinosaurFigure = 1;  // There are 4 dinosaur figures according to what position
			                         // the Dinosaur's feet are in
		    while (FireButtonNotPressed) {
		        while (DinosaurFigure <= 4) {
		            failure = DisplayDinosaur(DinosaurFigure, XPositionDinosaur); // <<==
		            DinosaurFigure++;
		            XPositionDinosaur -= 5;
		            if ((FireButtonNotPressed) && (XPositionDinosaur <= LeftEdge))
						XPositionDinosaur = RightEdge;
					}
			        Dinosaurfigure = 1;   }
			//    StopThemeMusic;
		    return failure;    }
	}
}

bool tog::GamePlay(gameWindow* window) {
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
