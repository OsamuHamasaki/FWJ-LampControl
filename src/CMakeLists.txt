set(MAIN_SOURCE LampControl.cpp)
file(GLOB COMPONENTS_SOURCES *.cpp)
list(FILTER COMPONENTS_SOURCES EXCLUDE REGEX ${MAIN_SOURCE})

add_executable(LampControl ${MAIN_SOURCE})
add_library(Components STATIC ${COMPONENTS_SOURCES})

target_include_directories(Components
    PRIVATE ${PROJECT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(LampControl PUBLIC Components IO)

