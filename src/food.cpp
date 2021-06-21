#include "food.h"

SDL_Rect FOOD_QUADRANT()
{
    int temp;
    SDL_Rect temp_food;

    temp = rand();
    temp_food.x = temp % SCREEN_WIDTH - (temp % SCREEN_WIDTH) % 30;

    temp = rand();
    temp_food.y = temp % SCREEN_HEIGHT - (temp % SCREEN_HEIGHT) % 30;

    temp_food.w = Python[0].body.w;
    temp_food.h = Python[0].body.h;

    return temp_food;
}

SDL_Rect CREATING_FOOD()
{
    SDL_Rect temp_food;

    for(;;)
    {
        int i;
        bool control = true;

        temp_food = FOOD_QUADRANT();

        for(i=0; i<=Elements.snake_size; i++)
        {
            if(temp_food.x == Python[i].body.x && temp_food.y == Python[i].body.y )
            {
                temp_food = FOOD_QUADRANT();
                i = -1;
            }
        }

        if(flag[GAME_STATES_LEVEL_1] == 1)
        {
            for(i=0; i<3; i++)
            {
                control = COLLISION_DETECTION(temp_food,Bricks[LEVEL_ONE].body[i]);
                if(control == false)
                {
                    break;
                }
            }

            if(i!=3)
            {
                continue;
            }
        }
        else if(flag[GAME_STATES_LEVEL_2] == 1)
        {
            for(i=0; i<10; i++)
            {
                control = COLLISION_DETECTION(temp_food,Bricks[LEVEL_TWO].body[i]);
                if(control == false)
                {
                    break;
                }
            }

            if(i!=10)
            {
                continue;
            }
        }
        else if(flag[GAME_STATES_LEVEL_3] == 1)
        {
            for(i=0; i<5; i++)
            {
                control = COLLISION_DETECTION(temp_food,Bricks[LEVEL_THREE].body[i]);
                if(control == false)
                {
                    break;
                }
            }

            if(i!=5)
            {
                continue;
            }
        }
        else if(flag[GAME_STATES_LEVEL_4] == 1)
        {
            for(i=0; i<8; i++)
            {
                control = COLLISION_DETECTION(temp_food,Bricks[LEVEL_FOUR].body[i]);
                if(control == false)
                {
                    break;
                }
            }

            if(i!=8)
            {
                continue;
            }
        }
        else if(flag[GAME_STATES_LEVEL_5] == 1)
        {
            for(i=0; i<8; i++)
            {
                control = COLLISION_DETECTION(temp_food,Bricks[LEVEL_FIVE].body[i]);
                if(control == false)
                {
                    break;
                }
            }

            if(i!=8)
            {
                continue;
            }
        }
        else if(flag[GAME_STATES_CAMPAIGN_BOSS_LEVEL] == 1)
        {
            //in the bricks
            for(i=0; i<7; i++)
            {
                control = COLLISION_DETECTION(temp_food,Bricks[LEVEL_BOSS].body[i]);
                if(control == false)
                {
                    break;
                }
            }

            if(i!=7)
            {
                continue;
            }

            //inside dragon
            for(i=0; i<3; i++)
            {
                if(dragon[i].life <= 0)
                {
                    continue;
                }

                control = COLLISION_DETECTION(temp_food,dragon[i].body);
                if(control == false)
                {
                    break;
                }
            }
            if(i!=3)
            {
                continue;
            }

            //same as poison bottle
            if(poison.bottle_rend)
            {
                if(temp_food.x == poison.bottle.x && temp_food.y == poison.bottle.y)
                {
                    continue;
                }
            }

        }

        if(temp_food.x == food.x && temp_food.y == food.y)
        {
            continue;
        }

        if(Elements.bonus_eat)
        {
            if(temp_food.x == bonus_food.x && temp_food.y == bonus_food.y)
            {
                continue;
            }
        }

        break;

    }

    return temp_food;
}
