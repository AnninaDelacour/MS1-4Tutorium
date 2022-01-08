#include <stdio.h>
#include <stdlib.h>

/*
 structs dienen dazu, Informationen zu bündeln und an einer Stelle im Code abzuspeichern. In structs kommen die üblichen
 Datentypen vor (int, char,...).
 structs können dazu verwendet werden, wenn wir wiederkehrende Attribute haben.
 Beispielsweise können wir Personendaten abfragen - jede Person hat idR einen Vor- und Nachnamen, ein Alter und ein Geburtsdatum.
 */

// Wir kreiern ein struct, um bestimmte Daten einer Person abzufragen
struct Person {
    char name[50];
    char surname[50];
    unsigned int age;
    char job[50];
};


int main() {

    /*
     Die Syntax von structs:
     Wenn wir unsere angelegten structs in der Main-Funktion verwenden möchten, rufen wir sie mit "struct" und dem
     Namen, den wir oberhalb deklariert haben, auf und fügen z.B. eine "Person 1" hinzu. Damit haben wir das struct deklariert.
     Um es zu initialisieren, übergeben wir den Attributen Werte/Inhalte (zB Attribut wäre hier "name",
     der Inhalt davon der Name der Person1).

     Man muss nicht ".name" usw. schreiben - es hilft aber der Lesbarkeit! Außerdem ist so klar, welches Attribut aufgerufen wird.
     Man kann allerdings auch einfach die jeweiligen Werte bzw. Inhalte in die struct schreiben {"Hans", "Meier", ...}.

     Strukturnamen beginnt man idR mit Großbuchstaben ("Person"). Es ist kein Muss, wird aber in der Praxis oft so verwendet.

     */

    struct Person person1 =
            {
                    .name = "Alexandra",
                    .surname="Ocasio-Cortez",
                    .age=32,
                    .job="Politikerin"
            };

    struct Person person2 =
            {
                    .name = "Noam",
                    .surname="Chomsky",
                    .age=93,
                    .job="Professor für Linguistik a.D."
            };

    struct Person person3 =
            {
                    .name = "Naoko",
                    .surname="Yamazaki",
                    .age=65,
                    .job="Astronautin"
            };

    printf("%s %s\n", person1.name, person1.surname);
    printf("%s %s\n", person2.name, person2.surname);
    printf("%s %s\n", person3.name, person3.surname);

    return EXIT_SUCCESS;
}