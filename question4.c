//Le processus père doit afficher un message à chaque fois qu'il reçoit une confirmation d'un processus fils.
// Dans le code du processus père après l'envoi de signal aux fils
pause(); // Attend un signal de confirmation
printf("Confirmation reçue d'un processus fils.\n");
