#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

struct league{
    int teams_number;
    int win;
    int lost;
    int drawn;
    char team1;
    char team2;
    int team1score;
    int team2score;
    int PTS;
    int MP;
    int GF;
    int GA;
    int GD;
    int W;
    int L;
    int D;
    int tempav;
    char host;
    char guest;
    int counter;
    char longname[12];
    char longname_point[12];
}records, record[MAX];

void default_league_settings(){                                                 //default league settings
    records.teams_number = 10;
    records.win = 3;
    records.drawn = 1;
    records.lost = 0;
}