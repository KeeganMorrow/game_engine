// Copyright 2014 Keegan Morrow

#ifndef _CORE_LOGGING_H_
#define _CORE_LOGGING_H_
#include <string>
#include <easylogging++.h>

namespace logging {

    class LoggerManager {
    public:
        LoggerManager(){
        }
        //TODO: Should I be tracking and unregistering loggers?
        ~LoggerManager(){}
        void Init(int argv, char* argc[]){
            START_EASYLOGGINGPP(argv, argc);
        }

        bool loadConfig(std::string configpath){
            el::Configurations conf(configpath);
            el::Loggers::reconfigureAllLoggers(conf);
            return true;
        }

        void registerLogger(std::string loggername){
            el::Loggers::getLogger(loggername,true);
        }
    private:
    };

    extern LoggerManager Manager;
}

#endif  // _CORE_LOGGING_H_
