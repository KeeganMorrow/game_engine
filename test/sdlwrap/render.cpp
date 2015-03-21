#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SDL2/SDL.h>

#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"

using namespace sdlwrap;

TEST(sdlwrapRender, constructor) {
    SDL_Init(SDL_INIT_EVERYTHING);
    Window w("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    bool didthrow = false;
    Render *pr = nullptr;

    // Verify exceptions work by passing invalid combination of flags
    try{
        pr = new Render(&w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_SOFTWARE );
    }
    catch (exInitFailure &e)
    {
        std::cout << "Exception occurred: " << e.what() << std::endl;
        didthrow = true;
    }
    EXPECT_TRUE(didthrow);

    delete pr;

    // Accept any type of renderer this time and verify no exception is thrown

    didthrow = false;
    try{
        pr = new Render(&w, -1, 0 );
    }
    catch (exInitFailure &e)
    {
        didthrow = true;
    }
    EXPECT_FALSE(didthrow);

    delete pr;
    SDL_Quit();
}
