#include "libUI.h"

void MOUSE_HANDLING()
{
    int x,y;
    SDL_GetMouseState(&x,&y);

    if(flag[GAME_STATES_HOMESCREEN] == 0 && flag[GAME_STATES_START_THE_GAME] == 0)
    {
        if(x>=420 && x<=630 && y>=180 && y<= 240)
        {
            flag[GAME_STATES_HOMESCREEN] = 1;
            flag[GAME_STATES_MODES] = 1;
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=400 && x<=650 && y >= 250 && y<= 310)
        {
            flag[GAME_STATES_HOMESCREEN] = 1;
            flag[GAME_STATES_HIGHSCORE] = 1;
            flag[GAME_STATES_MODES] = 1;
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=425 && x<= 620 && y>= 325 && y<= 380)
        {
            flag[GAME_STATES_HOMESCREEN] = 1;
            flag[GAME_STATES_DIFFICULTY] = 1;
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=470 && x <= 580 && y>= 390 && y<= 450)
        {
            flag[GAME_STATES_HELP] = 1;
            flag[GAME_STATES_HOMESCREEN] = 1;
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=420 && x<=630 && y>= 465 && y<= 510)
        {
            Elements.stop = false;
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
    }
    else if(flag[GAME_STATES_MODES] == 1 && flag[GAME_STATES_START_THE_GAME] == 0)
    {
        if(x>=Modes[MODES_CLASSIC].x && x<= Modes[MODES_CLASSIC].x + Modes[MODES_CLASSIC].w  && y>= Modes[MODES_CLASSIC].y  && y<= Modes[MODES_CLASSIC].y + Modes[MODES_CLASSIC].h )
        {
            flag[GAME_STATES_CLASSIC] = 1;
            flag[GAME_STATES_MODES] = 0;

            if(flag[GAME_STATES_HIGHSCORE] != 1)
            {
                flag[GAME_STATES_START_THE_GAME] = 1;
                Mix_HaltMusic();
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=Modes[MODES_ARCADE].x && x<= Modes[MODES_ARCADE].x + Modes[MODES_ARCADE].w  && y>= Modes[MODES_ARCADE].y  && y<= Modes[MODES_ARCADE].y + Modes[MODES_ARCADE].h)
        {
            flag[GAME_STATES_ARCADE] = 1;
            flag[GAME_STATES_MODES] = 0;
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=Modes[MODES_CAMPAIGN].x && x<= Modes[MODES_CAMPAIGN].x + Modes[MODES_CAMPAIGN].w  && y>= Modes[MODES_CAMPAIGN].y  && y<= Modes[MODES_CAMPAIGN].y + Modes[MODES_CAMPAIGN].h )
        {
            flag[GAME_STATES_CAMPAIGN] = 1;
            flag[GAME_STATES_MODES] = 0;

            if(flag[GAME_STATES_HIGHSCORE] != 1)
            {
                flag[GAME_STATES_START_THE_GAME] = 1;
                flag[GAME_STATES_LEVEL_1] = 1;
                Mix_HaltMusic();
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=Modes[MODES_BACK].x && x<= Modes[MODES_BACK].x + Modes[MODES_BACK].w  && y>= Modes[MODES_BACK].y  && y<= Modes[MODES_BACK].y + Modes[MODES_BACK].h)
        {
            flag[GAME_STATES_HOMESCREEN] = 0;
            flag[GAME_STATES_MODES] = 0;
            flag[GAME_STATES_HIGHSCORE] = 0;
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
    }
    else if(flag[GAME_STATES_ARCADE] == 1 && flag[GAME_STATES_START_THE_GAME] == 0)
    {
        if(x>=Modes[MODES_LEVEL_1].x && x<= Modes[MODES_LEVEL_1].x + Modes[MODES_LEVEL_1].w  && y>= Modes[MODES_LEVEL_1].y  && y<= Modes[MODES_LEVEL_1].y + Modes[MODES_LEVEL_1].h )
        {
            flag[GAME_STATES_LEVEL_1] = 1;

            if(flag[GAME_STATES_HIGHSCORE] != 1)
            {
                flag[GAME_STATES_START_THE_GAME] = 1;
                Mix_HaltMusic();
            }
            else if(flag[GAME_STATES_HIGHSCORE] == 1)
            {
                flag[GAME_STATES_ARCADE] = 0;
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=Modes[MODES_LEVEL_2].x && x<= Modes[MODES_LEVEL_2].x + Modes[MODES_LEVEL_2].w  && y>= Modes[MODES_LEVEL_2].y  && y<= Modes[MODES_LEVEL_2].y + Modes[MODES_LEVEL_2].h)
        {
            flag[GAME_STATES_LEVEL_2] = 1;

            if(flag[GAME_STATES_HIGHSCORE] != 1)
            {
                flag[GAME_STATES_START_THE_GAME] = 1;
                Mix_HaltMusic();
            }
            else if(flag[GAME_STATES_HIGHSCORE] == 1)
            {
                flag[GAME_STATES_ARCADE] = 0;
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=Modes[MODES_LEVEL_3].x && x<= Modes[MODES_LEVEL_3].x + Modes[MODES_LEVEL_3].w  && y>= Modes[MODES_LEVEL_3].y  && y<= Modes[MODES_LEVEL_3].y + Modes[MODES_LEVEL_3].h)
        {
            flag[GAME_STATES_LEVEL_3] = 1;

            if(flag[GAME_STATES_HIGHSCORE] != 1)
            {
                flag[GAME_STATES_START_THE_GAME] = 1;
                Mix_HaltMusic();
            }
            else if(flag[GAME_STATES_HIGHSCORE] == 1)
            {
                flag[GAME_STATES_ARCADE] = 0;
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=Modes[MODES_LEVEL_4].x && x<= Modes[MODES_LEVEL_4].x + Modes[MODES_LEVEL_4].w  && y>= Modes[MODES_LEVEL_4].y  && y<= Modes[MODES_LEVEL_4].y + Modes[MODES_LEVEL_4].h)
        {
            flag[GAME_STATES_LEVEL_4] = 1;

            if(flag[GAME_STATES_HIGHSCORE] != 1)
            {
                flag[GAME_STATES_START_THE_GAME] = 1;
                Mix_HaltMusic();
            }
            else if(flag[GAME_STATES_HIGHSCORE] == 1)
            {
                flag[GAME_STATES_ARCADE] = 0;
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=Modes[MODES_LEVEL_5].x && x<= Modes[MODES_LEVEL_5].x + Modes[MODES_LEVEL_5].w  && y>= Modes[MODES_LEVEL_5].y  && y<= Modes[MODES_LEVEL_5].y + Modes[MODES_LEVEL_5].h)
        {
            flag[GAME_STATES_LEVEL_5] = 1;

            if(flag[GAME_STATES_HIGHSCORE] != 1)
            {
                flag[GAME_STATES_START_THE_GAME] = 1;
                Mix_HaltMusic();
            }
            else if(flag[GAME_STATES_HIGHSCORE] == 1)
            {
                flag[GAME_STATES_ARCADE] = 0;
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=Modes[MODES_BACK].x && x<= Modes[MODES_BACK].x + Modes[MODES_BACK].w  && y>= Modes[MODES_BACK].y  && y<= Modes[MODES_BACK].y + Modes[MODES_BACK].h)
        {
            flag[GAME_STATES_ARCADE] = 0;
            flag[GAME_STATES_MODES] = 1;
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }

    }
    else if((flag[GAME_STATES_DIFFICULTY] == 1 || flag[GAME_STATES_HIGHSCORE] == 1) && flag[GAME_STATES_START_THE_GAME] == 0)
    {
        if(x>=Modes[MODES_EASY].x && x<= Modes[MODES_EASY].x + Modes[MODES_EASY].w  && y>= Modes[MODES_EASY].y  && y<= Modes[MODES_EASY].y + Modes[MODES_EASY].h)
        {
            if(flag[GAME_STATES_DIFFICULTY] == 1)
            {
                SETTING_DIFFICULTY(Easy);
            }
            else if(flag[GAME_STATES_HIGHSCORE] == 1)
            {
                flag[GAME_STATES_SHOW_HIGHSCORE] = 1;
                flag[GAME_STATES_HIGHSCORE] = 0;
                flag[GAME_STATES_EASY] = 1;
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);

        }
        else if(x>=Modes[MODES_MEDIUM].x && x<= Modes[MODES_MEDIUM].x + Modes[MODES_MEDIUM].w  && y>= Modes[MODES_MEDIUM].y  && y<= Modes[MODES_MEDIUM].y + Modes[MODES_MEDIUM].h)
        {
            if(flag[GAME_STATES_DIFFICULTY] == 1)
            {
                SETTING_DIFFICULTY(Medium);
            }
            else if(flag[GAME_STATES_HIGHSCORE] == 1)
            {
                flag[GAME_STATES_SHOW_HIGHSCORE] = 1;
                flag[GAME_STATES_HIGHSCORE] = 0;
                flag[GAME_STATES_MEDIUM] = 1;
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=Modes[MODES_HARD].x && x<= Modes[MODES_HARD].x + Modes[MODES_HARD].w  && y>= Modes[MODES_HARD].y  && y<= Modes[MODES_HARD].y + Modes[MODES_HARD].h)
        {
            if(flag[GAME_STATES_DIFFICULTY] == 1)
            {
                SETTING_DIFFICULTY(Hard);
            }
            else if(flag[GAME_STATES_HIGHSCORE] == 1)
            {
                flag[GAME_STATES_SHOW_HIGHSCORE] = 1;
                flag[GAME_STATES_HIGHSCORE] = 0;
                flag[GAME_STATES_HARD] = 1;
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
        else if(x>=Modes[MODES_BACK].x && x<= Modes[MODES_BACK].x + Modes[MODES_BACK].w  && y>= Modes[MODES_BACK].y  && y<= Modes[MODES_BACK].y + Modes[MODES_BACK].h)
        {
            if(flag[GAME_STATES_DIFFICULTY] == 1)
            {
                flag[GAME_STATES_DIFFICULTY] = 0;
                flag[GAME_STATES_HOMESCREEN] = 0;
            }
            else if(flag[GAME_STATES_HIGHSCORE] == 1)
            {
                int i,j;
                i = GAME_STATES_LEVEL_1;
                for(j = i; j<= i+4 ; j++)
                {
                    if(flag[j] == 1)
                    {
                        flag[GAME_STATES_ARCADE] = 1;
                        flag[j] = 0;
                        break;
                    }
                }

                if(j>GAME_STATES_LEVEL_5)
                {
                    flag[GAME_STATES_CLASSIC] = 0;
                    flag[GAME_STATES_CAMPAIGN] = 0;
                    flag[GAME_STATES_MODES] = 1;
                }
            }
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }

    }
    else if(flag[GAME_STATES_SHOW_HIGHSCORE] == 1 && flag[GAME_STATES_START_THE_GAME] == 0)
    {
        if(x>=Modes[MODES_BACK].x && x<= Modes[MODES_BACK].x + Modes[MODES_BACK].w  && y>= Modes[MODES_BACK].y  && y<= Modes[MODES_BACK].y + Modes[MODES_BACK].h)
        {
            flag[GAME_STATES_SHOW_HIGHSCORE] = 0;
            flag[GAME_STATES_HIGHSCORE] = 1;
            flag[GAME_STATES_EASY] = 0;
            flag[GAME_STATES_MEDIUM] = 0;
            flag[GAME_STATES_HARD] = 0;
        }
        Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
    }
    else if(flag[GAME_STATES_HELP] == 1 && flag[GAME_STATES_START_THE_GAME] == 0)
    {
        if(x>=Modes[MODES_BACK].x && x<= Modes[MODES_BACK].x + Modes[MODES_BACK].w  && y>= Modes[MODES_BACK].y  && y<= Modes[MODES_BACK].y + Modes[MODES_BACK].h)
        {
            flag[GAME_STATES_HELP] = 0;
            flag[GAME_STATES_HOMESCREEN] = 0;
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_CLICK],0);
        }
   
    }
}

void GAME_LOOP()
{
    SDL_Event event;

    for(; SDL_PollEvent(&event)!=0;)
    {
        if(event.type == SDL_QUIT)
        {
            Elements.stop = false;
        }
        else if(event.type == SDL_KEYDOWN && flag[GAME_STATES_START_THE_GAME] == 1)
        {
            if(event.key.keysym.sym == SDLK_UP && Elements.pause == false)
            {
                if(Elements.y_direction == 0)
                {
                    if(Elements.x_direction == 1)
                    {
                        Python[0].rotation_angle_present_state = -90;
                        Python[1].flip_present_state = SDL_FLIP_HORIZONTAL;
                    }
                    else
                    {
                        Python[0].rotation_angle_present_state = -90;
                        Python[1].flip_present_state = SDL_FLIP_NONE;
                    }
                    Elements.y_direction = 1;
                    Elements.x_direction = 0;

                    Python[0].movement_present_state = MOVEMENT_UP;
                }

            }
            else if(event.key.keysym.sym == SDLK_DOWN && Elements.pause == false)
            {

                if(Elements.y_direction == 0)
                {
                    if(Elements.x_direction == 1)
                    {
                        Python[0].rotation_angle_present_state = 90;
                        Python[1].flip_present_state = (SDL_RendererFlip)(SDL_FLIP_VERTICAL | SDL_FLIP_HORIZONTAL);
                    }
                    else
                    {
                        Python[0].rotation_angle_present_state = 90;
                        Python[1].flip_present_state = SDL_FLIP_VERTICAL;
                    }

                    Elements.y_direction = -1;
                    Elements.x_direction = 0;

                    Python[0].movement_present_state = MOVEMENT_DOWN;
                }
            }
            else if(event.key.keysym.sym == SDLK_LEFT && Elements.pause == false)
            {

                if(Elements.x_direction == 0)
                {
                    if(Elements.y_direction == 1)
                    {
                        Python[0].rotation_angle_present_state = 180;
                        Python[1].flip_present_state =(SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
                    }
                    else
                    {
                        Python[0].rotation_angle_present_state = 180;
                        Python[1].flip_present_state = SDL_FLIP_HORIZONTAL;
                    }

                    Elements.x_direction = -1;
                    Elements.y_direction = 0;

                    Python[0].movement_present_state = MOVEMENT_LEFT;
                }
            }
            else if(event.key.keysym.sym == SDLK_RIGHT && Elements.pause == false)
            {
                if(Elements.x_direction == 0)
                {
                    if(Elements.y_direction == 1)
                    {
                        Python[0].rotation_angle_present_state = 0;
                        Python[1].flip_present_state = SDL_FLIP_VERTICAL;
                    }
                    else
                    {
                        Python[0].rotation_angle_present_state = 0;
                        Python[1].flip_present_state = SDL_FLIP_NONE;
                    }

                    Elements.x_direction = 1;
                    Elements.y_direction = 0;

                    Python[0].movement_present_state = MOVEMENT_RIGHT;
                }
            }
            else if(event.key.keysym.sym == SDLK_s && Elements.pause == false && poison.venom == false && poison.venom_collected == true)
            {
                Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_HISS],0);
                poison.venom = true;
                if(Python[0].movement_present_state == MOVEMENT_RIGHT)
                {
                    poison.poison_drop.x = Python[0].body.x + 30;
                    poison.poison_drop.y = Python[0].body.y;
                    poison.x_vel = 1;
                    poison.y_vel = 0;
                }
                else if(Python[0].movement_present_state == MOVEMENT_LEFT)
                {
                    poison.poison_drop.x = Python[0].body.x - 30;
                    poison.poison_drop.y = Python[0].body.y ;
                    poison.x_vel = -1;
                    poison.y_vel = 0;
                }
                else if(Python[0].movement_present_state == MOVEMENT_DOWN)
                {
                    poison.poison_drop.x = Python[0].body.x;
                    poison.poison_drop.y = Python[0].body.y + 30;
                    poison.x_vel = 0;
                    poison.y_vel = 1;
                }
                else if(Python[0].movement_present_state == MOVEMENT_UP)
                {
                    poison.poison_drop.x = Python[0].body.x;
                    poison.poison_drop.y = Python[0].body.y - 30;
                    poison.x_vel = 0;
                    poison.y_vel = -1;
                }
                else
                {

                }
            }
            else if(event.key.keysym.sym == SDLK_SPACE)
            {
                if(Elements.pause == true)
                {
                    Elements.pause = false;
                }
                else
                {
                    Elements.pause = true;
                }
            }

        }
        else if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            MOUSE_HANDLING();
        }
    }
}

