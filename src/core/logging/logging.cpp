// Copyright 2014 Keegan Morrow

#include <log4cplus/configurator.h>
#include <string>
#include <iomanip>
#include "core/logging/logging.h"

namespace logging {

    LoggerManager Manager;

    LoggerManager::LoggerManager() {
        log4cplus::BasicConfigurator config;
        config.configure();
    }

    log4cplus::Logger LoggerManager::getLogger(std::string loggername) {
        return log4cplus::Logger::getInstance(
            LOG4CPLUS_TEXT(loggername.c_str()));
    }
};
