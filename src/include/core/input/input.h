// Copyright 2014 Keegan Morrow

#ifndef _CORE_INPUT_H
#define _CORE_INPUT_H

#include <SDL2/SDL.h>
#include <vector>

#include "core/logging/logging.h"

namespace input {

    extern log4cplus::Logger logger;

    class EventHandler {
    public:
        virtual bool isEventHandled(uint32_t eventtype) = 0;

        virtual bool handleEvent(SDL_Event *pevent) = 0;

        virtual ~EventHandler() {}
    };

    class InputController {
    public:
        InputController(void) {}
        ~InputController();
        bool handleInput(void);
        bool registerInput(EventHandler *phandler);
        bool unregisterInput(EventHandler *phandler);
    private:
        std::vector<EventHandler*>inputhandlers;
    };
};

#endif  // _CORE_INPUT_H

