#include "application.hpp"

namespace core{

void Application::init(){
    // TODO(KM, "Remove magic numbers")
    pwindow = new sdlwrap::Window("Engine", 0, 0, 640, 480, 0);
    prender = new sdlwrap::Render(pwindow, -1,
            SDL_RENDERER_ACCELERATED);

    toquit = false;
}

int Application::loop(){
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
    }
}
}
