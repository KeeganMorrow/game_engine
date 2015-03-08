#include "core/app.hpp"

namespace core {
        bool App::do_quit(){
            state = GAMESTATE_QUIT;
            return true;
        }
        bool App::do_init(){
            return true;
        }
        int App::do_runLoop(){
            int toreturn = 0;
            while (state != GAMESTATE_QUIT) {

            }
            return toreturn;
        }
        bool App::do_deinit(){
            return true;
        }

}

