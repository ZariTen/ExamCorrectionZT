CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
PROJECT(template)

SET(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_executable(programa
    src/main.cpp
    src/prova.cpp
    src/corretor.cpp
    src/candidato.cpp
    src/ordenacao.cpp
)
