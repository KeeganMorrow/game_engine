#ifndef WORLD_HPP
#define WORLD_HPP
#include "components/basic.hpp"
#include "components/render.hpp"
#include "components/player.hpp"
#include "systems/events.hpp"
#include "systems/player.hpp"
#include "systems/rendering.hpp"
#include "sdlwrap/surface.hpp"
#include <assert.h>
#include <iostream>
namespace core{

class Application;

class World : public entityx::EntityX {
public:
    World(Application *papplication);

    //TODO : Consider adding another layer of abstraction between "systems" and logic?
    // The goal would be to be less tied to entityx
    void init();

    void update(entityx::TimeDelta dt);

    void render(entityx::TimeDelta dt);

private:
    Application *papplication;
};

}

#endif /* WORLD_HPP */
