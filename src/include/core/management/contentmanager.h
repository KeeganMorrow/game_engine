// Copyright 2014 Keegan Morrow

#ifndef _CORE_CONTENTMANAGER_H_
#define _CORE_CONTENTMANAGER_H_

#include <unordered_map>
#include <string>
#include "core/logging/logging.h"

namespace management {

    enum ContentType {
        CONTENT_TYPE_NONE = 0,
        CONTENT_TYPE_TEXTURE,
        CONTENT_TYPE_COUNT
    };

    extern log4cplus::Logger logger;

    // TODO(Keegan): Come up with a way to avoid casting

    class Content {
    public:
        explicit Content(void *pContent, uint32_t size):
            pContent(pContent), size(size) {}

    protected:
        void *getContent(void) {
            return pContent;
        }

        void getContentSize(void) {
            uint32_t size;
        }
    private:
        void *pContent;
        uint32_t size;
    };

    typedef std::unordered_map<std::string, Content*> ContentMap;

    class ContentManager {
    public:
        ContentManager() {}
        Content *getContent(std::string path, ContentType type);
        bool removeContent(std::string);
        bool addContent(std::string path, ContentType type);
    private:
        ContentMap map;
    };
};

#endif  // _CORE_CONTENTMANAGER_H_
