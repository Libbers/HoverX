# Build system for debug platforms
add_executable(hoverx main.c)

target_link_libraries(hoverx -lSDL2 -lGL -lm)
