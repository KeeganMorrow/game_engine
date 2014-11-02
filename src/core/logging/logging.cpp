// Copyright 2014 Keegan Morrow

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <string>
#include <iomanip>

namespace logging {
    bool loggingInit(void) {
        log4cplus::BasicConfigurator config;
        config.configure();
    }
};
