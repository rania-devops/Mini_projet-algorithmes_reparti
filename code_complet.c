//code complet (toutes les questions ensembles)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#include <fcntl.h>

#define NUM_CHILDREN 4

// Déclaration des variables globales
pid_t children[NUM_CHILDREN];
sem_t *sem;

// Fonction de traitement du signal
void signal_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Signal de confirmation reçu du processus fils avec PID %d\n", getpid());
    }
}

int main() {
    // Initialiser le sémaphore
    sem = sem_open("/my_semaphore", O_CREAT | O_EXCL, 0666, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    // Enregistrement du gestionnaire de signal
    signal(SIGUSR1, signal_handler);

    // Créer les processus fils
    for (int i = 0; i < NUM_CHILDREN; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Code du processus fils
            signal(SIGUSR1, signal_handler); // Redéfinir le gestionnaire de signal dans le fils
            sem_wait(sem); // Attendre le signal de départ
            // Effectuer des tâches complexes (simulées par sleep ici)
            sleep(1);
            // Envoyer un signal de confirmation au processus père
            kill(getppid(), SIGUSR1);
            exit(EXIT_SUCCESS); // Fin du processus fils
        } else {
            // Code du processus père
            children[i] = pid;
        }
    }

    // Synchronisation : signal de départ pour les processus fils
    for (int i = 0; i < NUM_CHILDREN; i++) {
        sem_post(sem);
    }

    // Attendre les signaux de confirmation des processus fils
    int confirmed_children = 0;
    while (confirmed_children < NUM_CHILDREN) {
        // Attendre un signal de confirmation
        pause();
        confirmed_children++;
        printf("Confirmation reçue de %d processus fils.\n", confirmed_children);
    }

    // Fermer le sémaphore
    sem_close(sem);
    sem_unlink("/my_semaphore");

    return 0;
}
