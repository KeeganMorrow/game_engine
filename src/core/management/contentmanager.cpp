// Copyright 2014 Keegan Morrow

#include <string>
#include <utility>
#include "core/management/contentmanager.h"
#include "core/render/render.h"

namespace management {

    SDL_Texture *ContentManager::getTexture(std::string path) {
        auto it = textures.find(path);
        SDL_Texture *toreturn = it->second;
        return toreturn;
    }

    bool ContentManager::removeTexture(std::string path) {
        auto it = textures.find(path);
        if (it == textures.end()) {
            return false;
        } else {
            textures.erase(it);
            return true;
        }
    }

    bool ContentManager::addTexture(std::string path) {
        SDL_Renderer *pRenderer = render::pRenderer->getRenderer();
        SDL_Texture *ptex = IMG_LoadTexture(pRenderer, path.c_str());
        if (ptex == nullptr) {
        /*LOG4CPLUS_WARN(logger, "Failed loading texture " << path <<
            " due to SDL error:" << IMG_GetError());*/
            return false;
        }
        addTexture(path, ptex);
    }

    bool ContentManager::addTexture(std::string key, SDL_Texture *ptex) {
        // TODO(KM) Check if something already using that key?
        auto it = textures.begin();
        textures.insert(it, std::pair<std::string, SDL_Texture*>(key, ptex));
    }
};
