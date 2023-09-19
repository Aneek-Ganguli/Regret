#include"Player.hpp"

void Player::update(SDL_Event& event,int& currentTime){
	//currentTime = SDL_RENDERER_PRESENTVSYNC;

	 std::cout << currentFrame.x <<" "<< currentFrame.y <<std::endl;

    //setTexturePos(vec2(,16));

	if(SDL_KEYDOWN == event.type) {
        if (SDLK_a == event.key.keysym.sym) {
            setPos(vec2(getPos().x -= (speed / SDL_RENDERER_PRESENTVSYNC), getPos().y));

            if (currentTime >= elaspedTime )
            {
                leftPos+=16;
                setTexturePos(vec2( leftPos, 0));
                currentTime = 0;
            }

            if (getTexturePos().x == 128)
            {
                leftPos = 96;
            }
        }

        else if (SDLK_d == event.key.keysym.sym) {
            setPos(vec2(getPos().x += (speed / SDL_RENDERER_PRESENTVSYNC), getPos().y));

            if (currentTime >= elaspedTime)
            {
                rightPos+=16;
                setTexturePos(vec2(rightPos, 0));
                currentTime = 0;
            }


            if (getTexturePos().x == 192-16)
            {
                rightPos = 144-16;
            }
        }


        //up and down
        else if (SDLK_w == event.key.keysym.sym) {
            setPos(vec2(getPos().x, getPos().y -= (speed / SDL_RENDERER_PRESENTVSYNC)));

            if (currentTime >= elaspedTime)
            {
                upPos+=16;
                setTexturePos(vec2(upPos, 0));
                currentTime = 0;
            }


            if (getTexturePos().x == 48*2-16)
            {
                upPos = 48;
            }
        }

        else if (SDLK_s == event.key.keysym.sym) {
            setPos(vec2(getPos().x, getPos().y += (speed / SDL_RENDERER_PRESENTVSYNC)));
            if (currentTime >= elaspedTime)
            {
                downPos+=16;
                setTexturePos(vec2(downPos, 0));
                currentTime = 0;
            }


            if (getTexturePos().x == 48-16)
            {
                downPos = 0;
            }
        }
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