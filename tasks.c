#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "prints.h"

int readFromInput(void);
int dirmenu(void);
int rotmenu(void);
void genFromDataOdd(int size, int dir, int rot, int toFile, char dirS[5], char rotS[4]);
void genFromDataEven(int size, int dir, int rot, int toFile, char dirS[5], char rotS[4]);
int readFromFile(void);
int** createMatrix(int n);
void freeMatrix(int** matrix, int size);

//bekeri a matrix adatait es visszaadja azokat egy szamba kodolva
int readFromInput(void){
    int size = sizemenu();
    int dir = dirmenu();
    int rot = rotmenu();

    return ((size*100)+(dir*10)+rot) ;
}


//matrix helyet lefoglalja a memoriaban
int** createMatrix(int size) {
    int** matrix = (int**)malloc(size * sizeof(int*));
    if (matrix == NULL) {
        printf("Sikertelen memoriafoglalas.\n");
        return NULL;
    }
    for (int i = 0; i < size; ++i) {
        matrix[i] = (int*)malloc(size * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Sikertelen memoriafoglalas.\n");
            for (int j = 0; j < i; ++j) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

//matrix helyet felszabaditja
void freeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void genFromDataOdd(int size, int direction, int rotation, int toFile, char dirS[5], char rotS[4]){
    //paratlan meretu matrixot tud csak
    //dir: 1-bal 2-fel 3-jobb 4-le
    //rot: 1-cw 2-ccw

    int** matrix = createMatrix(size);
    if (matrix == NULL) {
        return;
    }
    //kozepso elem
    int row = size / 2;
    int col = size / 2;
    matrix[row][col] = 1;
    int dir = direction;
    int rot = rotation;
    int moves = 1;  //egyvonalban tett lepesszam
    int value = 1;  //mekkora legyen az elem erteke
    int readyToGrow = 0;//egyvonalban tett lepessorozatokat szamlalja

    int i = 0;
    while( i < (size*size) ){
        for(int j = 0; j < moves; j++){
            value += 1;
            if(dir == 1) col -= 1;          //balra
            else if(dir == 2) row -= 1;     //fel
            else if(dir == 3) col += 1;     //jobbra
            else if(dir == 4) row += 1;     //le
            if(value <= (size*size)){
                matrix[row][col] = value;       //ertekadas
            }
        }
        readyToGrow += 1;
        //iranyvaltas
        if(rot == 1){
            dir = (dir % 4) + 1; 
        }else{
            if(dir == 1) dir = 4;
            else dir -= 1;
        }
        i = i + moves;
        if(readyToGrow % 2 == 0) moves += 1;  //ketszer lephet ugyanannyi ertekkel, aztan novelni kell a lepeshosszat
    }
    //kiiratas
    if(toFile == 0){
        for(int k = 0; k < size; k++){
            for(int j = 0; j < size; j++){
                if(size < 4){
                    printf("%2d", matrix[k][j]);
                } else if(size < 10){
                    printf("%3d", matrix[k][j]);
                } else{
                    printf("%4d", matrix[k][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
    } else{
        char filename[30];
        snprintf(filename, sizeof(filename), "spiral_%d_%s_%s.txt", size, dirS, rotS);
        FILE *file = fopen(filename, "w");

        if (file == NULL) {
            fprintf(stderr, "Hiba tortent, probalja ujra!\n");
            return;
        }

        for (int k = 0; k < size; k++) {
            for (int j = 0; j < size; j++) {
                if(size < 4){
                    fprintf(file, "%2d", matrix[k][j]);
                } else if(size < 10){
                    fprintf(file, "%3d", matrix[k][j]);
                } else{
                    fprintf(file, "%4d", matrix[k][j]);
                }
            }
            fprintf(file, "\n");
        }

        fclose(file);
    }
    freeMatrix(matrix, size);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void genFromDataEven(int size, int direction, int rotation, int toFile, char dirS[5], char rotS[4]){
    //paros matrixot csinal paratlanbol
    //dir: 1-bal 2-fel 3-jobb 4-le
    //rot: 1-cw 2-ccw

    int** matrix = createMatrix(size+1);
    if (matrix == NULL) {
        return;
    }
    //kozepso elem
    int row = (size+1) / 2;
    int col = (size+1) / 2;
    matrix[row][col] = 1;
    int dir = direction;
    int rot = rotation;
    int moves = 1;  //egyvonalban tett lepesszam
    int value = 1;  //mekkora legyen az elem erteke
    int readyToGrow = 0;//egyvonalban tett lepessorozatokat szamlalja

    int i = 0;
    while( i < ((size+1)*(size+1)) ){
        for(int j = 0; j < moves; j++){
            value += 1;
            if(dir == 1) col = (col - 1 + size+1) % (size+1); //balra
            else if(dir == 2) row = (row - 1 + size+1) % (size+1);     //fel
            else if(dir == 3) col = (col + 1) % (size+1);     //jobbra
            else if(dir == 4) row = (row + 1) % (size+1);     //le
            if(value > size*size){
                matrix[row][col] = 0;       //ertekadas
            } else{
                matrix[row][col] = value;
            }
        }
        readyToGrow += 1;
        //iranyvaltas
        if(rot % 2 == 1){
            dir = (dir % 4) + 1; 
        }else{
            if(dir == 1) dir = 4;
            else dir -= 1;
        }
        i = i + moves;
        if(readyToGrow % 2 == 0) moves += 1;  //ketszer lephet ugyanannyi ertekkel, aztan novelni kell a lepeshosszat
    }  

    //kiiratas
    if(toFile == 0){
        for(int k = 0; k < size+1; k++){
            for(int j = 0; j < size+1; j++){
                if(matrix[k][j] != 0){ 
                    if(size < 4){
                        printf("%2d", matrix[k][j]);
                    } else if(size < 10){
                        printf("%3d", matrix[k][j]);
                    } else{
                        printf("%4d", matrix[k][j]);
                    }
                }
            }
            printf("\n");
        }
        printf("\n");
    } else {
        char filename[23];
        snprintf(filename, sizeof(filename), "spiral_%d_%s_%s.txt", size, dirS, rotS);
        FILE *file = fopen(filename, "w");

        if (file == NULL) {
            fprintf(stderr, "Hiba tortent, probalja ujra!\n");
            return;
        }

        for (int k = 0; k < size+1; k++) {
            for (int j = 0; j < size+1; j++) {
                if(matrix[k][j] != 0){
                    if(size < 4){
                        fprintf(file, "%2d", matrix[k][j]);
                    } else if(size < 10){
                        fprintf(file, "%3d", matrix[k][j]);
                    } else{
                        fprintf(file, "%4d", matrix[k][j]);
                    }
                }
            }
            fprintf(file, "\n");
        }

        fclose(file);
    }
    freeMatrix(matrix, size+1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

int readFromFile(void){
    char filename[31];
    printf("Adja meg a fajl nevet: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        fprintf(stderr, "Hiba a fajl megnyitasa kozben!\n");
        return 0;
    }

    char line[15];  // A beolvasott sor tarolasara

    // Ellenorizzuk, hogy csak egy sor van-e a fajlban
    if (fgets(line, sizeof(line), file) == NULL || strchr(line, '\n') == NULL) {
        fprintf(stderr, "Hiba: A fajl nem pontosan egy sort tartalmaz.\n");
        fclose(file);
        return 0;
    }

    int size = 0;
    int dir = 0, rot = 0;
    char str1[5], str2[4];
    int result = sscanf(line, "%d %s %s", &size, str1, str2);
    if (result != 3) {
        printf("Hiba: A fajl tartalma nem felel meg az elvarasoknak.\n");
        printf("A szoveges fajl egyetlen sorbol alljon, ami a matrix meretet,\nindulasi iranyat es forgasi iranyat tartalmazza ebben a sorrendben, egyetlen szokozzel elvalasztva!\nReszletesebb leiras a(z) users guide-ban.\n");
        fclose(file);
        return 0;
    }
    //adatok kiertekelese
    if ((size < 1) || (size > 20)){
        printf("Hiba: A fajl tartalma nem felel meg az elvarasoknak.\n");
        printf("A szoveges fajl egyetlen sorbol alljon, ami a matrix meretet,\nindulasi iranyat es forgasi iranyat tartalmazza ebben a sorrendben, egyetlen szokozzel elvalasztva!\nReszletesebb leiras a(z) users guide-ban.\n");
        fclose(file);
        return 0;
    }
    if ((strcmp(str1, "jobb") != 0) && (strcmp(str1, "bal") != 0) && (strcmp(str1, "fel") != 0) && (strcmp(str1, "le") != 0)){
        printf("Hiba: A fajl tartalma nem felel meg az elvarasoknak.\n");
        printf("A szoveges fajl egyetlen sorbol alljon, ami a matrix meretet,\nindulasi iranyat es forgasi iranyat tartalmazza ebben a sorrendben, egyetlen szokozzel elvalasztva!\nReszletesebb leiras a(z) users guide-ban.\n");
        fclose(file);
        return 0;
    } else if(strcmp(str1, "bal") == 0){
        dir = 1;
    } else if(strcmp(str1, "fel") == 0){
        dir = 2;
    } else if(strcmp(str1, "jobb") == 0){
        dir = 3;
    } else if(strcmp(str1, "le")){
        dir = 4;
    }

    if ((strcmp(str2, "cw") != 0) && (strcmp(str2, "ccw") != 0)){
        printf("Hiba: A fajl tartalma nem felel meg az elvarasoknak.\n");
        printf("A szoveges fajl egyetlen sorbol alljon, ami a matrix meretet,\nindulasi iranyat es forgasi iranyat tartalmazza ebben a sorrendben, egyetlen szokozzel elvalasztva!\nReszletesebb leiras a(z) users guide-ban.\n");
        fclose(file);
        return 0;
    } else if(strcmp(str2, "cw") == 0){
        rot = 1;
    } else if(strcmp(str2, "ccw")){
        rot = 2;
    }

    fclose(file);

    return ((size*100)+(dir*10)+rot) ;
}
