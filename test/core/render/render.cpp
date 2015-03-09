#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "core/render/render.hpp"
#include "components/basic/position.hpp"
#include "components/render/render.hpp"
#include "core/world.hpp"

using namespace render;

TEST(RenderSystem, update){
    entityx::EntityX *pmanager = new entityx::EntityX();
    pmanager->systems.add<RenderSystem>();
    pmanager->systems.configure();
    EXPECT_TRUE(pmanager->systems.system<RenderSystem>() != nullptr);
}

