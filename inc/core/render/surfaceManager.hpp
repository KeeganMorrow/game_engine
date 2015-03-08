#ifndef __CORE_SURFACE_MANAGER
#define __CORE_SURFACE_MANAGER

#include <string>
#include <unordered_map>
#include <SDL2/SDL.h>

namespace render{
    class iSurfaceManager{
    public:
        // TODO: Execeptions
        SDL_Surface *requestSurface(const std::string & file){
            return do_requestSurface(file);
        }

        virtual ~iSurfaceManager(){}
    private:
        virtual SDL_Surface *do_requestSurface(const std::string &)=0;
    };

    class surfaceManager : public iSurfaceManager{
        public:
            surfaceManager(){}
        protected:
            virtual SDL_Surface *do_requestSurface(const std::string &);
        private:
            std::unordered_map<std::string,SDL_Surface *>surfacemap;
    };
};



#endif // ifndef __CORE_SURFACE_MANAGER

