#include <stdio.h>

void title(void){

    printf("|-----------------------|\n");
    printf("|                       |\n");
    printf("|     SPIRAL MATRIX     |\n");
    printf("|                       |\n");
    printf("|-----------------------|\n\n\n");

}

void printmenu(void){

    printf("1: Felhasznaloi kezikonyv\n");
    printf("2: Matrix adatainak beolvasasa\n");
    printf("3: Matrix adatainak beolvasasa fajlbol\n");
    printf("4: Matrix mentese fajlba\n");
    printf("5: Aktualis matrix kiiratasa\n");
    printf("6: Kilepes\n\n");

}

void ug(void){
    printf("Ezzel a programmal negyzetes spiralmatrixokat tud generalni, menteni, betolteni vagy kirajzolni\n");
    printf("Valasszon menupontot attol fuggoen, hogy mit szeretne!\n\n");
    printf("Az egyes (1) menuponttal meg tudja tekinteni a felhasznaloi kezikonyvet.\n");
    printf("A kettes (2) menuponttal meg tudja adni egy spiralmatrix adatait.\n");
    printf("\tA megadott adatokbol ki tudja rajzolni a matrixot vagy el tudja menteni azt egy fajlba.\n");
    printf("\tA program csak egy matrixot tarol, ezert ha uj adatokat visz be neki a kettes menuponttal vagy fajlbol, \n\ta regi matrix mar nem lesz kirajzolhato vagy mentheto.\n");
    printf("A harmas (3) menuponttal a matrix adatait egy fajl-bol olvastathatja be.\n");
    printf("\tFONTOS! A beolvasando fajl egy pontosan egy sorbol allo szoveges fajl kell hogy legyen. \n");
    printf("\tA fajl egyetlen sora a matrix oldalhosszat, indulasi iranyat es forgasiranyat kell hogy tartalmazza, \n\tebben a sorrendben, egyetlen szokozzel elvalasztva.\n");
    printf("\tAz oldalhossz csak egy szam lehet 1-tol 20-ig. \n\tAz indulasi irany a \"bal\", \"jobb\", \"fel\", \"le\" szaka egyike lehet. A forgasirany pedig csak a \"cw\" es \"ccw\" szavak egyike lehet.\n");
    printf("\tA program csak egy matrixot tarol, ezert ha uj adatokat visz be neki a kettes menuponttal vagy fajlbol, \n\ta regi matrix mar nem lesz kirajzolhato vagy mentheto.\n");
    printf("A negyes(4) menuponttal fajlba tud kimenteni spiralmatrixot.\n");
    printf("\tA fajl neve tartalmazza a matrix jellemzoit. A mentes csak akkor mukodik, ha mar valahogy bevitte a matrix adatait.\n");
    printf("Az otos (5) menuponttal a matrix megjelenik a terminalon.\n");
    printf("\tCsak akkor lehet matrixot megjeleniteni a terminalon, ha mar elotte bevitte annak adatait a programba (2-es vagy 3-as menupont).\n");
    printf("A hatos (6) menuponttal kilep a programbol.\n\n");
    
}

//indulasi irany valaszto menu
int dirmenu(void){
    int choice;
    printf("Indulasi iranyok: \n\n");
    printf("1: Balra\n");
    printf("2: Fel\n");
    printf("3: Jobbra\n");
    printf("4: Le\n");
    printf("Valassza ki az indulasi irnyt a menubol: ");
    while( (scanf("%d", &choice) != 1) || ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4)) ){
        printf("Ervenytelen! Csak egy 1 es 4 kozotti szamot adjon meg!\n");
        printf("Valassza ki az indulasi irnyt a menubol: ");
        while(getchar() != '\n');
    }
    printf("\n\n");
    return choice;
}

//forgasirany valaszto menu
int rotmenu(void){
    int choice;
    printf("Forgasiranyok: \n\n");
    printf("1: Oramutato jarasaval megegyezo\n");
    printf("2: Oramutato jarasaval ellentetes\n");
    printf("Valassza ki a forgasiranyt a menubol: ");
    while( (scanf("%d", &choice) != 1) || ((choice != 1) && (choice != 2)) ){
        printf("Ervenytelen! Csak egy 1-et vagy 2-t fogad el!\n");
        printf("Valassza ki a forgasiranyt a menubol: ");
        while (getchar() != '\n');
    }
    printf("\n\n");
    return choice;
}

int sizemenu(void){
    int size;
    printf("Adja meg a matrix meretet: ");
    while( (scanf("%d", &size) != 1) || ((size < 1) || (size > 20)) ){
        printf("Ervenytelen! Csak egy 1 es 20 kozotti szamot adjon meg!\n");
        printf("Adja meg a matrix meretet: ");
        while (getchar() != '\n');
    }
    printf("\n\n");
    return size;
}
