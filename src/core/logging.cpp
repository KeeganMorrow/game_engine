// Copyright 2014 Keegan Morrow

#include <string>
#include <iomanip>
#include "core/logging.hpp"

namespace core{
void LoggerManager::Init(int argv, char* argc[]){
    START_EASYLOGGINGPP(argv, argc);
}

bool LoggerManager::loadConfig(std::string configpath){
    el::Configurations conf(configpath);
    el::Loggers::reconfigureAllLoggers(conf);
    return true;
}
}
