#include "core/application.hpp"
#include "sdlwrap/surface.hpp"
#include <string>
#include <iostream>

namespace core{

void Application::init(){
    // TODO(KM, "Remove magic numbers")
    pworld = new core::World();
    pworld->init();
    toquit = false;
}

int Application::loop(){
    //TODO: Move event handling out of application
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
            uint32_t old_time = loop_start_time;
            loop_start_time = SDL_GetTicks();
            float dt = (loop_start_time - old_time) / 1000.0;
            if ( loop_start_time >= last_update_time + 16 ){
                float update_dt = (loop_start_time - last_update_time) / 1000.0f;
                last_update_time = loop_start_time;
                pworld->update(update_dt);
            }
            pworld->render(dt);
        }
    }
    return 0;
}
}
