#include "libdeclare.h"
#include "libinitialize.h"
#include "snake_properties.h"
#include "food.h"
#include "liblife.h"
#include "libend.h"
#include "lib_dragon_poison.h"
#include "lib_HS_DIF.h"
#include "librender.h"
#include "libstring.h"
#include "lib_brick_modes.h"
#include "libUI.h"
#include "libNew.h"

void CALLLER_FUNCTION();

void CALLLER_FUNCTION()
{
    MEMSET_ALL();

    if(!(create_window()))
    {
        printf("ERROR 1\n");
    }
    else
    {
        if(!(load_media()))
        {
            printf("ERROR 2\n");
        }

        else
        {
            if(!(loadttf()))
            {
                printf("ERROR 3\n");
            }
            else
            {
                GAME_STARTER();
                INITIALIZER();

                for(; Elements.stop;)
                {
                    GAME_LOOP();

                    if(Elements.pause == true)
                    {
                        continue;
                    }

                    if(flag[GAME_STATES_START_THE_GAME] == 1)
                    {
                        SETTING_THE_DIRECTION();

                        SETTING_THE_WALL_PASSING_STATES();

                        SETTING_THE_MOVEMENTS();

                        SETTING_THE_ROTATION_ANGLES();

                        SETTING_THE_FLIP_STATES();

                        if(Elements.eat == false)
                        {
                            food = CREATING_FOOD();
                            Elements.eat = true;
                        }

                        if(Python[0].body.x == food.x && Python[0].body.y == food.y)
                        {
                            Elements.eat = false;
                            Elements.points+=5;
                            Elements.apple_counter++;

                            if(Elements.apple_counter % 5 == 0 && Elements.apple_counter != 0)
                            {
                                Elements.timer = 0;
                                bonus_food = CREATING_FOOD();
                                Elements.bonus_eat = true;
                            }

                            if(Elements.apple_counter == 30 && flag[GAME_STATES_CAMPAIGN_BOSS_LEVEL] == 1 && poison.venom_collected == false)
                            {
                                poison.bottle = CREATING_FOOD();
                                poison.bottle_rend = true;
                            }

                        }

                        if(Elements.bonus_eat)
                        {
                            Elements.timer++;
                            if(Elements.timer == 45)
                            {
                                Elements.bonus_eat = false;
                                Elements.timer = 0;
                            }
                            else if(Python[0].body.x == bonus_food.x && Python[0].body.y == bonus_food.y)
                            {
                                Elements.points+=(20 + (45-Elements.timer)*2);
                                Elements.bonus_eat = false;
                                Elements.timer = 0;
                                Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_EAT],0);
                            }
                        }

                        if(poison.bottle_rend)
                        {
                            if(Python[0].body.x == poison.bottle.x && Python[0].body.y == poison.bottle.y)
                            {
                                poison.venom_collected = true;
                                poison.bottle_rend = false;
                                Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_EAT],0);
                            }
                        }

                        if(flag[GAME_STATES_LEVEL_2] == 1)
                        {
                            MOVE_THE_BRICKS(8,10,LEVEL_TWO);
                        }
                        else if(flag[GAME_STATES_LEVEL_4] == 1)
                        {
                            MOVE_THE_BRICKS(6,8,LEVEL_FOUR);
                        }

                        RENDERING_SCREEN();

                        ALIVE_OR_DEAD();

                        SDL_RenderPresent(renderer);

                        if(Elements.eat == false)
                        {
                            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_EAT],0);
                        }

                        if(Elements.bonus_eat == false && Elements.timer != 0)
                        {
                            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_EAT],0);
                            Elements.timer = 0;
                        }

                        if(Elements.alive == false)
                        {
                            END_OF_GAME();
                            MEMSET_ALL();
                            GAME_STARTER();
                            continue;

                        }

                        if(flag[GAME_STATES_CAMPAIGN] == 1)
                        {
                            SET_THE_LEVEL();
                        }

                        if(Elements.eat == false && Elements.snake_size <= 490)
                        {
                            Elements.snake_size ++;
                        }

                        for(int i=1; i<=Elements.snake_size; i++)
                        {
                            Python[i].flip_past_state = Python[i].flip_present_state;
                            Python[i].flip_present_state = SDL_FLIP_NONE;
                        }

                        SDL_Delay(Elements.Delay);

                    }
                    else
                    {
                        RENDERING_SCREEN();
                        SDL_RenderPresent(renderer);
                    }

                }

            }

        }
    }

    close();
}


int main(int argc,char *argv[])
{
    CALLLER_FUNCTION();
    return 0;
}

