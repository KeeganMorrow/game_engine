#ifndef COMPONENTS_RENDER_HPP
#define COMPONENTS_RENDER_HPP
#include <sdlwrap/surface.hpp>
namespace components{
struct RenderTexture {
public:
    RenderTexture(sdlwrap::Texture *ptex = nullptr): ptex(ptex){}

    sdlwrap::Texture *get_texture(void){
        return ptex;
    }

    void set_texture(sdlwrap::Texture *pnew){
        if (ptex){
            delete ptex;
        }
        ptex = pnew;
    }
private:
    sdlwrap::Texture *ptex;
};

}
#endif /* COMPONENTS_RENDER_HPP */
