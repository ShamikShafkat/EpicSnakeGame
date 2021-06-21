#include "lib_dragon_poison.h"

void dragon_setup()
{
    dragon[0].body.x = SCREEN_WIDTH - 90;
    dragon[0].body.y = 30;
    dragon[0].body.w = 60;
    dragon[0].body.h = 90;

    dragon[0].fire.x = SCREEN_WIDTH - 90;
    dragon[0].fire.y = 30;
    dragon[0].fire.w = 30;
    dragon[0].fire.h = 30;

    dragon[0].life = 3;
    dragon[0].frame = 0;

    dragon[1].body.x = SCREEN_WIDTH - 90;
    dragon[1].body.y = 240;
    dragon[1].body.w = 60;
    dragon[1].body.h = 90;

    dragon[1].fire.x = SCREEN_WIDTH;
    dragon[1].fire.y = 240;
    dragon[1].fire.w = 30;
    dragon[1].fire.h = 30;

    dragon[1].life = 3;
    dragon[1].frame = 0;

    dragon[2].body.x = SCREEN_WIDTH - 90;
    dragon[2].body.y = 450;
    dragon[2].body.w = 60;
    dragon[2].body.h = 90;

    dragon[2].fire.x = SCREEN_WIDTH + 90;
    dragon[2].fire.y = 450;
    dragon[2].fire.w = 30;
    dragon[2].fire.h = 30;

    dragon[2].life = 3;
    dragon[2].frame = 0;
}

void dragon_mechanics()
{
    int i,j;
    bool smoke_or_not = false;

    for(i=0; i<3; i++)
    {
        if(dragon[i].life <= 0)
        {
            continue;
        }

        SDL_RenderCopy(renderer,Snake_Images[DRAGON],&dragon_image[dragon[i].frame++],&dragon[i].body);
        if(dragon[i].frame == 5)
        {
            dragon[i].frame = 0;
        }

        smoke_or_not = false;

        dragon[i].fire.x-=30;

        for(j=1; j<=Elements.snake_size; j++)
        {
            if(dragon[i].fire.x == Python[j].body.x && dragon[i].fire.y == Python[j].body.y)
            {
                smoke_or_not = true;

                if(j==1)
                {
                    if(Python[0].body.x - 30 == Python[j].body.x && Python[0].body.y == Python[j].body.y)
                    {
                        dragon[i].fire.x+=30;
                        smoke_or_not = false;
                    }

                }
                break;
            }
        }

        if(smoke_or_not)
        {
            SDL_RenderCopy(renderer,Snake_Images[SMOKE],NULL,&dragon[i].fire);
            dragon[i].fire.x = SCREEN_WIDTH;
            if(poison.venom_collected == false)
            {
                Elements.points -= 10;
                if(Elements.points<0)
                {
                    Elements.points = 0;
                }
                Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_OUCH],0);
                if(Elements.snake_size<=490)
                {
                    Elements.snake_size++;
                }
            }
            continue;
        }

        if(dragon[i].fire.x == 0)
        {
            SDL_RenderCopy(renderer,Snake_Images[SMOKE],NULL,&dragon[i].fire);
            dragon[i].fire.x = SCREEN_WIDTH;
        }
        if(dragon[i].fire.x <= SCREEN_WIDTH - 120)
        {
            SDL_RenderCopy(renderer,Snake_Images[DRAGON_FIRE],NULL,&dragon[i].fire);
        }
        if(dragon[i].fire.x == SCREEN_WIDTH - 120)
        {
           Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_FIRE],0);
        }
    }
}

void venom_mechanics()
{
    if(poison.x_vel == 1)
    {
        poison.poison_drop.x+=30;
        collision_of_venom();
    }
    else if(poison.x_vel == -1)
    {
        poison.poison_drop.x-=30;
        collision_of_venom();
    }
    else if(poison.y_vel == 1)
    {
        poison.poison_drop.y+=30;
        collision_of_venom();
    }
    else if(poison.y_vel == -1)
    {
        poison.poison_drop.y-=30;
        collision_of_venom();
    }

}

void collision_of_venom()
{
    int i;
    bool indicator;

    //collision between venom and brick
    for(i=0; i<7; i++)
    {
        indicator = COLLISION_DETECTION(poison.poison_drop,Bricks[LEVEL_BOSS].body[i]);
        if(indicator == false)
        {
            poison.venom = false;
            SDL_RenderCopy(renderer,Snake_Images[SMOKE],NULL,&poison.poison_drop);
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_BOOM],0);
            return ;
        }
    }

    //collision with snake body
    for(i=1; i<=Elements.snake_size; i++)
    {
        if(poison.poison_drop.x == Python[i].body.x && poison.poison_drop.y == Python[i].body.y)
        {
            poison.venom = false;
            SDL_RenderCopy(renderer,Snake_Images[SMOKE],NULL,&poison.poison_drop);
            Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_BOOM],0);
            return ;
        }
    }

    //collsion with dragon body
    for(i=0; i<3; i++)
    {
        if(dragon[i].life <= 0)
        {
            continue;
        }


        indicator = COLLISION_DETECTION(poison.poison_drop,dragon[i].body);
        if(indicator == false)
        {
            poison.venom = false;
            if(poison.poison_drop.x == dragon[i].body.x && poison.poison_drop.y == dragon[i].body.y)
            {
                dragon[i].life --;

                if(dragon[i].life == 0)
                {
                    Elements.points += 150;
                    Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_DEAD],0);
                }
                else
                {
                    Elements.points+=50;
                    Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_PAIN],0);
                }
                
                SDL_RenderCopy(renderer,Snake_Images[EXPLOSION],NULL,&poison.poison_drop);
            }
            else
            {
                Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_BOOM],0);
                SDL_RenderCopy(renderer,Snake_Images[SMOKE],NULL,&poison.poison_drop);
            }
            return ;
        }


    }

    //collision of fire and venom
    for(i=0; i<3; i++)
    {
        if(dragon[i].life <= 0)
        {
            continue;
        }

        if(dragon[i].fire.y == poison.poison_drop.y)
        {
            if(dragon[i].fire.x == poison.poison_drop.x)
            {
                poison.venom = false;
                SDL_RenderCopy(renderer,Snake_Images[SMOKE],NULL,&poison.poison_drop);
                Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_BOOM],0);
                break;
            }
            else if(dragon[i].fire.x + 30 == poison.poison_drop.x && poison.x_vel == 1)
            {
                poison.venom = false;
                SDL_RenderCopy(renderer,Snake_Images[SMOKE],NULL,&poison.poison_drop);
                Mix_PlayChannel(-1,Sound_Effects[SOUND_EFFECT_BOOM],0);
                break;
            }
        }
    }

    if(poison.venom == true)
    {
        SDL_RenderCopy(renderer,Snake_Images[POISON_DROP],NULL,&poison.poison_drop);
    }
}
