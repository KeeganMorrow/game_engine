#ifndef BASIC_HPP
#define BASIC_HPP
namespace components{
struct Position {
    Position(float x, float y) : x(x), y(y) {}
    float x, y;
};

struct Direction {
    Direction(float x, float y) : x(x), y(y) {}
    float x, y;
};
};
#endif /* BASIC_HPP */
