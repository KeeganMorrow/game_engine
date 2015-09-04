#ifndef WORLD_HPP
#define WORLD_HPP
#include "components/basic.hpp"
#include "systems/rendering.hpp"

namespace core{
class World : public entityx::EntityX {
public:
    World(){
        systems.add<systems::PositionPrinter>();
        systems.configure();
        entityx::Entity entity = entities.create();
        entity.assign<components::Position>(0.0, 4.0);
        entity.assign<components::Direction>(0.0, 0.4);
    }

    void update(entityx::TimeDelta dt) {
        systems.update<systems::PositionPrinter>(dt);
    }
};

};

#endif /* WORLD_HPP */
