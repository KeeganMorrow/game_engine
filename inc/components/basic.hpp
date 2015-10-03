#ifndef COMPONENTS_BASIC_HPP
#define COMPONENTS_BASIC_HPP
namespace components{
struct Spacial {
public:
    Spacial(float pos_x, float pos_y, float size_x=0,float size_y=0,
            float rotation=0, float vel_x=0, float vel_y=0
           ) :
        pos_x(pos_x), pos_y(pos_y), size_x(size_x), size_y(size_y),
        rotation(rotation), vel_x(vel_x), vel_y(vel_y){}

    float pos_x, pos_y, size_x, size_y, rotation, vel_x, vel_y;
};

};
#endif /* COMPONENTS_BASIC_HPP */
