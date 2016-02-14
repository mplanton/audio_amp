// amp_functions.c

#include "amp_functions.h"
#include <sndfile.h>

void testPrint(void)
{
  printf("This is the Test for managing it to build this program!\n");
}

void printUsage(void)
{
  printf("USAGE: audio_amp <input soundfile-path> <amp-factor>\n"
         "'audio_amp' scales the input-soundfile with the amp-factor.\n");
}
