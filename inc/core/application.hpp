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
        }

    private:
        sdlwrap::Render *prender;
        sdlwrap::Window *pwindow;
};

};

#endif /* APPLICATION_HPP */
