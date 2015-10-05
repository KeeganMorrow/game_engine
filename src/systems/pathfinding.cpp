#include <algorithm>
#include "systems/pathfinding.hpp"
#include "components/pathfinding.hpp"
#include "core/logging.hpp"

namespace systems{
    PathfindingSystem::PathfindingSystem(){}

    void PathfindingSystem::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt){
        entityx::ComponentHandle<components::Pathfinding> pathfinding;
        entityx::ComponentHandle<components::Spacial> spacial;
for (entityx::Entity entity : es.entities_with_components(pathfinding, spacial)) {
        (void)entity;
        auto diff_x = spacial->pos_x - pathfinding->dest_x;
        auto diff_y = spacial->pos_y - pathfinding->dest_y;
        if(pathfinding->isactive){
            if (diff_x > 0){
                spacial->vel_x = -80;
            }else if (diff_x < 0){
                spacial->vel_x = 80;
            }else{
                spacial->vel_x = 0;
            }
            if (diff_y > 0){
                spacial->vel_y = -80;
            }else if (diff_y < 0){
                spacial->vel_y = 80;
            }else{
                spacial->vel_y = 0;
            }
        }
    }
    }

}


