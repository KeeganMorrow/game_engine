#ifndef WORLD_HPP
#define WORLD_HPP
#include "components/basic.hpp"
#include "components/render.hpp"
#include "systems/rendering.hpp"
#include "systems/events.hpp"
#include "sdlwrap/surface.hpp"
#include <assert.h>
#include <iostream>
namespace core{

class Application;

class World : public entityx::EntityX {
public:
    World(Application *papplication):papplication(papplication){
        std::cout << "Constructing world\n";
        systems.add<systems::PositionPrinter>();
        systems.add<systems::RenderSystem>();
        systems.add<systems::EventSystem>();
        systems.configure();
        auto prender = systems.system<systems::RenderSystem>();
    }

    //TODO : Consider adding another layer of abstraction between "systems" and logic?
    // The goal would be to be less tied to entityx
    void init(){

        std::cout << "Initializing world\n";
        std::cout << "Initializing systems\n";
        auto prender = systems.system<systems::RenderSystem>();
        assert (prender != nullptr);
        prender->init();
        auto pevent = systems.system<systems::EventSystem>();
        assert (pevent != nullptr);
        pevent->init(papplication);
        std::cout << "Initialized systems\n";

        std::cout << "Initializing entity \n";
        auto ptex = prender->load_texture("resources/testimage.png");
        entityx::Entity entity = entities.create();
        entity.assign<components::Spacial>(100.0, 100.0, 200.0, 200.0, 0.0, 80, 0.0);
        entity.assign<components::RenderTexture>(ptex);
        std::cout << "Initialized entity \n";
        std::cout << "Initialized world\n";
    }

    void update(entityx::TimeDelta dt) {
        // Events should be handled first (I think?)
        systems.update<systems::EventSystem>(dt);
        systems.update<systems::PositionPrinter>(dt);
    }
    void render(entityx::TimeDelta dt) {
        systems.update<systems::RenderSystem>(dt);

    }
private:
    Application *papplication;
};

}

#endif /* WORLD_HPP */
