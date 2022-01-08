#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    printf("Bitte gib einen Text ein:\n");

    // Wir erstellen ein File mit dem Namen "integers_output.txt"; mit "w" geben wir an, dass wir in das File schreiben (w = write)
    FILE* output = fopen("../integers_output.txt", "w");

    // Wir überprüfen, ob das File geöffnet werden kann
    if (output == NULL) {
        perror("Datei konnte nicht geoeffnet werden!");
        return EXIT_FAILURE;
    }

    // Mit fgets können wir den Userinput zeilenweise einlesen; wir erstellen uns dafür einen Puffer, der 1000 Zeichen einlesen kann
    char buffer[1000];
    while (fgets(buffer, 1000, stdin) != NULL) {

        // Hat der User eine leere Zeile eingegeben (entered), wird die Schleife abgebrochen
        if (buffer[0] == '\r' /* Windows */ || buffer[0] == '\n' /* Linux */) {
            break;
        }

        // isInteger verwenden wir als Flag, um "true" oder "false" zu signalisieren
        int isInteger = 0;

        // Jeder char in einer Zeile wird eingelesen mithilfe von Pointer Arithmetik
        for (char* ptr = buffer; *ptr != '\0'; ptr++) {

            // Mit der If-Verzweigung prüfen wir, ob ein char eine Zahl ist. Wenn ja, wird diese in das Outputfile geschrieben
            if (*ptr >= '0' && *ptr <= '9') {
                isInteger = 1;
                fputc(*ptr, output);
                // Falls der jetzige char keine Zahl war, der vorherige char aber, soll ein Abstand in das File geschrieben werden
            } else if (isInteger) {
                isInteger = 0;
                fputc(' ', output);
            }
        }

        // Hier gebe wir an, dass wir nach jedem Check eine neue Zeile haben möchten
        fputc('\n', output);
    }

    // Wir schließen das File und können somit nichts mehr hineinschreiben.
    printf("Ende der Eingabe.\n");
    fclose(output);

    return EXIT_SUCCESS;
}
