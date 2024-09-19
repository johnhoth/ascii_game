#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Renderer.hpp"
#include <iostream> // For std::cout

// Define window dimensions
const int RENDERER_WIDTH = 80;
const int RENDERER_HIGHT = 40;

const int CHAR_WIDTH = 10;
const int CHAR_HEIGHT = 20;

const int WINDOW_WIDTH = RENDERER_WIDTH * CHAR_WIDTH;
const int WINDOW_HEIGHT = RENDERER_HIGHT * CHAR_HEIGHT;

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Initialize TTF
    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf could not initialize! TTF_Error: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("ASCII Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (sdlRenderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    Renderer renderer(RENDERER_WIDTH, RENDERER_HIGHT, CHAR_WIDTH, CHAR_HEIGHT, sdlRenderer);

    const int FRAME_DELAY = 200; // Delay in milliseconds
    Uint32 frameStart;
    int frameTime;

    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                // Break the loop if the window is closed
                SDL_DestroyRenderer(sdlRenderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
        }

        frameStart = SDL_GetTicks(); // Get current time

        renderer.clear();
        
        
        renderer.render(R""""(
               ......                  ............. \n
            .....;;...                ................ \n
         .......;;;;;/mmmmmmmmmmmmmm\/.................. \n
       ........;;;mmmmmmmmmmmmmmmmmmm..................... \n
     .........;;m/;;;;\mmmmmm/;;;;;\m...................... \n
  ..........;;;m;;mmmm;;mmmm;;mmmmm;;m...................... \n
..........;;;;;mmmnnnmmmmmmmmmmnnnmmmm\.................... \n
.........  ;;;;;n/#####\nmmmmn/#####\nmm\................. \n
.......     ;;;;n##...##nmmmmn##...##nmmmm\............. \n
....        ;;;n#.....|nmmmmn#.....#nmmmmm,l......... \n
 ..          mmmn\.../nmmmmmmn\.../nmmmm,m,lll..... \n
          /mmmmmmmmmmmmmmmmmmmmmmmmmmm,mmmm,llll.. \n
      /mmmmmmmmmmmmmmmmmmmmmmm\nmmmn/mmmmmmm,lll/ \n
   /mmmmm/..........\mmmmmmmmmmnnmnnmmmmmmmmm,ll \n
  mmmmmm|...........|mmmmmmmmmmmmmmmmmmmmmmmm,ll \n
  \mmmmmmm\......./mmmmmmmmmmmmmmmmmmmmmmmmm,llo \n
    \mmmmmmm\.../mmmmmmmmmmmmmmmmmmmmmmmmmm,lloo \n
      \mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm,ll/oooo \n
         \mmmmmmmmmmll..;;;.;;;;;;/mmm,lll/oooooo\ \n
                   ll..;;;.;;;;;;/llllll/ooooooooo \n
                   ll.;;;.;;;;;/.llll/oooooooooo..o \n
                   ll;;;.;;;;;;..ll/ooooooooooo...oo \n
                   \;;;;.;;;;;..ll/ooooo...ooooo..oo\ \n
                 ;;;;;;;;;;;;..ll|oooo.....oooooooooo \n
                ;;;;;;.;;;;;;.ll/oooo.....ooooooo....\ \n
                ;;;;;.;;;;;;;ll/ooooooooooooo.....oooo \n
                 \;;;.;;;;;;/oooooooooooo.....oooooooo\ \n
                  \;;;.;;;;/ooooooooo.....ooooooooooooo \n
                    \;;;;/ooooooo.....ooooooooooo...ooo\ \n
                    |o\;/oooo.....ooooooooooooo......ooo \n
                    oooooo....ooooooooooooooooooo.....oo\ \n
                   oooo....oooooooooooooooooooooooo..oooo \n
                  ___.oooooooooooooo....ooooooooooooooooo\ \n
                 /XXX\oooooooooooo.....ooooooooooooooooooo \n
                 |XXX|ooooo.oooooo....ooooooooooooooooooooo \n
               /oo\X/oooo..ooooooooooooooooooo..oooooooooooo \n
             /ooooooo..ooooo..oooooooooooooo.....ooooooooo... \n
           /ooooo...ooooo.....oooooooooooo.......ooooooo.....o\n)""""
           );


        renderer.display(); // Present the frame

        // Calculate time taken for the frame
        frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime); // Delay until the next frame
        }
    }


    // Free resources
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
