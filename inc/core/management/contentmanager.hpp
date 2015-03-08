// Copyright 2014 Keegan Morrow

#ifndef _CORE_CONTENTMANAGER_H_
#define _CORE_CONTENTMANAGER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <utility>
#include <string>

namespace management {

    template <class K>
    struct ContentMap: public std::unordered_map<std::string, K> {};

    template <class K>
    struct ContentPair: public std::pair<std::string, K> {};

    class ContentManager {
    public:
        ContentManager() {}
        SDL_Texture *getTexture(std::string path);
        bool removeTexture(std::string path);
        bool addTexture(std::string path);
        bool addTexture(std::string key, SDL_Texture *ptex);
    private:
        ContentMap<SDL_Texture*> textures;
    };
};

#endif  // _CORE_CONTENTMANAGER_H_
