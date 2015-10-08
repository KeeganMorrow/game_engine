#ifndef CORE_CONFIG_HPP
#define CORE_CONFIG_HPP

#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"
#include "core/world.hpp"

namespace core{
class Config{
    public:
        Config(int argc, char *argv[])
        {
            // Pretend this checks arguments for config override
        }

        ~Config(){
        }

        bool load_config(void);

        int res_x, res_y;
    private:
};

}

#endif /* CORE_CONFIG_HPP */
