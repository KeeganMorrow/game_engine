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

    Surface::Surface(const std::string filepath):psurface(nullptr){
        psurface = std::shared_ptr<SDL_Surface>(IMG_Load(filepath.c_str()));
        if (psurface == nullptr){
            throw exMissingFile(filepath);
        }
    }

    Texture::Texture(Render *prend, Surface *psurface):prenderer(prend), ptexture(nullptr){
        ptexture = SDL_CreateTextureFromSurface(
                        prenderer->get_renderer(),
                        psurface->get_surface().get()
                    );
    }
}
