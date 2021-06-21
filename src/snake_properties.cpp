#include "snake_properties.h"

void SETTING_THE_DIRECTION()
{
    int i;

    for(i=0; i<=RANGE; i++)
    {
        if(i==0)
        {

            if(Elements.x_direction == 1)
            {
                Python[i].body.x += 30;
            }
            else if(Elements.x_direction == -1)
            {
                Python[i].body.x -=30;
            }
            else if(Elements.y_direction == 1)
            {
                Python[i].body.y -= 30;
            }
            else if(Elements.y_direction == -1)
            {
                Python[i].body.y += 30;
            }
        }
        else
        {
            if(Python[i-1].movement_past_state == MOVEMENT_UP)
            {
                Python[i].body.y -= 30;
            }
            else if(Python[i-1].movement_past_state == MOVEMENT_DOWN)
            {
                Python[i].body.y += 30;
            }
            else if(Python[i-1].movement_past_state == MOVEMENT_LEFT)
            {
                Python[i].body.x -= 30;
            }
            else if(Python[i-1].movement_past_state == MOVEMENT_RIGHT)
            {
                Python[i].body.x += 30;
            }
        }

    }

}


void SETTING_THE_WALL_PASSING_STATES()
{
    int i;

    if(Python[0].body.x >= SCREEN_WIDTH)
    {
        Python[0].body.x = 0;

        Python[0].wall_passing_present_state = PASS_RIGHT;
    }
    else if(Python[0].body.x + Python[0].body.w <= 0)
    {
        Python[0].body.x = SCREEN_WIDTH - Python[0].body.w;

        Python[0].wall_passing_present_state = PASS_LEFT;
    }
    else if(Python[0].body.y + Python[0].body.h <= 0)
    {
        Python[0].body.y = SCREEN_HEIGHT - Python[0].body.h;

        Python[0].wall_passing_present_state = PASS_UP;
    }
    else if(Python[0].body.y >=SCREEN_HEIGHT)
    {
        Python[0].body.y = 0;

        Python[0].wall_passing_present_state = PASS_DOWN;
    }
    else
    {
        Python[0].wall_passing_present_state = PASS_NONE;
    }


    for(i=1; i<=RANGE; i++)
    {
        Python[i].wall_passing_present_state = Python[i-1].wall_passing_past_state;

        Python[i-1].wall_passing_past_state = PASS_NONE;

        if(Python[i].wall_passing_present_state == PASS_UP)
        {
            Python[i].body.y = SCREEN_HEIGHT - Python[i].body.h;
        }
        else if(Python[i].wall_passing_present_state == PASS_DOWN)
        {
            Python[i].body.y = 0;
        }
        else if(Python[i].wall_passing_present_state == PASS_LEFT)
        {
            Python[i].body.x = SCREEN_WIDTH - Python[i].body.w;
        }

        else if(Python[i].wall_passing_present_state == PASS_RIGHT)
        {
            Python[i].body.x = 0;
        }
    }


    for(i = 0; i<=RANGE; i++)
    {
        if(Python[i].wall_passing_present_state != Python[i].wall_passing_past_state)
        {
            Python[i].wall_passing_past_state = Python[i].wall_passing_present_state;
            Python[i].wall_passing_present_state = PASS_NONE;
        }
    }
}


void SETTING_THE_MOVEMENTS()
{
    int i;

    for(i=1; i<=RANGE; i++)
    {
        Python[i].movement_present_state = Python[i-1].movement_past_state;

        Python[i-1].movement_past_state = Python[i-1].movement_present_state;
    }
}

void SETTING_THE_ROTATION_ANGLES()
{
    int i;

    for(i=1; i<=RANGE; i++)
    {
        if(i==Elements.snake_size)
        {
            Python[i].rotation_angle_present_state = Python[i-1].rotation_angle_present_state;
        }
        else
        {
            Python[i].rotation_angle_present_state = Python[i-1].rotation_angle_past_state;
        }

        Python[i-1].rotation_angle_past_state = Python[i-1].rotation_angle_present_state;
    }

}

void SETTING_THE_FLIP_STATES()
{
    int i;

    for(i=2; i<=RANGE; i++)
    {
        Python[i].flip_present_state = Python[i-1].flip_past_state;
        Python[i-1].flip_past_state = SDL_FLIP_NONE;
    }


}

