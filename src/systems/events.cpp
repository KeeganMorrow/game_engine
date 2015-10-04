#include "systems/events.hpp"
#include "core/application.hpp"
#include <SDL.h>
#include <iostream>
#include <assert.h>

// We are bypassing sdlwrap here - should this be changed in the future?
namespace systems{
struct InputEvent;

void EventSystem::init(core::Application *papp){
    papplication = papp;
}

void EventSystem::deinit(void){
}

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
        default:
            //Unhandled event
            break;
        }
    }
}

}
