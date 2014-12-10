// Copyright 2014 Keegan Morrow


#include "core/loop/loop.h"


namespace loop {

    log4cplus::Logger logger = logging::Manager.getLogger("loop");

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
        LOG4CPLUS_INFO(logger, "Setting loop state to quit");
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
