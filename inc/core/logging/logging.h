// Copyright 2014 Keegan Morrow

#ifndef _CORE_LOGGING_H_
#define _CORE_LOGGING_H_
#include <string>
#include <map>

namespace logging {

    const std::string logconfig_path = "loggers.conf";

    // TODO(KM, "Rethink the design of this class")
    class LoggerManager {
    public:
        LoggerManager();
        int getLogger(std::string loggername);
    private:
    };

    extern LoggerManager Manager;
};

#endif  // _CORE_LOGGING_H_
