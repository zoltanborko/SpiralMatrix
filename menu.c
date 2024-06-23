#include <stdio.h>
#include <string.h>

#include "tasks.h"
#include "prints.h"

void menu(void){
    int choice;
    //matrix adatai tarolasara
    int n = 0;
    int size = 0;
    int dir = 0;
    int rot = 0;
    char rotS[4];
    char dirS[5];
    title();
    do{

        printmenu();
        printf("Valasszon a menubol: ");

        while( scanf("%d", &choice) != 1 ){
            printf("Ervenytelen! Csak szamot fogad el!\n");
            printf("Valasszon a menubol: ");
            while (getchar() != '\n');
        }
        printf("\n\n");



        //menurendszer
        switch(choice) {
            case 1:
                //leiras
                ug();
                break;
            case 2:
                //matrix "generalasa"
                n = readFromInput();
                size = n / 100;
                dir = (n % 100) / 10;
                rot = (n % 100) % 10;
                
                if(rot == 1){
                    strcpy(rotS, "cw");
                }else{
                    strcpy(rotS, "ccw");
                }
                if(dir == 1){
                    strcpy(dirS, "bal");
                } else if(dir == 2){
                    strcpy(dirS, "fel");
                } else if(dir == 3){
                    strcpy(dirS, "jobb");
                } else if(dir == 4){
                    strcpy(dirS, "le");
                }
                break;
            case 3:
                //matrix betoltese fajlbol
                n = readFromFile();
                size = n / 100;
                dir = (n % 100) / 10;
                rot = (n % 100) % 10;
                
                if(rot == 1){
                    strcpy(rotS, "cw");
                }else{
                    strcpy(rotS, "ccw");
                }
                if(dir == 1){
                    strcpy(dirS, "bal");
                } else if(dir == 2){
                    strcpy(dirS, "fel");
                } else if(dir == 3){
                    strcpy(dirS, "jobb");
                } else if(dir == 4){
                    strcpy(dirS, "le");
                }
                break;
            case 4:
                //matrix elmentese fajlba
                if(n != 0){
                    (size % 2 == 0) ? genFromDataEven(size, dir, rot, 1, dirS, rotS) : genFromDataOdd(size, dir, rot, 1, dirS, rotS);
                }
                break;
            case 5:
                //matrix kiiratasa
                if(n != 0){
                    (size % 2 == 0) ? genFromDataEven(size, dir, rot, 0, dirS, rotS) : genFromDataOdd(size, dir, rot, 0, dirS, rotS);
                }
                break;
            case 6:
                //kilepes
                printf("Viszlat!");
                break;
            default:
                printf("Ervenytelen valasztas. Kerem, valasszon ujra. (Csak egy szamot irjon be 1 es 6 kozott) \n");
        }
        printf("\n");  
    } while( choice != 6 );
}
