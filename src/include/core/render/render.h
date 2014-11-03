// Copyright 2014 Keegan Morrow

#ifndef _CORE_RENDER_H_
#define _CORE_RENDER_H_

#include "core/logging/logging.h"

namespace render {
    class Renderer {
    public:
        bool Init(uint16_t winwidth, uint16_t winheight);
        bool DeInit();
        Renderer() {}
        Renderer(uint16_t winwidth, uint16_t winheight) {
            Init(winwidth, winheight);
        }
        ~Renderer() {
            DeInit();
        }
    private:
        bool isinitialized = false;
        SDL_Window *pwindow = nullptr;
        SDL_Renderer *prenderer = nullptr;
        log4cplus::Logger logger = logging::Manager.getLogger("render");;
    };
};
#endif  // _CORE_RENDER_H_
