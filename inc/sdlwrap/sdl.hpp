#ifndef SDLWRAP_SDL_HPP
#define SDLWRAP_SDL_HPP

#include <SDL2/SDL.h>

namespace sdlwrap{
    class Sdl{
    public:
        Sdl(Uint32 flags=0){
            Init(flags);
        }

        ~Sdl(){
            SDL_Quit();
        }

        void Init(Uint32 flags = 0){
            if (flags != 0) {
                SDL_Init(flags);
            }
        }
    private:
    };
}

#endif /* SDLWRAP_SDL_HPP */
