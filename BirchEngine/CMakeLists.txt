include_directories(inc/)
aux_source_directory(src/ SRC_DIR)

add_executable(${PROJECT_NAME} ${SRC_DIR}
        src/ecs/ecs.cc
        src/ecs/collider_component.cc
        src/ecs/keyboard_controller.cc
        src/ecs/sprite_component.cc
        src/ecs/tile_component.cc
        src/ecs/transform_component.cc
 )

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})