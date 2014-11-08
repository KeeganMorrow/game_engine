// Copyright 2014 Keegan Morrow

#ifndef _CORE_LOOP_H
#define _CORE_LOOP_H

#include "core/input/input.h"
#include "core/logging/logging.h"
#include "core/render/render.h"

namespace loop {

    extern log4cplus::Logger logger;

    typedef enum {
        GAME_STATE_INIT,
        GAME_STATE_LOOP,
        GAME_STATE_QUIT,
        GAME_STATE_COUNT
    }GameState;

    class LoopManager : public input::EventHandler {
    public:
        LoopManager(input::InputController *pinput) : pinput(pinput) {}
        ~LoopManager();
        void init();
        // TODO(KM, Add an exit code?)
        void runLoop();
        // TODO(KM, Make this protected?)
        void quit();

        bool isEventHandled(uint32_t eventtype);

        bool handleEvent(SDL_Event *pevent);
    private:
        GameState state = GAME_STATE_INIT;
        input::InputController *pinput = nullptr;
    };
};

#endif  // _CORE_LOOP_H

