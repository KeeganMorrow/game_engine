# Aquire external libraries
INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

set(engine_SRC
    "core/application.cpp"
    "core/config.cpp"
    "core/logger_manager.cpp"
    "core/world.cpp"
    "systems/events.cpp"
    "systems/player.cpp"
    "systems/pathfinding.cpp"
    "systems/rendering.cpp"
    "components/basic.cpp"
)
# Define sdlwrap library
add_library (sdlwrap sdlwrap/render sdlwrap/surface sdlwrap/sdl sdlwrap/window)
target_include_directories(sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../inc/sdlwrap")
target_include_directories(sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/easyloggingpp/src")
target_include_directories(sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/json/src")
target_include_directories(sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/gtest/include")
target_link_libraries(sdlwrap ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

# Define engine executable
add_executable(engine main.cpp ${engine_SRC})
target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../inc/")
target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/entityx/")
target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/gtest/include")
target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/easyloggingpp/src")

target_link_libraries(engine sdlwrap)
target_link_libraries(engine entityx)
target_include_directories(engine PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

