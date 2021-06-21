#include "lib_HS_DIF.h"

void HIGHSCORE(char path[],SDL_Rect *temp, SDL_Rect *points_rect)
{
    char name[500] = " ";
    int score,i,j,start,finish;
    char ch[12][50],temp_ch[50];

    FILE* FILEPOINTER = fopen(path,"r");
    if(FILEPOINTER == NULL)
    {
        printf("FILE NULL\n");
    }

    if(Elements.Delay == Hard)
    {
        start = 7;
        finish = 9;
    }
    else if(Elements.Delay == Medium)
    {
        start = 4;
        finish = 6;
    }
    else if(Elements.Delay == Easy)
    {
        start = 1;
        finish = 3;
    }
    else
    {

    }


    for(i = 1; i<=9 ; i++)
    {
        fgets(ch[i],40,FILEPOINTER);
    }

    sscanf(ch[finish],"%s %s %d",ch[0],temp_ch,&score);

    fclose(FILEPOINTER);

    if(score<Elements.points)
    {
        SDL_SetRenderDrawColor(renderer,0,0,0,0xFF);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_HIGHSCORE],NULL,temp);
        SDL_RenderCopy(renderer,Snake_Images[SNAKE_SCORE],NULL,points_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);

        INPUT_NAME(name);

        for(i=1;;i++)
        {
            name[i-1] = name[i];
            if(name[i] == '\0')
            {
                break;
            }
        }

        sprintf(ch[finish],"03. %s %d\n",name,Elements.points);

        for(i = finish - 1,j=2; i>=start; i--,j--)
        {
            sscanf(ch[i],"%s %s %d",ch[0],temp_ch,&score);

            if(score<Elements.points)
            {
                sprintf(ch[i],"0%d. %s %d\n",j,name,Elements.points);
                sprintf(ch[i+1],"0%d. %s %d\n",j+1,temp_ch,score);
            }
            else
            {
                break;
            }
        }

        FILEPOINTER = fopen(path,"w");
        for(i=1; i<=9; i++)
        {
            fprintf(FILEPOINTER,"%s",ch[i]);
        }

        fclose(FILEPOINTER);

    }

}

void INPUT_NAME(char name[])
{
    SDL_Event event;
    int k = 1;
    SDL_StartTextInput();
    bool stop = false;

    SDL_Rect SIZE_SHOWNAME;
    SIZE_SHOWNAME.x = SCREEN_WIDTH / 2 - 200;
    SIZE_SHOWNAME.y = SCREEN_HEIGHT / 2 - 250;
    SIZE_SHOWNAME.w = 400;
    SIZE_SHOWNAME.h = 120;

    SDL_Rect SIZE_NAME;
    SIZE_NAME.x = SCREEN_WIDTH / 2 ;
    SIZE_NAME.y = 300;
    SIZE_NAME.w = 0;
    SIZE_NAME.h = 120;

    for(;(!stop);)
    {
        for(; SDL_PollEvent(&event)!=0;)
        {
            if(event.type == SDL_QUIT)
            {

            }
            else if(event.type == SDL_TEXTINPUT)
            {
                if(k<9 && event.text.text[0] != ' ')
                {
                    name[k++] = event.text.text[0];
                    name[k] = '\0';
                }
            }
            else if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_BACKSPACE)
                {
                    if(k>1)
                    {
                        k--;
                        name[k] = '\0';
                    }
                }
                else if(event.key.keysym.scancode == SDL_SCANCODE_RETURN && k>1)
                {
                    stop = true;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer,0,0,0,0xFF);
        SDL_RenderClear(renderer);

        SIZE_NAME.x = (SCREEN_WIDTH/2) - k*20;
        SIZE_NAME.w = k*20*2;

        image = MAKETTF(name,0,true);

        SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
        SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_PUTNAME],NULL,&SIZE_SHOWNAME);
        SDL_RenderCopy(renderer,image,NULL,&SIZE_NAME);

        SDL_RenderPresent(renderer);
    }

    SDL_StopTextInput();
}


void READING_DIFFICULTY()
{
    FILE* FILEPOINTER = fopen("res/DIFFICULTY.txt","r");
    if(FILEPOINTER == NULL)
    {
        printf("FILE NULL\n");
        return ;
    }
    fscanf(FILEPOINTER,"%d",&Elements.Delay);
    fclose(FILEPOINTER);
}

void SETTING_DIFFICULTY(int speed)
{
    FILE* FILEPOINTER = fopen("res/DIFFICULTY.txt","w");
    if(FILEPOINTER == NULL)
    {
        printf("FILE NULL\n");
        return ;
    }
    fprintf(FILEPOINTER,"%d",speed);
    Elements.Delay = speed;
    fclose(FILEPOINTER);
}

void SHOW_HIGHSCORE(char path[],int start,int finish)
{
    FILE* FILEPOINTER = fopen(path,"r");
    if(FILEPOINTER == NULL)
    {
        printf("FILE NULL\n");
    }

    char ch[10][50],serial[25],name[25],score[25];
    int i;

    SDL_Rect name_rect,score_rect,serial_rect;
    serial_rect.x = 200;
    serial_rect.y = 50;
    serial_rect.w = 40*3;
    serial_rect.h = 100;

    name_rect.x = 350;
    name_rect.y = 50;
    name_rect.w = 40*4;
    name_rect.h = 100;

    score_rect.x = 750;
    score_rect.y = 50;
    score_rect.w = 40*5;
    score_rect.h = 100;

    SDL_RenderCopy(renderer,Snake_Images[SNAKE_BG],NULL,NULL);
    SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_SL],NULL,&serial_rect);
    SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_NAME],NULL,&name_rect);
    SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_SCORE2],NULL,&score_rect);
    SDL_RenderCopy(renderer,True_Type_Font[TRUE_TYPE_FONT_BACK],NULL,&Modes[MODES_BACK]);

    for(i=0; fgets(ch[i],40,FILEPOINTER)!= NULL; i++)
    {

    }

    for(i=start; i<=finish; i++)
    {
        sscanf(ch[i],"%s %s %s",serial,name,score);

        serial_rect.y+=110;
        serial_rect.w = strlen(serial)*40;
        image = MAKETTF(serial,0,true);
        SDL_RenderCopy(renderer,image,NULL,&serial_rect);

        name_rect.y+=110;
        name_rect.w = strlen(name)*40;
        image = MAKETTF(name,0,true);
        SDL_RenderCopy(renderer,image,NULL,&name_rect);

        score_rect.y+=110;
        score_rect.w = strlen(score)*40;
        image = MAKETTF(score,0,true);
        SDL_RenderCopy(renderer,image,NULL,&score_rect);

        SDL_DestroyTexture(image);
    }

    SDL_RenderPresent(renderer);
    fclose(FILEPOINTER);
}

