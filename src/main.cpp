// Copyright 2014 Keegan Morrow
// Example program:
// Using SDL2 to create an application window

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "core/input/input.h"
#include "core/logging/logging.h"
#include "core/loop/loop.h"
#include "core/render/render.h"
#include "core/management/contentmanager.h"
#include "core/app.hpp"

int main(int argc, char* argv[]) {

    core::App mainApplication;

    mainApplication.init(argc, argv);

    return 0;
}

