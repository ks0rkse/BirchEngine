include_directories(inc/)
aux_source_directory(src/ SRC_DIR)

add_executable(${PROJECT_NAME} ${SRC_DIR}
        src/ECS/ecs.cc
        src/ECS/collidercomponent.cc
        src/ECS/keyboardcontroller.cc
        src/ECS/spritecomponent.cc
        src/ECS/tilecomponent.cc
        src/ECS/transformcomponent.cc
        inc/ECS/animation.hh)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})