#include "librender.h"

void RENDER_BRICKS()
{
    int i;

    if(flag[GAME_STATES_LEVEL_1] == 1)
    {
        for(i=0; i<3 ; i++)
        {
            SDL_RenderCopy(renderer,Snake_Images[SNAKE_BRICK],NULL,&Bricks[LEVEL_ONE].body[i]);
        }
    }
    else if(flag[GAME_STATES_LEVEL_2] == 1)
    {
        for(i=0; i<10; i++)
        {
            SDL_RenderCopy(renderer,Snake_Images[SNAKE_BRICK],NULL,&Bricks[LEVEL_TWO].body[i]);
        }
    }
    else if(flag[GAME_STATES_LEVEL_3] == 1)
    {
        for(i=0; i<5; i++)
        {
            SDL_RenderCopy(renderer,Snake_Images[SNAKE_BRICK],NULL,&Bricks[LEVEL_THREE].body[i]);
        }
    }
    else if(flag[GAME_STATES_LEVEL_4] == 1)
    {
        for(i=0; i<8; i++)
        {
            SDL_RenderCopy(renderer,Snake_Images[SNAKE_BRICK],NULL,&Bricks[LEVEL_FOUR].body[i]);
        }
    }
    else if(flag[GAME_STATES_LEVEL_5] == 1)
    {
        for(i=0; i<8; i++)
        {
            SDL_RenderCopy(renderer,Snake_Images[SNAKE_BRICK],NULL,&Bricks[LEVEL_FIVE].body[i]);
        }
    }
    else if(flag[GAME_STATES_CAMPAIGN_BOSS_LEVEL] == 1)
    {
        for(i=0; i<7 ; i++)
        {
            SDL_RenderCopy(renderer,Snake_Images[SNAKE_BRICK],NULL,&Bricks[LEVEL_BOSS].body[i]);
        }
    }
}

void RENDER_SCORE()
{
    char str[25];
    number_to_string(Elements.points,str);
    string_reverse(str);
    Snake_Images[SNAKE_SCORE] = MAKETTF(str,1,true);

    SDL_Rect temp;
    temp.x = 580;
    temp.y = 0;
    temp.w = 50;
    temp.h = 50;

    SDL_RenderCopy(renderer,Snake_Images[SNAKE_SCORE],NULL,&temp);
    SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_GAME_SCORE],NULL,&Game_points);
}

void RENDER_SNAKE()
{
    int i;

    for(i=Elements.snake_size; i>=0; i--)
    {
        if(i==0)
        {
            SDL_RenderCopyEx(renderer,Snake_Images[SNAKE_IMAGE],&head,&Python[i].body,Python[0].rotation_angle_present_state,NULL,SDL_FLIP_NONE);
        }
        else if(i!=Elements.snake_size)
        {
            if(Python[i].rotation_angle_present_state == Python[i-1].rotation_angle_present_state)
            {
                SDL_RenderCopyEx(renderer,Snake_Images[SNAKE_IMAGE],&body,&Python[i].body,Python[i].rotation_angle_present_state,NULL,SDL_FLIP_NONE);
            }
            else
            {
                SDL_RenderCopyEx(renderer,Snake_Images[SNAKE_IMAGE],&turn,&Python[i].body,0,NULL,Python[i].flip_present_state);
            }
        }
        else
        {
            SDL_RenderCopyEx(renderer,Snake_Images[SNAKE_IMAGE],&tail,&Python[i].body,Python[i].rotation_angle_present_state,NULL,SDL_FLIP_NONE);
        }
    }
}

void RENDERING_SCREEN()
{
    SDL_SetRenderDrawColor(renderer,0,0,0,0xFF);
    SDL_RenderClear(renderer);

    if(flag[GAME_STATES_HOMESCREEN] == 0)
    {
        SDL_RenderCopy(renderer,Snake_Images[SNAKE_HOMESCREEN],NULL,NULL);
    }
    else if(flag[GAME_STATES_MODES] == 1)
    {
        SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_CLASSIC],NULL,&Modes[MODES_CLASSIC]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_ARCADE],NULL,&Modes[MODES_ARCADE]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_CAMPAIGN],NULL,&Modes[MODES_CAMPAIGN]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_BACK],NULL,&Modes[MODES_BACK]);
    }
    else if(flag[GAME_STATES_HIGHSCORE] == 1)
    {
        if(flag[GAME_STATES_CLASSIC] == 1 || flag[GAME_STATES_CAMPAIGN] == 1)
        {
            SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_EASY],NULL,&Modes[MODES_EASY]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_MEDIUM],NULL,&Modes[MODES_MEDIUM]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_HARD],NULL,&Modes[MODES_HARD]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_BACK],NULL,&Modes[MODES_BACK]);
        }
        else if(flag[GAME_STATES_ARCADE] == 1)
        {

            SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_1],NULL,&Modes[MODES_LEVEL_1]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_2],NULL,&Modes[MODES_LEVEL_2]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_3],NULL,&Modes[MODES_LEVEL_3]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_4],NULL,&Modes[MODES_LEVEL_4]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_5],NULL,&Modes[MODES_LEVEL_5]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_BACK],NULL,&Modes[MODES_BACK]);
        }
        else if(flag[GAME_STATES_LEVEL_1] == 1 || flag[GAME_STATES_LEVEL_2] == 1 || flag[GAME_STATES_LEVEL_3] == 1 || flag[GAME_STATES_LEVEL_4] == 1 || flag[GAME_STATES_LEVEL_5] == 1)
        {
            SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_EASY],NULL,&Modes[MODES_EASY]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_MEDIUM],NULL,&Modes[MODES_MEDIUM]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_HARD],NULL,&Modes[MODES_HARD]);
            SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_BACK],NULL,&Modes[MODES_BACK]);
        }
        else
        {

        }
    }
    else if(flag[GAME_STATES_SHOW_HIGHSCORE] == 1 && flag[GAME_STATES_START_THE_GAME] == 0)
    {
        int start,finish;
        if(flag[GAME_STATES_EASY] == 1)
        {
            start = 0;
            finish = 2;
        }
        else if(flag[GAME_STATES_MEDIUM] == 1)
        {
            start = 3;
            finish = 5;
        }
        else if(flag[GAME_STATES_HARD] == 1)
        {
            start = 6;
            finish = 8;
        }

        if(flag[GAME_STATES_CLASSIC] == 1)
        {
            char path[50] = "res/CLASSIC.txt";
            SHOW_HIGHSCORE(path,start,finish);
        }
        else if(flag[GAME_STATES_LEVEL_1] == 1)
        {
            char path[50] = "res/ARCADE_LEVEL_1.txt";
            SHOW_HIGHSCORE(path,start,finish);
        }
        else if(flag[GAME_STATES_LEVEL_2] == 1)
        {
            char path[50] = "res/ARCADE_LEVEL_2.txt";
            SHOW_HIGHSCORE(path,start,finish);
        }
        else if(flag[GAME_STATES_LEVEL_3] == 1)
        {
            char path[50] = "res/ARCADE_LEVEL_3.txt";
            SHOW_HIGHSCORE(path,start,finish);
        }
        else if(flag[GAME_STATES_LEVEL_4] == 1)
        {
            char path[50] = "res/ARCADE_LEVEL_4.txt";
            SHOW_HIGHSCORE(path,start,finish);
        }
        else if(flag[GAME_STATES_LEVEL_5] == 1)
        {
            char path[50] = "res/ARCADE_LEVEL_5.txt";
            SHOW_HIGHSCORE(path,start,finish);
        }
        else if(flag[GAME_STATES_CAMPAIGN] == 1)
        {
            char path[50] = "res/CAMPAIGN.txt";
            SHOW_HIGHSCORE(path,start,finish);
        }
        else
        {

        }

    }
    else if(flag[GAME_STATES_ARCADE] == 1 && flag[GAME_STATES_START_THE_GAME] != 1)
    {
        SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_1],NULL,&Modes[MODES_LEVEL_1]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_2],NULL,&Modes[MODES_LEVEL_2]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_3],NULL,&Modes[MODES_LEVEL_3]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_4],NULL,&Modes[MODES_LEVEL_4]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_LEVEL_5],NULL,&Modes[MODES_LEVEL_5]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_BACK],NULL,&Modes[MODES_BACK]);

    }
    else if(flag[GAME_STATES_DIFFICULTY] == 1 && flag[GAME_STATES_START_THE_GAME] == 0)
    {
        SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_EASY],NULL,&Modes[MODES_EASY]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_MEDIUM],NULL,&Modes[MODES_MEDIUM]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_HARD],NULL,&Modes[MODES_HARD]);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_BACK],NULL,&Modes[MODES_BACK]);

        SDL_Rect temp = {650,80,70,70};
        if(Elements.Delay == 120)
        {
            SDL_RenderCopy(renderer,Snake_Images[RIGHT_SIGN],NULL,&temp);
        }
        else if(Elements.Delay == 90)
        {
            temp.y += 120;
            SDL_RenderCopy(renderer,Snake_Images[RIGHT_SIGN],NULL,&temp);
        }
        else if(Elements.Delay == 70)
        {
            temp.y += 220;
            SDL_RenderCopy(renderer,Snake_Images[RIGHT_SIGN],NULL,&temp);
        }

    }
    else if(flag[GAME_STATES_HELP] == 1 && flag[GAME_STATES_START_THE_GAME] == 0)
    {
        SDL_RenderCopy(renderer,Snake_Images[HELP],NULL,NULL);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_BACK],NULL,&Modes[MODES_BACK]);
    }
    else
    {
        RENDER_BRICKS();
        RENDER_SCORE();
        RENDER_SNAKE();

        if(Elements.eat)
        {
            SDL_RenderCopy(renderer,Snake_Images[SNAKE_IMAGE],&fruit,&food);
        }

        if(Elements.bonus_eat)
        {
            SDL_RenderCopy(renderer,Snake_Images[SNAKE_BONUS_FOOD],NULL,&bonus_food);
        }

        if(flag[GAME_STATES_CAMPAIGN_BOSS_LEVEL] == 1)
        {
            dragon_mechanics();
            if(poison.venom == true)
            {
                venom_mechanics();
            }

            if(poison.bottle_rend)
            {
                SDL_RenderCopy(renderer,Snake_Images[POISON],NULL,&poison.bottle);
            }
        }

    }
}

