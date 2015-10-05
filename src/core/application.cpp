#include "core/application.hpp"
#include "sdlwrap/surface.hpp"
#include <string>

namespace core{

int Application::loop(){

    while(toquit != true){
        if (pworld){
            loop_start_time = SDL_GetTicks();
            float dt = (loop_start_time - last_update_time) / 1000.0;
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
