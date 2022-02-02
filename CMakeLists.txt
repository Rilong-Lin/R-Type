cmake_minimum_required(VERSION 3.5)

project(r-type)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

Set(SOURCE_FILES_GAMEENGINE
        Jo/Game/GameBlock.hpp
        Jo/GameEngine/Architechture/include/BasicBlock.hpp
        Jo/GameEngine/Architechture/include/BasicDisplay.hpp
        Jo/GameEngine/Architechture/include/Canva.hpp
        Jo/GameEngine/Architechture/include/MouvementTemplate.hpp
        Jo/GameEngine/Architechture/include/MyMusic.hpp
        Jo/GameEngine/Architechture/include/Utility.hpp

        Jo/Game/src/Enemy.cpp
        Jo/Game/src/main.cpp
        Jo/Game/src/Missile.cpp
        Jo/Game/src/Obstacle.cpp
        Jo/Game/src/Player.cpp
        Jo/GameEngine/Architechture/src/BasicDisplay.cpp
        Jo/GameEngine/Architechture/src/BasicEntities.cpp
        Jo/GameEngine/Architechture/src/Canva.cpp
        Jo/GameEngine/Architechture/src/MouvementTemplate.cpp
        Jo/GameEngine/Architechture/src/Music.cpp
        



)
Set(SOURCE_FILES_COMMON

        Common/include/Request.h
        Common/include/RequestNewGame.h
        Common/include/ResponseListGames.h
        Common/include/RequestGameState.h
        Common/include/RequestClientAction.h
        Common/include/RequestEnum.h
        Common/include/BasicBlock.hpp
        Common/include/Canva.hpp
        Common/include/GameBlock.hpp
        Common/include/MouvementTemplate.hpp
        Common/include/Utility.hpp
        Common/include/BasicDisplay.hpp
        Common/include/MyMusic.hpp


        Common/src/Request.cpp
        Common/src/RequestNewGame.cpp
        Common/src/RequestGameState.cpp
        Common/src/BasicEntities.cpp
        Common/src/Canva.cpp
        Common/src/BasicDisplay.cpp
        Common/src/Enemy.cpp
        Common/src/Missile.cpp
        Common/src/MouvementTemplate.cpp
        Common/src/Player.cpp
        Common/src/Music.cpp
        Common/src/Obstacle.cpp
        )

set(SOURCE_FILES_SERVER

        Server/include/Game.h
        Server/include/Server.h


        Server/src/Game.cpp
        Server/src/Server.cpp
        Server/src/main.cpp)

set(SOURCE_FILES_CLIENT
        Client/include/Client.h
        Client/include/Mainframe.h

        Client/src/main.cpp
        Client/src/Client.cpp
        Client/src/Mainframe.cpp)

add_executable(r-type_game ${SOURCE_FILES_GAMEENGINE})
add_executable(r-type_server ${SOURCE_FILES_SERVER} ${SOURCE_FILES_COMMON})
add_executable(r-type_client ${SOURCE_FILES_CLIENT} ${SOURCE_FILES_COMMON})

target_link_libraries(r-type_game ${CONAN_LIBS})
target_link_libraries(r-type_server ${CONAN_LIBS})
target_link_libraries(r-type_client ${CONAN_LIBS})

target_include_directories(
        r-type_server PUBLIC

        Server/include
        Server/src

        Common/include
        Common/src
)

target_include_directories(
        r-type_client PUBLIC

        Client/include
        Client/src

        Common/include
        Common/src
)

target_include_directories(
        r-type_game PUBLIC

        Jo/Game
        Jo/Game/src

        Jo/GameEngine/Architechture/include
        Jo/GameEngine/Architechture/src
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Jo/Game/asset
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)

set_property(TARGET r-type_game PROPERTY CXX_STANDARD 20)
set_property(TARGET r-type_server PROPERTY CXX_STANDARD 20)
set_property(TARGET r-type_client PROPERTY CXX_STANDARD 20)