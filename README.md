# projet-algo-reparti

**Rapport sur le Projet de Gestion Avancée des Processus et des Signaux en C sous Linux**

**1. Préambule**

Cette étude de cas expose le développement d'une application en C fonctionnant sous l'environnement Linux, démontrant la gestion poussée des processus et des signaux. L'objectif de ce projet est de mettre en œuvre la création de processus parent-enfant, la communication par signaux, la synchronisation des activités et l'emploi de dispositifs de contrôle des processus.

**2. Buts du Projet**

Les buts principaux de ce projet incluent :

1. Concevoir un processus parent capable de générer quatre processus enfants.
2. Transmettre des signaux aux processus enfants pour initier des actions déterminées.
3. Gérer les signaux reçus par les processus enfants, réaliser des opérations complexes et renvoyer des signaux d'achèvement au processus parent.
4. Signaler par un message chaque réception de confirmation par le processus parent.
5. Établir une synchronisation parmi les processus enfants afin qu'ils entament leurs actions seulement après réception d'un signal commun.
6. Appliquer des sémaphores pour orchestrer la synchronisation.

**3. Approche Méthodologique**

Les étapes suivantes ont été adoptées pour réaliser les buts fixés :

1. Planification : Un schéma précis a été élaboré pour chaque but, identifiant les fonctions clés et les mécanismes nécessaires à l'exécution des actions.
2. Codage : À travers le langage C et les fonctions système Linux (fork, kill, signal, etc.), le code a été écrit pour matérialiser chaque aspect du projet.
3. Essais et Correction : Des tests rigoureux ont été menés pour assurer la fiabilité du programme, corrigeant toute erreur ou dysfonctionnement.
4. Documentation : Le code a été documenté de façon claire, détaillant chaque fonction et élément significatif de l'application.

**4. Accomplissements**

L'application conçue atteint avec succès tous les buts établis. Elle initie un processus parent qui engendre quatre processus enfants, communique via signaux, exécute des opérations complexes, reçoit des confirmations des processus enfants et synchronise leurs actions grâce aux sémaphores.

**5. Synthèse**

Ce projet a été une occasion concrète d'appliquer des notions avancées de manipulation des processus et des signaux en C sous Linux. L'application illustre efficacement la génération de processus, la communication inter-processus, la synchronisation des actions et l'usage de dispositifs de contrôle des processus.

