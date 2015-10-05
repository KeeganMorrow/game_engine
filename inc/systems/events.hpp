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
    EventSystem(core::Application *papp):papplication(papp){}

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:
    core::Application *papplication;
};

}

#endif /* SYSTEMS_EVENTS_HPP */
