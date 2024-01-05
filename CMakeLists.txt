cmake_minimum_required(VERSION 3.25.2)
project(crossing_road)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#######################################RAYLIB#######################################
# Dependencies
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

if (APPLE)
    set(CMAKE_CXX_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit")
#    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
#    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
#    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
#######################################RAYLIB#######################################

########################### JSON #####################################
include(FetchContent)
FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz
)
FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
########################### JSON #####################################

include_directories(${CMAKE_SOURCE_DIR}/source ${CMAKE_SOURCE_DIR}/external)
add_subdirectory(external)

add_executable(crossing_road main.cpp
        external/raylib-aseprite.h
        source/Window.cpp
        source/Window.h
        source/screen/BaseScreen.cpp
        source/screen/BaseScreen.h
        source/screen/ScreenManager.cpp
        source/screen/ScreenManager.h
        source/screen/MenuScreen.cpp
        source/screen/MenuScreen.h
        source/assetsLib/ConfigIO.cpp
        source/assetsLib/ConfigIO.h
        source/screen/ImportScreens.h
        source/assetsLib/TexturesIO.cpp
        source/assetsLib/TexturesIO.h
        source/screen/GameScreen.cpp
        source/screen/GameScreen.h
        source/gameObjects/Observer.h
        source/gameObjects/Road.cpp
        source/gameObjects/Road.h
        source/gameObjects/Obstacle.cpp
        source/gameObjects/Obstacle.h
        source/gameObjects/NonRoad.cpp
        source/gameObjects/NonRoad.h
        source/temp.cpp
        source/gameObjects/River.cpp
        source/gameObjects/River.h
        source/gameObjects/River.h
        source/gameObjects/BaseGameObject.h
        source/gameObjects/Message.h
        source/gameObjects/MainChar.h
        source/gameObjects/MainChar.cpp
        source/screen/Position.h
        source/gameObjects/MainChar.cpp
        source/gameObjects/TrafficLight.cpp
        source/gameObjects/TrafficLight.h
        source/utils/RandomNumber.cpp
        source/gameObjects/Animal.cpp
        source/gameObjects/Animal.h
        source/utils/RandomNumber.h source/assetsLib/AsepriteIO.cpp source/assetsLib/AsepriteIO.h source/gameObjects/Boat.cpp source/gameObjects/Boat.h
)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json raylib)
