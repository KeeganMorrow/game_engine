#include "sdlwrap/sdl.hpp"

#include <SDL2/SDL.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(SDLmain,init){
    EXPECT_FALSE(SDL_WasInit(SDL_INIT_EVERYTHING));
    sdlwrap::Sdl *psdl = new sdlwrap::Sdl(SDL_INIT_EVERYTHING);;
    EXPECT_TRUE(SDL_WasInit(SDL_INIT_EVERYTHING));
    delete psdl;
    EXPECT_FALSE(SDL_WasInit(SDL_INIT_EVERYTHING));
}

