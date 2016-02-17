// amp_functions.c

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sndfile.h>
#include "amp_functions.h"


void printUsage(void)
{
  printf("USAGE: audio_amp <input soundfile-path> <output-soundfile-path> <amp-factor>\n"
         "'audio_amp' scales the input-soundfile with the amp-factor and"
         " generates the scaled output-soundfile.\n");
}

int guessMajorFileFormat(const char *file_name)
{
  char *file_extension = NULL;
  
  file_extension = strrchr(file_name, '.');
  if(file_extension == NULL)
  {
    puts(strerror(errno));
    return -1;
  }
  
  if (strcasecmp (file_extension, ".wav") == 0)
		return SF_FORMAT_WAV ;
	if (strcasecmp (file_extension, ".aif") == 0 ||
      strcasecmp (file_extension, ".aiff") == 0 ||
      strcasecmp (file_extension, ".aifc") == 0)
		return SF_FORMAT_AIFF ;
	if (strcasecmp (file_extension, ".au") == 0)
		return SF_FORMAT_AU ;
	if (strcasecmp (file_extension, ".caf") == 0)
		return SF_FORMAT_CAF ;
	if (strcasecmp (file_extension, ".w64") == 0)
		return SF_FORMAT_W64 ;
  if (strcasecmp (file_extension, ".flac") == 0)
		return SF_FORMAT_FLAC ;
  if (strcasecmp (file_extension, ".ogg") == 0)
		return SF_FORMAT_OGG ;

	printf("\nError : Can only generate files with extentions: "
         "'wav','flac', 'ogg', 'aifc', 'aiff', 'aif', 'au', 'w64', 'caf'.\n");
  
  return -1;
}
