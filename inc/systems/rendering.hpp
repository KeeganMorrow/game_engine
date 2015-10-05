#ifndef RENDERING_HPP
#define RENDERING_HPP
#include <string>
#include <unordered_map>
#include <memory>
#include <entityx/entityx.h>
#include "components/basic.hpp"
#include "components/render.hpp"
#include "sdlwrap/surface.hpp"
#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"
#include <string>
#include <assert.h>

namespace systems{

class PositionPrinter : public entityx::System<PositionPrinter> {
public:
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override {
        es.each<components::Spacial>([dt](
                    entityx::Entity entity,
                    components::Spacial &spacial) {
            spacial.pos_x += spacial.vel_x * dt;
            spacial.pos_y += spacial.vel_y * dt;
        });
    }
};

class RenderSystem : public entityx::System<RenderSystem> {
public:
    RenderSystem();

    ~RenderSystem();

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;

    void draw_object(components::RenderTexture &texture, components::Spacial &spacial);

    void draw_object_interpolated(components::RenderTexture &texture, components::Spacial &spacial, float dt);

    std::shared_ptr<sdlwrap::Texture>load_texture(std::string path);

private:
    components::Spacial &calculate_spacial(const components::Spacial *camera, const components::Spacial *target);
    sdlwrap::Window *pwindow;
    sdlwrap::Render *prender;
    std::unordered_map<std::string, std::shared_ptr<sdlwrap::Texture>> textures;
};

// Updates the cameras to track their target entities.
class CameraSystem : public entityx::System<CameraSystem> {
public:
    CameraSystem(){}

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:

};
}

#endif /* RENDERING_HPP */
