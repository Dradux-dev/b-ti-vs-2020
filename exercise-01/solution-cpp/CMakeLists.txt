project(solution-cpp)

set(SOURCE_FILES main.cpp)

add_executable(solution-cpp ${SOURCE_FILES})
target_link_libraries(solution-cpp pthread)
