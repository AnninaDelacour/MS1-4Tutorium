#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    char surname[50];
    unsigned int age;
    char job[50];
};

/*
 Wenn wir nun Namen+Nachnamen+Alter+Job als Funktion anlegen, haben wir jedes Mal 154 Byte, die wir aufrufen.
 Das ist nicht besonders effizient.
 Wir können aber mit Pointern arbeiten! Dafür können wir auf Unions zurückgreifen!
 Überall, wo wir den "."-Operator (=Punktoperator) verwendet haben, machen wir einen Pfeil hin: ->
 */

void print_person(struct Person *person) {
    printf("%s %s\n", person->name, person->surname);
    printf("%u\n%s\r\n\n", person->age, person->job);
}


int main() {

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

    struct Person person_list[] = {person1, person2, person3};

    print_person(&person_list[0]);
    print_person(&person_list[1]);
    print_person(&person_list[2]);

    return EXIT_SUCCESS;
}//
// Created by Annina Ecker on 04.01.22.
//

