// Copyright 2014 Keegan Morrow


#include "core/loop/loop.hpp"
#include "core/logging/logging.hpp"


namespace loop {

    void LoopManager::init() {
        state = GAME_STATE_LOOP;
        pinput->registerInput(this);
    }

    void LoopManager::runLoop() {
        while (state == GAME_STATE_LOOP) {
            if (pinput) {
                pinput->handleInput();
            }
        }
    }

    void LoopManager::quit() {
        state = GAME_STATE_QUIT;
        CLOG(ERROR, "core.loop") << "Setting loop state to quit";
    }

    bool LoopManager::isEventHandled(uint32_t eventtype) {
        bool toreturn = false;
        if (eventtype == SDL_QUIT) {
            toreturn = true;
        }
        return toreturn;
    }

    bool LoopManager::handleEvent(SDL_Event *pevent) {
        bool toreturn = false;
        if (pevent->type == SDL_QUIT) {
            quit();
            toreturn = true;
        }
        return toreturn;
    }
};
