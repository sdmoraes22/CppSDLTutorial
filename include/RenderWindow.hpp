#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow
{
public:
	RenderWindow(const char* title, int width, int height );
	SDL_Texture* loadTexture(const char* filePath);
	void cleanUp();
	void clear();
	void render(Entity& entity);
	void display();
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};
