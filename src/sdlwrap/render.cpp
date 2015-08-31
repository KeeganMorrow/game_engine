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
        const SDL_Rect *srcrect,
        const SDL_Rect *dstrect){
    SDL_RenderCopy(prenderer,
                   ptexture->get_texture(),
                   srcrect,
                   dstrect);
}

};
