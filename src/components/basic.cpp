#include "components/basic.hpp"

namespace components{
Spacial operator+(const Spacial &s1, const Spacial &s2){
    return Spacial(
                s1.pos_x + s2.pos_x,
                s1.pos_y + s2.pos_y,
                s1.size_x + s2.size_x,
                s1.size_y + s2.size_y,
                s1.rotation + s2.rotation,
                s1.vel_x + s2.vel_x,
                s1.vel_y + s2.vel_y
    );
}

Spacial operator-(const Spacial &s1, const Spacial &s2){
    return Spacial(
                s1.pos_x - s2.pos_x,
                s1.pos_y - s2.pos_y,
                s1.size_x - s2.size_x,
                s1.size_y - s2.size_y,
                s1.rotation - s2.rotation,
                s1.vel_x - s2.vel_x,
                s1.vel_y - s2.vel_y
    );
}
}
