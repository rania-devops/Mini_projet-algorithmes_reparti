/*Le processus père doit envoyer des signaux aux processus fils pour leur demander d'exécuter des tâches spécifiques.*/
pid_t pid; // PID du processus fils
int signal_number = SIGUSR1;
kill(pid, signal_number);
