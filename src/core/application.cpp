#include "core/application.hpp"
#include "sdlwrap/surface.hpp"
#include <string>

namespace core{

void Application::init(){
    // TODO(KM, "Remove magic numbers")
    pwindow = new sdlwrap::Window("Engine", 0, 0, 640, 480, 0);
    prender = new sdlwrap::Render(pwindow, -1,
            SDL_RENDERER_ACCELERATED);
    pworld = new core::World();
    toquit = false;
}

int Application::loop(){
    int old_time;
    int ret;
    float dt;
    old_time = loop_start_time;
    loop_start_time = SDL_GetTicks();
    dt = (loop_start_time - old_time) / 1000.0f;

    auto psurface = new sdlwrap::Surface();
    psurface->init(std::string("resources/testimage.png"));
    auto ptexture = new sdlwrap::Texture();
    ptexture->init(prender, psurface);
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

        ret = prender->RenderClear();
        if (ret){
            printf("Error clearing renderer\n");
            return ret;
        }
        auto pdst = new sdlwrap::Rectangle(25, 25, 150, 80);
        ret = prender->RenderCopy(ptexture, nullptr, pdst);
        if (ret){
            printf("Error clearing renderer\n");
            return ret;
        }
        ret = prender->RenderPresent();
        if (ret){
            printf("Error presenting renderer\n");
            return ret;
        }
    }
}
}
