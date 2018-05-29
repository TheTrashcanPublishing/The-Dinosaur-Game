//TOG.hpp

#ifndef _TOG_INCL_
#define _TOG_INCL_

class tog {

public:
	
	UInt32 color(string colorName);
	
	void SecWait(int seconds);
	
	void MillisecWait(int millisecs);
	
	void wait(int Level);
	
	Uint16 GetInput(SDL_Window* window);

    bool DisplayStartScreen(gameWindow* window);

    void GamePlay(gameWindow* window);

};

#endif // _TOG_INCL_
