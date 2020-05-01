set(BINARY ${CMAKE_PROJECT_NAME}_tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LOTR_SOURCE_DIR}/bin)

add_executable(${BINARY} main.cpp 
                         hobbits_creating_test.cpp
                         orcs_creating_test.cpp
                         humans_creating_test.cpp
                         gendalf_creating_test.cpp
                         dragon_creating_test.cpp
                         team_testing.cpp
              )         

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)