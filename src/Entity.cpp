#include "Entity.hpp"

Entity::Entity(Vector2f pos, SDL_Texture* texture)
: pos(pos), texture(texture)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;

}



SDL_Texture* Entity::getTexture()
{
	return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}