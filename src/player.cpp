#include"Player.hpp"

void Player::update(SDL_Event& event,int currentTime){
	//currentTime = SDL_RENDERER_PRESENTVSYNC;

	 std::cout << currentTime<<std::endl;
	// if (currentTime>= elaspedTime)std::cout << "sip"; 

	if(SDL_KEYDOWN == event.type){
		if(SDLK_a == event.key.keysym.sym)
		{
			setPos(vec2(getPos().x-=(speed/SDL_RENDERER_PRESENTVSYNC),getPos().y));
			
			if(currentTime>=elaspedTime)
			{
				currentTime = 0;
				setTexturePos(vec2(getTexturePos().x + 16,0));
				if(getTexturePos().x>=4)
				{
					setTexturePos(vec2(0,0));
				}
			}

			else
			{
				setTexturePos(vec2(0,0));
			}

		}

		if(SDLK_d == event.key.keysym.sym)
		{
			setPos(vec2(getPos().x+=(speed/SDL_RENDERER_PRESENTVSYNC),getPos().y));
		}


		//up and down
		if(SDLK_w == event.key.keysym.sym)
		{
			setPos(vec2(getPos().x,getPos().y-=(speed/SDL_RENDERER_PRESENTVSYNC)));
		}

		if(SDLK_s == event.key.keysym.sym)
		{
			setPos(vec2(getPos().x,getPos().y+=(speed/SDL_RENDERER_PRESENTVSYNC)));
		}
	}

	else
	{
		setTexturePos(vec2(0,0));
	}
}



Player::Player(vec2 p_pos,vec2 p_scale, vec2 p_texture_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
	currentFrame.x = p_texture_pos.x;
	currentFrame.y = p_texture_pos.y;
	currentFrame.w = p_scale.x;
	currentFrame.h = p_scale.y;
}


SDL_Texture* Player::getTex(){return tex;}
SDL_Rect Player::getCurrentFrame(){return currentFrame;}
void Player::setPos(vec2 p_pos)
{
	pos = p_pos;
}

void Player::setScale(vec2 p_scale)
{
	currentFrame.w = p_scale.x;
	currentFrame.h = p_scale.y;
}

void Player::setTexturePos(vec2 p_texture_pos){
	currentFrame.x = p_texture_pos.x;
	currentFrame.y = p_texture_pos.y;
}
vec2 Player::getTexturePos(){return vec2(currentFrame.x,currentFrame.y);}