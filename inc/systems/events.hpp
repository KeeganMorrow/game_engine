#ifndef SYSTEMS_EVENTS_HPP
#define SYSTEMS_EVENTS_HPP
#include <entityx/entityx.h>
#include <memory>
#include <string>
#include <assert.h>
#include <unordered_map>
#include <gtest/gtest_prod.h>
#include <SDL.h>

namespace core{
    class Application;
    class Config;
}


namespace systems{
enum Keycodes{
    KEYS_MOVE_LEFT,
    KEYS_MOVE_RIGHT,
    KEYS_MOVE_UP,
    KEYS_MOVE_DOWN,
    KEYS_COUNT
};

enum KeyState{
    KEY_STATE_PRESS,
    KEY_STATE_RELEASE,
    KEY_STATE_REPEAT,
    KEY_STATE_COUNT
};

struct EventKey{
    EventKey(Keycodes key, bool press, bool release, bool repeat):
             key(key),press(press),release(release),repeat(repeat){}
    Keycodes key;
    bool press, release, repeat;
};


class EventSystem : public entityx::System<EventSystem> {
public:
    EventSystem(core::Application *papp):papplication(papp){}

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;

    bool bind_key(SDL_Keycode inputkey, std::shared_ptr<EventKey> peventkey);

    bool unbind_key(SDL_Keycode inputkey);

    bool load_config(core::Config *pconfig);

private:
    bool emit_keypress(entityx::EventManager &events, const SDL_KeyboardEvent &keyevent);
    std::unordered_map<SDL_Keycode, std::shared_ptr<EventKey>> keymap;
    bool test(void){return true;}
    core::Application *papplication;
};

}

#endif /* SYSTEMS_EVENTS_HPP */
