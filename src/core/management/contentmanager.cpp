// Copyright 2014 Keegan Morrow

#include <string>
#include "core/management/contentmanager.h"
#include "core/render/render.h"

namespace management {

    log4cplus::Logger logger = logging::Manager.getLogger("management");

    SDL_Texture *ContentManager::getTexture(std::string path) {
        auto it = textures.find(path);
        SDL_Texture *toreturn = it->second;
        return toreturn;
    }
    bool ContentManager::removeContent(std::string) {
        return true;
    }
    bool ContentManager::addContent(std::string path, ContentType type) {
        void *pcontent;
        switch (type) {
        case CONTENT_TYPE_TEXTURE:
        {
            SDL_Renderer *pRenderer = render::pRenderer->getRenderer();
            SDL_Texture *ptexture = IMG_LoadTexture(pRenderer, path.c_str());
            if (ptexture == nullptr) {
            LOG4CPLUS_WARN(logger,
                "Failed loading texture " << path << " due to SDL error:" << IMG_GetError());
                return false;
            }
            // TODO(KM, Does this need to check if something with the same key is in already?)
            auto it = textures.begin();
            textures.insert(it, std::pair<std::string, SDL_Texture*>(path, ptexture));
            break;
        }
        default:
            return false;
        }
        return true;
    }
};
