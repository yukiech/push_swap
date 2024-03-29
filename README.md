# Push_Swap
Push_Swap est un projet d’algo simple.<br />
Nous disposons de 2 "Stacks" (de notre choix) et devont implémenter ou réaliser un algo qui permettra de trier les INT donnés (qui commencent en Stack A) en entrée de programme du plus petit au plus grand sur la stack A.<br />
Nous ne pouvons utiliser que les commandes prédéfinies décrites plus bas.<br />
Le programme doit print une suite de ces commandes dans le terminal.<br />

# Utilisation

> $>./push_swap 2 1 3 6 5 8<br />
> sa<br />
> pb<br />
> pb<br />
> pb<br />
> sa<br />
> pa<br />
> pa<br />
> pa<br />
> $>./push_swap 0 one 2 3<br />
> Error<br />

> $>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG<br />
> OK<br />

Le repo contient également 2 checkers ([push_swap_tester](https://github.com/louisabricot/push_swap_tester) et [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)) qui ont été réalisés par d'autre programmeurs et qui m'ont énormément aidés à réaliser le projet.

Le 125% nécessitait aussi de coder un checker nous même. (checker.c)

# Liste des commandes

**__sa (swap a) :__**<br />
  Intervertit les 2 premiers éléments au sommet de la pile a.<br />
  Ne fait rien s’il n’y en a qu’un ou aucun.<br />

**__sb (swap b ) :__**<br />
  Intervertit les 2 premiers éléments au sommet de la pile b.<br />
  Ne fait rien s’il n’y en a qu’un ou aucun.<br />
  
**__ss :__** <br />
  sa et sb en même temps.<br />
  
**__pa (push a) :__**<br />
  Prend le premier élément au sommet de b et le met sur a.<br />
  Ne fait rien si b est vide.<br />
  
**__pb (push b) :__**<br />
  Prend le premier élément au sommet de a et le met sur b.<br />
  Ne fait rien si a est vide.<br />
  
**__ra (rotate a) :__**<br />
  Décale d’une position vers le haut tous les élements de la pile a.<br />
  Le premier élément devient le dernier.<br />
  
**__rb (rotate b) :__**<br />
  Décale d’une position vers le haut tous les élements de la pile b.<br />
  Le premier élément devient le dernier.<br />
  
**__rr :__**<br />
  ra et rb en même temps.<br />
  
**__rra (reverse rotate a) :__**<br />
  Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.<br />
  
**__rrb (reverse rotate b) :__**<br />
  Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.<br />
  
**__rrr :__**<br />
  rra et rrb en même temps.<br />

![alt text](https://cdn.discordapp.com/attachments/903236693463797810/1023507482057904148/push_swap2.png)

# Ma solution
Pour des raisons de simplicité et de connaissance j'ai choisi d'utiliser des int * comme type de Stacks.
Ce choix était moins pratique que des listes chaînées mais correspondait mieux à mes connaissances.

J'ai fait le choix de ne pas tenter d'algo complexe et déjà existants que j'aurais du adapter au commandes à ma disposition mais de tenter une autre logique plus simple a comprendre et expliquer.
(Exemples d'algo de tri standards : https://www.youtube.com/watch?v=OOBBI-kSChM)

La base de logique de mon algo est la suivante :
![alt text](https://cdn.discordapp.com/attachments/903236693463797810/1023514160853696624/algo.png)

Cette logique avait été sufffisante pour valider le projet mais j'étais revenu dessus afin de la valider à 125%.
Le 125% consistait à "optimiser" l'algo afin que le nombre de commandes à effectuer soit le plus petit possible. (La vitesse d'execution n'est pas relevante même si elle doit rester raisonnable)
J'ai donc du rajouter divers petites optimisations frustrante (-20 commandes, -30commandes, ...) qui ont finies par rendre mon code moins joli.

Notamment, au lieu de calculer une taille de "chunk" fixe en fonction du nombre d'int en input, j'ai créer un nouveau main qui appele mon ancien main avec +- 10 de la taille de "chunk" calculée puis récupère les commandes sous forme de strings et les compares entre elles afin de trouver une version plus courte.
