#include "lib_brick_modes.h"

void BRICKS_SETUP_LEVEL_1()
{
    Bricks[LEVEL_ONE].body[0].x = 240;
    Bricks[LEVEL_ONE].body[0].y = 150;
    Bricks[LEVEL_ONE].body[0].w = 240;
    Bricks[LEVEL_ONE].body[0].h = 30;

    Bricks[LEVEL_ONE].body[1].x = 480;
    Bricks[LEVEL_ONE].body[1].y = 150;
    Bricks[LEVEL_ONE].body[1].w = 30;
    Bricks[LEVEL_ONE].body[1].h = 240;

    Bricks[LEVEL_ONE].body[2].x = 480;
    Bricks[LEVEL_ONE].body[2].y = 390;
    Bricks[LEVEL_ONE].body[2].w = 270;
    Bricks[LEVEL_ONE].body[2].h = 30;
}

void BRICKS_SETUP_LEVEL_2()
{
    Bricks[LEVEL_TWO].body[0].x = 0;
    Bricks[LEVEL_TWO].body[0].y = 0;
    Bricks[LEVEL_TWO].body[0].w = 240;
    Bricks[LEVEL_TWO].body[0].h = 30;

    Bricks[LEVEL_TWO].body[1].x = 0;
    Bricks[LEVEL_TWO].body[1].y = 0;
    Bricks[LEVEL_TWO].body[1].w = 30;
    Bricks[LEVEL_TWO].body[1].h = 240;

    Bricks[LEVEL_TWO].body[2].x = SCREEN_WIDTH - 240;
    Bricks[LEVEL_TWO].body[2].y = 0;
    Bricks[LEVEL_TWO].body[2].w = 240;
    Bricks[LEVEL_TWO].body[2].h = 30;

    Bricks[LEVEL_TWO].body[3].x = SCREEN_WIDTH - 30;
    Bricks[LEVEL_TWO].body[3].y = 0;
    Bricks[LEVEL_TWO].body[3].w = 30;
    Bricks[LEVEL_TWO].body[3].h = 240;

    Bricks[LEVEL_TWO].body[4].x = 0;
    Bricks[LEVEL_TWO].body[4].y = SCREEN_HEIGHT - 240;
    Bricks[LEVEL_TWO].body[4].w = 30;
    Bricks[LEVEL_TWO].body[4].h = 240;

    Bricks[LEVEL_TWO].body[5].x = 0;
    Bricks[LEVEL_TWO].body[5].y = SCREEN_HEIGHT - 30;
    Bricks[LEVEL_TWO].body[5].w = 240;
    Bricks[LEVEL_TWO].body[5].h = 30;

    Bricks[LEVEL_TWO].body[6].x = SCREEN_WIDTH - 240;
    Bricks[LEVEL_TWO].body[6].y = SCREEN_HEIGHT - 30;
    Bricks[LEVEL_TWO].body[6].w = 240;
    Bricks[LEVEL_TWO].body[6].h = 30;

    Bricks[LEVEL_TWO].body[7].x = SCREEN_WIDTH - 30;
    Bricks[LEVEL_TWO].body[7].y = SCREEN_HEIGHT - 240;
    Bricks[LEVEL_TWO].body[7].w = 30;
    Bricks[LEVEL_TWO].body[7].h = 240;

    Bricks[LEVEL_TWO].body[8].x = 360;
    Bricks[LEVEL_TWO].body[8].y = 180;
    Bricks[LEVEL_TWO].body[8].w = 300;
    Bricks[LEVEL_TWO].body[8].h = 30;
    Bricks[LEVEL_TWO].x_vel[8] = -1;

    Bricks[LEVEL_TWO].body[9].x = 360;
    Bricks[LEVEL_TWO].body[9].y = 390;
    Bricks[LEVEL_TWO].body[9].w = 300;
    Bricks[LEVEL_TWO].body[9].h = 30;
    Bricks[LEVEL_TWO].x_vel[9] = 1;

}

void BRICKS_SETUP_LEVEL_3()
{
    Bricks[LEVEL_THREE].body[0].x = 150;
    Bricks[LEVEL_THREE].body[0].y = 90;
    Bricks[LEVEL_THREE].body[0].w = 30;
    Bricks[LEVEL_THREE].body[0].h = 390;

    Bricks[LEVEL_THREE].body[1].x = 510;
    Bricks[LEVEL_THREE].body[1].y = 90;
    Bricks[LEVEL_THREE].body[1].w = 30;
    Bricks[LEVEL_THREE].body[1].h = 390;

    Bricks[LEVEL_THREE].body[2].x = 870;
    Bricks[LEVEL_THREE].body[2].y = 90;
    Bricks[LEVEL_THREE].body[2].w = 30;
    Bricks[LEVEL_THREE].body[2].h = 390;

    Bricks[LEVEL_THREE].body[3].x = 210;
    Bricks[LEVEL_THREE].body[3].y = 270;
    Bricks[LEVEL_THREE].body[3].w = 270;
    Bricks[LEVEL_THREE].body[3].h = 30;

    Bricks[LEVEL_THREE].body[4].x = 570;
    Bricks[LEVEL_THREE].body[4].y = 270;
    Bricks[LEVEL_THREE].body[4].w = 270;
    Bricks[LEVEL_THREE].body[4].h = 30;

}

void BRICKS_SETUP_LEVEL_4()
{
    Bricks[LEVEL_FOUR].body[0].x = 360;
    Bricks[LEVEL_FOUR].body[0].y = 150;
    Bricks[LEVEL_FOUR].body[0].w = 330;
    Bricks[LEVEL_FOUR].body[0].h = 30;

    Bricks[LEVEL_FOUR].body[1].x = 360;
    Bricks[LEVEL_FOUR].body[1].y = 450;
    Bricks[LEVEL_FOUR].body[1].w = 330;
    Bricks[LEVEL_FOUR].body[1].h = 30;

    Bricks[LEVEL_FOUR].body[2].x = 360;
    Bricks[LEVEL_FOUR].body[2].y = 180;
    Bricks[LEVEL_FOUR].body[2].w = 30;
    Bricks[LEVEL_FOUR].body[2].h = 120;

    Bricks[LEVEL_FOUR].body[3].x = 360;
    Bricks[LEVEL_FOUR].body[3].y = 330;
    Bricks[LEVEL_FOUR].body[3].w = 30;
    Bricks[LEVEL_FOUR].body[3].h = 120;

    Bricks[LEVEL_FOUR].body[4].x = 660;
    Bricks[LEVEL_FOUR].body[4].y = 180;
    Bricks[LEVEL_FOUR].body[4].w = 30;
    Bricks[LEVEL_FOUR].body[4].h = 120;

    Bricks[LEVEL_FOUR].body[5].x = 660;
    Bricks[LEVEL_FOUR].body[5].y = 330;
    Bricks[LEVEL_FOUR].body[5].w = 30;
    Bricks[LEVEL_FOUR].body[5].h = 120;

    Bricks[LEVEL_FOUR].body[6].x = 150;
    Bricks[LEVEL_FOUR].body[6].y = 120;
    Bricks[LEVEL_FOUR].body[6].w = 30;
    Bricks[LEVEL_FOUR].body[6].h = 390;
    Bricks[LEVEL_FOUR].y_vel[6] = -1;

    Bricks[LEVEL_FOUR].body[7].x = 870;
    Bricks[LEVEL_FOUR].body[7].y = 120;
    Bricks[LEVEL_FOUR].body[7].w = 30;
    Bricks[LEVEL_FOUR].body[7].h = 390;
    Bricks[LEVEL_FOUR].y_vel[7] = 1;
}

void BRICKS_SETUP_LEVEL_5()
{
    Bricks[LEVEL_FIVE].body[0].x = 90;
    Bricks[LEVEL_FIVE].body[0].y = 90;
    Bricks[LEVEL_FIVE].body[0].w = 30;
    Bricks[LEVEL_FIVE].body[0].h = 420;

    Bricks[LEVEL_FIVE].body[1].x = 210;
    Bricks[LEVEL_FIVE].body[1].y = 90;
    Bricks[LEVEL_FIVE].body[1].w = 30;
    Bricks[LEVEL_FIVE].body[1].h = 210;

    Bricks[LEVEL_FIVE].body[2].x = 330;
    Bricks[LEVEL_FIVE].body[2].y = 300;
    Bricks[LEVEL_FIVE].body[2].w = 30;
    Bricks[LEVEL_FIVE].body[2].h = 210;

    Bricks[LEVEL_FIVE].body[3].x = 450;
    Bricks[LEVEL_FIVE].body[3].y = 90;
    Bricks[LEVEL_FIVE].body[3].w = 30;
    Bricks[LEVEL_FIVE].body[3].h = 210;

    Bricks[LEVEL_FIVE].body[4].x = 570;
    Bricks[LEVEL_FIVE].body[4].y = 300;
    Bricks[LEVEL_FIVE].body[4].w = 30;
    Bricks[LEVEL_FIVE].body[4].h = 210;

    Bricks[LEVEL_FIVE].body[5].x = 690;
    Bricks[LEVEL_FIVE].body[5].y = 90;
    Bricks[LEVEL_FIVE].body[5].w = 30;
    Bricks[LEVEL_FIVE].body[5].h = 210;

    Bricks[LEVEL_FIVE].body[6].x = 810;
    Bricks[LEVEL_FIVE].body[6].y = 300;
    Bricks[LEVEL_FIVE].body[6].w = 30;
    Bricks[LEVEL_FIVE].body[6].h = 210;

    Bricks[LEVEL_FIVE].body[7].x = 930;
    Bricks[LEVEL_FIVE].body[7].y = 90;
    Bricks[LEVEL_FIVE].body[7].w = 30;
    Bricks[LEVEL_FIVE].body[7].h = 420;
}

void BRICKS_SETUP_LEVEL_BOSS()
{
    Bricks[LEVEL_BOSS].body[0].x = 0;
    Bricks[LEVEL_BOSS].body[0].y = 0;
    Bricks[LEVEL_BOSS].body[0].w = SCREEN_WIDTH;
    Bricks[LEVEL_BOSS].body[0].h = 30;

    Bricks[LEVEL_BOSS].body[1].x = 0;
    Bricks[LEVEL_BOSS].body[1].y = 0;
    Bricks[LEVEL_BOSS].body[1].w = 30;
    Bricks[LEVEL_BOSS].body[1].h = SCREEN_HEIGHT;

    Bricks[LEVEL_BOSS].body[2].x = 0;
    Bricks[LEVEL_BOSS].body[2].y = SCREEN_HEIGHT - 30;
    Bricks[LEVEL_BOSS].body[2].w = SCREEN_WIDTH;
    Bricks[LEVEL_BOSS].body[2].h = 30;

    Bricks[LEVEL_BOSS].body[3].x = SCREEN_WIDTH - 30;
    Bricks[LEVEL_BOSS].body[3].y = 0;
    Bricks[LEVEL_BOSS].body[3].w = 30;
    Bricks[LEVEL_BOSS].body[3].h = SCREEN_HEIGHT;

    Bricks[LEVEL_BOSS].body[4].x = SCREEN_WIDTH - 90;
    Bricks[LEVEL_BOSS].body[4].y = 120;
    Bricks[LEVEL_BOSS].body[4].w = 60;
    Bricks[LEVEL_BOSS].body[4].h = 120;

    Bricks[LEVEL_BOSS].body[5].x = SCREEN_WIDTH - 90;
    Bricks[LEVEL_BOSS].body[5].y = 330;
    Bricks[LEVEL_BOSS].body[5].w = 60;
    Bricks[LEVEL_BOSS].body[5].h = 120;

    Bricks[LEVEL_BOSS].body[6].x = SCREEN_WIDTH - 90;
    Bricks[LEVEL_BOSS].body[6].y = SCREEN_HEIGHT - 60;
    Bricks[LEVEL_BOSS].body[6].w = 60;
    Bricks[LEVEL_BOSS].body[6].h = 30;
}

void MOVE_THE_BRICKS(int start,int finish,int level)
{
    int  i,j;

    for(j=start; j<finish; j++)
    {
        bool move_or_not = true;

        if(level == LEVEL_TWO)
        {
            if(Bricks[level].x_vel[j] > 0)
            {
                bool move_or_not = true;

                for(i=1; i<=Elements.snake_size; i++)
                {
                    SDL_Rect temp;
                    temp.x = Bricks[level].body[j].x + Bricks[level].body[j].w ;
                    temp.y = Bricks[level].body[j].y;
                    temp.w = Python[0].body.w;
                    temp.h = Python[0].body.h;


                    if(temp.x == Python[i].body.x && temp.y == Python[i].body.y)
                    {
                        move_or_not = false;
                        Bricks[level].x_vel[j] = -1;
                        Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_BUMP],0);
                    }
                }

                if(move_or_not == true)
                {
                    if(Bricks[level].body[j].x + Bricks[level].body[j].w <=720)
                    {
                        Bricks[level].body[j].x += 30;
                    }
                    else
                    {
                        Bricks[level].body[j].x -= 60;
                        Bricks[level].x_vel[j] = -1;
                    }
                }
            }
            else
            {

                for(i=1; i<=Elements.snake_size; i++)
                {

                    SDL_Rect temp;
                    temp.x = Bricks[level].body[j].x - 30;
                    temp.y = Bricks[level].body[j].y;
                    temp.w = Python[0].body.w;
                    temp.h = Python[0].body.h;


                    if(temp.x == Python[i].body.x && temp.y == Python[i].body.y)
                    {
                        move_or_not = false;
                        Bricks[level].x_vel[j] = 1;
                        Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_BUMP],0);
                    }

                }

                if(move_or_not == true)
                {
                    if(Bricks[level].body[j].x >=300)
                    {
                        Bricks[level].body[j].x -= 30;
                    }
                    else
                    {
                        Bricks[level].body[j].x += 60;
                        Bricks[level].x_vel[j] = 1;
                    }
                }


            }
        }
        else if(level == LEVEL_FOUR)
        {
            if(Bricks[level].y_vel[j] > 0)
            {
                bool move_or_not = true;

                for(i=1; i<=Elements.snake_size; i++)
                {
                    SDL_Rect temp;
                    temp.x = Bricks[level].body[j].x ;
                    temp.y = Bricks[level].body[j].y + Bricks[level].body[j].h ;
                    temp.w = Python[0].body.w;
                    temp.h = Python[0].body.h;


                    if(temp.x == Python[i].body.x && temp.y == Python[i].body.y)
                    {
                        move_or_not = false;
                        Bricks[level].y_vel[j] = -1;
                        Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_BUMP],0);
                    }
                }

                if(move_or_not == true)
                {
                    if(Bricks[level].body[j].y + Bricks[level].body[j].h <=SCREEN_HEIGHT - 30)
                    {
                        Bricks[level].body[j].y += 30;
                    }
                    else
                    {
                        Bricks[level].body[j].y -= 60;
                        Bricks[level].y_vel[j] = -1;
                    }
                }
            }
            else
            {

                for(i=1; i<=Elements.snake_size; i++)
                {

                    SDL_Rect temp;
                    temp.x = Bricks[level].body[j].x;
                    temp.y = Bricks[level].body[j].y - 30;
                    temp.w = Python[0].body.w;
                    temp.h = Python[0].body.h;


                    if(temp.x == Python[i].body.x && temp.y == Python[i].body.y)
                    {
                        move_or_not = false;
                        Bricks[level].y_vel[j] = 1;
                        Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_BUMP],0);
                    }

                }

                if(move_or_not == true)
                {
                    if(Bricks[level].body[j].y >= 30)
                    {
                        Bricks[level].body[j].y -= 30;
                    }
                    else
                    {
                        Bricks[level].body[j].y += 60;
                        Bricks[level].y_vel[j] = 1;
                    }
                }


            }
        }
    }
}


void MODES_SETUP()
{
    Modes[MODES_CLASSIC].x = 400;
    Modes[MODES_CLASSIC].y = 80;
    Modes[MODES_CLASSIC].w = 220;
    Modes[MODES_CLASSIC].h = 95;

    Modes[MODES_ARCADE].x = 400;
    Modes[MODES_ARCADE].y = 195;
    Modes[MODES_ARCADE].w = 220;
    Modes[MODES_ARCADE].h = 95;

    Modes[MODES_CAMPAIGN].x = 380;
    Modes[MODES_CAMPAIGN].y = 305;
    Modes[MODES_CAMPAIGN].w = 260;
    Modes[MODES_CAMPAIGN].h = 95;

    Modes[MODES_BACK].x = 400;
    Modes[MODES_BACK].y = 510;
    Modes[MODES_BACK].w = 220;
    Modes[MODES_BACK].h = 80;

    Modes[MODES_LEVEL_1].x = 400;
    Modes[MODES_LEVEL_1].y = 60;
    Modes[MODES_LEVEL_1].w = 220;
    Modes[MODES_LEVEL_1].h = 80;

    Modes[MODES_LEVEL_2].x = 400;
    Modes[MODES_LEVEL_2].y = 150;
    Modes[MODES_LEVEL_2].w = 220;
    Modes[MODES_LEVEL_2].h = 80;

    Modes[MODES_LEVEL_3].x = 400;
    Modes[MODES_LEVEL_3].y = 240;
    Modes[MODES_LEVEL_3].w = 220;
    Modes[MODES_LEVEL_3].h = 80;

    Modes[MODES_LEVEL_4].x = 400;
    Modes[MODES_LEVEL_4].y = 330;
    Modes[MODES_LEVEL_4].w = 220;
    Modes[MODES_LEVEL_4].h = 80;

    Modes[MODES_LEVEL_5].x = 400;
    Modes[MODES_LEVEL_5].y = 420;
    Modes[MODES_LEVEL_5].w = 220;
    Modes[MODES_LEVEL_5].h = 80;

    Modes[MODES_EASY].x = 420;
    Modes[MODES_EASY].y = 80;
    Modes[MODES_EASY].w = 200;
    Modes[MODES_EASY].h = 95;

    Modes[MODES_MEDIUM].x = 395;
    Modes[MODES_MEDIUM].y = 195;
    Modes[MODES_MEDIUM].w = 240;
    Modes[MODES_MEDIUM].h = 95;

    Modes[MODES_HARD].x = 420;
    Modes[MODES_HARD].y = 305;
    Modes[MODES_HARD].w = 200;
    Modes[MODES_HARD].h = 95;

    Modes[MODES_CAMPAIGN_COMPLETED].x = 240;
    Modes[MODES_CAMPAIGN_COMPLETED].y = 250;
    Modes[MODES_CAMPAIGN_COMPLETED].w = 620;
    Modes[MODES_CAMPAIGN_COMPLETED].h = 100;
}

