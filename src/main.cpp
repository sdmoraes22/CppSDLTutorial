#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>


#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init Has Failed. SDL_ERROR: " << SDL_GetError() << std::endl;

	if(!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "Img_Init Has Failed. SDL_ERROR: " << SDL_GetError() << std::endl;	

	RenderWindow window("Game v1.0", 1280, 720);

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");



	// Entity entities[4] = {Entity(0,0, grassTexture),
	// 					  Entity(30,0, grassTexture), 
	// 					  Entity(30,30, grassTexture),
	// 					  Entity(30,60, grassTexture)};

	std::vector<Entity> entities = {Entity(Vector2f(0,0), grassTexture),
						  			Entity(Vector2f(30,0), grassTexture), 
						  			Entity(Vector2f(30,30), grassTexture),
						  			Entity(Vector2f(30,60), grassTexture)};

	{
		Entity test(Vector2f(100,50), grassTexture);

		entities.push_back(test);	
	}
	

	bool gameRunning = true;

	SDL_Event event;

	while(gameRunning)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				gameRunning = false;

		}
		window.clear();		

		for(Entity& entity : entities)
		{
			window.render(entity);
		}

		
		window.display();

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}