#include <stdbool.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>

#include "draw.h"
#include "vec3.h"

int main() {

  SDL_SetHint("SDL_HINT_NO_SIGNAL_HANDLERS", "1");

  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    fprintf(stderr, "Video initialization failed: %s\n", SDL_GetError());
    exit(1);
  }

  SDL_Window *window = SDL_CreateWindow("HoverX!", 0, 0, 640, 480, SDL_WINDOW_OPENGL);
    
  // Create an OpenGL context associated with the window.
  SDL_GLContext glcontext = SDL_GL_CreateContext(window);

  while(true) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      //FIXME: Handle?
    }


    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw some X pattern
    Vec3 tl = { -1.0f,  1.0f, 0.0f };
    Vec3 tr = {  1.0f,  1.0f, 0.0f };
    Vec3 bl = { -1.0f, -1.0f, 0.0f };
    Vec3 br = {  1.0f, -1.0f, 0.0f };
    drawDebugLine(&tl, &br);
    drawDebugLine(&tr, &bl);

    // Get current time
    float t = SDL_GetTicks() / 1000.0f;

    // Create a fake-player state on a fixed trajectory
    Vec3 center = { 0.0f, 0.0f, 0.0f };
    float radius = 0.1f;
    float angle = t;
    pointOnCircle(&center.x, &center.y, angle, 0.5);

    // Draw something like a player 
    drawDebugCircle(&center, radius);

    // Mark direction of travel
    Vec3 tip;
    Vec3 heading = { 0.0f, 0.0f, 0.0f };
    pointOnCircle(&heading.x, &heading.y, angle + M_PI_2, radius);
    vec3_add(&tip, &center, &heading);
    drawDebugLine(&center, &tip);

    // Display new image
    SDL_GL_SwapWindow(window);
  }

  // Once finished with OpenGL functions, the SDL_GLContext can be deleted.
  SDL_GL_DeleteContext(glcontext);  
  
  return 0;  
}
