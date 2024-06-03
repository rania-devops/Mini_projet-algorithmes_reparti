//Utilisation d un mécanisme de sémaphore pour gérer la synchronisation
sem_t *sem;
sem = sem_open("/my_semaphore", O_CREAT | O_EXCL, 0666, 0);
// Code de synchronisation entre les processus
sem_wait(sem); // Processus fils attend le signal de départ
sem_post(sem); // Processus père envoie le signal de départ
