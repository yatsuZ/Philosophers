# Résumé de l'énoncé

Ce résumé inclut une traduction des principaux points de l'énoncé du projet [Philosopeher](en.subject.pdf)

## Règles de l'énoncé

- Un ou plusieurs philosophes sont assis autour d'une table ronde avec un grand bol de spaghettis au milieu.
- Les philosophes alternent entre manger, penser ou dormir, avec des règles spécifiques pour chaque état.
- Des fourchettes sont placées sur la table, correspondant au nombre de philosophes présents.
- Chaque philosophe utilise les deux fourchettes pour manger.
- Le programme s'arrête lorsque l'un des philosophes meurt de faim.
- Les philosophes ne se parlent pas et ne peuvent pas détecter si un autre philosophe est sur le point de mourir.

## Regle global du code

Les règles suivantes doivent être respectées :

- Interdiction d'utiliser des variables globales.
- Le programme doit prendre les arguments suivants :
	- number_of_philosophers
	- time_to_die
	- time_to_eat
	- time_to_sleep
	- \[number_of_times_each_philosopher_must_eat](optionnel)
- Chaque philosophe possède un numéro.

## LES LOGS

Concernant les logs que votre programme doit afficher :
Tout changement d’état d’un philosophe doit être formaté comme suit :
  ◦ timestamp_in_ms X a pris une fourchette
  ◦ timestamp_in_ms X mange
  ◦ timestamp_in_ms X dort
  ◦ timestamp_in_ms X réfléchit
  ◦ timestamp_in_ms X est mort

Remplacez timestamp_in_ms par le temps écoulé en millisecondes
et X par le numéro du philosophe.

- Un message d'état affiché ne doit pas être confondu avec un autre message.
- Un message annonçant la mort d'un philosophe ne doit pas être affiché plus de 10 ms après la mort effective du premier philosophe.

## Partie obligatoire

! PAS DE LIBFT

- Utilisation de threads pour chaque philosophe.
- Utilisation de mutex pour protéger l'état des fourchettes et éviter les conflits.

## Arborescence des dossiers

- Dossier 'philo' pour la version normale.
- Dossier 'philo_bonus' pour la version bonus.