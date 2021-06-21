#include"libend.h"

void END_OF_GAME()
{
    if(flag[GAME_STATES_CAMPAIGN_COMPLETED] == 0)
    {
        Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CRASH],0);

        SDL_Delay(1000);

        SDL_SetRenderDrawColor(renderer,0,0,0,0xFF);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,Snake_Images[SNAKE_GAMEOVER],NULL,NULL);

        SDL_RenderPresent(renderer);

        SDL_Delay(3000);
    }
    else
    {
        SDL_SetRenderDrawColor(renderer,0,0,0,0xFF);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_CAMPAIGN_COMPLETED],NULL,&Modes[MODES_CAMPAIGN_COMPLETED]);

        SDL_RenderPresent(renderer);
        Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_YAY],0);
        SDL_Delay(4000);
    }

    SDL_SetRenderDrawColor(renderer,0,0,0,0xFF);
    SDL_RenderClear(renderer);

    SDL_Rect temp;
    temp.x = 350;
    temp.y = 150;
    temp.w = 300;
    temp.h = 200;

    SDL_Rect points_rect;
    points_rect.x = 450;
    points_rect.y = 280;
    points_rect.w = 100;
    points_rect.h = 200;

    char ch[25];

    number_to_string(Elements.points,ch);
    string_reverse(ch);
    Snake_Images[SNAKE_SCORE] = MAKETTF(ch,0,true);

    SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
    SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_SCORE],NULL,&temp);
    SDL_RenderCopy(renderer,Snake_Images[SNAKE_SCORE],NULL,&points_rect);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);


    if(flag[GAME_STATES_ARCADE] == 1)
    {
        if(flag[GAME_STATES_LEVEL_1] == 1)
        {
            char path[50] = "res/ARCADE_LEVEL_1.txt";

            HIGHSCORE(path,&temp,&points_rect);
        }
        else if(flag[GAME_STATES_LEVEL_2] == 1)
        {
            char path[50] = "res/ARCADE_LEVEL_2.txt";

            HIGHSCORE(path,&temp,&points_rect);
        }
        else if(flag[GAME_STATES_LEVEL_3] == 1)
        {
            char path[50] = "res/ARCADE_LEVEL_3.txt";

            HIGHSCORE(path,&temp,&points_rect);
        }
        else if(flag[GAME_STATES_LEVEL_4] == 1)
        {
            char path[50] = "res/ARCADE_LEVEL_4.txt";

            HIGHSCORE(path,&temp,&points_rect);
        }
        else if(flag[GAME_STATES_LEVEL_5] == 1)
        {
            char path[50] = "res/ARCADE_LEVEL_5.txt";

            HIGHSCORE(path,&temp,&points_rect);
        }
        else
        {

        }
    }
    else if(flag[GAME_STATES_CAMPAIGN] == 1)
    {
        char path[50] = "res/CAMPAIGN.txt";

        HIGHSCORE(path,&temp,&points_rect);
    }
    else
    {
        char path[50] = "res/CLASSIC.txt";

        HIGHSCORE(path,&temp,&points_rect);
    }
}

void close()
{
    int i;

    for(i=0; i<SNAKE_TOTAL; i++)
    {
        SDL_DestroyTexture(Snake_Images[i]);
        Snake_Images[i] = NULL;
    }

    for(i=0; i<TRUE_TYPE_FONT_TOTAL; i++)
    {
        SDL_DestroyTexture(True_Type_Font[i]);
        True_Type_Font[i] = NULL;
    }

    SDL_DestroyTexture(image);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_CloseFont(Name_and_Score);

    Mix_FreeMusic(beat);
    for(i=0; i<SOUND_EFFECT_TOTAL; i++)
    {
        Mix_FreeChunk(Sound_Effects[i]);
        Sound_Effects[i] = NULL;
    }

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

