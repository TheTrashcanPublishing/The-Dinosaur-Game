// Header file for class movingFigure for TOG of DinosaurGame

#ifndef MOVINGFIGURE_HPP
#define MOVINGFIGURE_HPP

#include "SDL_image.h"

class movingFigure
{
	public:
		SDL_Texture* texture;
		SDL_Renderer* renderer;
		Cartesian position;
		int numframes, currentFrame;
		SDL_Surface*[] sdlsurf[numframes];
		string[] filename[numframes];

		movingFigure();
		movingFigure(int fr, string* fnamearyptr);
		movingFigure(int fr, int xpos, int ypos. string* fnamearyptr);
		movingFigure(int fr, Cartesian pos, string* fnamearyptr);
		movingFigure(int fr, int xpos, int ypos, SDL_Surface** surf, string* fnamearyptr);
		movingFigure(int fr, int xpos, int ypos, int curf, string* fnamearyptr);
		movingFigure(int fr, Cartesian pos, int curf, string* fnamearyptr);
		movingFigure(int fr, int xpos, int ypos, int curf, SDL_Surface** surf, string* fnamearyptr);
		movingFigure(int fr, Cartesian pos, int curf, SDL_Surface** surf, string* fnameptr);
		movingFigure(const movingFigure &figCopy);
		movingFigure operator=(const movingFigure &figAssignment);
		movingFigure operator++(const movingFigure &figPostIncrement, int);
		movingFigure& operator++ (movingFigure figPreIncrement);
		movingFigure operator--(const movingFigure &figPostDecrement, int);
		movingFigure& operator-- (movingFigure figPreDecrement)
		bool operator==(const movingFigure &figEqual1, const movingFigure &figEqual2);
		bool operator!=(const movingFigure &figUnequal1, const movingFigure &figUnequal2);
		~movingFigure();
		
		int X(void);
		int Y(void);
		Cartesian Position(void);
		int NumberOfFrames(void);
		int CurrentFrame(void);
		string Filename(void);
		SDL_Surface* SDLSurfPointer(void);
		
		void X(int xpos);
		void Y(int ypos);
		void X_Y(int xpos, int ypos);
		void Position(Cartesian pos);
		void CurrentFrame(int curf);
		void SDLSurfPointer(SDL_Surface* surf);
		SDL_Surface* Filename(string fname);
		
		void incFrame(void);
		void decFrame(void);
		
		void display(void);

	protected:
};

#endif
