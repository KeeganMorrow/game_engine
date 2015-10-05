#ifndef COMPONENTS_PATHFINDING_HPP
#define COMPONENTS_PATHFINDING_HPP
namespace components{
struct Pathfinding {
public:
    Pathfinding(bool isactive, float dest_x, float dest_y):isactive(isactive),dest_x(dest_x), dest_y(dest_y){}
    bool isactive;
    float dest_x, dest_y;
};

}
#endif /* COMPONENTS_PATHFINDING_HPP */
