// Copyright 2014 Keegan Morrow

#ifndef _CORE_CONTENTMANAGER_H_
#define _CORE_CONTENTMANAGER_H_

#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "core/logging/logging.h"

namespace management {

    enum ContentType {
        CONTENT_TYPE_NONE = 0,
        CONTENT_TYPE_TEXTURE,
        CONTENT_TYPE_COUNT
    };

    extern log4cplus::Logger logger;

    template <class K>
    struct ContentMap: public std::map<std::string, K> {};

    template <class K>
    struct ContentPair: public std::pair<std::string, K> {};

    class ContentManager {
    public:
        ContentManager() {}
        SDL_Texture *getTexture(std::string path);
        bool removeContent(std::string);
        bool addContent(std::string path, ContentType type);
    private:
        ContentMap<SDL_Texture*> textures;
    };
};

#endif  // _CORE_CONTENTMANAGER_H_
