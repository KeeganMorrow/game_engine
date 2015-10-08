#include <assert.h>
#include <stdio.h>
#include <SDL.h>
#include "core/config.hpp"
#include "core/logging.hpp"

#include "systems/events.hpp"
#include "core/application.hpp"
// We are bypassing sdlwrap here - should this be changed in the future?
namespace systems{

//Note: dt should be the time since the last logic update!!
void EventSystem::update(entityx::EntityManager &es,
                          entityx::EventManager &events,
                          entityx::TimeDelta dt){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            papplication->quit();
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            emit_keypress(events, event.key);
            break;
        default:
            break;
        }
    }
}

bool EventSystem::bind_key(SDL_Keycode inputkey, std::shared_ptr<EventKey> peventkey){
    if (!keymap[inputkey]) {
        LOG(INFO) << "Binding key " << (int)inputkey;
        keymap[inputkey] = peventkey;
        return true;
    }else{
        // Raise an exception instead?
        return false;
    }
}

bool EventSystem::unbind_key(SDL_Keycode inputkey){
    if (keymap[inputkey]) {
        // Since this is a shared pointer we shouldn't have to delete it.
        // Scary magic!
        LOG(INFO) << "Unbinding key " << (int)inputkey;
        keymap.erase(inputkey);
        return true;
    }else{
        // Raise an exception instead?
        return false;
    }
}

bool EventSystem::emit_keypress(entityx::EventManager &events, const SDL_KeyboardEvent &keyevent){
    if (keymap[keyevent.keysym.sym]){
        bool press = (keyevent.type == SDL_KEYDOWN)? true : false;
        bool release = !press;
        bool repeat = (keyevent.repeat)? true : false;
        bool emit = false;
        const EventKey &map_data = *keymap[keyevent.keysym.sym].get();

        // Filter out repeat events that aren't subscribed to first
        if (!(repeat && !map_data.repeat)){
            // Then filter out by type of key event
            if ((press && map_data.press)||(release && map_data.release)){
                EventKey emittedevent = EventKey(map_data.key, press, release, repeat);
                events.emit<EventKey>(emittedevent);
                return true;
            }
        }
    }
    return false;
}


bool EventSystem::load_config(core::Config *pconfig){
    assert(pconfig != nullptr);
    bind_key(SDLK_a, std::make_shared<EventKey>(KEYS_MOVE_LEFT, true, true, false));
    bind_key(SDLK_d, std::make_shared<EventKey>(KEYS_MOVE_RIGHT, true, true, false));
    bind_key(SDLK_w, std::make_shared<EventKey>(KEYS_MOVE_UP, true, true, false));
    bind_key(SDLK_s, std::make_shared<EventKey>(KEYS_MOVE_DOWN, true, true, false));
    return true;
}
}
