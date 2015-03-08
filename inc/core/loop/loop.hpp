// Copyright 2014 Keegan Morrow

#ifndef _CORE_LOOP_H
#define _CORE_LOOP_H

#include "core/input/input.hpp"
#include "core/render/render.hpp"

namespace loop {

    typedef enum {
        GAME_STATE_INIT,
        GAME_STATE_LOOP,
        GAME_STATE_QUIT,
        GAME_STATE_COUNT
    }GameState;

    class LoopManager : public input::EventHandler {
    public:
        explicit LoopManager(input::InputController *pinput) : pinput(pinput) {}
        virtual ~LoopManager() {}
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

