#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "RenderWindow.hpp"
#include "Math.hpp"
#include "Building.hpp"


int main(int argc, char const *argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO)> 0)
		std::cout<<"HEY .. SDL_Init HAS FAILED. SDL_ERROR"<<SDL_GetError()<<std::endl;

	if(!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;
	
	RenderWindow window("why did i do this",1360,768);  


	//SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");
	//SDL_Texture* KnightTexture = window.loadTexture("res/gfx/hulking_knight.png");
	SDL_Texture* playerTextureNormal = window.loadTexture("res/gfx/Sprout Lands - Sprites - Basic pack/Characters/its 16x16.png");
	
        
        
	Player player(vec2(0,0),vec2(16,16),vec2(0,0),playerTextureNormal);

	// std::vector<Entity> v = {
	// 	Entity(69,78,grassTexture),
	// 	Entity(87,86,grassTexture)
	// };

	/*
	tpos += 64 
	if tops > t.size
		tpos zero
	*/

	

	bool gameRunning = true; 

	SDL_Event event;

	int elT=1024;
	int cT;// = SDL_RENDERER_PRESENTVSYNC;
	int playerYPos= 0;


	while(gameRunning == true)
	{

		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
			{
				gameRunning=false;
			}

			player.update(event,cT);
		}

		window.clear();

		// for(Entity& iu : v)
		// {
		// 	window.render(iu);
		// }

		cT+=SDL_RENDERER_PRESENTVSYNC;


		// if(player.getTexturePos().x == 48)  
		// {
		// 	playerYPos += 16;
		// 	player.	setTexturePos(vec2(0,playerYPos));
		// }

		// if(player.getTexturePos().y >= 64)
		// {
		// 	playerYPos = 0;
		// }
		


		// if(cT >= elT)
		// {
		// 	player.setTexturePos(vec2(player.getTexturePos().x+16,playerYPos));
		// 	cT= 0;
		// }

		// std::cout << "x: " << player.getTexturePos().x << " y: " << player.getTexturePos().y << std::endl; 
		//window.render(platform0);

		//if(player.getTexturePos().x  >=144)
			//

		//69 x
		//232y

		//player.update(event);

		window.render(player);

		window.display();

//64

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}