// Source file for class gameWindow for TOG of DinosaurGame

#include "gameWindow.hpp"

// default constructor
gameWindow::gameWindow() {
	failure = false;
	window = NULL;
	window = openWindow(&failure);
	if (failure) {
		window = NULL;
		renderer = NULL;
		_closed = true;
	}
	else {
		_closed = false;
		renderer = NULL;
		renderer = makeRenderer(window, &failure);
		if (failure) {
			window = NULL;
			_closed = true; }
		else {
			surface = NULL;
			surface = SDL_CreateRGBSurface(0, 0, 0, 0, 0, 0, 0, 0);
			failure = (surface == NULL);
			if (failure) {
			renderer = NULL;
			_closed = true; } } }
	_open = !(_closed); }

// constructor with file name
gameWindow::gameWindow(string fname) {
	_closed = false;
	failure = false;
	filename = fname;
	window = renderer = surface =  texture = NULL;
	window = openWindow(&failure);
	if (failure) _closed = true;
	else {
		renderer = makeRenderer(window, &failure);
		if (failure) _closed = true;
		else {
			surface = loadSurface(window, renderer, filename, &failure);
			if (failure) _closed = true;
			else {
				texture = makeTexture(renderer, surface, &failure);
				if (failure) _closed = true
				else _closed = false; } } }
	_open = !(_closed); }

// constructor with key pointers
gameWindow::gameWindow(SDL_Window* windowcp, SDL_Renderer* renderercp) {
	failure = false;
	window = NULL;
	window = openWindow(&failure)
	*window = *windowcp;
	if (failure) {
		window = NULL;
		renderer = NULL;
		_closed = true; }
	else {
		_closed = false;
		*renderer = *renderercp;
		if (failure) {
			window = NULL;
			renderer = NULL;
			_closed = true; }
	}
	_open = !(_closed);
}

// constructor with all attributes defined
gameWindow::gameWindow(SDL_Window* windowcp, SDL_Renderer* renderercp, bool failurecp)
{
	window = new SDL_Window();
	*window = *windowcp;
	renderer = new SDL_Renderer();
	*renderer = *renderercp;
	failure = failurecp;
	_closed = failure;
	_open = !(_closed);
}

// copy constructor
gameWindow gameWindow::gameWindow(const gameWindow &windowCopy) {
	failure = false;
	*window = windowCopy.*window;
	if (failure) {
		window = NULL;
		renderer = NULL;
		_closed = true; }
	else {
		_closed = false;
		*renderer = windowCopy.*renderer;
		if (failure) {
			window = NULL;
			renderer = NULL;
			_closed = false; }
		}
	_open = !(_closed);
}

// assignment operator
gameWindow gameWindow::operator=(const gameWindow &windowAssignment) {
	if (this != windowAssignment) {  // exclude self-assignment
		failure = false;
		*window = windowAssignment.*window;
		if (failure) {
			window = NULL;
			renderer = NULL;
			_closed = true; }
		else {
			_closed = false;
			*renderer = windowAssignment.*renderer;
			if (failure) {
				window = NULL;
				renderer = NULL;
				_closed = true; }
		}
	_open = !(_closed);	
	return *this;
}

// destructor
gameWindow::~gameWindow() {
	cleanUp(texture, surface);
	closeWindow(window, renderer); }

SDL_Window* gameWindow::Window(void) { return window; }

SDL_Surface* gameWindow::Surface(void) { return surface; }

SDL_Renderer* gameWindow::Renderer(void) {return renderer; }

SDL_Texture* gameWindow::Texture(void) { return texture; }

void gameWindow::Surface(SDL_Surface* surf) {
	surface = surf;
	return; }

void gameWindow::Renderer(SDL_Renderer* rend) {
	renderer = rend;
	return; }

SDL_Window* gameWindow::openWindow(bool &fail) {
	int status = SDL_Init(SDL_INIT_EVERYTHING);
	fail = (!(status == 0));
	if (fail) {
		SDL_Log("Could NOT initialize SDL: %s\n"), SDL_GetError());
		_closed = true; }
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
	        SDL_WINDOW_RESIZABLE               // flags
	    );

	    // Check that the window was successfully created
	    fail = (dow == NULL);
	    // In case the window could not be made
	    if (fail) {
	        SDL_Log("Could not create window: %s\n", SDL_GetError());
	        _closed = true; }
	    // Otherwise, if window was made
	    else _closed = false;
	}
	_open = !(_closed);
	return dow; }
	
SDL_Renderer* gameWindow::makeRenderer(SDL_Window* dow, bool &fail) {
	SDL_Renderer* rend = SDL_CreateRenderer();
	fail = (rend == NULL);
	_closed = fail;
	_open = !(_closed);
	return rend; }

SDL_Surface* gameWindow::loadSurface(string filename, bool &fail) {
	SDL_Surface* surf = NULL;
	surf = SDL_LoadBMP(filename);
	failure = (surf == NULL);
	if (failure) SDL_Log("Could not load surface screen: %s\n", SDL_GetError);
	return surf; }

SDL_Texture* gameWindow::makeTexture(SDL_Renderer* rend, SDL_Surface* surf, bool &fail) {
	SDL_Texture* tex = NULL;
	tex = SDL_CreateTextureFromSurface(rend, surf);
	fail = (tex == NULL);
	if (fail) SDL_Log("Could not make texture from surface. %s\n", SDL_GetError);
	else {
		SDL_FreeSurface(surf);
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, tex, NULL, NULL); } 
	return tex; }

SDL_Texture* gameWindow::makeTexture(SDL_Renderer* rend, int w, int h, bool &fail) {
	SDL_Texture* tex = NULL;
	tex = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, w, h);
	fail = (tex == NULL);
	if (fail) SDL_Log("Could not make texture. %s\n", SDL_GetError);
	else {
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, tex, NULL, NULL); }
	return tex; }

void gameWindow::display(SDL_Renderer* rend) {
	SDL_RenderPresent(rend);
	return; }

void gameWindow::cleanUp(SDL_Texture* tex, SDL_Surface* surf) {
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surf);
	return; }

void gameWindow::closeWindow(SDL_Window* dow, SDL_Renderer* rend) {
	_closed = true;
	_open = !(_closed);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(dow);
	SDL_Quit();
	return; }

