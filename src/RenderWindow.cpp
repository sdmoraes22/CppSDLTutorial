#include "RenderWindow.hpp"
#include <iostream>

RenderWindow::RenderWindow(const char* title, int width, int height)
	:m_Window(NULL), m_Renderer(NULL)
{
	m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if(m_Window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(m_Renderer, filePath);

	if(texture == NULL)
		std::cout << "SDL Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;

}

void RenderWindow::clear()
{
	SDL_RenderClear(m_Renderer);

}

void RenderWindow::render(Entity& entity)
{
	SDL_Rect src;
	src.x = entity.getCurrentFrame().x;
	src.y = entity.getCurrentFrame().y;
	src.w = entity.getCurrentFrame().w;
	src.h = entity.getCurrentFrame().h;


	SDL_Rect dst;
	dst.x = entity.getPos().x * 4;
	dst.y = entity.getPos().y * 4;
	dst.w = entity.getCurrentFrame().w * 4;
	dst.h = entity.getCurrentFrame().h * 4;
	
	SDL_RenderCopy(m_Renderer, entity.getTexture(), &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(m_Renderer);
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(m_Window);
}

