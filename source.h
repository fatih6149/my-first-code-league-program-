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

void league_settings(){//changing the league settings

    int selection;
    int match_set[4];

    printf("===============================\nTo change the settings from file (setting.txt): 1\n");
    printf("To change the settings from keyboard: 2\n");
    printf("Enter a choice: ");
    scanf("%d",&selection);

    while (selection != 1 && selection !=2){//not pressing 1 or 2, it will give an error
        printf("===============================\nYou pressed wrongly!!!\n");
        printf("===============================\nEnter: 1 or 2\n");
        scanf(" %d", &selection);
    }

    if (selection == 1){
        FILE *fp;
        fp=fopen("setting.txt","r");

      if (fp == NULL){
                                                                   //check file existing
        printf("Unable to open the file.\nPlease create a file and try again.");
        exit(1);
      }

      int i;
      for(i=0;i<4;i++){//read and save league settings from the file to the (int match_set[4])
        fscanf(fp,"%d",&match_set[i]);
        }//end of for
        records.teams_number=match_set[0];                //set team number
        records.win=match_set[1];                         //set win
        records.lost=match_set[2];                        //set lost
        records.drawn=match_set[3];                       //set drawn
        printf("===============================\n");
    }

    if(selection == 2){
        printf("===============================\nSet the settings:");
        printf("\nTeams number = ");
        scanf("%d", &records.teams_number);
        printf("For winning  = ");
        scanf("%d", &records.win);
        printf("For losing   = ");
        scanf("%d", &records.lost);
        printf("For drawing  = ");
        scanf("%d", &records.drawn);
        printf("===============================\n");
    }
}

void fixtures(){
    
    int selection;

    printf("===============================\nTo take the fixtures from file (matches.txt): 1\n");
    printf("To enter the fixtures from keyboard: 2\n");
    printf("Enter a choice: ");
    scanf("%d",&selection);
    while (selection != 1 && selection !=2){//not pressing 1 or 2, it will give you an error
        printf("===============================\nYou pressed wrongly!!!\n");
        printf("===============================\nEnter: 1 or 2\n");
        scanf("%d", &selection);
    }//end of while error

    if(selection ==1){//selection to read the fixtures from file (matches.txt)
        FILE *ffix;
        ffix=fopen("matches.txt","r");
        if(ffix == NULL){
            printf("Unable to open the file.\nPlease create a file and try again.");
        }
        printf("===============================\n");
        printf("NOT: If the match played before, it will not effect on the table.\n");
        printf("NOT: A team can not play with itself.\n");
        int count;
        int i;
        for(count=0;count<records.teams_number;count++){//looping as much as team numbers
            fscanf(ffix," %c %d %c %d",&records.team1,&records.team1score,&records.team2,&records.team2score);//take input from file

            for(i = 0; i <= records.teams_number; i++){
                if(records.team1 == records.team2){//checking a fixture of playing with itself
                    break;
                }//end of fixture of playing with itself
                if(record[i].host == records.team1 && record[i].guest == records.team2){//checking of error of playing the match again
                    break;
                }//end of error of playing the match again
                update_table_score(i);
            }//end of for of looping as much as team numbers
            record[records.counter].host=records.team1;//save the entered team1 to the array of the struct
            record[records.counter].guest=records.team2;//save the entered team2 to the array of the struct
            records.counter++;//save the location of fixtures
        }//end of looping as much as team numbers
        printf("The results have been successfully processed.\n");
    }//end of reading the fixtures from file

    //========================================================
	int j;
    if(selection==2){//selection to enter the fixtures from keyboard
        int fixnum;
        printf("===============================\nHow many fixtures do you want to enter ?\n= ");
        scanf("%d", &fixnum);//number of fixtures
        printf("Enter the fixtures:\n");
        for(j = 0; j < fixnum; j++){//looping as much as fixnum
            printf(" ");
            scanf(" %c %d %c %d", &records.team1, &records.team1score, &records.team2, &records.team2score);//take input from keyboard
            int i;
            for(i = 0; i <= records.teams_number; i++){//looping as much as team numbers
                if(records.team1 == records.team2){//checking a fixture of playing with itself
                    printf("A team can not play with himself!!!\n");
                    break;
                }//end of fixture of playing with itself
                if(record[i].host == records.team1 && record[i].guest == records.team2){//checking of error of playing the match again
                    printf("This match played before!!!\n");
                    break;
                }//end of error of playing the match again
                update_table_score(i);
            }//end of for of looping as much as team numbers
            record[records.counter].host=records.team1;//save the entered team1 to the array of the struct
            record[records.counter].guest=records.team2;//save the entered team2 to the array of the struct
            records.counter++;//save the location of fixtures
        }//end of fixnum
    }//end of entering fixture from keyboard

}

void update_table_score(int i){
    if(i == records.teams_number){//after finishing of checking the errors. it will come to this if and begin processing on the table.
        if(records.team1score > records.team2score){//if of team1score > team2score
            records.tempav = records.team1score - records.team2score;
            record[records.team1-65].GF += records.team1score;
            record[records.team2-65].GF += records.team2score;
            record[records.team1-65].GD += records.tempav;
            record[records.team2-65].GD -= records.tempav;
            record[records.team1-65].W += 1;
            record[records.team2-65].L += 1;
            record[records.team1-65].MP += 1;
            record[records.team2-65].MP += 1;
            record[records.team1-65].PTS += records.win;
            record[records.team2-65].PTS += records.lost;
            record[records.team1-65].GA += records.team2score;
            record[records.team2-65].GA += records.team1score;
        }//end of if of team1score > team2score
        else if(records.team2score > records.team1score){//if of team1score < team2score
            records.tempav = records.team2score - records.team1score;
            record[records.team1-65].GF += records.team1score;
            record[records.team2-65].GF += records.team2score;
            record[records.team1-65].GD -= records.tempav;
            record[records.team2-65].GD += records.tempav;
            record[records.team1-65].L += 1;
            record[records.team2-65].W += 1;
            record[records.team1-65].MP += 1;
            record[records.team2-65].MP += 1;
            record[records.team1-65].PTS += records.lost;
            record[records.team2-65].PTS += records.win;
            record[records.team1-65].GA += records.team2score;
            record[records.team2-65].GA += records.team1score;
        }//end of if of team1score < team2score
        else if(records.team1score == records.team2score){//if of team1score = team2score
            record[records.team1-65].GF += records.team1score;
            record[records.team2-65].GF += records.team2score;
            record[records.team1-65].D += 1;
            record[records.team2-65].D += 1;
            record[records.team1-65].MP += 1;
            record[records.team2-65].MP += 1;
            record[records.team1-65].PTS += records.drawn;
            record[records.team2-65].PTS += records.drawn;
            record[records.team1-65].GA += records.team2score;
            record[records.team2-65].GA += records.team1score;
        }//end of if of team1score > team2score
        //break;
    }//end of if of there are not an error
}