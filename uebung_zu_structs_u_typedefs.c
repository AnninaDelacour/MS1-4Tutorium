#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 Formel für die Berechnung des Volumens eines Zylinders: V = G * h = pi * r^2 * h
 */

typedef struct Zylinder {
    double radius;
    double height;
} Zylinder_t;

void calc_zylinder(Zylinder_t *zylinder, double *result){
    *result = M_PI * (pow(zylinder->radius, 2)) * zylinder->height;
}


int main() {

    Zylinder_t z =
            {
                    .radius = 4,
                    .height = 8,
            };

    z.height = 8;
    z.radius = 4;

    printf("Radius = %.2f, Höhe = %.2f\n", z.radius, z.height);
    double result = 0;
    calc_zylinder(&z, &result);

    printf("Volumen des Zylinders: %.2f\r\n", result);

    return EXIT_SUCCESS;
}
