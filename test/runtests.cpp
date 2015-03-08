#include "gtest/gtest.h"
#include "core/logging/logging.h"

int main(int argc, char **argv) {
    logging::LoggerManager *pLogManager = new logging::LoggerManager();
    pLogManager->loadConfig("test/logging.conf");
    LOG(INFO) << "testing some logging";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
