// audio_amp.c
// the main program 'audio_amp'

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <sndfile.h>

#include "amp_functions.h"

// USAGE: audio_amp <input-soundfile-path> <output-soundfile-path> <amp-factor>
enum ARGS {PROG_NAME, IN_FILE_NR, OUT_FILE_NR, AMP_FACTOR_NR, ARG_NR};

#define ARG_NUM ARG_NR-1 // number of arguments
#define BUFFER_SIZE 2048

int main(int argc, char **argv)
{
  char *in_file_path = "";
  char *out_file_path = "";
  float amp_factor = 0;
  int out_format = 0;
  
  // file pointers
  SNDFILE *in_file = NULL;
  SNDFILE *out_file = NULL;
  
  // sound file information
  SF_INFO sf_info;
  memset(&sf_info, 0, sizeof(sf_info)); // initialize to zero
  
  // check arguments
  
  // check number of arguments
  if(argc != ARG_NR)
  {
    printf("ERROR: 'audio_amp' needs exactly %d arguments instead of %d"
           " arguments.\n", ARG_NUM, argc-1);
    printUsage();
    exit(EXIT_FAILURE);
  }
  
  // check if amp-factor is a number like '0.5' or '.5'
  if(! (isdigit(argv[AMP_FACTOR_NR][0]) ||
       ( (argv[AMP_FACTOR_NR][0] == '.') && isdigit(argv[AMP_FACTOR_NR][1]) )))
  {
    printf("ERROR: The argument <amp-factor> must be a decimal number!\n");
    printUsage();
    exit(EXIT_FAILURE);
  }
  
  // get amp factor
  amp_factor = atof(argv[AMP_FACTOR_NR]);

  // get file paths
  in_file_path = argv[IN_FILE_NR];
  out_file_path = argv[OUT_FILE_NR];
  
  // open input file
  in_file = sf_open(in_file_path, SFM_READ, &sf_info);
  if(in_file == NULL)
  {
    printf("ERROR: Could not open input file %s!\n", in_file_path);
    puts(sf_strerror(in_file));
    exit(EXIT_FAILURE);
  }


  out_format = guessMajorFileFormat(out_file_path);
  if(out_format < 0)
  {
    printf("ERROR: Could not find a valid file format from file extension "
           "for output-file '%s'\n", out_file_path);
    exit(EXIT_FAILURE);
  }

  sf_info.format = out_format | SF_FORMAT_FLOAT; // add subtype format


  // open output file
  out_file = sf_open(out_file_path, SFM_WRITE, &sf_info);
  if(out_file == NULL)
  {
    printf("ERROR: Could not open output file %s!\n", out_file_path);
    puts(sf_strerror(out_file));
    exit(EXIT_FAILURE);
  }
  
  
  // main processing loop
  sf_count_t frames_read = 0;
  sf_count_t frames_written = 0;
  sf_count_t counter = 0;
  float buffer[BUFFER_SIZE * sf_info.channels];
  
  while(1)
  {
    frames_read = sf_readf_float(in_file, buffer, BUFFER_SIZE);
    if(frames_read == 0) break;
    
    // processing
    for(counter = 0; counter < frames_read * sf_info.channels; counter++)
    {
      buffer[counter] = amp_factor * buffer[counter];
    }
    
    frames_written = sf_writef_float(out_file, buffer, frames_read);
    if(frames_written != frames_read)
    {
      printf("ERROR: There was a problem writing to file %s! "
             "It may be damaged!\n", out_file_path);
      puts(sf_strerror(out_file));
      break;
    }
    
    // End of File
    if(frames_read < BUFFER_SIZE) break;
  }
  
  // clean up
  sf_close(in_file);
  sf_close(out_file);
  
  return EXIT_SUCCESS;
}
