#include <stdio.h>
#include <stdlib.h>
#include "lib/linear_system.h"

int main (int argc, char *argv[]) {
    linearSystem c;
    c.n = 3;
    allocateSystem(&c);
    c.A[0][0] = 1;
    c.A[0][1] = 2;
    c.A[0][2] = 3;
    c.A[1][0] = 4;
    c.A[1][1] = 5;
    c.A[1][2] = 6;
    c.A[2][0] = 7;
    c.A[2][1] = 8;
    c.A[2][2] = 9;
    c.b[0] = 1;
    c.b[1] = 2;
    c.b[2] = 3;
    printSystem(&c);
}