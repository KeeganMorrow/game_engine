#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SDL2/SDL.h>

#include "sdlwrap/window.hpp"

using namespace sdlwrap;

#ifndef NO_GUI

TEST(sdlwrapWindow, Constructor){
    Window w("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    int x, y;
    w.GetSize(&x,&y);
    EXPECT_EQ(640, x);
    EXPECT_EQ(480, y);
    Uint32 flags = w.GetFlags();
    EXPECT_EQ(0, SDL_WINDOW_SHOWN);
}

#endif //NO_GUI
