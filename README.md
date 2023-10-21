# Philosophers

projet Philosophers de 42

## Description

![image qui represente de hilosophe se partagent un repa](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7b/An_illustration_of_the_dining_philosophers_problem.png/220px-An_illustration_of_the_dining_philosophers_problem.png)

Le problème du « [dîner des philosophes](https://fr.wikipedia.org/wiki/D%C3%AEner_des_philosophes) » illustre le partage de ressources dans les systèmes informatique en mettant en scène des philosophes qui doivent se partager des fourchettes pour pouvoir déguster des spaghettis.
Le problème consiste à identifier les conditions de partage impossible qui surviennent lorsque plusieurs philosophes essaient de saisir leurs fourchettes simultanément.

Il concerne l'ordonnancement des processus et l'allocation des ressources à ces derniers et a été énoncé par Edsger Dijkstra1. 

## Regle de l'enonce

- Un ou plusieurs philosophes sont assis autour d'une table ronde.
Il y a un grand bol de spaghettis au milieu de la table.
- Les philosophes alternativement mangent, pensent ou dorment.
Pendant qu’ils mangent, ils ne pensent ni ne dorment ;
en pensant, ils ne mangent ni ne dorment ;
et, bien sûr, pendant leur sommeil, ils ne mangent ni ne pensent.
- Il y a aussi des fourchettes sur la table. Il y a autant de fourchettes que de philosophes.
- Parce que servir et manger des spaghettis avec une seule fourchette est très peu pratique, un
le philosophe prend leurs fourchettes droite et gauche pour manger, une dans chaque main.
- Quand un philosophe a fini de manger, il remet ses fourchettes sur la table et
commence à dormir. Une fois réveillés, ils recommencent à réfléchir. La simulation s'arrête lorsque
un philosophe est mort de faim.
- Tout philosophe a besoin de manger et ne devrait jamais mourir de faim.
- Les philosophes ne se parlent pas.
- Les philosophes ne savent pas si un autre philosophe est sur le point de mourir.
- les philosophes doivent éviter de mourir !

En gros y a des philosophe autour d'une table et il doivent se partager un fourchette pourquil puisse mange et ils ont 3 etat
1. Mange
2. Pense
3. Dormen

## Regle global du code

si je décide de faire la partie bonus. Ils doivent tous deux respecter les règles suivantes :
- Les variables globales sont interdites !
- le programme doit prendre les arguments suivants :
```bash
number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
  - number_of_philosophers : Le nombre de philosophes et aussi le nombre
de fourchettes
  - time_to_die (en millisecondes) : Si un philosophe ne commençait pas à manger time_to_die
millisecondes depuis le début de leur dernier repas ou le début de la simulation, ils meurent.
  - time_to_eat (en millisecondes) : Le temps qu'il faut à un philosophe pour manger.
Pendant ce temps, ils devront tenir deux fourchettes
  - time_to_sleep (en millisecondes) : Le temps qu'un philosophe passera à dormir.
  - number_of_times_each_philosopher_must_eat (argument facultatif) : si y a rien la simulation sarret quand il y aura mort sinon faire que chaque philosophe mange number_of_times_each_philosopher_must_eat
- Chaque philosophe possède un numéro allant de 1 à number_of_philosophers.
- Le philosophe numéro 1 se trouve à côté du philosophe numéro number_of_philosophers.
Tout autre numéro philosophe N se situe entre le numéro philosophe N - 1 et le numéro philoso-
numéro de téléphone N + 1.

## LES LOGS

A propos des logs de ce que mon prgramme devra affiché : 
Tout changement d’état d’un philosophe doit être formaté comme suit :
  ◦ timestamp_in_ms X a pris une fourchette
  ◦ timestamp_in_ms X mange
  ◦ timestamp_in_ms X dort
  ◦ timestamp_in_ms X réfléchit
  ◦ timestamp_in_ms X est mort
Remplacez timestamp_in_ms par le temps ecoulé en millisecondes
et X avec le numéro philosophe

- Un message d'état affiché ne doit pas être confondu avec un autre message.
- Un message annonçant la mort d'un philosophe ne doit pas être affiché plus de 10 ms
après la mort effective du 1ier philosophe.

## Partie obligatoire

! PAS DE LIBFT

- Chaque philosophe est un thread
- Il y a une fourchette entre chaque paire de philosophes. Ainsi, s'il y a plusieurs
philosophes, chaque philosophe a une fourchette à gauche et une fourchette à droite
côté. S’il n’y a qu’un philosophe, il ne devrait y avoir qu’une seule fourchette sur la table.
- pour empêcher les philosophes de dupliquer les forks, vous devez protéger l'état des forks
avec un mutex pour chacun d'eux.

dossier philo pour le normal 
dossier philo_bonus pour le bonus