#include "libNew.h"

void MEMSET_ALL()
{
    memset(flag,0,sizeof(flag));
    memset(Python,0,sizeof(Python));
}

void GAME_STARTER()
{
    int i;

    Elements.stop = true;
    Elements.alive =true;
    Elements.eat = false;
    Elements.pause = false;
    Elements.bonus_eat = false;

    Elements.x_direction = 1;
    Elements.y_direction = 0;
    Elements.snake_size = 4;
    Elements.points = 0;
    Elements.timer = 0;
    Elements.apple_counter = 0;

    poison.bottle.x = 0;
    poison.bottle.y = 0;
    poison.poison_drop.x = 0;
    poison.poison_drop.y = 0;
    poison.bottle_rend = false;
    poison.venom = false;
    poison.venom_collected = false;

    srand(time(0));

    MEMSET_ALL();

    Python[0].body.x = 30*15;
    Python[0].body.y = 30;
    Python[0].body.w = 30;
    Python[0].body.h = 30;


    for(i=1; i<=RANGE; i++)
    {
        Python[i].body.x = Python[i-1].body.x - 30;
        Python[i].body.y = Python[i-1].body.y;
        Python[i].body.w = Python[i-1].body.w;
        Python[i].body.h = Python[i-1].body.h;

    }

    BRICKS_SETUP_LEVEL_1();
    BRICKS_SETUP_LEVEL_2();
    BRICKS_SETUP_LEVEL_3();
    BRICKS_SETUP_LEVEL_4();
    BRICKS_SETUP_LEVEL_5();
    BRICKS_SETUP_LEVEL_BOSS();

    MODES_SETUP();
    dragon_setup();
    READING_DIFFICULTY();

    Mix_PlayMusic(beat,-1);
}



void SET_THE_LEVEL()
{
    if(Elements.apple_counter == 50 && flag[GAME_STATES_LEVEL_1] == 1)
    {
        int temp = Elements.points;
        GAME_STARTER();
        Mix_HaltMusic();

        flag[GAME_STATES_HOMESCREEN] = 1;
        flag[GAME_STATES_CAMPAIGN] = 1;
        flag[GAME_STATES_LEVEL_2] = 1;
        flag[GAME_STATES_START_THE_GAME] = 1;

        Elements.points = temp;
        Elements.pause = true;
        Elements.snake_size--;

        LEVEL_COMPLETED();
    }
    else if(Elements.apple_counter == 40 && flag[GAME_STATES_LEVEL_2] == 1)
    {
        int temp = Elements.points;
        GAME_STARTER();
        Mix_HaltMusic();

        flag[GAME_STATES_HOMESCREEN] = 1;
        flag[GAME_STATES_CAMPAIGN] = 1;
        flag[GAME_STATES_LEVEL_3] = 1;
        flag[GAME_STATES_START_THE_GAME] = 1;

        Elements.points = temp;
        Elements.pause = true;
        Elements.snake_size--;

        LEVEL_COMPLETED();
    }
    else if(Elements.apple_counter == 40 && flag[GAME_STATES_LEVEL_3] == 1)
    {
        int temp = Elements.points;
        GAME_STARTER();
        Mix_HaltMusic();

        flag[GAME_STATES_HOMESCREEN] = 1;
        flag[GAME_STATES_CAMPAIGN] = 1;
        flag[GAME_STATES_LEVEL_4] = 1;
        flag[GAME_STATES_START_THE_GAME] = 1;

        Elements.points = temp;
        Elements.pause = true;
        Elements.snake_size--;

        LEVEL_COMPLETED();
    }
    else if(Elements.apple_counter == 30 && flag[GAME_STATES_LEVEL_4] == 1)
    {
        int temp = Elements.points;
        GAME_STARTER();
        Mix_HaltMusic();

        flag[GAME_STATES_HOMESCREEN] = 1;
        flag[GAME_STATES_CAMPAIGN] = 1;
        flag[GAME_STATES_LEVEL_5] = 1;
        flag[GAME_STATES_START_THE_GAME] = 1;

        Elements.points = temp;
        Elements.pause = true;
        Elements.snake_size--;

        LEVEL_COMPLETED();
    }
    else if(Elements.apple_counter == 30 && flag[GAME_STATES_LEVEL_5] == 1)
    {
        int temp = Elements.points;
        GAME_STARTER();
        Mix_HaltMusic();

        flag[GAME_STATES_HOMESCREEN] = 1;
        flag[GAME_STATES_CAMPAIGN] = 1;
        flag[GAME_STATES_CAMPAIGN_BOSS_LEVEL] = 1;
        flag[GAME_STATES_START_THE_GAME] = 1;

        Elements.points = temp;
        Elements.pause = true;
        Elements.snake_size--;

        LEVEL_COMPLETED();

    }
    else if(flag[GAME_STATES_CAMPAIGN_BOSS_LEVEL] == 1)
    {
        if(dragon[0].life ==0 && dragon[1].life == 0 && dragon[2].life == 0)
        {
            SDL_Delay(750);
            flag[GAME_STATES_CAMPAIGN_COMPLETED] = 1;

            LEVEL_COMPLETED();

            END_OF_GAME();

            GAME_STARTER();
        }

    }
    else
    {

    }

}

void LEVEL_COMPLETED()
{
    SDL_SetRenderDrawColor(renderer,0,0,0,0xFF);
    SDL_RenderClear(renderer);

    SDL_Rect temp;
    temp.x = 300;
    temp.y = 250;
    temp.w = 560;
    temp.h = 100;

    SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
    SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_COMPLETED],NULL,&temp);

    SDL_RenderPresent(renderer);
    Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_YAY],0);
    SDL_Delay(4000);
}

