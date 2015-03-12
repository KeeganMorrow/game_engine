#ifndef SDLWRAP_WINDOW_HPP
#define SDLWRAP_WINDOW_HPP

#include <assert.h>
#include <string>
#include <SDL2/SDL.h>

namespace sdlwrap{

    class Window{
    public:
        Window(std::string title, int x, int y, int w, int h, Uint32 flags):pwindow(nullptr){
            pwindow = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
        }
        ~Window(){
            assert(pwindow != nullptr);
            SDL_DestroyWindow(pwindow);
        }
        void GetSize(int *retw, int *reth){
            SDL_GetWindowSize(pwindow, retw, reth);
        }
        Uint32 GetFlags(){
            return SDL_GetWindowFlags(pwindow);
        }
    private:
        SDL_Window *pwindow;
    };
};
#endif /* SDLWRAP_WINDOW_HPP */
