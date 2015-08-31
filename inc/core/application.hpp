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

        void init();

        int loop();

    private:
        sdlwrap::Render *prender;
        sdlwrap::Window *pwindow;

        bool toquit;
};

};

#endif /* APPLICATION_HPP */
