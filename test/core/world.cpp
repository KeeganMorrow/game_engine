#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "core/world.hpp"
using namespace core;

TEST(WorldTest, init) {
    World *pworld = new World();
    //EXPECT_EQ(pworld->systems.system
    delete pworld;
}
