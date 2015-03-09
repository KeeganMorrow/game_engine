#ifndef COMPONENTS_RENDER_H
#define COMPONENTS_RENDER_H

#include <assert.h>
#include <SDL2/SDL.h>

namespace render{
    struct compSurface : entityx::Component<compSurface> {
    public:
        compSurface(SDL_Surface *psurface) : psurface(psurface) {}
        ~compSurface(){
            assert (psurface != nullptr);
            delete psurface;
        }
        SDL_Surface *const getSurface(){
            return psurface;
        }
    private:
        SDL_Surface *psurface;
    };
};

#endif /* COMPONENTS_RENDER_H */
