#ifndef RASTERTEXT_H
#define RASTERTEXT_H

class RasterText
{
	public:
		
		RasterText(void);
		RasterText();
		RasterText(int )
		~RasterText();

		bool initializeFont(int fntNum, int charWidth, int charHeight, string fontfilename);
		bool initializeFont(int fntNum, string fontfilename, string charsizefilename);
		bool initializeChar(int fntNum, int charSeq);

		int Ascii2CharCode(char ascii);
		char CharCode2Ascii (int chrcode);
		int CharSeq(void);
		int FontNum(void);
		int CurrentFontCode(void);
		int CurrentCharCode(void);
		int CurrentCharSize(void);
		SDL_Texture CurrentCharTexture(void);
		void CharSeq(int chrSeq);
		void FontNum(int fntNum);
		void CurrentFontCode(int curFntCode);
		void CurrentCharCode(int curChrCode);
		void CurrentCharSize(int curChrSize);
		void CurrentCharTexture(SDL_Texture* curChrTexture);
		
	protected:
		int charSeq;
		int fontNum;
		SDL_Texture** fontPtr[8];
		int charCode[8][128];
		int charSize[8][128];
		SDL_Texture* charTexture[8][128];
};

#endif
