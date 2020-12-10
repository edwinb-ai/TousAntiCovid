
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define true 1
#define false 0

int main(int argc, char* argv[]) {

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* lettuce_sur;
    SDL_Texture* lettuce_tex;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    	printf("Error SDL2 Initialization : %s \n",SDL_GetError());
    	return 1;
    }
    	
    if (IMG_Init(IMG_INIT_PNG) == 0) {
    	printf("Error SDL2_image Initialization");
    	return 2;
    }
    
    window = SDL_CreateWindow(
        "First program", SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL
    );
    if (window == NULL) {
    	printf("Error window creation\n");
    	return 3;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
    	printf("Error renderer creation\n");
    	return 4;
    }
    
    lettuce_sur = IMG_Load("../images/lambda.png");
    if (lettuce_sur == NULL) {
    	printf("Error loading image: \n%s\n", IMG_GetError());
    	return 5;
    }
    
    lettuce_tex = SDL_CreateTextureFromSurface(renderer, lettuce_sur);
    if (lettuce_tex == NULL) {
    	printf("Error creating texture\n");
    	return 6;
    }
    
    SDL_FreeSurface(lettuce_sur);
    
    while (true) {
    	SDL_Event e;
    	if (SDL_PollEvent(&e)) {
    		if (e.type == SDL_QUIT) {
    			break;
    		}
    	}
    
    	SDL_RenderClear(renderer);
    	SDL_RenderCopy(renderer, lettuce_tex, NULL, NULL);
    	SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyTexture(lettuce_tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}
