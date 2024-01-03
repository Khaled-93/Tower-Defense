#ifndef __GRAPHISME
#define __GRAPHISME


#include <MLV/MLV_color.h>
#include <MLV/MLV_mouse.h>
#include <MLV/MLV_shape.h>
#include <MLV/MLV_text.h>
#include <MLV/MLV_time.h>
#include <MLV/MLV_window.h>
#include <string.h>



#include "Config.h"
#include "Object.h"
#include "Tower.h"





void init_window();
/*title screen for message when the tower looses the game*/
void loose_screen();


void win_screen();


void refresh(time_t end_time, time_t new_time);

int title_screen(MLV_Image *image) ;

void draw_tower(Tower tower) ;

void draw_grid(char grid[SIZE_Y][SIZE_X]);

void buttons();



void draw_window(Object base, Tower tower, char grid[SIZE_Y][SIZE_X]/*implementer le reste de la partie*/);

void help_window(int width, int height) ;


void draw_spawn(Object spawn);

#endif