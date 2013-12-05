//
//  main.cpp
//  SWF-RPG
//
//  Created by Dylan McAllister on 11/4/13.
//  Copyright (c) 2013 Sea Water Fox. All rights reserved.
//

#include "main.h"
//I'm a Mac!
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <SDL/SDL.h>


int main(int argc, char *argv[])
{
    const int xres = 1280;   //set x resolution to 640
    const int yres = 800;   //set y resolution to 480
    
    SDL_Event event;      //create event structure so we can detect keypresses
    
    SDL_Init(SDL_INIT_VIDEO);  //initialise SDL & the video subsystem
    
    //SDL_SetVideoMode:
    //the 3rd value is the bits per pixel,
    //    but passing 0 uses the desktop's bit depth.
    //SDL_OPENGL creates an OpenGL rendering context
    //SDL_HWSURFACE creates the surface in video memory,
    //              rather than system memory
    //SDL_FULLSCREEN sets full screen mode
    SDL_SetVideoMode(xres,yres,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    
    //Initialize OpenGL
    
    //Do an initial Change of Size
    
    bool done = false;
    while (!done)
    {
        
        //Draw the scene
        
        SDL_GL_SwapBuffers();
        
        //while there are events in the queue
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                    
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE) //look for escape key
                        done = true;
                    break;
                case SDL_QUIT:
                    done = true;
            }
        }
    }       //end of main loop
    
    SDL_Quit();
    return(0);
} 
