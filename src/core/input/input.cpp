// Copyright 2014 Keegan Morrow


#include "core/input/input.hpp"


namespace input {

    InputController::~InputController() {}

    bool InputController::handleInput(void) {
        SDL_Event e;
        // TODO(KM, "Should make a maximum # of events that can be read")
        while (SDL_PollEvent(&e)) {
            for (auto it = inputhandlers.begin();
                it != inputhandlers.end(); ++it) {
                if ((*it)->isEventHandled(e.type)) {
                    (*it)->handleEvent(&e);
                }
            }
        }
        return true;
    }

    bool InputController::registerInput(EventHandler *phandler) {
        inputhandlers.push_back(phandler);
        return true;
    }
};
