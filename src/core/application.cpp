#include "application.hpp"
#include "sdlwrap/surface.hpp"
#include <string>

namespace core{

void Application::init(){
    // TODO(KM, "Remove magic numbers")
    pwindow = new sdlwrap::Window("Engine", 0, 0, 640, 480, 0);
    prender = new sdlwrap::Render(pwindow, -1,
            SDL_RENDERER_ACCELERATED);

    toquit = false;
}

int Application::loop(){
    int ret;

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
