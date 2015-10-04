// Copyright 2014 Keegan Morrow

#ifndef _CORE_LOGGING_H_
#define _CORE_LOGGING_H_
#include <string>
#define ELPP_UNICODE 1
#include <easylogging++.h>
namespace core{
    // Handles configuration (but NOT distribution!) of logging
    class LoggerManager {
    public:
        LoggerManager(){
        }
        //TODO: Should I be tracking and unregistering loggers?
        ~LoggerManager(){}

        void Init(int argv, char* argc[]);

        bool loadConfig(std::string configpath);

    };

    extern LoggerManager Manager;
}

#endif  // _CORE_LOGGING_H_
