#include <stdio.h>
#include <stdlib.h>

/*
 Um nun nicht immer ein struct schreiben zu müssen, kann man TypDefs verwenden; diese sind Alias-Namen.
 */

typedef struct Person {
    char name[50];
    char surname[50];
    unsigned int age;
    char job[50];
} person_t;

// typedef struct Person person_t;
// --> Man kann auch unter dem struct das Typdef schreiben, gängiger ist jedoch die obere Schreibweise!


void print_person(person_t *person) {
    printf("%s %s\n", person->name, person->surname);
    printf("%u\n%s\r\n\n", person->age, person->job);
}


int main() {

    person_t person1=
            {
                    .name = "Alexandra",
                    .surname="Ocasio-Cortez",
                    .age=32,
                    .job="Politikerin"
            };


    person_t person2 =
            {
                    .name = "Noam",
                    .surname="Chomsky",
                    .age=93,
                    .job="Professor für Linguistik a.D."
            };

    person_t person3 =
            {
                    .name = "Naoko",
                    .surname="Yamazaki",
                    .age=65,
                    .job="Astronautin"
            };

    person_t person_list[] = {person1, person2, person3};

    print_person(&person_list[0]);
    print_person(&person_list[1]);
    print_person(&person_list[2]);

    return EXIT_SUCCESS;
}


