#include <stdlib.h>
#include <stdio.h>

void memory_leak_function() {
    int* leaky_array = malloc(5 * sizeof(int)); // Alloue de la mémoire mais ne la libère pas

    if (!leaky_array) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    leaky_array[5] = 42; // Problème 1 : Dépassement du tableau
    // Problème 2 : Mémoire non libérée (fuite de mémoire intentionnelle)
}

int main() {
    memory_leak_function();

    int* dangling_pointer = malloc(10 * sizeof(int));
    if (!dangling_pointer) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    free(dangling_pointer); // Libère la mémoire
    *dangling_pointer = 123; // Problème 3 : Utilisation d'un pointeur dangling

    return 0;
}

