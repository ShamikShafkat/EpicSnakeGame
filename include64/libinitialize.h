#ifndef LIBINITIALIZE_H
#define LIBINITIALIZE_H

#include "libdeclare.h"
#include "libstring.h"

bool create_window();

bool load_media();

SDL_Texture *loadtexture(char path[],int colorkey_black);

bool loadttf();

SDL_Texture *MAKETTF(char path[],int colour,bool Make_Null);

void INITIALIZER();

#endif // LIBINITIALIZE_H
