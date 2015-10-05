#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "sdlwrap/surface.hpp"
#include "sdlwrap/exceptions.hpp"

using namespace sdlwrap;

TEST(Surface, Constructor){
    bool didexcept = false;
    try{
        Surface s(std::string("resources/testimage.png"));
    }
    catch (exMissingFile &e)
    {
        didexcept = true;
    }
    EXPECT_FALSE(didexcept);

    didexcept = false;
    try {
        Surface s2(std::string("notarealfile.png"));
    }
    catch (exMissingFile &e)
    {
        didexcept = true;
    }
    EXPECT_TRUE(didexcept);
}
