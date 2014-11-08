// Copyright 2014 Keegan Morrow

#ifndef _CORE_INPUT_H
#define _CORE_INPUT_H

#include <SDL2/SDL.h>
#include <vector>

namespace core {

    typedef enum {
        EVENT_TYPE_NONE = 0,
        EVENT_TYPE_KEY,
        EVENT_TYPE_MOUSE,
        EVENT_TYPE_JOYAXIS,
        EVENT_TYPE_JOYBUTTON,
        EVENT_TYPE_TOUCH,
        EVENT_TYPE_RENDER,
        EVENT_TYPE_QUIT,
        EVENT_TYPE_COUNT
    }EventType;

    struct HandledEvents {
        unsigned char
            key : 1,
            mouse : 1,
            joyaxis : 1,
            joybutton : 1,
            touch : 1,
            render : 1,
            quit : 1;
    };

    typedef bool EventHandler(SDL_Event *pevent);

    class InputRegistration {
    public:
        InputRegistration(EventHandler phandler, HandledEvents handledtypes)
         : phandler(phandler), handledtypes(handledtypes) {}

        HandledEvents getHandledEvents() {
            return handledtypes;
        }

        bool isEventHandled(EventType eventtype);

        bool handleEvent(SDL_Event *pevent) {
            return phandler(pevent);
        }

    private:
        EventHandler *phandler;
        HandledEvents handledtypes;
    };

    class InputController {
    public:
        InputController(void);
        ~InputController();
        bool handleInput(void);
        bool registerInput(EventHandler handler,
            struct HandledEvents eventtypes);
    private:
        std::vector<InputRegistration>inputhandlers;
    };
};

#endif  // _CORE_INPUT_H

