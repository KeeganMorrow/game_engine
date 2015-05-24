// Copyright 2014 Keegan Morrow
// Example program:
// Using SDL2 to create an application window

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "core/application.hpp"

int main(int argc, char* argv[]) {
    core::Application *papp = new core::Application(argc, argv);
    papp->init();
    delete papp;
    return 0;
}

