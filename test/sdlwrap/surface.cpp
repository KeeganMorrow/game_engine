#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "sdlwrap/surface.hpp"
#include "sdlwrap/exceptions.hpp"

using namespace sdlwrap;

TEST(Surface, Constructor){
    bool didexcept = false;
    Surface s;
    try{
        s.init(std::string("resources/testimage.png"));
    }
    catch (exMissingFile &e)
    {
        didexcept = true;
    }
    EXPECT_FALSE(didexcept);

    didexcept = false;
    Surface s2;
    try {
        s2.init(std::string("notarealfile.png"));
    }
    catch (exMissingFile &e)
    {
        didexcept = true;
    }
    EXPECT_TRUE(didexcept);
}
