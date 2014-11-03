// Copyright 2014 Keegan Morrow

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <log4cplus/loggingmacros.h>

#include "core/render/render.h"
#include "core/logging/logging.h"

namespace render {

    bool Renderer::Init(uint16_t winwidth, uint16_t winheight) {
        if (isinitialized){
            LOG4CPLUS_WARN(logger,
                "Re-Initializing Renderer");
            DeInit();
        }
            LOG4CPLUS_INFO(logger,
                "Re-Initializing Renderer");
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
            LOG4CPLUS_ERROR(logger,
                "Could not create window: " << SDL_GetError());
            DeInit();
            return false;
        }

        SDL_Renderer *prenderer = SDL_CreateRenderer(
            pwindow,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (prenderer = nullptr) {
            // In the event that the renderer could not be created
            LOG4CPLUS_ERROR(logger,
                "Could not create renderer: " << SDL_GetError());
            DeInit();
            return false;

        }
        isinitialized = true;
        return true;
}

    bool Renderer::DeInit() {
        LOG4CPLUS_INFO(logger,
            "De-Initializing Renderer");
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
};
