#include <Entity.hpp>


Entity::Entity(vec2 p_pos,vec2 p_scale, vec2 p_texture_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
	currentFrame.x = p_texture_pos.x;
	currentFrame.y = p_texture_pos.y;
	currentFrame.w = p_scale.x;
	currentFrame.h = p_scale.y;
}


SDL_Texture* Entity::getTex(){return tex;}
SDL_Rect Entity::getCurrentFrame(){return currentFrame;}
void Entity::setPos(vec2 p_pos)
{
	pos = p_pos;
}

void Entity::setScale(vec2 p_scale)
{
	currentFrame.w = p_scale.x;
	currentFrame.h = p_scale.y;
}

void Entity::setTexturePos(vec2 p_texture_pos){
	currentFrame.x = p_texture_pos.x;
	currentFrame.y = p_texture_pos.y;
}

vec2 Entity::getTexturePos(){return vec2(currentFrame.x,currentFrame.y);}