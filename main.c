#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "source.h"

int main(){

    default_league_settings();
    teams_file();
    teams_file_point();

    records.counter=0;
    int selection;

    do{
        printf("Teams number = %d\nFor winning  = %d\nFor losing   = %d\nFor drawing  = %d\n", records.teams_number, records.win, records.lost, records.drawn);
        selection = display_menu();

        switch (selection)
        {
            case 1: league_settings();
            break;
        }

    }while(selection != 5);

    return 0;
}