#ifndef SYSTEMS_EVENTS_HPP
#define SYSTEMS_EVENTS_HPP
#include <entityx/entityx.h>
#include <string>
#include <assert.h>

namespace core{
    class Application;
}

namespace systems{

class EventSystem : public entityx::System<EventSystem> {
public:
    EventSystem(void):papplication(nullptr){}

    void init(core::Application *papplication);

    void deinit(void);

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:
    core::Application *papplication;
};

}

#endif /* SYSTEMS_EVENTS_HPP */
