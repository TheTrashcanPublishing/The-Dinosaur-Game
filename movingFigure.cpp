// Source file for class movingFigure for TOG of DinosaurGame

#include "movingFigure.hpp"


movingFigure::movingFigure() {
	numframes = 1;
	currentFrame = 0;
	filename = NULL;
	sdlsurf = NULL;
	position.atOrigin(); }

movingFigure::movingFigure(int fr, string* fnamearyptr) {
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	int initted = IMG_Init(flags);
	if((initted & flags) != flags) {
    	cerr << "IMG_Init: Failed to init required jpg, png, and tiff support!\n";
    	cerr << "IMG_Init: " << IMG_GetError()) << "\n"; }
	numframes = fr;
	currentFrame = 0;
	for (int i = 0; i < numframes; i++) {
		filename[i] = *(fnamearyptr + i);
		sdlsurf[i] = IMG_Load(filename[i]);
		if (sdlsurf[i] == NULL) cerr << "IMG_Load: " << IMG_GetError() << "\n"; }
	position.atOrigin(); }

movingFigure::movingFigure(int fr, int xpos, int ypos, string* fnamearyptr) {
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	int initted = IMG_Init(flags);
	if((initted & flags) != flags) {
    	cerr << "IMG_Init: Failed to init required jpg, png, and tiff support!\n";
    	cerr << "IMG_Init: " << IMG_GetError()) << "\n"; }
	numframes = fr;
	currentFrame = 0;
	for (int i = 0; i < numframes; i++) {
		filename[i] = *(fnamearyptr + i);
		sdlsurf[i] = IMG_Load(filename[i]); }
	position.x = xpos;
	position.y = ypos;
	position.concordanceInt(); }

movingFigure::movingFigure(int fr, Cartesian pos, string* fnamearyptr) {
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	int initted = IMG_Init(flags);
	if((initted & flags) != flags) {
    	cerr << "IMG_Init: Failed to init required jpg, png, and tiff support!\n";
    	cerr << "IMG_Init: " << IMG_GetError()) << "\n"; }
	numframes = fr;
	currentFrame = 0;
	for (int i = 0; i < numframes; i++) {
		filename[i] = *(fnamearyptr + i);
		sdlsurf[i] = IMG_Load(filename[i]); }
	position.x = pos.x;
	position.y = pos.y;
	position.concordanceInt(); }

movingFigure::movingFigure(int fr, int xpos, int ypos, SDL_Surface** surf, string* fnamearyptr) {
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	int initted = IMG_Init(flags);
	if((initted & flags) != flags) {
    	cerr << "IMG_Init: Failed to init required jpg and png support!\n";
    	cerr << "IMG_Init: " << IMG_GetError()) << "\n"; }
	numframes = fr;
	currentFrame = 0;
	for (int i = 0; i < numframes; I++) {
		filename[i] = *(fnamearyptr + i);
		sdlsurf[i] = IMG_Load(filename[i]);
		if (sdlsurf[i] == NULL) cerr << "IMG_Load: " << IMG_GetError() << "\n";
		else **(surf + i) = *sdlsurf[i]; }
	position.x = xpos;
	position.y = ypos;
	position.concordanceInt(); }

movingFigure::movingFigure(int fr, int xpos, int ypos, int fr, int curf, string* fnamearyptr) {
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	int initted = IMG_Init(flags);
	if((initted & flags) != flags) {
    	cerr << "IMG_Init: Failed to init required jpg, png, and tiff support!\n";
    	cerr << "IMG_Init: " << IMG_GetError()) << "\n"; }
	numframes = fr;
	currentFrame = curf;
	for (int i = 0; i < numframes; i++) {
		filename[i] = *(fnamearyptr + i);
		sdlsurf[i] = IMG_Load(filename[i]);
		if (sdlsurf[i] == NULL) cerr << "IMG_Load: " << IMG_GetError() << "\n"; }
	position.x = xpos;
	position.y = ypos;
	position.concordanceInt(); }

movingFigure::movingFigure(int fr, Cartesian pos, int curf, string* fnamearyptr) {
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	int initted = IMG_Init(flags);
	if((initted & flags) != flags) {
    	cerr << "IMG_Init: Failed to init required jpg, png, and tiff support!\n";
    	cerr << "IMG_Init: " << IMG_GetError()) << "\n"; }
	numframes = fr;
	currentFrame = curf;
	for (int i = 0; i < numframes; i++) {
		filename[i] = *(fnamearyptr + i);
		sdlsurf[i] = IMG_Load(filename[i]);
		if (sdlsurf[i] == NULL) cerr << "IMG_Load: " << IMG_GetError() << "\n"; }
	position.x = pos.x;
	position.y = pos.y;
	position.concordanceInt(); }

movingFigure::movingFigure(int fr, int xpos, int ypos, int curf, SDL_Surface** surf,
		string* fnamearyptr) {
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	int initted = IMG_Init(flags);
	if((initted & flags) != flags) {
    	cerr << "IMG_Init: Failed to init required jpg and png support!\n";
    	cerr << "IMG_Init: " << IMG_GetError()) << "\n"; }

	numframes = fr;
	currentFrame = curf;
	for (int i = 0; i < numframes; i++) {
		filename[i] = *(fnamearyptr + i);
		sdlsurf[i] = IMG_Load(filename[i]);
		if (sdlsurf[i] == NULL) cerr << "IMG_Load: " << IMG_GetError() << "\n";
		else **(surf + i) = *sdlsurf[i]; }
	position.x = xpos;
	position.y = ypos;
	position.concordanceInt(); }

movingFigure::movingFigure(int fr, Cartesian pos, int curf, SDL_Surface** surf,
		string* fnamearyptr) {
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	int initted = IMG_Init(flags);
	if((initted & flags) != flags) {
    	cerr << "IMG_Init: Failed to init required jpg and png support!\n";
    	cerr << "IMG_Init: " << IMG_GetError()) << "\n"; }

	numframes = fr;
	currentFrame = curf;
	for (int i = 0; i < numframes; i++) {
		filename[i] = *(fnamearyptr + i);
		sdlsurf[i] = IMG_Load(filename[i]);
		if (sdlsurf[i] == NULL) cerr << "IMG_Load: " << IMG_GetError() << "\n";
		else **(surf + i) = *sdlsurf[i]; }
	position.x = pos.x;
	position.y = pos.y;
	position.concordanceInt(); }

movingFigure::movingFigure(const movingFigure &figCopy) {
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	int initted = IMG_Init(flags);
	if((initted & flags) != flags) {
    	cerr << "IMG_Init: Failed to init required jpg and png support!\n";
    	cerr << "IMG_Init: " << IMG_GetError()) << "\n"; }

	numframes = figCopy.numframes;
	currentFrame = figCopy.currentFrame;
	for (int i = 0; i < numframes; i++) {
		filename[i] = figCopy.filename[i];
		*sdlsurf[i] = figCopy.*sdlsurf[i]; }
	position = figCopy.position;
	if !(position.concordance()) position.concordanceInt(); }

movingFigure movingFigure::operator=(const movingFigure &figAssignment) {
	if (figAssignment != *this) {
		int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
		int initted = IMG_Init(flags);
		if((initted & flags) != flags) {
    		cerr << "IMG_Init: Failed to init required jpg and png support!\n";
    		cerr << "IMG_Init: " << IMG_GetError()) << "\n"; }

		numframes = figAssignment.numframes;
		currentFrame = figAssignment.currentFrame;
		for (int i = 0; i < numframes; i++) {
			filename[i] = figAssignment.filename[i];
			*sdlsurf[i] = figAssignment.*sdlsurf[i]; }
		position = figAssignment.position;
		if !(position.concordance()) position.concordanceInt(); }
	return *this; }

movingFigure movingFigure::operator++(movingFigure &figPostIncrement, int) {
	*this(figPostIncrement);
	figPostIncrement.currentFrame = figPostIncrement.currentFrame + 1;
	if (figPostIncrement.currentFrame >= numframes) figPostIncrement.currentFrame = 0;
	return *this; }

movingFigure& movingFigure::operator++(movingFigure &figPreIncrement) {
	*this(figPreIncrement);
	currentFrame = figPreIncrement.currentFrame + 1;
	if (currentFrame >= numeframes) currentFrame = 0;
	figPreIncrement(*this);
	return *this; }

movingFigure movingFigure::operator--(movingFigure &figPostDecrement, int) {
	*this(figPostDecrement);
	figPostDecrement.currentFrame = figPostDecrement.currentFrame - 1;
	if (figPostDecrement.currentFrame < 0) figPostDecrement.currentFrame = numframes - 1;
	return *this; }

movingFigure& movingFigure::operator--(const movingFIgure &figPreDecrement) {
	*this(figPreDecrement);
	currentFrame = figPostDecrement.currentFrame - 1;
	if (currentFrame < 0) currentFrame = numframes - 1;
	figPreDecrement(*this);
	return *this; }

bool movingFigure::operator==(const movingFigure &figEqual1, const movingFigure &figEqual2) {
	bool equality = false;
	if (figEqual1.numframes == figEqual2.numframes) {
		equality = true;
		for (int i = 0; i < figEqual1.numframes; i++) {
			if (figEqual1.filename[i] == figEqual2.filename[i])
				if (figEqual1.*sdlsurf[i] == figEqual2.*sdlsurf[i])
					equality = (equality && true);
			else equality = false; } }
	return equality; }

bool movingFigure::operator!=(const movingFigure &figUnequal1, const movingFigure &figUnequal2) {
	bool inequality = false;
	if (figUnequal1.numframes != figUnequal2.numframes) inequality = true;
	else for (int i = 0; i < figUnequal1.numframes; i++) {
		if (figUnequal1.filename[i] != figUnequal2.filename[i]) inequality = true;
		else if (figUnequal1.*sdlsurf[i] != figUnequal2.*sdlsurf[i]) inequality = true; }
	return inequality; }

movingFigure::~movingFigure() {
	for (int i = 0; i < numframes; i++) SDL_FreeSurface(sdlsurf[i]);

	delete *sdlsurf[];
	delete filename[];
	delete position;
	
	IMG_Quit(); }

int movingFigure::X(void) { return position.x; }

int movingFigure::Y(void) { return position.y; }

Cartesian movingFigure::Position(void) { return position; }

int movingFigure::NumberOfFrames(void) { return numframes; }

int movingFigure::CurrentFrame(void) { return currentFrame; }

string movingFigure::Filename(void) { return filename[currentframe]; }

SDL_Surface* movingFigure::SDLSurfPointer(void) { return sdlsurf; }

void movingFigure::X(int xpos) {
	position.x = xpos;
	position.concordanceInt();
	return; }

void movingFigure::Y(int ypos) {
	position.y = ypos;
	position.concordanceInt();
	return; }

void movingFigure::X_Y(int xpos, int ypos) {
	position.x = xpos;
	position.y = ypos;
	position.concordanceInt();
	return; }

void movingFigure::Position(Cartesian pos) {
	position.x = pos.x;
	position.y = pos.y;
	position.concordanceInt();
	return; }

void movingFigure::CurrentFrame(int curf) {
	currentFrame = curf;
	return; }

void movingFigure::SDLSurfPointer(SDL_Surface* surf) {
	*sdlsurf[currentFrame] = *surf;
	return; }

SDL_Surface* movingFigure::Filename(string fname) {
	filename[currentFrame] = fname;
	sdlsurf[currentFrame] = IMG_Load(fname);
	if (sdlsurf[currentFrame] ==NULL ) cerr << "IMG_Load: " << IMG_GetError() << "\n";
	else SDL_Surface (*surf) = *sdlsurf[currentFrame];
	return surf; }

void movingFigure::incFrame(void) {
	currentFrame++;
	if (currentFrame >= numframes) currentFrame = 0;
	return; }

void movingFigure::decFrame(void) {
	currentFrame--;
	if (currentFrame < 0) currentFrame = numframes - 1;
	return; }

void movingFigure::display(void) {
	SDL_Rect background, mfigure;
	background.x = mfigure.x = (int) round(position.xx - (mfwidth / 2.0));
	background.y = mfigure.y = (int) round(position.yy - (mfheight / 2.0));
	background.w = mfigure.w = mfwidth;
	background.h = mfigure.h = mfheight;
	
	texture = SDL_CreateTextureFromSurface(renderer, sdlsurf[currentFrame]);
	int error = SDL_RenderCopy(renderer, texture, NULL, &mfigure);
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(renderer);
	return; }
