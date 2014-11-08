// Copyright 2014 Keegan Morrow


#include "core/input/input.h"


namespace core {

     bool InputRegistration::isEventHandled(EventType eventtype) {
        switch (eventtype) {
        case EVENT_TYPE_KEY:
            return handledtypes.key != 0;
        case EVENT_TYPE_MOUSE:
            return handledtypes.mouse != 0;
        case EVENT_TYPE_JOYAXIS:
            return handledtypes.joyaxis != 0;
        case EVENT_TYPE_JOYBUTTON:
            return handledtypes.joybutton != 0;
        case EVENT_TYPE_TOUCH:
            return handledtypes.touch != 0;
        case EVENT_TYPE_RENDER:
            return handledtypes.render != 0;
        case EVENT_TYPE_QUIT:
            return handledtypes.quit != 0;
        default:
            // TODO(KM, "Log an error")
            return false;
        }
    }
    bool InputController::handleInput(void) {
        SDL_Event e;
        // TODO(KM, "Should make a maximum # of events that can be read")
        while (SDL_PollEvent(&e)) {
            EventType type = EVENT_TYPE_NONE;
            switch(e.type){
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    type = EVENT_TYPE_KEY;
                case SDL_MOUSEMOTION:
                case SDL_MOUSEBUTTONDOWN:
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEWHEEL:
                    type = EVENT_TYPE_MOUSE;
                default:
                    //TODO(KM, "Log an error")
                    type = EVENT_TYPE_NONE;
            }
            for (auto it = inputhandlers.begin();
                it != inputhandlers.end(); ++it) {
                if (it->isEventHandled(type)) {
                    it->handleEvent(&e);
                }
            }
        }
        return true;
    }

    bool InputController::registerInput(EventHandler handler,
        struct HandledEvents eventtypes) {
        inputhandlers.emplace_back(handler, eventtypes);
        return true;
    }
};
