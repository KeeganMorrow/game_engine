#include "sdlwrap/surface.hpp"
#include "sdlwrap/render.hpp"

namespace sdlwrap{

    int Surface::init(std::string filepath){
        psurface = IMG_Load(filepath.c_str());
        if (psurface == nullptr){
            throw exMissingFile(filepath);
        }
    }
    void Texture::init(Render *prenderer, Surface *psurface){
        prenderer = prenderer;
        ptexture = SDL_CreateTextureFromSurface(
                        prenderer->get_renderer(),
                        psurface->get_surface()
                    );
    }
}
