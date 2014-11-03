// Copyright 2014 Keegan Morrow

#ifndef _CORE_LOGGING_H_
#define _CORE_LOGGING_H_
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <string>
#include <map>

namespace logging {

    const std::string logconfig_path = "loggers.conf";

    class LoggerManager {
    public:
        LoggerManager();
        log4cplus::Logger getLogger(std::string loggername);
    private:
        std::map<std::string, log4cplus::Logger> loggers;
    };
};

#endif  // _CORE_LOGGING_H_
