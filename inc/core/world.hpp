#ifndef WORLD_HPP
#define WORLD_HPP
#include <entityx/entityx.h>

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
