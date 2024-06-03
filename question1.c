//Créeation un processus père qui génère quatre processus fils.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_CHILDREN 4

int main() {
    pid_t children[NUM_CHILDREN];
    
    // Créer les processus fils
    for (int i = 0; i < NUM_CHILDREN; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Code du processus fils
            printf("Je suis le processus fils %d avec PID %d\n", i+1, getpid());
            exit(EXIT_SUCCESS); // Fin du processus fils
        } else {
            // Code du processus père
            children[i] = pid;
        }
    }

    // Code du processus père
    printf("Processus père avec PID %d\n", getpid());

    // Attendre la fin de tous les processus fils
    for (int i = 0; i < NUM_CHILDREN; i++) {
        waitpid(children[i], NULL, 0);
    }

    return 0;
}
