add_library(raylib_aseprite INTERFACE ../source/gameObjects/River.h)

# Include Directory
target_include_directories(raylib_aseprite INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/)

# Set the header files as install files.
install(FILES
        raylib-aseprite.h
        cute_aseprite.h
        DESTINATION include
)