#ifndef LIBDECLARE_H
#define LIBDECLARE_H

#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include<SDL2/SDL_mixer.h>

#define SCREEN_HEIGHT  600
#define SCREEN_WIDTH 1050
#define RANGE 500
#define Easy 120
#define Medium 90
#define Hard 70

enum SNAKE
{
    SNAKE_IMAGE,
    SNAKE_GAMEOVER,
    SNAKE_HOMESCREEN,
    SNAKE_MODES,
    SNAKE_LEVEL,
    SNAKE_BRICK,
    SNAKE_BG,
    SNAKE_BONUS_FOOD,
    SNAKE_SCORE,
    DRAGON,
    DRAGON_FIRE,
    SMOKE,
    POISON,
    POISON_DROP,
    EXPLOSION,
    RIGHT_SIGN,
    HELP,
    SNAKE_TOTAL
};

enum GAME_STATES
{
    GAME_STATES_HOMESCREEN,
    GAME_STATES_MODES,
    GAME_STATES_CLASSIC,
    GAME_STATES_ARCADE,
    GAME_STATES_CAMPAIGN,
    GAME_STATES_CAMPAIGN_COMPLETED,
    GAME_STATES_LEVEL_1,
    GAME_STATES_LEVEL_2,
    GAME_STATES_LEVEL_3,
    GAME_STATES_LEVEL_4,
    GAME_STATES_LEVEL_5,
    GAME_STATES_CAMPAIGN_BOSS_LEVEL,
    GAME_STATES_START_THE_GAME,
    GAME_STATES_HIGHSCORE,
    GAME_STATES_DIFFICULTY,
    GAME_STATES_EASY,
    GAME_STATES_MEDIUM,
    GAME_STATES_HARD,
    GAME_STATES_SHOW_HIGHSCORE,
    GAME_STATES_HELP,
    GAME_STATES_TOTAL
};

enum TRUE_TYPE_FONT
{
    TRUE_TYPE_FONT_CLASSIC,
    TRUE_TYPE_FONT_ARCADE,
    TRUE_TYPE_FONT_CAMPAIGN,
    TRUE_TYPE_FONT_BACK,
    TRUE_TYPE_FONT_SCORE,
    TRUE_TYPE_FONT_HIGHSCORE,
    TRUE_TYPE_FONT_GAME_SCORE,
    TRUE_TYPE_FONT_PUTNAME,
    TRUE_TYPE_FONT_LEVEL_1,
    TRUE_TYPE_FONT_LEVEL_2,
    TRUE_TYPE_FONT_LEVEL_3,
    TRUE_TYPE_FONT_LEVEL_4,
    TRUE_TYPE_FONT_LEVEL_5,
    TRUE_TYPE_FONT_EASY,
    TRUE_TYPE_FONT_MEDIUM,
    TRUE_TYPE_FONT_HARD,
    TRUE_TYPE_FONT_LEVEL_COMPLETED,
    TRUE_TYPE_FONT_CAMPAIGN_COMPLETED,
    TRUE_TYPE_FONT_NAME,
    TRUE_TYPE_FONT_SL,
    TRUE_TYPE_FONT_SCORE2,
    TRUE_TYPE_FONT_GARBAGE,
    TRUE_TYPE_FONT_TOTAL

};

enum MODES
{
    MODES_CLASSIC,
    MODES_ARCADE,
    MODES_CAMPAIGN,
    MODES_CAMPAIGN_COMPLETED,
    MODES_BACK,
    MODES_LEVEL_1,
    MODES_LEVEL_2,
    MODES_LEVEL_3,
    MODES_LEVEL_4,
    MODES_LEVEL_5,
    MODES_EASY,
    MODES_MEDIUM,
    MODES_HARD,
    MODES_TOTAL
};

enum LEVEL
{
    LEVEL_ONE,
    LEVEL_TWO,
    LEVEL_THREE,
    LEVEL_FOUR,
    LEVEL_FIVE,
    LEVEL_BOSS,
    LEVEL_TOTAL
};

enum MOVEMENT
{
    MOVEMENT_RIGHT,
    MOVEMENT_LEFT,
    MOVEMENT_UP,
    MOVEMENT_DOWN
};

enum PASS
{
    PASS_NONE,
    PASS_RIGHT,
    PASS_LEFT,
    PASS_UP,
    PASS_DOWN
};

enum SOUND_EFFECT
{
    SOUND_EFFECT_EAT,
    SOUND_EFFECT_CRASH,
    SOUND_EFFECT_HISS,
    SOUND_EFFECT_CLICK,
    SOUND_EFFECT_OUCH,
    SOUND_EFFECT_YAY,
    SOUND_EFFECT_PAIN,
    SOUND_EFFECT_DEAD,
    SOUND_EFFECT_BOOM,
    SOUND_EFFECT_BUMP,
    SOUND_EFFECT_FIRE,
    SOUND_EFFECT_TOTAL
};

extern SDL_Window *window;
extern SDL_Surface *surface;
extern SDL_Renderer *renderer;
extern SDL_Texture *image;
extern SDL_Texture *convert;
extern SDL_Texture *Snake_Images[SNAKE_TOTAL];
extern SDL_Texture *True_Type_Font[TRUE_TYPE_FONT_TOTAL];
extern TTF_Font *Name_and_Score;
extern Mix_Music *beat;
extern Mix_Chunk *Sound_Effects[SOUND_EFFECT_TOTAL];

extern SDL_Rect head,tail,turn,body,food,fruit,bonus_food,dragon_fire,dragon_image[5];
extern SDL_Rect Game_points;
extern SDL_Rect Modes[MODES_TOTAL];

struct My_Snake
{
    SDL_Rect body;
    SDL_RendererFlip flip_present_state,flip_past_state;
    char movement_present_state,movement_past_state;
    char wall_passing_present_state,wall_passing_past_state;
    float rotation_angle_present_state,rotation_angle_past_state;
} extern Python[510];

struct Game_Elements
{
    bool alive ;
    bool eat ;
    bool stop;
    bool pause;
    bool bonus_eat ;
    bool venom = false;

    int snake_size ;
    int points ;
    int timer;
    int apple_counter;
    int x_direction,y_direction;
    int Delay;

}extern Elements;

struct enemy
{
    SDL_Rect body;
    int life = 3;
    SDL_Rect fire;
    int frame = 0;
} extern dragon[3];

struct VENOM
{
    SDL_Rect poison_drop = {0,0,30,30};
    int x_vel,y_vel;
    bool venom = false;
    bool venom_collected = false;
    SDL_Rect bottle = {0,0,30,30};
    bool bottle_rend = false;

} extern poison;

extern int flag[GAME_STATES_TOTAL];

struct Wall
{
    SDL_Rect body[15];
    int x_vel[15],y_vel[15];
} extern Bricks[LEVEL_TOTAL];



#endif // DECLARE2_H

