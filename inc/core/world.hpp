#ifndef WORLD_HPP
#define WORLD_HPP
#include <entityx/entityx.h>

namespace core{

class Application;
class Config;

class World : public entityx::EntityX {
public:
    World(Application *papplication, Config *pconfig);

    // All resources should be cleaned up by base class so far

    void update(entityx::TimeDelta dt);

    void render(entityx::TimeDelta dt);

private:
    Application *papplication;
    Config *pconfig;
};

}

#endif /* WORLD_HPP */
