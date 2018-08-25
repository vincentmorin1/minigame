/*
 * Main.cpp
 * 
 * @author Chocorean
 */

// OS distinctions
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else // Windows & Linux
#include <GL/gl.h>
#include <GL/glu.h>
#endif

// Including SDL
#include <SDL2/SDL.h>

// Including custom logger
#include "Logger.h"

// Setting namespace
using namespace std;

//App constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char *GAME_NAME = "Minigame !";

/* ==== MAIN PROGRAM ==== */
int main(int argc, char **argv)
{
    // Init
    Logger(INFO) << "Welcome to our minigame !";
    Logger(INFO) << "Main executed with " << (argc - 1) << " arguments";
    if (argc > 1)
    {
        for (int i=1; i<argc; i++)
        {
            Logger(INFO) << "Argument #" << i << ": " << *(argv+i);
        }
    }
    // SDL2 Init
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        Logger(ERROR) << "Could not initialize SDL2: " << SDL_GetError();
        SDL_Quit();
        return -1;
    }
    Logger(DEBUG) << "SDL correctly initialized.";
    // OpenGL version
    if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3) < 0)
    {
        Logger(ERROR) << "Could not initialize OpenGL v3: " << SDL_GetError();
        SDL_Quit();
        return -1;
    }
    if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1) < 0)
    {
        Logger(ERROR) << "Could not initialize OpenGL v3.1: " << SDL_GetError();
        SDL_Quit();
        return -1;
    }

    // Double Buffer
    if (SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1) < 0)
    {
        Logger(ERROR) << "Could not enable double buffer: " << SDL_GetError();
        SDL_Quit();
        return -1;
    }
    if (SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24) < 0)
    {
        Logger(ERROR) << "Could not set depth size: " << SDL_GetError();
        SDL_Quit();
        return -1;
    }

    // Creating window
    SDL_Window *window(0);
    window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(window == 0)
    {
        Logger(ERROR) << "Could not create window: " << SDL_GetError();
        SDL_Quit();
        return -1;
    }
    Logger(DEBUG) << "Window created.";
    // Linking OpenGL context to window
    SDL_GLContext openGLContext(0);
    openGLContext = SDL_GL_CreateContext(window);
    if(openGLContext == 0)
    {
        Logger(ERROR) << "Could not link OpenGL context: " << SDL_GetError();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    Logger(DEBUG) << "OpenGL context linked to the window.";
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
    Logger(INFO) << "Leaving... Bye!";
    SDL_GL_DeleteContext(openGLContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}