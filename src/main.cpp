/*
 * Main.cpp
 * 
 * @author Chocorean
 */

#include <iostream>

// OS distinctions
    // Windows
#if defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif
    // MacOS
#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#endif
    // Linux
#ifdef linux
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

// Including SDL
#include <SDL2/SDL.h>

// Setting namespace
using namespace std;

//App constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char *GAME_NAME = "Minigame !";

/* ==== MAIN PROGRAM ==== */
int main(int argc, char *argv[])
{
    SDL_Window *window(0);
    // SDL2 Init
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Could not initialize SDL2: " << SDL_GetError() << endl;
        SDL_Quit();
        return -1;
    }
    // OpenGL version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // Double Buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Creating window
    window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(window == 0)
    {
        cout << "Could not create window: " << SDL_GetError() << endl;
        SDL_Quit();
        return -1;
    }
    // Linking OpenGL context to window
    SDL_GLContext openGLContext(0);
    openGLContext = SDL_GL_CreateContext(window);
    if(openGLContext == 0)
    {
        cout << "Could not link OpenGL context: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    // Displaying window
    SDL_Event events;
    bool run(true);
    while (run)
    {
        SDL_WaitEvent(&events);
        if(events.window.event == SDL_WINDOWEVENT_CLOSE)
            run = !run;
    }
    // Exiting SDL..
    SDL_GL_DeleteContext(openGLContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}