#ifndef RENDERING_HPP
#define RENDERING_HPP
#include <entityx/entityx.h>
#include "components/basic.hpp"
#include <iostream>
namespace systems{


class PositionPrinter : public entityx::System<PositionPrinter> {
public:
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override {
        es.each<components::Position, components::Direction>([dt](entityx::Entity entity, components::Position &position, components::Direction &direction) {
            position.x += direction.x * dt;
            position.y += direction.y * dt;
            std::cout << "position is now " << position.x << "," << position.y << "\n";
        });
    }
    };
};
#endif /* RENDERING_HPP */
