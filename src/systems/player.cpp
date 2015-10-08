#include <SDL.h>
#include <assert.h>
#include "systems/player.hpp"
#include "systems/events.hpp"
#include "components/player.hpp"
#include "components/basic.hpp"
#include "core/application.hpp"
#include "core/logging.hpp"

// We are bypassing sdlwrap here - should this be changed in the future?
namespace systems{

void PlayerControlSystem::update(entityx::EntityManager &es,
                          entityx::EventManager &events,
                          entityx::TimeDelta dt){
    entityx::ComponentHandle<components::Player> player;
    for (entityx::Entity entity : es.entities_with_components(player)) {
        entityx::ComponentHandle<components::Spacial> spacial = entity.component<components::Spacial>();
        // TODO: Consider splitting this into a seperate function
        if (spacial){
            spacial->vel_x = input_x * 200;
            spacial->vel_y = input_y * 200;
        }
    }
}

void PlayerControlSystem::configure(entityx::EventManager &event_manager) {
    event_manager.subscribe<EventKey>(*this);
}

void PlayerControlSystem::receive(const EventKey &event){
    LOG(DEBUG) << "Keypress event recieved";
    if (! event.repeat){
        if(event.key == KEYS_MOVE_UP){
            if (event.press){
                input_y -= 1.0;
            }else{
                input_y += 1.0;
            }
        }else if(event.key == KEYS_MOVE_DOWN){
            if (event.press){
                input_y += 1.0;
            }else{
                input_y -= 1.0;
            }
        }else if(event.key == KEYS_MOVE_LEFT){
            if (event.press){
                input_x -= 1.0;
            }else{
                input_x += 1.0;
            }
        }else if(event.key == KEYS_MOVE_RIGHT){
            if (event.press){
                input_x += 1.0;
            }else{
                input_x -= 1.0;
            }
        }
    }
}

}
