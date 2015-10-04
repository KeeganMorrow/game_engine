add_executable(test_sdlwrap runtests.cpp sdlwrap/render.cpp sdlwrap/sdl.cpp sdlwrap/surface.cpp sdlwrap/window.cpp)
target_include_directories(test_sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/gtest/include")
target_include_directories(test_sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/gmock/include")
target_include_directories(test_sdlwrap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../inc")
target_link_libraries(test_sdlwrap gtest gtest_main)
# To disable graphics when running sdlwrap unit tests do this:
# cmake .. -Dsdlwrap_test_no_graphics
target_link_libraries(test_sdlwrap sdlwrap)
if (sdlwrap_test_no_graphics)
    target_compile_definitions(test_sdlwrap PRIVATE NO_GRAPHICS=1)
endif()

# This is disabled for now becuase sdlwrap tests when run by ctest (gui?)
#add_test(NAME sdlwrap COMMAND test_sdlwrap)


add_executable(test_components runtests.cpp components/basic.cpp ../src/components/basic.cpp)
target_include_directories(test_components PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/gtest/include")
target_include_directories(test_components PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../lib/gmock/include")
target_include_directories(test_components PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../inc")
target_link_libraries(test_components gtest gtest_main)

add_test(NAME components COMMAND test_components)
