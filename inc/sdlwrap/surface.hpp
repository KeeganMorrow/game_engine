#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <string>
#include <assert.h>
#include <exception>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sdlwrap/exceptions.hpp"

namespace sdlwrap{
    class Surface{
    public:
        Surface(std::string filepath):psurface(nullptr){
            psurface = IMG_Load(filepath.c_str());
            if (psurface == nullptr){
                throw exMissingFile(filepath);
            }
        }
        ~Surface(){
            assert(psurface != nullptr);
            delete psurface;
        }
    private:
        SDL_Surface *psurface;
    };
};

#endif /* SURFACE_HPP */
