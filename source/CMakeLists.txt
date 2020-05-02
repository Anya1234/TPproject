set(BINARY ${CMAKE_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LOTR_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LOTR_SOURCE_DIR}/lib)

add_executable(${BINARY}
    main.cpp 
    Creatures.h 
    interface_factory.h 
    Creatures.cpp 
    Dragon.h 
    Dragon.cpp
    Gendalf.h 
    Gendalf_types.h 
    Gendalf.cpp 
    Gendalf_types.cpp
    creature_factory.h 
    creature_factory.cpp
    Team.h
    Team.cpp
    )

add_library(${BINARY}_lib STATIC     	
    main.cpp 
    Creatures.h 
    interface_factory.h 
    Creatures.cpp 
    Dragon.h 
    Dragon.cpp
    Gendalf.h 
    Gendalf_types.h 
    Gendalf.cpp 
    Gendalf_types.cpp
    creature_factory.h 
    creature_factory.cpp
    Team.h
    Team.cpp
    )

install(TARGETS ${BINARY}
        RUNTIME DESTINATION  ${CMAKE_INSTALL_PREFIX}
        )