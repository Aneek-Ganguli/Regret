
#include "RenderWindow.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL) 
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
}



SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
	return texture;	

}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
	SDL_Rect src; 
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPos().x * 4;
	dst.y = p_entity.getPos().y * 4;
	dst.w = p_entity.getCurrentFrame().w * 4;
	dst.h = p_entity.getCurrentFrame().h * 4;

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::render(Player& p_player)
{
	SDL_Rect src; 
	src.x = p_player.getCurrentFrame().x;
	src.y = p_player.getCurrentFrame().y;
	src.w = p_player.getCurrentFrame().w;
	src.h = p_player.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_player.getPos().x * 4;
	dst.y = p_player.getPos().y * 4;
	dst.w = p_player.getCurrentFrame().w * 4;
	dst.h = p_player.getCurrentFrame().h * 4;

	SDL_RenderCopy(renderer, p_player.getTex(), &src, &dst);
}



void RenderWindow::draw(Entity& p_entity)
{
	SDL_Rect src; 
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPos().x * 4;
	dst.y = p_entity.getPos().y * 4;
	dst.w = p_entity.getCurrentFrame().w * 4;
	dst.h = p_entity.getCurrentFrame().h * 4;

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::draw(Player& p_player)
{
	SDL_Rect src; 
	src.x = p_player.getCurrentFrame().x;
	src.y = p_player.getCurrentFrame().y;
	src.w = p_player.getCurrentFrame().w;
	src.h = p_player.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_player.getPos().x * 4;
	dst.y = p_player.getPos().y * 4;
	dst.w = p_player.getCurrentFrame().w * 4;
	dst.h = p_player.getCurrentFrame().h * 4;

	SDL_RenderCopy(renderer, p_player.getTex(), &src, &dst);
}


void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}