#ifndef __CORE_APP_HPP
#define __CORE_APP_HPP
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
    protected:
        iApp();
        bool init(){
            return do_init();
        }
        int runLoop(){
            return do_runLoop();
        }
        bool deinit(){
            return do_deinit();
        }
        virtual ~iApp() {};
    private:
        virtual bool do_quit() = 0;
        virtual bool do_init() = 0;
        virtual int do_runLoop() = 0;
        virtual bool do_deinit() = 0;
};

    class App : public iApp{
    public:
        App(){}
        ~App(){}
    protected:
        virtual bool do_quit();
        virtual bool do_init();
        virtual int do_runLoop();
        virtual bool do_deinit();
    private:
        GAMESTATE state;
    };

}
#endif // __CORE_APP_HPP
