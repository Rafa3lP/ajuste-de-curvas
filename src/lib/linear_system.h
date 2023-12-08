#ifndef LINEAR_SYSTEM_H
#define LINEAR_SYSTEM_H

#include <stdio.h>

typedef struct {
    int n;
    float **A;
    float *b;
    float *x;
} linearSystem;

void allocateSystem(linearSystem *s);

void freeSystem(linearSystem *s);

void gausianElimination(linearSystem *s);

void swapRows(linearSystem *s, int row1, int row2);

void readSystem(linearSystem *s, FILE *file);

void printSolution(linearSystem *s);

void printSystem(linearSystem *s);

void fillSystem(linearSystem *s, float number);

#endif