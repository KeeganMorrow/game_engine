#ifndef __CORE_APP_HPP
#define __CORE_APP_HPP

#include <assert.h>
#include "core/logging/logging.h"

namespace core{

    enum GAMESTATE{
        GAMESTATE_INIT,
        GAMESTATE_IDLE,
        GAMESTATE_RUNNING,
        GAMESTATE_PAUSED,
        GAMESTATE_QUIT,
        GAMESTATE_ERR,
        GAMETSTATE_COUNT
    };

    class iApp{
    public:
        bool quit(){
            return do_quit();
        }

        virtual ~iApp() {};

        bool init(int argc, char *argv[]){
            return do_init(argc, argv);
        }

        int runLoop(){
            return do_runLoop();
        }

        bool deinit(){
            return do_deinit();
        }

        logging::LoggerManager *getLoggerManager(){
            return do_getLoggerManager();
        }
    private:
        virtual bool do_quit() = 0;
        virtual bool do_init(int argc, char *argv[]) = 0;
        virtual int do_runLoop() = 0;
        virtual bool do_deinit() = 0;
        virtual logging::LoggerManager *do_getLoggerManager() = 0;
    };

    class App : public iApp{
    public:
        App():plogmanager(nullptr),state(GAMESTATE_INIT){}
        ~App(){}
    private:
        virtual bool do_quit();

        virtual bool do_init(int argc, char *argv[]){
            assert(plogmanager == nullptr);
            plogmanager = new logging::LoggerManager();
        }

        virtual bool do_deinit(){
            assert(plogmanager != nullptr);
            delete plogmanager;
        }

        virtual int do_runLoop();

        virtual logging::LoggerManager *do_getLoggerManager(){
            return plogmanager;
        }

        GAMESTATE state;
        logging::LoggerManager *plogmanager;
    };

}
#endif // __CORE_APP_HPP
