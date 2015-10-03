#include "render.hpp"
#include "surface.hpp"

namespace sdlwrap{

int Render::RenderClear(){
    return SDL_RenderClear(prenderer);
}

void Render::RenderPresent(){
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

    return SDL_RenderCopy(prenderer,
                   ptexture->get_texture(),
                   psrc,
                   pdst);
}

}
