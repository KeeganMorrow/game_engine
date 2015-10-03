add_executable(test_sdlwrap runtests.cpp sdlwrap/render.cpp sdlwrap/sdl.cpp sdlwrap/surface.cpp sdlwrap/window.cpp)
target_include_directories(test_sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/gtest/include")
target_include_directories(test_sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/gmock/include")
target_include_directories(test_sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../inc")
target_link_libraries(test_sdlwrap gtest gtest_main)
target_link_libraries(test_sdlwrap sdlwrap)

add_test(NAME sdlwrap COMMAND test_sdlwrap)
