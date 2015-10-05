#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"
#include "core/world.hpp"
#include "core/logging.hpp"

namespace core{
class Application{
    public:
        Application(int argc, char *argv[]):
            loop_start_time(0),last_update_time(-1),
            plogger(nullptr),pworld(nullptr)
        {
            plogger = new core::LoggerManager(argc, argv);
            plogger->loadConfig(std::string("logging.conf"));
            // TODO(KM, "Add some arument parsing type stuff here")
            pworld = new core::World(this);

            toquit = false;
        }

        ~Application(){
            if (pworld){
                delete pworld;
            }
            if (plogger){
                delete plogger;
            }
        }

        int loop();

        void quit(){
            toquit = true;
        }

    private:
        uint32_t loop_start_time;
        uint32_t last_update_time;
        core::LoggerManager *plogger;
        core::World *pworld;

        bool toquit;
};

}

#endif /* APPLICATION_HPP */
