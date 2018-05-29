//source file for class gameWindow for TOG of DinosaurGame

#include "gameWindow.hpp"

// default constructor
gameWindow::gameWindow() {
	failure = FALSE;
	window = new SDL_Window;
	window = OpenWindow(&failure);
	if (failure) {
		window = NULL;
		renderer = NULL;
		_closed = TRUE;
	}
	else {
		_closed = FALSE;
		renderer = new SDL_Renderer;
		renderer = createRenderer(window, &failure);
	if (failure) {
		window = NULL;
		renderer = NULL;
		_closed = TRUE; }
	_open = !(_closed); }
}

// constructor with key pointers
gameWindow::gameWindow(SDL_Window* windowcp, SDL_Renderer* renderercp) {
	failure = FALSE;
	*window = *windowcp;
	if (failure) {
		window = NULL;
		renderer = NULL;
		_closed = TRUE; }
	else {
		_closed = FALSE;
		*renderer = *renderercp;
		if (failure) {
			window = NULL;
			renderer = NULL;
			_closed = TRUE; }
	}
	_open = !(_closed);
}

// constructor with all attributes defined
gameWindow::gameWindow(SDL_Window* windowcp, SDL_Renderer* renderercp, bool failurecp)
{
	window = new SDL_Window;
	*window = *windowcp;
	renderer = new SDL_Renderer;
	*renderer = *renderercp;
	failure = failurecp;
	_closed = failure;
	_open = !(_closed);
}

// copy constructor
gameWindow::gameWindow(const gameWindow &windowCopy) {
	failure = FALSE;
	*window = windowCopy->window;
	if (failure) {
		window = NULL;
		renderer = NULL;
		_closed = TRUE; }
	else {
		_closed = FALSE;
		*renderer = windowCopy->renderer;
		if (failure) {
			window = NULL;
			renderer = NULL;
			_closed = FALSE; }
		}
	_open = !(_closed);
}

// assignment operator
gameWindow::operator=(const gameWindow &windowAssignment) {
	if (this != windowAssignment) {  // exclude self-assignment
		failure = FALSE;
		*window = windowAssignment->window;
		if (failure) {
			window = NULL;
			renderer = NULL;
			_closed = TRUE; }
		else {
			_closed = FALSE;
			*renderer = windowAssignment->renderer;
			if (failure) {
				window = NULL;
				renderer = NULL;
				_closed = TRUE; }
		}
	_open = !(_closed);	
	return *this;
}

// destructor
gameWindow::~gameWindow() {
	CloseWindow(window, renderer);
}

SDL_Window* gameWindow::OpenWindow(bool &fail) {
	int status = SDL_Init(SDL_INIT_EVERYTHING);
	fail = (!(status == 0));
	if (fail) {
		SDL_Log("Could NOT initialize SDL: %s\n"), SDL_GetError());
	}
	else {
		SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN); // Debug
    
	    SDL_Window* dow = NULL;             // Declare a Window pointer
	    // Create an application window with the following settings:
	    dow = SDL_CreateWindow(
	        "The Dinosaur Game",               // window title
	        SDL_WINDOWPOS_UNDEFINED,           // initial x position
	        SDL_WINDOWPOS_UNDEFINED,           // initial y position
	        640,                               // width, in pixels
	        480,                               // height, in pixels
	        0                                  // flags
	    );

	    // Check that the window was successfully created
	    fail = (dow == NULL);
	    // In case the window could not be made
	    if (fail) {
	        SDL_Log("Could not create window: %s\n", SDL_GetError());
	    }
	}
	return (dow); }
	
SDL_Renderer* gameWindow::CreateRenderer(SDL_Window* dow, bool &fail) {
	SDL_Renderer* rend = SDL_CreateRenderer();
	fail = (rend != NULL);
	return rend;
}

void gameWindow::CloseWindow(SDL_Window* dow, SDL_Renderer* rend) {
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(dow);
	SDL_Quit();
	return;
}

