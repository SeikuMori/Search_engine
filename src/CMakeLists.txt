cmake_minimum_required(VERSION 3.10)
project(search_engine)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

target_include_directories(search_engine PRIVATE ${PROJECT_SOURCE_DIR}/includes)

add_executable(search_engine
    main.cpp
    includes/ConverterJSON.h
    includes/InvertedIndex.h
    includes/SearchServer.h
    src/ConverterJSON.cpp
    src/InvertedIndex.cpp
    src/SearchServer.cpp
)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

enable_testing()
add_subdirectory(tests)
