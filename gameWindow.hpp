// Header file for class gameWindow for TOG of DinosaurGame

#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

class gameWindow
{
	public:
		gameWindow();	// default constructor
		gameWindow(string fname);
		gameWindow(SDL_Window* windowcp, SDL_Renderer* renderercp);
						// constructor with key pointers
		              
		gameWindow(SDL_Window* windowcp, SDL_Renderer* renderercp, bool failurecp);
						// constructor with all attributes defined
						
		gameWindow gameWindow(const gameWindow &windowCopy);		// copy constructor
		gameWindow operator=(const gameWindow &windowAssignment);	// assignment operator
		~gameWindow();	// destructor
		
		SDL_Window* Window(void);
		SDL_Surface* Surface(void);
		SDL_Renderer* Renderer(void);
		SDL_Texture* Texture(void);
		
		void Surface(SDL_Surface* surf);
		void Renderer(SDL_Renderer* rend);
		
	protected:
		SDL_Window* window;
		SDL_Surface* surface;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		string filename;
		bool failure;
		bool _closed;
		bool _open;
		SDL_Window* openWindow(bool &fail);
		SDL_Renderer* makeRenderer(SDL_Window* dow, bool &fail);
		SDL_Surface* loadSurface(string filename, bool &fail);
		SDL_Texture* makeTexture(SDL_Renderer* rend, SDL_Surface* surf, bool &fail);
		SDL_Texture* makeTexture(SDL_Renderer* rend, int w, int h, bool &fail);
		
		void display(SDL_Renderer* rend);
		void cleanUp(SDL_Texture* tex, SDL_Surface* surf);
		void closeWindow(SDL_Window* dow, SDL_Renderer* rend);
};

#endif
