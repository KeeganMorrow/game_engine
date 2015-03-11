#ifndef SDLWRAP_SDL_HPP
#define SDLWRAP_SDL_HPP

#include <SDL2/SDL.h>

namespace sdlwrap{
    class Sdl{
    public:
        Sdl(Uint32 flags){
            SDL_Init(flags);
        }
        ~Sdl(){
            SDL_Quit();
        }
    private:
    };
}

#endif /* SDLWRAP_SDL_HPP */
