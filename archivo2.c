#include <stdio.h>

struct Persona {
    char nombre[20];
    int edad;
};

int main() {
    struct Persona p1;
    struct Persona *p2;

    p2 = &p1;

    p1.edad = 25;
    printf("Edad de p1: %d\n", p1.edad);

    p2->edad = 30;
    printf("Edad de p2: %d\n", p2->edad);

    return 0;
}
