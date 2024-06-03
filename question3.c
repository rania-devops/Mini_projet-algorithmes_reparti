/*Les processus fils doivent traiter les signaux reçus, effectuer des tâches complexes, et répondre en envoyant des signaux de confirmation au processus père.*/

void signal_handler(int signum) {
    // Gérer le signal reçu
}

signal(SIGUSR1, signal_handler);
