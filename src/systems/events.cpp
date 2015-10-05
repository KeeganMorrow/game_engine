#include "systems/events.hpp"
#include "core/application.hpp"

#include <SDL.h>
#include <assert.h>
#include <stdio.h>

#include "core/logging.hpp"

// We are bypassing sdlwrap here - should this be changed in the future?
namespace systems{

//Note: dt should be the time since the last logic update!!
void EventSystem::update(entityx::EntityManager &es,
                          entityx::EventManager &events,
                          entityx::TimeDelta dt){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            papplication->quit();
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            LOG(DEBUG) << "Emitting keypress";
            events.emit<SDL_KeyboardEvent>(event.key);
            LOG(DEBUG) << "keypress emitted";
            break;
        default:
            break;
        }
    }
}

}
