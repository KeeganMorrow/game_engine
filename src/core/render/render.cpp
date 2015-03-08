// Copyright 2014 Keegan Morrow

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "core/render/render.hpp"
#include "core/logging/logging.hpp"

namespace render {

    Renderer *pRenderer = nullptr;

    void RenderInit(uint16_t winwidth, uint16_t winheight) {
        pRenderer = new Renderer(winwidth, winheight);
    }

    void RenderDeInit() {
        if (pRenderer != nullptr) {
            pRenderer->DeInit();
        } else {
            //  This shouldn't happen
        }
    }

    bool Renderer::Init(uint16_t winwidth, uint16_t winheight) {
        if (isinitialized) {
            CLOG(INFO, "render.render") << "Re-Initializing Renderer";
            DeInit();
        }
        CLOG(INFO, "render.render") << "Re-Initializing Renderer";
        SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

        // Create an application window with the following settings:
        pwindow = SDL_CreateWindow(
            "An SDL2 window",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            winwidth,
            winheight,
            SDL_WINDOW_OPENGL);

        // Check that the window was successfully made
        if (pwindow == nullptr) {
            // In the event that the window could not be made...
           CLOG(ERROR,"render.render") << "Could not create window: "\
               << SDL_GetError();
            DeInit();
            return false;
        }

        prenderer = SDL_CreateRenderer(
            pwindow,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (prenderer == nullptr) {
            // In the event that the renderer could not be created
            CLOG(ERROR, "render.render") << "Could not create renderer: "\
                << SDL_GetError();
            DeInit();
            return false;
        }
        isinitialized = true;
        return true;
}

    bool Renderer::DeInit() {
        CLOG(INFO, "render.render") << "De-Initializing Renderer";
        // Destroy the renderer
        if (prenderer) {
            SDL_DestroyRenderer(prenderer);
        }
        // Close and destroy the window
        if (prenderer) {
            SDL_DestroyWindow(pwindow);
        }
        // Clean up
        SDL_Quit();
    }

    void Renderer::renderTexture(SDL_Texture *ptex, int x,
                                 int y, int w, int h) {
        SDL_Rect dst;
        dst.x = x;
        dst.y = y;
        dst.w = w;
        dst.h = h;
        SDL_RenderCopy(prenderer, ptex, NULL, &dst);
    }
};
