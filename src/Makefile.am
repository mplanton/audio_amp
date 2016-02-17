# Makefile in directory "src"
bin_PROGRAMS = audio_amp
audio_amp_SOURCES = audio_amp.c amp_functions.h amp_functions.c sndfile.h

audio_amp_CFLAGS = -Wall

# get libsndfile
audio_amp_LDFLAGS = -L/usr/lib/i386-linux-gnu
audio_amp_LDADD = -lsndfile
