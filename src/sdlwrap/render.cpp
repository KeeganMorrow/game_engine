#include "sdlwrap/render.hpp"
#include "sdlwrap/surface.hpp"

namespace sdlwrap{

int Render::RenderClear(){
    SDL_RenderClear(prenderer);
}

int Render::RenderPresent(){
    SDL_RenderPresent(prenderer);
}

int Render::RenderCopy(Texture *ptexture,
        const Rectangle *srcrect,
        const Rectangle *dstrect){
    const SDL_Rect *pdst = nullptr;
    const SDL_Rect *psrc = nullptr;
    if (srcrect){
        psrc = srcrect->get_raw();
    }
    if (dstrect){
        pdst = dstrect->get_raw();
    }

    SDL_RenderCopy(prenderer,
                   ptexture->get_texture(),
                   psrc,
                   pdst);
}

};
