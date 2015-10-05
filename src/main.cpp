// Copyright 2014 Keegan Morrow
// Example program:
// Using SDL2 to create an application window

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "core/application.hpp"
#include "core/logging.hpp"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[]) {
    LOG(INFO) << "initializing things";
    core::Application *papp = new core::Application(argc, argv);
    papp->loop();
    delete papp;
    return 0;
}

