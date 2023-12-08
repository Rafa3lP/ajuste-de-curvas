#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib/linear_system.h"

/**
 * 
 * Transformação em linear
 * 
 * N = B0 * e^(B1 * t)
 *
 * ln N = ln B0 + (B1 * t) * ln e
 * ln N = ln B0 + (B1 * t)
 * 
 * u = ln N
 * _B0 = ln B0
 * _B1 = B1
 * x = t
 * 
 *    1   x               y
 * 1[ ∑1  ∑t  ] [_B0] = [  ∑(ln N)    ]
 * x[ ∑t  ∑t² ] [_B1]   [  ∑(t * ln N)]
 */

int main (int argc, char *argv[]) {
    const char *fileName = "dados.dat";
    FILE *file = fopen(fileName, "r");

    float t, N;

    if(file == NULL) {
        printf("Error: cannot open file %s\n", fileName);
        return EXIT_FAILURE;
    }

    linearSystem s;
    s.n = 2;
    allocateSystem(&s);
    fillSystem(&s, 0);

    while (fscanf(file, "%f %f", &t, &N) == 2) {
        // somatório de 1
        s.A[0][0] += 1;
        // somatório de t
        s.A[0][1] += t;
        // somatório de t²
        s.A[1][1] += pow(t, 2);
        // somatório de ln de N
        s.b[0] += log(N);
        // somatório de t * ln de N
        s.b[1] += t * log(N);
    }

    fclose(file);

    s.A[1][0] = s.A[0][1];

    // resolver sistema linear
    gausianElimination(&s);

    // re-transformando valores
    float beta_0 = exp(s.x[0]);
    float beta_1 = s.x[1];

    // Estimando a idade para uma quantidade específica de carbono-14
    float target_N = 53307321157;
    /**
     * N = B0 * e^(B1 * t)
     * ln N = ln B0 + (B1 * t)
     * ln B0 + (B1 * t) = ln N
     * (B1 * t) = ln N - ln B0
     * t = (ln N - ln B0) / B1
     * 
     * t = ln(N / B0) / B1
     */
    float estimated_age =  log(target_N / beta_0) / beta_1;

    // resultados
    printf("--------------------------------------------------\n");
    printf("Beta0: %g\n", beta_0);
    printf("Beta1: %g\n\n", beta_1);
    printf("Estimativa de idade para N = %g: %g anos\n", target_N, estimated_age);
    printf("--------------------------------------------------\n");

    freeSystem(&s);
}