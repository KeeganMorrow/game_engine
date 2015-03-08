// Copyright 2014 Keegan Morrow

#ifndef _CORE_RENDER_H_
#define _CORE_RENDER_H_

#include "core/logging/logging.h"

namespace render {

    class Renderer;

    void RenderInit(uint16_t winwidth, uint16_t winheight);
    void RenderDeInit();

    extern Renderer *pRenderer;

    /* Note: A key assumption with this renderer class is that
       There will only be 1 renderer per window. If this is not
       true then it will need to be re-thought */
    class Renderer {
    public:
        bool Init(uint16_t winwidth, uint16_t winheight);
        bool DeInit();
        SDL_Renderer *getRenderer(void) {
            return prenderer;
        }
        void renderTexture(SDL_Texture *ptex, int x, int y, int w, int h);
        inline void presentRenderer() {
            SDL_RenderPresent(prenderer);
        }
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
