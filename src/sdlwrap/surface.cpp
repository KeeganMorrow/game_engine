#include "surface.hpp"
#include "render.hpp"

namespace sdlwrap{

    Rectangle::Rectangle(int x, int y, int w, int h){
        prect = new SDL_Rect{x, y, w, h};
    }
    void Rectangle::get(int *x, int *y, int *w, int *h){
        if (x){
            *x = prect->x;
        }
        if (y){
            *y = prect->y;
        }
        if (w){
            *w = prect->w;
        }
        if (h){
            *h = prect->h;
        }
    }
    const SDL_Rect *Rectangle::get_raw() const{
        return prect;
    }

    void Surface::init(std::string filepath){
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
