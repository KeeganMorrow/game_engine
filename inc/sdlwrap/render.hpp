#ifndef RENDER_HPP
#define RENDER_HPP

#include <assert.h>

#include "sdlwrap/window.hpp"
#include "sdlwrap/exceptions.hpp"

namespace sdlwrap {

class Render{
    public:
        Render(Window *pwindow, int index, Uint32 flags):prenderer(nullptr){
            prenderer = SDL_CreateRenderer(pwindow->getWindow(), index, flags);
            if (prenderer == nullptr){
                throw exInitFailure(std::string(SDL_GetError()));
            }
        }
        ~Render(){
            assert(prenderer != nullptr);
            SDL_DestroyRenderer(prenderer);
        }
    private:
        SDL_Renderer *prenderer;
};

};

#endif /* RENDER_HPP */
