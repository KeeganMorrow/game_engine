#include "systems/events.hpp"
#include "core/application.hpp"
#include <SDL.h>
#include <iostream>
#include <assert.h>
#include <stdio.h>

// We are bypassing sdlwrap here - should this be changed in the future?
namespace systems{

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
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            events.emit<SDL_KeyboardEvent>(event.key);
            break;
        default:
            break;
        }
    }
}

}
