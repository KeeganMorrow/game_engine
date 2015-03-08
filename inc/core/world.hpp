#ifndef CORE_WORLD_HPP
#define CORE_WORLD_HPP
#include <assert.h>
#include <entityx/entityx.h>

namespace core{
    class iWorld : public entityx::EntityX{
    public:
        iWorld() {}
        bool init(int argc, char* argv[]){
            return do_init(argc, argv);
        }

        bool deInit(){
            return do_deInit();
        }

        void update(entityx::TimeDelta dt){
            do_update(dt);
        }

    private:
        virtual bool do_init(int argc, char* argv[]) = 0;
        virtual bool do_deInit() = 0;

        //Note: type argument changes based on Entityx configuration
        virtual void do_update(entityx::TimeDelta dt)=0;
    };

    class World : public iWorld{
    public:
        World(){}
    private:
        virtual bool do_init(int argc, char* argv[]){
            // Add systems, etc
            //
            systems.configure();
        }

        virtual bool do_deInit(){}

        //Note: type argument changes based on Entityx configuration
        virtual void do_update(entityx::TimeDelta dt);

    };
}

#endif /* CORE_WORLD_HPP */
