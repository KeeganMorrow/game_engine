#include "core/config.hpp"
#include "sdlwrap/surface.hpp"
#include <string>
#include <fstream>
#include <json.hpp>
#include <iostream>

using json = nlohmann::json;

namespace core{
bool Config::load_config(void){
    std::ifstream ifs ("engine.cfg", std::ifstream::in);
    json j;
    j << ifs;
    res_x = j["ResolutionX"];
    res_y = j["ResolutionY"];
    return true;
}
}
