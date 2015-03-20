#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SDL2/SDL.h>

#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"

using namespace sdlwrap;

TEST(sdlwrapRender, constructor) {
    SDL_Init(SDL_INIT_EVERYTHING);
    Window w("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    Render r(&w, -1, 0 );
    SDL_Quit();
}
