#ifndef CORE_RENDER_HPP
#define CORE_RENDER_HPP
#include <entityx/entityx.h>

namespace render {
    class iRenderSystem : public entityx::System<iRenderSystem> {
    public:
        void update(entityx::EntityManager &es,
                    entityx::EventManager &events,
                    entityx::TimeDelta dt) override
        {
            do_update(es,events,dt);
        }
    private:
        virtual void do_update(entityx::EntityManager &es,
                       entityx::EventManager &events,
                       entityx::TimeDelta dt) = 0;
    };

    class RenderSystem : public iRenderSystem {
    public:
        RenderSystem(){}
        ~RenderSystem(){}
    private:
        virtual void do_update(entityx::EntityManager &es,
                       entityx::EventManager &events,
                       entityx::TimeDelta dt);
    };

};

#endif /* CORE_RENDER_HPP */
