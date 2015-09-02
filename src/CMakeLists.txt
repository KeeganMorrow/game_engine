# Aquire external libraries
INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)


# Define sdlwrap library
add_library (sdlwrap sdlwrap/render sdlwrap/surface sdlwrap/sdl sdlwrap/window)
target_include_directories(sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../inc/sdlwrap")
target_compile_features(sdlwrap PRIVATE cxx_range_for)

# Define engine executable
add_executable(engine main.cpp core/application.cpp)
target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../inc/")
target_compile_features(engine PRIVATE cxx_range_for)
target_link_libraries(engine sdlwrap)
target_include_directories(engine PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(engine ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

