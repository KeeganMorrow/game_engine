#ifndef WORLD_HPP
#define WORLD_HPP
#include <entityx/entityx.h>

namespace core{

class Application;

class World : public entityx::EntityX {
public:
    World(Application *papplication);

    // All resources should be cleaned up by base class so far

    void update(entityx::TimeDelta dt);

    void render(entityx::TimeDelta dt);

private:
    Application *papplication;
};

}

#endif /* WORLD_HPP */
