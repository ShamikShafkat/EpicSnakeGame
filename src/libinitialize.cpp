#include "libinitialize.h"

SDL_Window *window = NULL;
SDL_Surface *surface = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *image = NULL;
SDL_Texture *convert = NULL;
SDL_Texture *Snake_Images[SNAKE_TOTAL];
SDL_Texture *True_Type_Font[TRUE_TYPE_FONT_TOTAL];
TTF_Font *Name_and_Score = NULL;
Mix_Music *beat = NULL;
Mix_Chunk *Sound_Effects[SOUND_EFFECT_TOTAL];

SDL_Rect head,tail,turn,body,food,fruit,bonus_food,dragon_fire,dragon_image[5];
SDL_Rect Game_points = {460,0,100,50};
SDL_Rect Modes[MODES_TOTAL];

Game_Elements Elements;
My_Snake Python[510];
int flag[GAME_STATES_TOTAL];
Wall Bricks[LEVEL_TOTAL];
enemy dragon[3];
VENOM poison;

bool create_window()
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)<0)
    {
        printf("ERROR IN INITIALIZATION %s\n",SDL_GetError());
        return false;
    }
    else
    {
        window = SDL_CreateWindow("EPIC SNAKE GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

        if(window == NULL)
        {
            printf("ERROR IN CREATING WINDOW %s\n",SDL_GetError());
            return false;
        }

        else
        {
            if(!(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1")))
            {
                printf("ERROR IN LINEAR TEXTURE %s\n",SDL_GetError());
                return false;
            }
            else
            {
                renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

                if(renderer == NULL)
                {
                    printf("ERROR IN RENDERING WINDOW %s\n",SDL_GetError());
                    return false;
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);

                    if(!(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)))
                    {
                        printf("ERROR IN INITIALIZING IMAGE %s\n",SDL_GetError());
                        return false;
                    }
                    else
                    {
                        if(TTF_Init()==-1)
                        {
                            printf("CANNOT INITIALIAZE TTF %s\n",TTF_GetError());
                            return false;
                        }
                        else
                        {
                            if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
                            {
                                printf("CANNOT INITIALIAZE MIXER %s\n",Mix_GetError());
                                return false;
                            }
                            else
                            {
                                return true;
                            }
                        }
                    }
                }


            }
        }
    }
}



bool load_media()
{
    char ch[100][100] = {"PNG IMAGES/green_snake.png","PNG IMAGES/gameover.jpeg","PNG IMAGES/snake_background.png",
                         "PNG IMAGES/brick.jpg","PNG IMAGES/snake bg.png","PNG IMAGES/purple_grape.jpg","PNG IMAGES/dragon.png","PNG IMAGES/dragon fire.png",
                         "PNG IMAGES/smoke.png","PNG IMAGES/poison.png","PNG IMAGES/poison drop.png","PNG IMAGES/explosion.png",
                         "PNG IMAGES/sign.png","PNG IMAGES/Help.png"};

    Snake_Images[SNAKE_IMAGE] = loadtexture(ch[0],1);
    if(Snake_Images[SNAKE_IMAGE] == NULL)
    {
        printf("ERROR IN LOADING SNAKE SPRITE SHEET %s\n",SDL_GetError());
        return false;
    }

    Snake_Images[SNAKE_GAMEOVER] = loadtexture(ch[1],1);
    if(Snake_Images[SNAKE_GAMEOVER] == NULL)
    {
        printf("ERROR IN LOADING GAMEOVER IMAGE %s\n",SDL_GetError());
        return false;
    }

    Snake_Images[SNAKE_HOMESCREEN] = loadtexture(ch[2],0);
    if(Snake_Images[SNAKE_HOMESCREEN] == NULL)
    {
        printf("ERROR IN LOADING SNAKE HOMESCREEN %s\n",SDL_GetError());
        return false;
    }

    Snake_Images[SNAKE_BRICK] = loadtexture(ch[3],0);
    if(Snake_Images[SNAKE_BRICK] == NULL)
    {
        printf("ERROR IN LOADING BRICK IMAGE %s\n",SDL_GetError());
        return false;
    }


    Snake_Images[SNAKE_BG] = loadtexture(ch[4],0);
    if(Snake_Images[SNAKE_BG] == NULL)
    {
        printf("ERROR IN LOADING SNAKE BG %s\n",SDL_GetError());
        return false;
    }

    Snake_Images[SNAKE_BONUS_FOOD] = loadtexture(ch[5],1);
    if(Snake_Images[SNAKE_BONUS_FOOD] == NULL)
    {
        printf("ERROR IN LOADING SNAKE BONUS FOOD %s\n",SDL_GetError());
        return false;
    }

    Snake_Images[DRAGON] = loadtexture(ch[6],0);
    if(Snake_Images[DRAGON] == NULL)
    {
        printf("ERROR IN LOADING DRAGON IMAGE %s/n",SDL_GetError());
        return false;
    }

    Snake_Images[DRAGON_FIRE] = loadtexture(ch[7],0);
    if(Snake_Images[DRAGON_FIRE] == NULL)
    {
        printf("ERROR IN LOADING DRAGON_FIRE IMAGE %s/n",SDL_GetError());
        return false;
    }

    Snake_Images[SMOKE] = loadtexture(ch[8],0);
    if(Snake_Images[SMOKE] == NULL)
    {
        printf("ERROR IN LOADING SMOKE IMAGE %s/n",SDL_GetError());
        return false;
    }

    Snake_Images[POISON] = loadtexture(ch[9],0);
    if(Snake_Images[POISON] == NULL)
    {
        printf("ERROR IN LOADING POISON IMAGE %s/n",SDL_GetError());
        return false;
    }

    Snake_Images[POISON_DROP] = loadtexture(ch[10],0);
    if(Snake_Images[POISON_DROP] == NULL)
    {
        printf("ERROR IN LOADING POISON_DROP IMAGE %s/n",SDL_GetError());
        return false;
    }

    Snake_Images[EXPLOSION] = loadtexture(ch[11],0);
    if(Snake_Images[EXPLOSION] == NULL)
    {
        printf("ERROR IN LOADING EXPLOSION IMAGE %s/n",SDL_GetError());
        return false;
    }

    Snake_Images[RIGHT_SIGN] = loadtexture(ch[12],0);
    if(Snake_Images[RIGHT_SIGN] == NULL)
    {
        printf("ERROR IN LOADING RIGHT SIGN IMAGE %s/n",SDL_GetError());
        return false;
    }

    Snake_Images[HELP] = loadtexture(ch[13],0);
    if(Snake_Images[HELP] == NULL)
    {
        printf("ERROR IN LOADING HELP IMAGE %s/n",SDL_GetError());
        return false;
    }

    Name_and_Score = TTF_OpenFont("res/TTF FILE.ttf",72);
    if(Name_and_Score == NULL)
    {
        printf("CANNOT OPEN TTF FILE %s\n",TTF_GetError());
        return false;
    }

    beat = Mix_LoadMUS("res/menu.mp3");
    if(beat == NULL)
    {
        printf("CANNOT LOAD MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_EAT] = Mix_LoadWAV("res/EAT.mp3");
    if(Sound_Effects[SOUND_EFFECT_EAT] == NULL)
    {
        printf("CANNOT LOAD EAT MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_CRASH] = Mix_LoadWAV("res/DIE.ogg");
    if(Sound_Effects[SOUND_EFFECT_CRASH] == NULL)
    {
        printf("CANNOT LOAD CRASH MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_HISS] = Mix_LoadWAV("res/HISS.mp3");
    if(Sound_Effects[SOUND_EFFECT_HISS] == NULL)
    {
        printf("CANNOT LOAD HISS MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_OUCH] = Mix_LoadWAV("res/ouch2.mp3");
    if(Sound_Effects[SOUND_EFFECT_OUCH] == NULL)
    {
        printf("CANNOT LOAD OUCH MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_CLICK] = Mix_LoadWAV("res/click.wav");
    if(Sound_Effects[SOUND_EFFECT_CLICK] == NULL)
    {
        printf("CANNOT LOAD CLICK MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_YAY] = Mix_LoadWAV("res/HURRAY.mp3");
    if(Sound_Effects[SOUND_EFFECT_YAY] == NULL)
    {
        printf("CANNOT LOAD YAY MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_PAIN] = Mix_LoadWAV("res/dragon_pain.mp3");
    if(Sound_Effects[SOUND_EFFECT_PAIN] == NULL)
    {
        printf("CANNOT LOAD PAIN MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_DEAD] = Mix_LoadWAV("res/dragon_dead.mp3");
    if(Sound_Effects[SOUND_EFFECT_DEAD] == NULL)
    {
        printf("CANNOT LOAD DEAD MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_BOOM] = Mix_LoadWAV("res/BOOM.mp3");
    if(Sound_Effects[SOUND_EFFECT_BOOM] == NULL)
    {
        printf("CANNOT LOAD BOOM MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_BUMP] = Mix_LoadWAV("res/BUMP.mp3");
    if(Sound_Effects[SOUND_EFFECT_BUMP] == NULL)
    {
        printf("CANNOT LOAD BUMP MUSIC %s\n",Mix_GetError());
        return false;
    }

    Sound_Effects[SOUND_EFFECT_FIRE] = Mix_LoadWAV("res/dragon_fire.mp3");
    if(Sound_Effects[SOUND_EFFECT_BUMP] == NULL)
    {
        printf("CANNOT LOAD FIRE MUSIC %s\n",Mix_GetError());
        return false;
    }

    return true;

}

SDL_Texture *loadtexture(char path[],int colorkey_black)
{
    SDL_Surface *temp = NULL ;

    temp = IMG_Load(path);

    if(temp == NULL)
    {
        printf("Cannot load image %s\n",SDL_GetError());
    }
    else
    {
        if(colorkey_black==1)
        {
            SDL_SetColorKey(temp,true,SDL_MapRGB(temp->format,0,0,0));
        }

        image = SDL_CreateTextureFromSurface(renderer,temp);


        if(image == NULL)
        {
            printf("Cannot convert surface to texture %s\n",SDL_GetError());
        }
        else
        {

        }
    }

    SDL_FreeSurface(temp);

    return image;

}

bool loadttf()
{
    char ch[100][100] = {"CLASSIC","ARCADE","CAMPAIGN","BACK","YOUR SCORE","HIGH SCORE !","SCORE","PUT YOUR NAME BELOW","LEVEL 1","LEVEL 2",
                         "LEVEL 3","LEVEL 4","LEVEL 5","EASY","MEDIUM","HARD","LEVEL COMPLETED !","NAME","SL.","SCORE","CAMPAIGN COMPLETED !"
                        };

    True_Type_Font[TRUE_TYPE_FONT_CLASSIC] = MAKETTF(ch[0],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_CLASSIC] == NULL)
    {
        printf("ERROR IN LOADING TRUE TYPE FONT %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_ARCADE] = MAKETTF(ch[1],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_ARCADE] == NULL)
    {
        printf("ERROR IN LOADING TRUE TYPE FONT %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_CAMPAIGN] = MAKETTF(ch[2],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_CAMPAIGN] == NULL)
    {
        printf("ERROR IN LOADING TRUE TYPE FONT %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_BACK] = MAKETTF(ch[3],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_BACK] == NULL)
    {
        printf("ERROR IN LOADING TRUE TYPE FONT %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_SCORE] = MAKETTF(ch[4],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_SCORE] == NULL)
    {
        printf("ERROR IN LOADING TRUE TYPE FONT %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_HIGHSCORE] = MAKETTF(ch[5],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_HIGHSCORE] == NULL)
    {
        printf("ERROR IN LOADING TRUE TYPE FONT %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_GAME_SCORE] = MAKETTF(ch[6],1,false);
    if(True_Type_Font[TRUE_TYPE_FONT_GAME_SCORE] == NULL)
    {
        printf("ERROR IN LOADING TRUE TYPE FONT %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_PUTNAME] = MAKETTF(ch[7],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_PUTNAME] == NULL)
    {
        printf("ERROR IN LOADING NAME TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_LEVEL_1] = MAKETTF(ch[8],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_LEVEL_1] == NULL)
    {
        printf("ERROR IN LOADING LEVEL_1 TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_LEVEL_2] = MAKETTF(ch[9],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_LEVEL_2] == NULL)
    {
        printf("ERROR IN LOADING LEVEL_2 TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_LEVEL_3] = MAKETTF(ch[10],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_LEVEL_3] == NULL)
    {
        printf("ERROR IN LOADING LEVEL_3 TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_LEVEL_4] = MAKETTF(ch[11],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_LEVEL_4] == NULL)
    {
        printf("ERROR IN LOADING LEVEL_4 TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_LEVEL_5] = MAKETTF(ch[12],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_LEVEL_5] == NULL)
    {
        printf("ERROR IN LOADING LEVEL_5 TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_EASY] = MAKETTF(ch[13],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_EASY] == NULL)
    {
        printf("ERROR IN LOADING EASY TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_MEDIUM] = MAKETTF(ch[14],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_MEDIUM] == NULL)
    {
        printf("ERROR IN LOADING MEDIUM TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_HARD] = MAKETTF(ch[15],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_HARD] == NULL)
    {
        printf("ERROR IN LOADING HARD TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_LEVEL_COMPLETED] = MAKETTF(ch[16],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_LEVEL_COMPLETED] == NULL)
    {
        printf("ERROR IN LOADING GARBAGE TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_NAME] = MAKETTF(ch[17],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_NAME] == NULL)
    {
        printf("ERROR IN LOADING NAME TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_SL] = MAKETTF(ch[18],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_SL] == NULL)
    {
        printf("ERROR IN LOADING SL TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_SCORE2] = MAKETTF(ch[19],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_SCORE2] == NULL)
    {
        printf("ERROR IN LOADING SCORE2 TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_CAMPAIGN_COMPLETED] = MAKETTF(ch[20],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_CAMPAIGN_COMPLETED] == NULL)
    {
        printf("ERROR IN LOADING CAMPAIGN COMPLETED TTF %s\n",SDL_GetError());
        return false;
    }

    True_Type_Font[TRUE_TYPE_FONT_GARBAGE] = MAKETTF(ch[0],0,false);
    if(True_Type_Font[TRUE_TYPE_FONT_GARBAGE] == NULL)
    {
        printf("ERROR IN LOADING GARBAGE TTF %s\n",SDL_GetError());
        return false;
    }

    return true;

}

SDL_Texture* MAKETTF(char path[],int colour,bool Make_Null)
{
    SDL_Surface *temp = NULL;

    if(Make_Null == true)
    {
        if(convert!=NULL)
        {
            SDL_DestroyTexture(convert);
            convert = NULL;
        }
    }

    SDL_Color font_color1 = {0,0,0};
    SDL_Color font_color2 = {255,255,0};

    if(colour==0)
    {
        temp = TTF_RenderText_Solid(Name_and_Score,path,font_color1);
    }
    else
    {
        temp = TTF_RenderText_Solid(Name_and_Score,path,font_color2);
    }

    if(temp == NULL)
    {
        printf("CANNOT CREATE SURFACE FOR TTF %s\n",SDL_GetError());
    }
    else
    {
        convert = SDL_CreateTextureFromSurface(renderer,temp);
        if(convert == NULL)
        {
            printf("CANNOT CREATE TEXTURE FOR TTF %s\n",SDL_GetError());
        }
    }

    SDL_FreeSurface(temp);

    return convert;
}

void INITIALIZER()
{
    int width,height;

    image = Snake_Images[SNAKE_IMAGE];
    SDL_QueryTexture(image,NULL,NULL,&width,&height);

    head.x = width - (width/5)*1 + 5;
    head.y = 0;
    head.w = width/5 - 5;
    head.h = (height/4);

    tail.x = width - (width/5)*1;
    tail.y = height - (height/4) * 2;
    tail.w = width / 5;
    tail.h = height / 4;

    body.x = width - (width/5)*4;
    body.y = 0;
    body.w = width / 5;
    body.h = height / 4;

    turn.x = 0;
    turn.y = height - (height/4) * 3;
    turn.w = width / 5;
    turn.h = height / 4;

    fruit.x = 0;
    fruit.y = height - (height/4) * 1;
    fruit.w = width/5;
    fruit.h = height / 4;

    SDL_QueryTexture(Snake_Images[DRAGON],NULL,NULL,&width,&height);

    dragon_image[0].x = 0;
    dragon_image[0].y = 0;
    dragon_image[0].w = width/5;
    dragon_image[0].h = height/4;

    dragon_image[1].x = width - (width/5)*4;
    dragon_image[1].y = 0;
    dragon_image[1].w = width/5;
    dragon_image[1].h = height/4;

    dragon_image[2].x = width - (width/5)*3;
    dragon_image[2].y = 0;
    dragon_image[2].w = width/5;
    dragon_image[2].h = height/4;

    dragon_image[3].x = width - (width/5)*2;
    dragon_image[3].y = 0;
    dragon_image[3].w = width/5;
    dragon_image[3].h = height/4;

    dragon_image[4].x = width - (width/5)*1;
    dragon_image[4].y = 0;
    dragon_image[4].w = width/5;
    dragon_image[4].h = height/4;

    dragon_fire.x = width - (width/5)*2;
    dragon_fire.y = height - (height/4);
    dragon_fire.w = width/5;
    dragon_fire.h = height/4;

}
