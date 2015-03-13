#include "sdlwrap/sdl.hpp"

#include <SDL2/SDL.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(SDLmain,init){
    sdlwrap::Sdl *psdl = new sdlwrap::Sdl();
    EXPECT_FALSE(SDL_WasInit(SDL_INIT_EVERYTHING));
    psdl->Init(SDL_INIT_TIMER);
    EXPECT_TRUE(SDL_WasInit(SDL_INIT_TIMER));
    psdl->Init(SDL_INIT_AUDIO);
    EXPECT_TRUE(SDL_WasInit(SDL_INIT_AUDIO));
    psdl->Init(SDL_INIT_VIDEO);
    EXPECT_TRUE(SDL_WasInit(SDL_INIT_VIDEO));
    psdl->Init(SDL_INIT_JOYSTICK);
    EXPECT_TRUE(SDL_WasInit(SDL_INIT_JOYSTICK));
    psdl->Init(SDL_INIT_HAPTIC);
    EXPECT_TRUE(SDL_WasInit(SDL_INIT_HAPTIC));
    psdl->Init(SDL_INIT_GAMECONTROLLER);
    EXPECT_TRUE(SDL_WasInit(SDL_INIT_GAMECONTROLLER));
    psdl->Init(SDL_INIT_EVENTS);
    EXPECT_TRUE(SDL_WasInit(SDL_INIT_EVENTS));
    delete psdl;
    EXPECT_FALSE(SDL_WasInit(SDL_INIT_EVERYTHING));
}

