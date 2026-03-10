#include <SDL2/SDL.h>
#include <GL/gl.h>

int main() {

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* window = SDL_CreateWindow("OpenGL Triangle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);

  SDL_GLContext context = SDL_GL_CreateContext(window);

  int running = 1;
  SDL_Event event;

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
          running = 0;
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, -0.5);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.5, -0.5);

    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 0.5);

    glEnd();

    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
