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

Application::Application(int argc, char *argv[]):
        loop_start_time(0),last_update_time(-1),
        pconfig(nullptr),plogger(nullptr),pworld(nullptr)
{
    plogger = new core::LoggerManager(argc, argv);
    plogger->loadConfig(std::string("logging.conf"));
    pconfig = new core::Config(argc, argv);
    pconfig->load_config();
    // TODO(KM, "Add some arument parsing type stuff here")
    pworld = new core::World(this, pconfig);

    toquit = false;
}

Application::~Application(){
    if (pworld){
        delete pworld;
    }
    if (plogger){
        delete plogger;
    }
    if (pconfig){
        delete pconfig;
    }
}

}
