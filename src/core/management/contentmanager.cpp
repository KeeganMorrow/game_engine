// Copyright 2014 Keegan Morrow

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "core/management/contentmanager.h"
#include "core/render/render.h"

namespace management {

    log4cplus::Logger logger = logging::Manager.getLogger("management");

    Content *ContentManager::getContent(std::string path, ContentType type) {
        return nullptr;
    }
    bool ContentManager::removeContent(std::string) {
        return true;
    }
    bool ContentManager::addContent(std::string path, ContentType type) {
        void *pcontent;
        // TODO(KM, Refactor this! It doesn't seem like a good design)
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
            break;
        }
        default:
            return false;
        }
        return true;
    }
};
