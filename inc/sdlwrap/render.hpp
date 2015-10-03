#ifndef RENDER_HPP
#define RENDER_HPP

#include <assert.h>

#include "window.hpp"
#include "exceptions.hpp"

namespace sdlwrap {
class Rectangle;
class Texture;

class Render{
    public:
        Render(Window *pwindow, int index, Uint32 flags):prenderer(nullptr){
            if (pwindow == nullptr){
                throw exInitFailure(std::string(SDL_GetError()));
            }
            prenderer = SDL_CreateRenderer(pwindow->getWindow(), index, flags);
            if (prenderer == nullptr){
                throw exInitFailure(std::string(SDL_GetError()));
            }
        }
        ~Render(){
            assert(prenderer != nullptr);
            SDL_DestroyRenderer(prenderer);
        }
        int RenderClear();
        void RenderPresent();

        SDL_Renderer *get_renderer(void){
            return prenderer;
        }

        int RenderCopy(Texture *ptexture, const Rectangle *srcrect, const Rectangle *dstrect);
    private:
        SDL_Renderer *prenderer;
};

}

#endif /* RENDER_HPP */
