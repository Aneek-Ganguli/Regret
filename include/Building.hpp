#include <iostream>
#include <vector>
//#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Math.hpp"

class Building
{
public:
	Building(SDL_Texture* p_tex,int P_floorNum,std::string p_doorType,vec2 p_pos,vec2 p_doorAnimtionScale);
	std::string doorType; // Auto or Norm
	int floorNum;
	vec2 getScale();
	vec2 getAnimationPos();
	void setAnimationPos(vec2 p_pos);

private:
	SDL_Texture* tex;
	vec2 scale;
	vec2 pos;
	vec2 doorAimationScale;
	vec2 doorAimationPos;
};