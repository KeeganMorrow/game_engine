#ifndef RENDER_HPP
#define RENDER_HPP

#include <assert.h>
#include "sdlwrap/window.hpp"

namespace sdlwrap {

class Render{
    public:
        Render(Window *pwindow, int index, Uint32 flags):prenderer(nullptr){
            prenderer = SDL_CreateRenderer(pwindow->getWindow(), index, flags);
            //TODO: Validate prenderer and throw exception if nullptr
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
