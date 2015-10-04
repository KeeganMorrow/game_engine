#ifndef COMPONENTS_RENDER_HPP
#define COMPONENTS_RENDER_HPP
#include <sdlwrap/surface.hpp>
namespace components{

struct RenderCamera {
    RenderCamera():zoomlevel(1.0){}
    float zoomlevel;
};

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

struct RenderData {
    RenderData(int layer):layer(layer){}
    int layer;
    // Later information about render distance, etc also
};
}
#endif /* COMPONENTS_RENDER_HPP */
