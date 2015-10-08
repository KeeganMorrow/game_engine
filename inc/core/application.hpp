#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"
#include "core/world.hpp"
#include "core/logger_manager.hpp"
#include "core/config.hpp"

namespace core{
class Application{
    public:
        Application(int argc, char *argv[]);

        ~Application();

        int loop();

        void quit(){
            toquit = true;
        }

    private:
        uint32_t loop_start_time;
        uint32_t last_update_time;
        core::Config *pconfig;
        core::LoggerManager *plogger;
        core::World *pworld;

        bool toquit;
};

}

#endif /* APPLICATION_HPP */
