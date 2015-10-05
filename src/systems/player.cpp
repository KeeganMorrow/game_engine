#include <SDL.h>
#include <assert.h>
#include "systems/player.hpp"
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
    event_manager.subscribe<SDL_KeyboardEvent>(*this);
}

void PlayerControlSystem::receive(const SDL_KeyboardEvent &event){
    LOG(DEBUG) << "Keypress event recieved";
    if (! event.repeat){
        if(event.keysym.sym == SDLK_w){
            if (event.type == SDL_KEYDOWN){
                input_y -= 1.0;
            }else{
                input_y += 1.0;
            }
        }else if(event.keysym.sym == SDLK_s){
            if (event.type == SDL_KEYDOWN){
                input_y += 1.0;
            }else{
                input_y -= 1.0;
            }
        }else if(event.keysym.sym == SDLK_a){
            if (event.type == SDL_KEYDOWN){
                input_x -= 1.0;
            }else{
                input_x += 1.0;
            }
        }else if(event.keysym.sym == SDLK_d){
            if (event.type == SDL_KEYDOWN){
                input_x += 1.0;
            }else{
                input_x -= 1.0;
            }
        }
    }
}

}
