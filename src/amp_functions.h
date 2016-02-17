// amp_functions.h
// This file holds the functions for the main program.

#ifndef _AMP_FUNCTIONS_H_
#define _AMP_FUNCTIONS_H_


#ifndef M_PI
#define M_PI (3.1415926535897932)
#endif

// print the usage message
void printUsage(void);

// guess major file format from file ext
// returns the Major Format SF_FORMAT_XXX
int guessMajorFileFormat(const char *file_name);


#endif
