#ifndef SDLWRAP_SDL_HPP
#define SDLWRAP_SDL_HPP

#include <SDL2/SDL.h>

namespace sdlwrap{
    class Sdl{
    public:
        Sdl(){
            SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
        }
        ~Sdl(){
            SDL_Quit();
        }
    private:
    };
}

#endif /* SDLWRAP_SDL_HPP */
