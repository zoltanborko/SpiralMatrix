#ifndef TASKS_H
#define TASKS_H

int readFromInput(void);

void genFromDataOdd(int size, int dir, int rot, int toFile, char dirS[5], char rotS[4]);
void genFromDataEven(int size, int dir, int rot, int toFile, char dirS[5], char rotS[4]);

int readFromFile(void);

#endif //TASKS_H
