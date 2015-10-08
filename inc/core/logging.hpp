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
        LoggerManager(int argv, char* argc[]);

        //TODO: Should I be tracking and unregistering loggers?
        ~LoggerManager(){}

        bool loadConfig(std::string configpath);

    };
}

#endif  // _CORE_LOGGING_H_
