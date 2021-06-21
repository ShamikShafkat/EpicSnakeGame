#ifndef LIBINITIALIZE_H
#define LIBINITIALIZE_H

#include "libdeclare.h"
#include "libstring.h"

bool create_window();

bool load_media();

SDL_Texture *loadtexture(char ch[],int x);

bool loadttf();

SDL_Texture *MAKETTF(char ch[],int a,bool Make_Null);

void INITIALIZER();

#endif // LIBINITIALIZE_H
