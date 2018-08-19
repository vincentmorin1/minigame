/*
 * Main.cpp
 * 
 * @author Chocorean
 */

// Including SDL
#include <SDL/SDL.h>

// Including windows.h for VSCode users on Windows
// #include <windows.h>

// Including openGL
#include <GL/gl.h>
#include <GL/glu.h>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("My minigame !", NULL);
    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);

    bool run = true;
    SDL_Event event;

    while (run)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                run = !run;
        }
		// display starts here
		glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
            glColor3ub(255,0,0);    glVertex2d(-0.75,-0.75);
            glColor3ub(0,255,0);    glVertex2d(0,0.75);
            glColor3ub(0,0,255);    glVertex2d(0.75,-0.75);
        glEnd();

        glFlush();

        SDL_GL_SwapBuffers();
    }

    SDL_Quit();
    return 0;
}