// Copyright 2014 Keegan Morrow
// Example program:
// Using SDL2 to create an application window

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "core/logging/logging.h"
#include "core/render/render.h"
int main(int argc, char* argv[]) {
    SDL_Window *pWindow;                    // Declare a pointer

    logging::LoggerManager *pLogManager = new logging::LoggerManager();

    log4cplus::Logger logger = pLogManager->getLogger("logger");

    render::RenderInit(640,480);

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    render::RenderDeInit();

    delete pLogManager;

    return 0;
}

