#include "libraries.h"



void parse_commandline(int argc, char **argv, int *N, int *save_output)
{

if(argc!=3)
  {
  explain_useage_exit(argv[0]);
  }

if(1 != sscanf(argv[1], "%d", N) )
  {
  explain_useage_exit(argv[0]);
  }

if(1 != sscanf(argv[2], "%d", save_output) )
  {
  explain_useage_exit(argv[0]);
  }

if( /* Check valid number of persons */
    (*N<=1) || 
    /* Check valid save_output */
    ((*save_output > 1) || (*save_output < 0))
  )
  {
  explain_useage_exit(argv[0]);
  }

}





void explain_useage_exit(char *myname)
{
printf("\n\nUseage:\n\n%s  N graphics\n\n"\
       "graphics := either 1 or 0\n"\
       "will run a social dynamics simulation\n"\
       "of N persons in an 'unrequited love' situation:\n\n"\
       "Person 1 is in love with person 2 and walks towards him/her,\n"\
       "person 2 is in love with person 3 and walks towards him/her,\n"\
       "person 3 is in love with person 4 and walks towards him/her,\n"\
       ".\n"\
       ".\n"\
       ".\n", myname);
printf("person N-1 is in love with person N and walks towards him/her,\n"\
       "person N is in love with person 1 and walks towards him/her.\n\n"\
       "Graphical output uses two methods:\n"\
       "First, the SDL library (libsdlorg) for on-the-fly graphics window output, and\n"\
       "second, ppm picture output, automatically converted to gif by system calls.\n\n"\
       "Parameter N must be an integer bigger than 1.\n\n\n");
exit(0);
}

