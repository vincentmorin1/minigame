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

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/* ==== MAIN PROGRAM ==== */
int main(int argc, char *argv[])
{
    // Initialisation de la SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Could not initialize SDL2: " << SDL_GetError() << endl;
        SDL_Quit();
        return -1;
    }
    // Exiting SDL...
    SDL_Quit();
    return 0;
}