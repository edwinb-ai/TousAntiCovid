#ifndef __73432u_CONSTANTS_H
#define __73432u_CONSTANTS_H

#define TRUE 1
#define FALSE 0

#define MAX_LINELENGTH 1024

#define PI (4.0*atan(1.0))
#define BLOBSIZE 10

#define SIM_TO_GRAPHICS 20
#define N_LINES 30
#define M_COLUMNS 80
#define GRAPHICS_HEIGHT N_LINES*SIM_TO_GRAPHICS
#define GRAPHICS_WIDTH  M_COLUMNS*SIM_TO_GRAPHICS 
/*
#define GRAPHICS_WIDTH  1600 
#define GRAPHICS_HEIGHT 600
#define N_LINES GRAPHICS_HEIGHT/SIM_TO_GRAPHICS
#define M_COLUMNS GRAPHICS_WIDTH/SIM_TO_GRAPHICS
*/
#define GRAPHICS_MARGIN 10

#define FADER 8

#define MAX_SIMULATION_STEPS 1000
#define SMALLDISTANCE 0.1

#define RND_VERBOSITY 0

#define GIF_STEP 2

#endif
