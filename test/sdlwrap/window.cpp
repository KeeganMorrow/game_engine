#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SDL2/SDL.h>

#include "sdlwrap/window.hpp"

using namespace sdlwrap;

TEST(sdlwrapWindow, Constructor){
    Window w("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_HIDDEN);
    int x, y;
    w.GetSize(&x,&y);
    EXPECT_EQ(x, 640);
    EXPECT_EQ(y, 480);
    Uint32 flags = w.GetFlags();
    EXPECT_EQ(flags, SDL_WINDOW_HIDDEN);
}

