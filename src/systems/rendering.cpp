#include "systems/rendering.hpp"
#include <SDL.h>

namespace systems{
void RenderSystem::init(void){
    // Should we call deinit here?
    std::cout << "Initializing RenderSystem\n";
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

void RenderSystem::update(entityx::EntityManager &es,
                          entityx::EventManager &events,
                          entityx::TimeDelta dt){
    assert(prender != nullptr);
    //TODO: Don't ignore return value
    (void)prender->RenderClear();
    es.each<components::RenderTexture, components::Spacial>([this, dt](
                entityx::Entity entity,
                components::RenderTexture &texture,
                components::Spacial &spacial) {
            draw_object(texture, spacial);
    });

    //TODO: Don't ignore return value
    (void)prender->RenderPresent();
}

void RenderSystem::draw_object(components::RenderTexture &texture,
                               components::Spacial &spacial){
    auto pdst = new sdlwrap::Rectangle(spacial.pos_x,
                                       spacial.pos_y,
                                       spacial.size_x,
                                       spacial.size_y);

    //TODO: Don't ignore return value
    (void)prender->RenderCopy(texture.get_texture(), nullptr, pdst);
}

sdlwrap::Texture *RenderSystem::load_texture(const std::string path){
    std::cout << "loading texture " << path <<'\n';
    auto psurface = new sdlwrap::Surface();
    std::cout << "initializing surface\n";
    psurface->init(std::string("resources/testimage.png"));
    auto ptexture = new sdlwrap::Texture();
    std::cout << "initializing texture\n";
    ptexture->init(prender, psurface);
    return ptexture;
}
}
