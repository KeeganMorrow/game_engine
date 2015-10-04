#include "systems/rendering.hpp"
#include <SDL.h>
#include "core/logging.hpp"

namespace systems{
void RenderSystem::init(void){
    // Should we call deinit here?
    LOG(INFO) << "Initializing RenderSystem";
    pwindow = new sdlwrap::Window("Engine", 0, 0, 640, 480, 0);
    prender = new sdlwrap::Render(pwindow, -1,
            SDL_RENDERER_ACCELERATED);
}

void RenderSystem::deinit(void){
    if (pwindow){
        delete pwindow;
    }
    if (prender){
        delete prender;
    }
}

//Note: dt should be the time since the last logic update!!
void RenderSystem::update(entityx::EntityManager &es,
                          entityx::EventManager &events,
                          entityx::TimeDelta dt){
    assert(prender != nullptr);
    entityx::ComponentHandle<components::RenderCamera> camera;
    entityx::ComponentHandle<components::Spacial> camera_spacial;
    for (entityx::Entity entity :es.entities_with_components(camera, camera_spacial)){
        (void) entity;
    }

    //TODO: Don't ignore return value
    (void)prender->RenderClear();
    es.each<components::RenderTexture, components::Spacial>([this, dt](
                entityx::Entity entity,
                components::RenderTexture &texture,
                components::Spacial &spacial) {
            draw_object_interpolated(texture, spacial, dt);

    });

    //TODO: Don't ignore return value
    (void)prender->RenderPresent();
}
void RenderSystem::draw_object(components::RenderTexture &texture,
                               components::Spacial &spacial){
    auto pdst = sdlwrap::Rectangle(spacial.pos_x,
                                       spacial.pos_y,
                                       spacial.size_x,
                                       spacial.size_y);

    //TODO: Don't ignore return value
    (void)prender->RenderCopy(texture.get_texture(), nullptr, &pdst);
}

void RenderSystem::draw_object_interpolated(components::RenderTexture &texture,
                               components::Spacial &spacial, float dt){

    auto pdst = sdlwrap::Rectangle(spacial.pos_x + (spacial.vel_x * dt),
                                       spacial.pos_y + (spacial.vel_y * dt),
                                       spacial.size_x,
                                       spacial.size_y);

    //TODO: Don't ignore return value
    (void)prender->RenderCopy(texture.get_texture(), nullptr, &pdst);
}

sdlwrap::Texture *RenderSystem::load_texture(const std::string path){
    LOG(INFO) << "loading texture " << path;
    auto psurface = new sdlwrap::Surface();
    LOG(INFO) << "initializing surface";
    psurface->init(std::string("resources/testimage.png"));
    auto ptexture = new sdlwrap::Texture();
    LOG(INFO) << "initializing texture";
    ptexture->init(prender, psurface);
    return ptexture;
}
}
