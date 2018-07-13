#include "RasterText.h"

RasterText::RasterText(int charNum, int fontNum)
{
}

RasterText::~RasterText()
{
}

bool RasterText::initializeFont(int fntNum, int charWidth, int charHeight, string fontfilename) {
	bool failure = false;
	SDL_Surface* surface = NULL;
	SDL_Renderer* renderer = NULL;
	surface = SDL_LoadBMP(fontfilename);
	if (surface != NULL) {
		long int lastX = 0L;
		for (int i = 0; i < 127; i++) {
			SDL_Rect charRect;
			charRect.x = (short int) lastX;
			charRect.y = 0;
			charRect.w = charWidth;
			charRect.h = charHeight;
			SDL_CreateTextureFromSurface(renderer, surface);
			SDL_RenderCopy(renderer, charTexture[fntNum][i], NULL, &charRect);
			SDL_DestroyRenderer(renderer);
			lastX += (long int) charWidth; }
		fontPtr[fntNum] = *charTexture[fntNum][0]; }
	else {
		SDL_Log("Could not open file. %s", SDL_GetError());
		failure = true; }
	return failure; }

bool RasterText::initializeFont(int fntNum, string fontfilename, string charsizefilename) {
	bool failure = false;
	SDL_Surface* surface = NULL;
	SDL_Renderer* renderer = NULL;
	string line = "";
	ifstream sizefile;
	sizefile.open(charsizefilename, ios::in);
	surface = SDL_LoadBMP(fontfilename);
	if (surface != NULL) {
		getline(sizefile, line);
		int charHeight = stoi(line, NULL, 10);
		long int lastX = 0L;

		for (int i = 0; i < 127; i++) {
			getline(sizefile, line);
			charSize[fntNum][i] = stoi(line, NULL, 10);
			SDL_Rect charRect;
			charRect.x = (short int) lastX;
			charRect.y = 0;
			charRect.w = charSize[fntNum][i];
			charRect.h = charHeight;
			SDL_CreateTextureFromSurface(renderer, surface);
			SDL_RenderCopy(renderer, charTexture[fntNum][i], NULL, &charRect);
			SDL_DestroyRenderer(renderer);
			lastX += (long int) charSize[fntNum][i]; }
		fontPtr[fntNum] = *charTexture[fntNum][0];
		sizefile.close; }
	else {
		SDL_Log("Could not open file. %s", SDL_GetError());
		failure = true; }
	return failure; }

int RasterText::Ascii2CharCode(char ascii) {
	int chrcode = -1;
	chrcode = ((int) ascii) - 32;
	if ((chrcode < 0) || (chrcode >= 128)) chrcode = -1;
	return chrcode; }

char RasterText::CharCode2Ascii(int chrcode) {
	char ascii = '\0';
	if ((chrcode < 0) || (chrcode >= 128)) ascii = '\0';
	else ascii = (char) (chrcode + 32);
	return ascii; }

int RasterText::CharSeq(void) { return charSeq; }

int RasterText::FontNum(void) { return fontNum; }

int RasterText::CurrentFontCode(void) { return fontCode[fontNum]; }

int RasterText::CurrentCharCode(void) { return charCode[charSeq]; }

int RasterText::CurrentCharSize(void) { return charSize[charSeq]; }

SDL_Texture* RasterText::CurrentCharTexture(void) { return charTexture[charSeq]; }

void RasterText::CharSeq(int chrSeq) {
	charSeq = chrSeq;
	return; }

void RasterText::FontNum(int fntNum) {
	fontNum = fntNum;
	return; }

void RasterText::CurrentFontCode(int curFntCode) {
	fontCode[fontNum] = curFntCode;
	return; }

void RasterText::CurrentCharCode(int curChrCode) {
	charCode[charSeq] = curChrCode;
	return; }

void RasterText::CurrentCharSize(int curChrSize) {
	charSize[charSeq] = curChrSize;
	return; }


