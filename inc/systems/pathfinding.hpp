#ifndef SYSTEMS_PATHFINDING_HPP
#define SYSTEMS_PATHFINDING_HPP
#include <entityx/entityx.h>
#include "components/basic.hpp"

namespace systems{

class PathfindingSystem : public entityx::System<PathfindingSystem> {
public:
    PathfindingSystem();

    // Eventually Ai will be able to send commands like recalc path, etc

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:
};

class CommandSystem :
    public entityx::System<CommandSystem>,
    public entityx::Receiver<CommandSystem> {
public:
    CommandSystem();

    void configure(entityx::EventManager &event_manager) {}

    // Eventually Ai will be able to send commands like recalc path, etc

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:
};

}

#endif /* SYSTEMS_PATHFINDING_HPP */
