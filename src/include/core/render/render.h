// Copyright 2014 Keegan Morrow

#ifndef _CORE_RENDER_H_
#define _CORE_RENDER_H_

#include "core/logging/logging.h"

namespace render {

    class Renderer;

    void RenderInit(uint16_t winwidth, uint16_t winheight);
    void RenderDeInit();

    extern Renderer *pRenderer;

    extern log4cplus::Logger logger;

    class Renderer {
    public:
        bool Init(uint16_t winwidth, uint16_t winheight);
        bool DeInit();
    protected:
        Renderer() {}
        Renderer(uint16_t winwidth, uint16_t winheight) {
            Init(winwidth, winheight);
        }
        ~Renderer() {
            DeInit();
        }
        friend void RenderInit(uint16_t, uint16_t);
    private:
        bool isinitialized = false;
        SDL_Window *pwindow = nullptr;
        SDL_Renderer *prenderer = nullptr;
    };
};
#endif  // _CORE_RENDER_H_
