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

void teams_file(){                                                              //read 'teams.txt' file
    int i;
    FILE *fp=fopen("teams.txt","r");                                         //open file teams.txt
    if(fp == NULL)                                                              //checking if the file is exist or not
        printf("Unable to open the file.\nPlease create a file and try again.");
    
    for(i=0;i<26;i++)                                                           //save teams name to struct
        fscanf(fp,"%s",record[i].longname);
}

void teams_file_point(){
    int i;
    FILE *fp1=fopen("teams.txt","r");
    if(fp1 == NULL)
        printf("Unable to open the file.\nPlease create a file and try again.");

    for(i=0;i<26;i++)//save teams name to struct
        fscanf(fp1,"%s",record[i].longname_point);

}

int display_menu(){//menu selections
    int selection;
    printf("===============================\n");
    printf("To change the settings: 1\n");
    printf("To enter the fixtures: 2\n");
    printf("TO see the table alphabetically: 3\n");
    printf("TO see the table in order of points: 4\n");
    printf("To exit: 5\n===============================");
    printf("\nEnter a choice: ");
    scanf("%d", &selection);
    while (selection != 1 && selection !=2 && selection !=3 && selection !=4 && selection !=5){//not pressing 1,2,3,4, or 5, it will give an error
        printf("===============================\nYou pressed wrongly!!!\n");
        printf("===============================\nEnter a choice: ");
        scanf("%d", &selection);
        getchar();
    }//end of while of error
    return selection;
}