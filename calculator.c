#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "operations.h"


// Call by Reference-Funktion, um dem User die Möglichkeit zu geben, den Rechner zu schließen, sobald "exit" in die
// Konsole eingetippt wurde

void checkExit(const char* str) {
    if (strcmp(str, "exit\n") == 0 || strcmp(str, "exit\r\n") == 0) { // Zweifacher Check für Windows bzw. Linux/UNIX OS
        printf("Rechner wird geschlossen\n");
        /* Außerhalb der Main-Funktion können wir ein Programm mithilfe von "exit()" schließen (benötigt dafür <stdlib.h>).
         Die '0' signalisiert ein erfolgreiches Beenden --> exit(0) ist auf andere Systeme portabel, exit(1) nicht!
         */
        exit(0);
    }
}


int main(int argc, char* argv[]) {

    // Wir legen zwei integer Variablen an für die Usereingabe, und eine char Variable für den Operator
    int num1, num2;
    char operator;

    while (1) {
        // Im buffer werden die jeweiligen eingegebenen Zahlen gespeichert
        char buffer[128];

        // Mit der ersten Eingabe wird die erste Zahl abgefragt
        printf("Bitte 1. Zahl eingeben: ");
        fflush(stdout);
        fgets(buffer, 128, stdin);
        checkExit(buffer);
        if (sscanf(buffer, "%d", &num1) == 0) {
            // Tätigt ein User eine falsche Eingabe, wird die Eingabe übersprungen --> continue
            fprintf(stderr, "> Falsche Eingabe!\n");
            continue;
        }

        // Eingabe der Operation
        printf("> Geben Sie die Operation ein: ");
        fflush(stdout);
        fgets(buffer, 128, stdin);

        checkExit(buffer);

        // Es wird kontrolliert, ob eine gültige Eingabe für den Operator getätigt wurde
        // -> es darf nur ein gültiger char eingegeben werden

        if ( (buffer[1] == '\r' /* Windows */ || buffer[1] == '\n' /* Linux */)
             && (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '/' || buffer[0] == '*')) {
            operator = buffer[0];
        } else {
            fprintf(stderr, "> Falsche Eingabe!\n");
            continue;
        }

        // Eingabe der 2. Zahl
        printf("> Geben Sie Zahl 2 ein: ");
        fflush(stdout);
        fgets(buffer, 128, stdin);
        checkExit(buffer);
        if (sscanf(buffer, "%d", &num2) == 0) {
            fprintf(stderr, "> Falsche Eingabe!\n");
            continue;
        }


        if (operator == '+') {
            int r = 0;
            r = add(num1, num2);
            printf("%d\n", r);
            break;
        } else if (operator == '-') {
            int r = 0;
            r = sub(num1, num2);
            printf("%d\n", r);
            break;
        } else if (operator == '*') {
            int r = 0;
            r = mult(num1, num2);
            printf("%d\n", r);
            break;
        } else if (operator == '/') {
            float r2 = mydiv(num1, num2);
            printf("%f\n", r2);
            break;
        }
    }

    return EXIT_SUCCESS;
}
