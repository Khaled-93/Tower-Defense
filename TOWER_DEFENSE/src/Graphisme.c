#include "../include/Graphisme.h"


void init_window() {
    MLV_create_window(NAME, ICON, SIZE_X * SCALE, SIZE_Y * SCALE);
    MLV_actualise_window();
}

/*title screen for message when the tower looses the game*/
void loose_screen(){
    MLV_draw_text_box((SIZE_X * SCALE )/ 3+100, (SIZE_Y *SCALE )/ 2, 170, 110, "GAME OVER",120, MLV_COLOR_BLACK, MLV_COLOR_BLUE1, MLV_COLOR_RED1, MLV_TEXT_CENTER,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    MLV_wait_mouse(NULL,NULL);
}



void draw_tower(Tower tower) {
    float length, width, offset;
    Uint8 red, green, blue, alpha;

    width = 10;
    length = 20;
    offset = 15;

    MLV_convert_color_to_rgba(MLV_COLOR_GREEN, &red, &green, &blue, &alpha);


    MLV_draw_filled_circle(tower.obj.x * SCALE, tower.obj.y * SCALE, SIZE_TOWER * SCALE, MLV_convert_rgba_to_color(red, green, blue, alpha));

    /* Mana jauge */
    MLV_draw_rectangle(tower.obj.x * SCALE + offset, tower.obj.y * SCALE - offset, length, width, MLV_COLOR_GREY);
    if (tower.mana > 0) {
        MLV_draw_filled_rectangle(tower.obj.x * SCALE + offset, tower.obj.y * SCALE - offset, (tower.mana * length) / MAX_MANA, width, MLV_COLOR_BLUE);
    }
}



int title_screen(MLV_Image *image) {
    int width, height;
    int x, y;
    int quit;

    width = SIZE_X * SCALE;
    height = SIZE_Y * SCALE;

    MLV_create_window(NAME, ICON, width, height);
    image = MLV_load_image(BACKGROUND_MENU);
    MLV_resize_image(image, width, height);
    MLV_draw_image(image, 0, 0);

    buttons();
    MLV_actualise_window();
    /*affichage du bouton jouer et des options et de quitter*/
    do {
        MLV_wait_mouse(&x, &y);
        if ((x > width / 2.4) && x < ((width / 2.4) + (width / 6)) && (y > height / 2) && (y < height / 2 + (height / 9))) {
            quit = 0;
            break;
        } else if (x > width / 1.6 && x < (width / 1.6 + width / 6) && y > height / 2 && y < (height / 2 + height / 9)) {
            quit = 1;
            break;
        } else if (x > width / 4.8 && x < (width / 4.8 + width / 6) && y > height / 2 && y < (height / 2 + height / 9)) {
            MLV_free_window();
            help_window(width, height);
            return title_screen(image);
            break;
        }

    } while (x > 0 && x < width && y > 0 && y < height);
    MLV_free_window();
    return quit;
}

void help_window(int width, int height) {
/*TODO*/
}

void buttons() {
    int width, height;

    width = SIZE_X * SCALE;
    height = SIZE_Y * SCALE;

    MLV_draw_text_box(width / 2.4, height / 2, width / 6, height / 9, "PLAY", 120, MLV_COLOR_BLACK, MLV_COLOR_BLUE1, MLV_COLOR_YELLOW1, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(width / 4.8, height / 2, width / 6, height / 9, "HELP", 120, MLV_COLOR_BLACK, MLV_COLOR_BLUE1, MLV_COLOR_YELLOW1, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(width / 1.6, height / 2, width / 6, height / 9, "QUIT", 120, MLV_COLOR_BLACK, MLV_COLOR_BLUE1, MLV_COLOR_YELLOW1, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}

void draw_spawn(Object spawn) {
    int offset;

    offset = SCALE / 2;
    MLV_draw_filled_rectangle(spawn.x * SCALE - offset, spawn.y * SCALE - offset, SCALE * 1.5, SCALE * 1.5, MLV_COLOR_YELLOW1);
}


void refresh(time_t end_time, time_t new_time) {
    int frametime, extratime;

    /* Compute the time spent for the current frame */
    frametime = new_time - end_time;
    frametime += (new_time - end_time) / 1.0E9;

    /* Force the program to spend at least 1/60 second in total*/
    extratime = 1.0 / 60 - frametime;
    if (extratime > 0) {
        MLV_wait_milliseconds((int)(extratime * 1000));
    }
    MLV_actualise_window();
}


void win_screen(){
    MLV_draw_text_box((SIZE_X * SCALE) / 3+100, (SIZE_Y * SCALE) /2, 170, 110, "YOU WIN",120, MLV_COLOR_BLACK, MLV_COLOR_BLUE1, MLV_COLOR_GREEN1, MLV_TEXT_CENTER,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    MLV_wait_mouse(NULL,NULL);
}


void draw_window(Object base, Tower tower /*implementer le reste de la partie*/) {
    static int init = 0;
    /*int i;*/

    /* Window initiated ? */
    if (!init) {
        init = 1;
        init_window();
    }

    /* clean the window */
    MLV_clear_window(MLV_COLOR_WHITE);


    /* draw Tower's spawn */
    draw_spawn(base);


    /* draw ennemis */
    /*le faire en for*/

    /* draw tower */
    draw_tower(tower);

    /* draw paths */
    /*le faire en for*/

}


