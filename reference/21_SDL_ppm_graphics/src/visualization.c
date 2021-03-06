#include "libraries.h"




int allocate_SDL_pixelarray(struct SDL_graphics *graph)
{
graph->pixel=(unsigned char*)malloc(3*graph->width*graph->height*sizeof(unsigned char));
if(NULL == graph->pixel)
  {
  printf("\n\nMemory allocation error in function 'allocate_SDL_pixelarray()'.\n\n");
  exit(0);
  }
return(1);
}




int initialize_SDL_graphics(struct SDL_graphics *graph)
{
SDL_Init(SDL_INIT_VIDEO);
graph->screen = SDL_SetVideoMode(graph->width, graph->height, 24, SDL_HWSURFACE);
atexit(SDL_Quit);
return(1);
}





int initialize_pixel_array(struct SDL_graphics *graph)
{
int i;
for(i = 0; i < 3*graph->width*graph->height; i++)
  {
  graph->pixel[i]=255;
  }
return(1);
}





int fade_pixel_array(struct SDL_graphics *graph, int fader)
{
int i;
for(i = 0; i < 3*graph->width*graph->height; i++)
  {
  if(graph->pixel[i] + fader < 256)
    {
    graph->pixel[i] += fader;
    }
  else
    {
    graph->pixel[i] = 255;
    }
  }
return(1);
}




int sdl_update(struct SDL_graphics *graph)
{
graph->memfield = SDL_CreateRGBSurfaceFrom(graph->pixel, graph->width,graph->height, 24, \
                                           3*graph->width, 0xff0000, 0xff0000, 0xff0000, 0);
SDL_BlitSurface (graph->memfield, NULL, graph->screen, NULL);
SDL_UpdateRect(graph->screen, 0, 0, 0, 0);
return(1);
}
	 



int visualize_person(struct SDL_graphics *graph, float *persons, int n, int radius)
{
/*
 * Draws a filled circular disk with 'radius' in units of pixels around
 * the (x, y) position of person 'n'. The color of the disk is related to
 * the value of 'n'.
 *
 */   
int row, col;
float x, y, r, phi, dphi;

x = persons[2*n  ];
y = persons[2*n+1];

for(r = 0.0; r < radius; r += 0.5){
  dphi = 1.0 / (2.0 * PI * r);
  for(phi = 0.0; phi < 2.0*PI; phi += dphi){
    col = (int)(x + r*cos(phi)); 
    row = (int)(y + r*sin(phi)); 

    if((row >= 0) && (row < graph->height) && (col >= 0) && (col < graph->width)){
      graph->pixel[3*row*graph->width + 3*col    ] = ( (11*n) % 255);
      graph->pixel[3*row*graph->width + 3*col + 1] = ((101*n) % 255);
      graph->pixel[3*row*graph->width + 3*col + 2] = ( (23*n) % 255);
    }
  }
}

return(1);
}
		





int drawbox (struct SDL_graphics *graph, int left, int right, int top, int bottom, int width, int brightness)
{
int x, z, line;

line = 3*graph->width;

if(left>right || top>bottom || width<=0 || brightness<0 || brightness>255)
  {
  printf("\n\nFunction 'drawbox()' was called with nonsense arguments.\n\n");
  exit(0);
  }

for(x=left-width+1; x!=right+width; x++)
  {
  for(z=top-width+1; z!=top+1; z++)
    {
    graph->pixel[z*line+3*x  ]=brightness;
    graph->pixel[z*line+3*x+1]=brightness;
    graph->pixel[z*line+3*x+2]=brightness;
    }
  for(z=bottom; z!=bottom+width; z++)
    {
    graph->pixel[z*line+3*x  ]=brightness;
    graph->pixel[z*line+3*x+1]=brightness;
    graph->pixel[z*line+3*x+2]=brightness;
    }
  }

for(z=top-width+1; z!=bottom+width; z++)
  {
  for(x=left-width+1; x!=left+1; x++)
    {
    graph->pixel[z*line+3*x  ]=brightness;
    graph->pixel[z*line+3*x+1]=brightness;
    graph->pixel[z*line+3*x+2]=brightness;
    }
  for(x=right; x!=right+width; x++)
    {
    graph->pixel[z*line+3*x  ]=brightness;
    graph->pixel[z*line+3*x+1]=brightness;
    graph->pixel[z*line+3*x+2]=brightness;
    }
  }

return(1);
}





int write_ppm(struct SDL_graphics *graph, char *filename)
{
FILE *file;

if((file=fopen(filename,"w"))==NULL)
  {
  printf("\n\nError:\n\nCould not open the file %s for writing\n\n",filename);
  exit(0);
  }

fprintf(file,"P6\n%d %d\n%d\n", graph->width, graph->height, 255);

fwrite (graph->pixel, 1, 3*graph->width*graph->height, file);

fclose(file);
return(1);
}
