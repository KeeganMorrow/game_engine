#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"
#include "core/world.hpp"

namespace core{
class Application{
    public:
        Application(int argc, char *arv[]):loop_start_time(0),last_update_time(-1){
            // TODO(KM, "Add some arument parsing type stuff here")
            pworld = new core::World(this);
            toquit = false;
        }

        ~Application(){
            delete pworld;
        }

        int loop();

        void quit(){
            toquit = true;
        }

    private:
        uint32_t loop_start_time;
        uint32_t last_update_time;
        core::World *pworld;

        bool toquit;
};

}

#endif /* APPLICATION_HPP */
