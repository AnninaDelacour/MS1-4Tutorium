#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[255];
    char surname[255];
    int age;
    char hobbies[5][255];
} Person;

int main(){

    // Wir erstellen ein Array, das 20 Personen speichert
    Person personen[20];

    // Wir öffnen die Datei, in der wir die Daten gegeben haben. Aus dieser Datei LESEN wir die benötigten Informationen heraus.
    FILE *input = fopen("../persons_input.txt", "r");
    // Wie immer überprüfen wir, ob die Datei geöffnet werden kann oder nicht
    if (input == NULL) {
        perror("Datei konnte nicht geoeffnet werden");
        return EXIT_FAILURE;
    }


    int i = 0; // Wir erstellen eine Variable, die den Indexwert der aktuellen Person im Array liefert

    char buffer[1000];

    // Wir lesen Zeile für Zeile das File
    while (fgets(buffer, 1000, input) != NULL) {
        char buffer2[1000]; // Den zweiten Puffer erstellen wir, um die Hobbies als Strings abzuspeichern

        /*
         Zu memset:
         memset wird dazu verwendet, einen Speicherblock mit bestimmten Werten zu befüllen.
         Um diese Funktion verwenden zu können, müssen wir die Standardbibliothek von <string.h> inkludieren.

         memeset's Syntax ist folgendermaßen aufgebaut:      void *memset(void *ptr, int x, size_t n);
         - ptr: Ist die Startadresse im Speicher, wo wir mit dem Befüllen von Werten beginnen
         - x: Der Wert/die Werte, mit denen wir befüllen
         - n: Anzahl an Bytes, die wir befüllen --> ist somit die Größe, daher können wir hier sizeof() verwenden!
         memset ist hier ein void pointer, um jeden Datentyp als Pointer in der Funktion verwenden zu können.

         Sources:
         https://www.geeksforgeeks.org/memset-c-example/
         https://www.tutorialspoint.com/c_standard_library/c_function_memset.htm

         Wir übergeben hier also in jeder Zeile die Speicheradresse aus unserem Personen-Array,
         beginnend am Anfang, und geben als Größe die Länge des structs Person an.
         So können wir den aktuellen Eintrag initialisieren und gleichzeitig überprüfen,
         ob valide Daten bei den Hobbies in persons_input.txt eingetragen wurden.
         All dies wird in die Variable "buffer" gegeben!
         */
        memset(&personen[i], 0, sizeof(Person));

        // Parse the line
        // We can directly store the name, surname and the age into the structure
        // The hobbies are stored in a buffer
        // The return value of sscanf tells us whether the format of the line is correct or not

        /*
         sscanf liest formattierten Input eines Strings ein --> sscanf(const char *str, const char *format,...).
         Auf diese Weise können wir prüfen, ob in "buffer" die jeweiligen Daten in entsprechendem Format und in
         einer durchführbaren Größe vorhanden sind.
         In der Variable "buffer2" speichern wir die Hobbies ab, durch die wir dann noch einmal gesondert iterieren!
         %254[^, \r\n] = ist ein Regex Befehl, der prüft, ob eine maximale Stringlänge von 254 erfüllt ist, ohne "," (Komma),
         \r oder \n.
         */
        if (sscanf(buffer, "%254[^;\r\n];%254[^;\r\n];%d;%999[^\r\n]", personen[i].name,
                   personen[i].surname, &personen[i].age, buffer2) == 4) {

            // Parse the hobby string and store up to five hobbies in our struct
            // When there are less than five hobbies then sscanf will skip the struct entries for which it cannot find hobbies
            /*
             Mithilfe von sscanf prüfen wir die Einträge der Hobbies, die wir in buffer2 gespeichert haben.
             Auch hier verwenden wir Regex, und prüfen, ob Länge bzw. Größe und Format passen.
             Bis zu fünf Hobbies können gespeichert werden.
             */
            sscanf(buffer2, "%254[^,\r\n],%254[^,\r\n],%254[^,\r\n],%254[^,\r\n],%254[^,\r\n]",
                   personen[i].hobbies[0], personen[i].hobbies[1], personen[i].hobbies[2],
                   personen[i].hobbies[3], personen[i].hobbies[4]);

            // Nachdem wir eine Person und deren Hobbies geprüft haben, zählen wir unseren "Index-Zähler" um eins hoch.
            i++;

            // Haben wir 20 Zeilen eingelesen, brechen wir die Schleife ab, um einen Buffer Overflow zu verhindern
            if (i >= 20) {
                break;
            }

        } else {
            fprintf(stderr, "Nicht korrekte Zeile gefunden: %s\n", buffer);
        }

    }


    /*
     Sobald wir unsere validen Array entries erstellt haben, werden die Nachnamen all jener ausgegeben,
     die zwischen 20 und 30 Jahre alt sind und deren Hobby tanzen ist.
     Um das in einem Schritt zu lösen, können wir eine verschachtelte For-Schleife mit einer If-Bedingung verwenden.
     Für die äußere For-Schleife verwenden wir eine neue Variable int j = 0, und lassen die äußere For-Schleife durch
     alle 20 Zeilen laufen (i = 20)!
     Wenn das Alter >20 und <30 ist, gehen wir mit einer zweiten For-Schleife durch Einträge in jeder Zeile (Name, Nachname, Hobbies).
     Um auf die Hobbies zugreifen und diese mit dem String "Tanzen" vergleichen zu können, verwenden wir strcmp(),
     und wir greifen auf die Daten mittels Punktoperator zu: personen[ZEILE = j].hobbies[ZEILENEINTRAG = k].
     Achtung: Die strcmp()-Funktion wird auf "True" gesetzt mit "0", da wir in C wahr = 0 ausdrücken und falsch = 1.
     */
    for (int j = 0; j < i; j++) {
        if (personen[j].age >= 20 && personen[j].age <= 30) {
            for (int k = 0; k < 5; k++) {
                if (strcmp(personen[j].hobbies[k], "Tanzen") == 0) {
                    printf("%s\n", personen[j].surname);
                }
            }
        }
    }

    return EXIT_SUCCESS;
}