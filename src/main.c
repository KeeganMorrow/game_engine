// Example program:
// Using SDL2 to create an application window

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    SDL_Window *pWindow;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    pWindow = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully made
    if (pWindow == NULL) {
        // In the event that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Texture *pTexture = IMG_LoadTexture(pRenderer, "resources/testimage.png");

    if ( pTexture == NULL ){
        printf ("Oh balls.");
    }

    SDL_Rect dst;
    dst.x = 100;
    dst.y = 100;
    dst.w = 100;
    dst.h = 100;
    SDL_RenderCopy(pRenderer, pTexture, NULL, &dst);
    SDL_RenderPresent(pRenderer);
    // The window is open: enter program loop (see SDL_PollEvent)

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(pWindow);

    // Clean up
    SDL_Quit();
    return 0;
}

