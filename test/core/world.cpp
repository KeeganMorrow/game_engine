#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "core/world.hpp"
#include "components/basic/position.h"
#include "components/render/render.h"
using namespace core;

TEST(WorldTest, init) {
    World *pworld = new World();
    //EXPECT_EQ(pworld->systems.system
    delete pworld;
}
