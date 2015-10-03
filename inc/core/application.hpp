#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"
#include "core/world.hpp"

namespace core{
class Application{
    public:
        Application(int argc, char *arv[]){
            // TODO(KM, "Add some arument parsing type stuff here")
        }

        ~Application(){
            delete pworld;
        }

        void init();

        int loop();

    private:
        int loop_start_time;
        core::World *pworld;

        bool toquit;
};

}

#endif /* APPLICATION_HPP */
