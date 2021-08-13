file(GLOB TestSources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(LampControlTest ${TestSources})

add_subdirectory(TestDouble)
add_subdirectory(googletest-release-1.11.0)

target_link_libraries(LampControlTest PUBLIC
    Components
    IOforTest
    gtest_main
    pthread)

target_include_directories(LampControlTest
    PRIVATE "googletest-release-1.11.0/googletest/include")

include(GoogleTest)
gtest_discover_tests(LampControlTest)

