/*
#include <stdio.h>
#include <math.h>

void genFromDataOdd(int size, int direction, int rotation){
    //paratlan meretu matrixot tud csak
    //dir: 1-bal 2-fel 3-jobb 4-le
    //rot: 1-cw 2-ccw

    int matrix[size][size];
    //kozepso elem
    int row = size / 2;
    int col = size / 2;
    matrix[row][col] = 1;
    int dir = direction;
    int rot = rotation;
    int moves = 1;  //egyvonalban tett lepesszam
    int value = 1;  //mekkora legyen az elem erteke
    int readyToRotate = 0;//egyvonalban tett lepessorozatokat szamlalja

    int i = 0;
    while( i < (size*size) ){
        for(int j = 0; j < moves; j++){
            value += 1;
            if(dir == 1) col -= 1;          //balra
            else if(dir == 2) row -= 1;     //fel
            else if(dir == 3) col += 1;     //jobbra
            else if(dir == 4) row += 1;     //le
            matrix[row][col] = value;       //ertekadas
            
        }
        readyToRotate += 1;
        //iranyvaltas
        if(rot % 2 == 1){
            dir = (dir % 4) + 1; 
        }else{
            if(dir == 1) dir = 4;
            else dir -= 1;
        }
        i = i + moves;
        if(readyToRotate % 2 == 0) moves += 1;  //ketszer lephet ugyanannyi ertekkel, aztan novelni kell a lepeshosszat
    }  

    //kiiratas
    for(int k = 0; k < size; k++){
        for(int j = 0; j < size; j++){
            printf("%3d", matrix[k][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void genFromDataEven(int size, int direction, int rotation){
    //paros matrixot csinal paratlanbol
    //dir: 1-bal 2-fel 3-jobb 4-le
    //rot: 1-cw 2-ccw

    int matrix[size+1][size+1];
    //kozepso elem
    int row = (size+1) / 2;
    int col = (size+1) / 2;
    matrix[row][col] = 1;
    int dir = direction;
    int rot = rotation;
    int moves = 1;  //egyvonalban tett lepesszam
    int value = 1;  //mekkora legyen az elem erteke
    int readyToRotate = 0;//egyvonalban tett lepessorozatokat szamlalja

    int i = 0;
    while( i < ((size+1)*(size+1)) ){
        for(int j = 0; j < moves; j++){
            value += 1;
            if(dir == 1) col -= 1;          //balra
            else if(dir == 2) row -= 1;     //fel
            else if(dir == 3) col += 1;     //jobbra
            else if(dir == 4) row += 1;     //le
            if(value > size*size){
                matrix[row][col] = 0;       //ertekadas
            } else{
                matrix[row][col] = value;
            }
        }
        readyToRotate += 1;
        //iranyvaltas
        if(rot % 2 == 1){
            dir = (dir % 4) + 1; 
        }else{
            if(dir == 1) dir = 4;
            else dir -= 1;
        }
        i = i + moves;
        if(readyToRotate % 2 == 0) moves += 1;  //ketszer lephet ugyanannyi ertekkel, aztan novelni kell a lepeshosszat
    }  

    //kiiratas
    for(int k = 0; k < size+1; k++){
        for(int j = 0; j < size+1; j++){
            if(matrix[k][j] != 0){ 
                printf("%4d", matrix[k][j]);
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

int main(void){

    genFromDataOdd(7, 2, 2);
    genFromDataEven(10,1,2);

    return 0;
}




void saveMatrixToFile(int n, int matrix[n][n], const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        fprintf(stderr, "Hiba a fajl megnyitasa kozben!\n");
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fprintf(file, "%4d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Matrix sikeresen mentve a %s fajlba.\n", filename);
}

int main() {
    
    

    // Fájl mentése
    char filename[50];
    snprintf(filename, sizeof(filename), "spiral_%d_%s.txt", n, clockwise ? "cw" : "ccw");
    saveMatrixToFile(n, matrix, filename);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processFile(const char *filename) {
    // Fájl megnyitása olvasásra
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        fprintf(stderr, "Hiba a fajl megnyitasa kozben!\n");
        return;
    }

    char line[1000];  // A beolvasott sor tárolására

    // Ellenőrizzük, hogy csak egy sor van-e a fájlban
    if (fgets(line, sizeof(line), file) == NULL || strchr(line, '\n') == NULL) {
        fprintf(stderr, "Hiba: A fajl nem tartalmaz pontosan egy sort.\n");
        fclose(file);
        return;
    }

    // Szóközök mentén bontjuk a sort
    char *token = strtok(line, " ");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    fclose(file);  // Fájl bezárása
}

int main() {
    char filename[50];

    // Felhasználótól bekérjük a fájl nevét
    printf("Adja meg a fajl nevet: ");
    scanf("%s", filename);

    // Függvény meghívása a fájl feldolgozásához
    processFile(filename);

    char szo[6] = "Marci";
    printf("%d\n", strcmp(szo, "Marci"));


    return 0;
}



//////////////////

void genFromDataOdd(int size, int direction, int rotation, int toFile, char dirS[5], char rotS[4]){
    //paratlan meretu matrixot tud csak
    //dir: 1-bal 2-fel 3-jobb 4-le
    //rot: 1-cw 2-ccw

    int matrix[size][size];
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
        printf("\n\n");
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
}