// Header file for class gameWindow for TOG of DinosaurGame

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

class gameWindow
{
	public:
		SDL_Window* window;
		SDL_Renderer* renderer;
		bool failure;	
		gameWindow();	// default constructor
		gameWindow(SDL_Window* windowcp, SDL_Renderer* renderercp);
						// constructor with key pointers
		              
		gameWindow(SDL_Window* windowcp, SDL_Renderer* renderercp, bool failurecp);
						// constructor with all attributes defined
						
		gameWindow(const gameWindow &windowCopy);		// copy constructor
		operator=(const gameWindow &windowAssignment);	// assignment operator
		~gameWindow();	// destructor
	protected:
		bool _closed;
		bool _open;
		SDL_Window* OpenWindow(bool &failure);
		SDL_Renderer* CreateRenderer(SDL_Window* window, bool &failure);
		void CloseWindow(SDL_Window* window, SDL_Renderer* renderer );
};

#endif
