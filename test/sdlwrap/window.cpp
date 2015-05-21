#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SDL2/SDL.h>

#include "sdlwrap/window.hpp"

using namespace sdlwrap;

#ifndef NO_GRAPHICS
TEST(sdlwrapWindow, Constructor){
    SDL_Init(SDL_INIT_EVERYTHING);
    Window w("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    // TODO: Validate that exception is thrown correctly in constructor
    int x, y;
    w.GetSize(&x,&y);
    EXPECT_EQ(640, x);
    EXPECT_EQ(480, y);
    Uint32 flags = w.GetFlags();
    SDL_Quit();
}

#endif //ndef NO_GUI
