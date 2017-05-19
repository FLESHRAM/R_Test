#include "SDL2/SDL.h"
#include <stdio.h>


int main( int argc, char* args[] ) 
{ 
//   SDL_Window     *window;

//   SDL_Init(SDL_INIT_VIDEO);

//   window = SDL_CreateWindow("Test Environment", 100, 100, 640, 480, 0); 
  
//   if(window==NULL)
//   {   
//     printf("Could not create window: %s\n", SDL_GetError());
//     return 1;
//   }
  
//   SDL_Delay(3000);
  
//   SDL_DestroyWindow(window); 
   
//   SDL_Quit(); 

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);

    SDL_Window * screen;

    screen = SDL_CreateWindow("Test Environment", 100, 100, 640, 480, SDL_WINDOW_SHOWN); 

    bool running = true;



    SDL_Renderer* rR = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

    //SDL_Delay(3000);
    while(running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running = false;
                break;
            }
        }
    }

    // while(running)
    // {
    //     SDL_Event event;
    //     while(SDL_PollEvent(&event))
    //     {
    //         switch(event.type)
    //         {
    //             case SDL_QUIT:
    //                 running = false;
    //             break;
    //         }

    //         SDL_Delay(3000);
    //     }
    // }

    SDL_DestroyWindow(screen); 
    SDL_Quit();
    return 0;   
}