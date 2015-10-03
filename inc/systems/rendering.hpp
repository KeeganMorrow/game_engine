#ifndef RENDERING_HPP
#define RENDERING_HPP
#include <entityx/entityx.h>
#include "components/basic.hpp"
#include "components/render.hpp"
#include "sdlwrap/surface.hpp"
#include "sdlwrap/window.hpp"
#include "sdlwrap/render.hpp"
#include <string>
#include <assert.h>
#include <iostream>
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
    RenderSystem():pwindow(nullptr), prender(nullptr){}
    void init(void);

    void deinit(void);

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;

    void draw_object(components::RenderTexture &texture, components::Spacial &spacial);

    sdlwrap::Texture *load_texture(const std::string path);

private:
    sdlwrap::Window *pwindow;
    sdlwrap::Render *prender;
};

}

#endif /* RENDERING_HPP */
