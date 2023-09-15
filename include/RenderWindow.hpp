#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Entity.hpp"
#include "Player.hpp"

class RenderWindow
{
public:
	RenderWindow(const char* title,int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(Entity& p_entity);
	void render(Player& p_player);
	void draw(Entity& p_entity);
	void draw(Player& p_player);
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};