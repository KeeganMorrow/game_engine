#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "core/world.hpp"
#include "components/basic/position.hpp"
#include "components/render/render.hpp"
using namespace core;

TEST(WorldTest, init) {
    World *pworld = new World();
    //EXPECT_EQ(pworld->systems.system
    delete pworld;
}
