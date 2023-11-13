#include <time.h>

#include "../include/all.h"

int main(int argc, char *argv[]) {
    /*Manage of position*/
    int i, j;


    /*Manage of events*/
    int quit;

    /*Manage of time*/
    struct timespec end_time, new_time, begin_time;
    int time;
    
    /*Manage of Image and Music*/
    MLV_Image *image;
    MLV_Music *music;


    /*Initialisation*/
    quit = 0;
    image = NULL;
    music = NULL;
    srand(time(NULL));


    /*initialisation of tower and base */
    init_Tower(0, 0);




    /*generations of paths and enemys*/






    /*moteur du jeu*/


    
    return 0;







}