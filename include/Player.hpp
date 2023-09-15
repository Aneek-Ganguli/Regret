#pragma once 
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Math.hpp"

class Player
{
public:
	void update(SDL_Event& event,int currentTime);

	Player(vec2 pos ,vec2 p_scale, vec2 p_texture_pos, SDL_Texture* p_tex);
	vec2&  getPos(){
		return pos;
	}
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
	void setPos(vec2 p_pos);
	void setScale(vec2 p_scale);
	void setTexturePos(vec2 p_texture_pos);
	vec2 getScale();
	vec2 getTexturePos();
private:
	vec2  pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
	float speed = 10.0f;
	//int currentTime = SDL_RENDERER_PRESENTVSYNC;
	int elaspedTime = 1024;
};