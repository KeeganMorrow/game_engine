#ifndef SYSTEMS_PLAYER_HPP
#define SYSTEMS_PLAYER_HPP
#include <entityx/entityx.h>

namespace core{
    class Application;
}

namespace systems{

class EventKey;

class PlayerControlSystem : public entityx::System<PlayerControlSystem>, public entityx::Receiver<PlayerControlSystem>{
public:
    PlayerControlSystem():input_x(0.0), input_y(0.0){}

    void configure(entityx::EventManager &event_manager);

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;
    void receive(const EventKey &event);
private:
    float input_x, input_y;
};

}

#endif /* SYSTEMS_PLAYER_HPP */
