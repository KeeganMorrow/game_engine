#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"

namespace core{
class Application{
    public:
        Application(int argc, char *arv[]):prender(nullptr), pwindow(nullptr){
            // TODO(KM, "Add some arument parsing type stuff here")
        }

        ~Application(){
            delete prender;
            delete pwindow;
        }

        void init(){
            // TODO(KM, "Remove magic numbers")
            pwindow = new sdlwrap::Window("Engine", 0, 0, 640, 480, 0);
            prender = new sdlwrap::Render(pwindow, -1,
                    SDL_RENDERER_ACCELERATED);

            toquit = false;
        }

        int loop(){
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

    private:
        sdlwrap::Render *prender;
        sdlwrap::Window *pwindow;

        bool toquit;
};

};

#endif /* APPLICATION_HPP */
