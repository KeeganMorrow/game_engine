#include "core/application.hpp"
#include "sdlwrap/surface.hpp"
#include <string>

namespace core{

void Application::init(){
    // TODO(KM, "Remove magic numbers")
    pworld = new core::World();
    pworld->init();
    toquit = false;
}

int Application::loop(){
    int old_time;
    int ret;
    float dt;
    old_time = loop_start_time;
    loop_start_time = SDL_GetTicks();
    dt = (loop_start_time - old_time) / 1000.0f;

    while(toquit != true){
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                toquit=true;
                break;
            default:
                //Unhandled event
                break;
            }
        }

        if (pworld){
            pworld->update(dt);
        }
    }
}
}
