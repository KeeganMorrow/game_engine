#ifndef COMPONENTS_RENDER_HPP
#define COMPONENTS_RENDER_HPP
#include <memory>
#include <sdlwrap/surface.hpp>
namespace components{

struct RenderCamera {
    RenderCamera():zoomlevel(1.0){}
    float zoomlevel;
};

struct RenderCameraTarget{};

struct RenderTexture {
public:
    RenderTexture(std::shared_ptr<sdlwrap::Texture> ptexture): ptex(ptexture){}

    std::shared_ptr<sdlwrap::Texture> get_texture(void){
        return ptex;
    }

    void set_texture(std::shared_ptr<sdlwrap::Texture> pnew){
        // Remember - this class does not manage the resources!!
        ptex = pnew;
    }
private:
    std::shared_ptr<sdlwrap::Texture> ptex;
};

struct RenderData {
    RenderData(int layer):layer(layer){}
    int layer;
    // Later information about render distance, etc also
};
}
#endif /* COMPONENTS_RENDER_HPP */
