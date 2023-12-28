
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 1999309L


#include <time.h>


#include "../include/all.h"







int main(int argc, char *argv[]) {
    /*Manage of position*/
    /*int i, j;*/


    /*Manage of tower and base*/
    Object base_tower;
    Tower tower;
    Monster monster;

    /* initialisation of the grid */
    char grid[SIZE_X][SIZE_Y];


    /*Manage of events*/
    int quit;

    /*Manage of time*/
    struct timespec end_time, new_time, begin_time;
    int time_game;
    
    /*Manage of Image and Music*/
    MLV_Image *image;
    MLV_Music *music;


    /*Initialisation*/
    quit = 0;
    image = NULL;
    music = NULL;
    srand(time(NULL));

    /*initialisation of tower and base */
    tower = *init_tower(BASE_TOWER_X, BASE_TOWER_Y);
    base_tower = *init_object(tower.obj.x, tower.obj.y);
    
    generatePath(grid);
    printGrid(grid);


    /*generations of paths and enemys*/
    /*monster = init_monster();*/



    /*screen and song*/
     if (title_screen(image) == 1) {
        quit = 1;
    }



    /*moteur du jeu*/
    clock_gettime(CLOCK_REALTIME, &begin_time);

/*GIT*/
    /* Main loop over the frames... */
    while (!quit) {
        /*Get the time in nano second at the start of the frame */
        clock_gettime(CLOCK_REALTIME, &end_time);

        /* Display of the currentframe, samplefunction */
        /* THIS FUNCTION CALLS ONCE AND ONLY ONCE MLV_update_window */
        
        draw_window(base_tower, tower/*ajouter le reste*/);

        /* Dealing with the events */


       /* quit = (event == INPUT_QUIT); */

        /*SHOOT TOWER*/



        /* Get the time in nano second at the end of the frame */
        clock_gettime(CLOCK_REALTIME, &new_time);

        refresh(end_time.tv_sec, new_time.tv_sec); /* Graphisme.h */
    }

    time_game = end_time.tv_sec - begin_time.tv_sec;
    /*free ennemis and paths etc*/


    if(quit >= 2){
        MLV_draw_text((SIZE_X*SCALE) / 2-100 , (SIZE_Y * SCALE) /3 +100, " TEMPS ECOULE : %ds", MLV_COLOR_ORANGE1, (int)time_game);  
        MLV_draw_text((SIZE_X*SCALE) / 2-100 , (SIZE_Y * SCALE) /3 +100 + 20, "MANA UTILISE : %d / %d", MLV_COLOR_ORANGE1, MAX_MANA - tower.mana, MAX_MANA);  
        MLV_draw_text((SIZE_X*SCALE) / 2-100 , (SIZE_Y * SCALE) /3 +100 - 200, "CLIQUEZ POUR QUITTER", MLV_COLOR_ORANGE1);  
        MLV_actualise_window();
        if(quit == 2){
            win_screen();
        }
        else{
            loose_screen();
        }
        free_music(music);
        MLV_free_image(image);
        MLV_free_window();
    }

    
    return 0;


}