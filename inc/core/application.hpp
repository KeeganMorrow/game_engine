#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"
#include "core/world.hpp"

namespace core{
class Application{
    public:
        Application(int argc, char *arv[]):prender(nullptr), pwindow(nullptr){
            // TODO(KM, "Add some arument parsing type stuff here")
        }

        ~Application(){
            delete prender;
            delete pwindow;
            delete pworld;
        }

        void init();

        int loop();

    private:
        int loop_start_time;
        sdlwrap::Render *prender;
        sdlwrap::Window *pwindow;
        core::World *pworld;

        bool toquit;
};

};

#endif /* APPLICATION_HPP */
