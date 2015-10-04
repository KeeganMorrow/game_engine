#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "components/basic.hpp"

using namespace components;

TEST(ComponentSpacial, PlusOperator) {
    // Only position and velocity are tested so far
    {
        Spacial s1(10, 24);
        Spacial s2(-120, 42);
        Spacial s3(2020, -412);
        auto result = s1 + s2 + s3;
        ASSERT_EQ(1910, result.pos_x);
        ASSERT_EQ(-346, result.pos_y);
    }
    {
        Spacial s1(0, 0, 0, 0, 0, -412, 20);
        Spacial s2(0, 0, 0, 0, 0, 212, 100);
        Spacial s3(0, 0, 0, 0, 0, 0, 43);
        auto result = s1 + s2 + s3;
        ASSERT_EQ(-200, result.vel_x);
        ASSERT_EQ(163, result.vel_y);
    }
}


TEST(ComponentSpacial, MinusOperator) {
    // Only position and velocity are tested so far
    {
        Spacial s1(10, 24);
        Spacial s2(-120, 42);
        Spacial s3(2020, -412);
        auto result = s1 - s2 - s3;
        ASSERT_EQ(-1890, result.pos_x);
        ASSERT_EQ(394, result.pos_y);
    }
    {
        Spacial s1(0, 0, 0, 0, 0, -412, 20);
        Spacial s2(0, 0, 0, 0, 0, 212, 100);
        Spacial s3(0, 0, 0, 0, 0, 0, 43);
        auto result = s1 - s2 - s3;
        ASSERT_EQ(-624, result.vel_x);
        ASSERT_EQ(-123, result.vel_y);
    }
}
