#ifndef LIB_HS_DIF_H
#define LIB_HS_DIF_H

#include "libdeclare.h"
#include "libinitialize.h"

void HIGHSCORE(char path[],SDL_Rect *temp, SDL_Rect *points_rect);

void INPUT_NAME(char name[]);

void READING_DIFFICULTY();

void SETTING_DIFFICULTY(int speed);

void SHOW_HIGHSCORE(char path[],int start,int finish);

#endif // LIB_HS_DIF_H
