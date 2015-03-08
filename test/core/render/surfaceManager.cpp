#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "core/render/surfaceManager.hpp"

using namespace render;

TEST(surfaceManager, Loader) {
    surfaceManager *manager = new surfaceManager();
    SDL_Surface *psurf1 = manager->requestSurface(std::string("resources/testimage.png"));

    SDL_Surface *psurf2 = manager->requestSurface(std::string("resources/testimage.png"));

    EXPECT_EQ(psurf1, psurf2);
}

