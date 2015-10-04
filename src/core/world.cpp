#include <entityx/entityx.h>
#include "core/world.hpp"

namespace core{
World::World(Application *papplication):papplication(papplication){
    std::cout << "Constructing world\n";
    systems.add<systems::PositionPrinter>();
    systems.add<systems::RenderSystem>();
    systems.add<systems::EventSystem>();
    systems.add<systems::PlayerControlSystem>();
    systems.configure();
    auto prender = systems.system<systems::RenderSystem>();
}

//TODO : Consider adding another layer of abstraction between "systems" and logic?
// The goal would be to be less tied to entityx
void World::init(){

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
    entity.assign<components::Player>();
    std::cout << "Initialized entity \n";
    std::cout << "Initialized world\n";
}

void World::update(entityx::TimeDelta dt) {
    // Events should be handled first (I think?)
    systems.update<systems::EventSystem>(dt);
    systems.update<systems::PlayerControlSystem>(dt);
    systems.update<systems::PositionPrinter>(dt);
}
void World::render(entityx::TimeDelta dt) {
    systems.update<systems::RenderSystem>(dt);

}
}
