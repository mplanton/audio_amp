// audio_amp.c
// the main program 'audio_amp'

#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "amp_functions.h"

// USAGE: audio_amp <input soundfile-path> <amp-factor>
enum ARGS {PROG_NAME, IN_FILE_NR, AMP_FACTOR_NR, ARG_NR};

#define ARG_NUM ARG_NR-1 // number of arguments


int main(int argc, char **argv)
{
  char *in_file_path;
  float amp_factor;
  
  // check arguments
  
  // check number of arguments
  if(argc != ARG_NR)
  {
    printf("ERROR: 'audio_amp' needs exactly %d arguments instead of %d"
           " arguments.\n", ARG_NUM, argc-1);
    printUsage();
    exit(EXIT_FAILURE);
  }
  
  // check if amp-factor is a number
  if(! isdigit(argv[AMP_FACTOR_NR][0]))
  {
    printf("ERROR: The argument <amp-factor> must be a decimal number!\n");
    printUsage();
    exit(EXIT_FAILURE);
  }
  
  // get amp factor
  amp_factor = atof(argv[AMP_FACTOR_NR]);


  // initialize stuff
  
  // open files
  
  // main loop
  
  // clean up
  
  return EXIT_SUCCESS;
}
