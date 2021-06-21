#include "liblife.h"

//returns false when collision detected 
bool COLLISION_DETECTION(SDL_Rect target,SDL_Rect obstacle)
{
    if(target.x>=obstacle.x && target.x + target.w<=obstacle.x + obstacle.w)
    {
        if(target.y>=obstacle.y && target.y + target.h<=obstacle.y + obstacle.h)
        {
            return false;
        }
    }
    return true;
}



void ALIVE_OR_DEAD()
{
    int i;

    for(i=1; i<=Elements.snake_size; i++)
    {
        Elements.alive = COLLISION_DETECTION(Python[0].body,Python[i].body);
        if(Elements.alive == false)
        {
            return ;
        }
    }

    if(flag[GAME_STATES_LEVEL_1] == 1)
    {
        for(i=0; i<3; i++)
        {
            Elements.alive = COLLISION_DETECTION(Python[0].body,Bricks[LEVEL_ONE].body[i]);
            if(Elements.alive == false)
            {
                return ;
            }
        }
    }
    else if(flag[GAME_STATES_LEVEL_2] == 1)
    {
        for(i=0; i<10; i++)
        {
            Elements.alive = COLLISION_DETECTION(Python[0].body,Bricks[LEVEL_TWO].body[i]);
            if(Elements.alive == false)
            {
                return ;
            }
        }
    }
    else if(flag[GAME_STATES_LEVEL_3] == 1)
    {
        for(i=0; i<5; i++)
        {
            Elements.alive = COLLISION_DETECTION(Python[0].body,Bricks[LEVEL_THREE].body[i]);
            if(Elements.alive == false)
            {
                return ;
            }
        }
    }
    else if(flag[GAME_STATES_LEVEL_4] == 1)
    {
        for(i=0; i<8; i++)
        {
            Elements.alive = COLLISION_DETECTION(Python[0].body,Bricks[LEVEL_FOUR].body[i]);
            if(Elements.alive == false)
            {
                return ;
            }
        }
    }
    else if(flag[GAME_STATES_LEVEL_5] == 1)
    {
        for(i=0; i<8; i++)
        {
            Elements.alive = COLLISION_DETECTION(Python[0].body,Bricks[LEVEL_FIVE].body[i]);
            if(Elements.alive == false)
            {
                return ;
            }
        }
    }
    else if(flag[GAME_STATES_CAMPAIGN_BOSS_LEVEL] == 1)
    {
        for(i=0; i<7; i++)
        {
            Elements.alive = COLLISION_DETECTION(Python[0].body,Bricks[LEVEL_BOSS].body[i]);
            if(Elements.alive == false)
            {
                return ;
            }
        }

        //collision with dragon
        for(i=0; i<3; i++)
        {
            if(dragon[i].life <= 0)
            {
                continue;
            }

            Elements.alive = COLLISION_DETECTION(Python[0].body,dragon[i].body);
            if(Elements.alive == false)
            {
                return ;
            }
        }

        //collision with fire
        for(i=0; i<3; i++)
        {
            if(dragon[i].life <= 0)
            {
                continue;
            }

            if(Python[0].body.x == dragon[i].fire.x && Python[0].body.y == dragon[i].fire.y)
            {
                Elements.alive = false;
                break;
            }
        }
    }

}
