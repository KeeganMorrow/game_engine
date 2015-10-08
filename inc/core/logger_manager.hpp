// Copyright 2014 Keegan Morrow

#ifndef _CORE_LOGGER_MANAGER_H_
#define _CORE_LOGGER_MANAGER_H_
#include <string>
#define ELPP_UNICODE 1
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

#endif  // _CORE_LOGGER_MANAGER_H_
