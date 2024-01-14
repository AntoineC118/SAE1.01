# SAE1.01 Agenda

Ce projet est une SAE (un devoir universitaire), l'objectif est de réaliser un agenda simple, sans utiliser de librairies avec comme interface la console.

Cette application possède donc un ensemble de fonction dont le but est de pouvoir gérer un agenda simple:
- F0 Créer et charger un agenda.
- F1 Modifier la description et le titre de l'agenda.
- F2 Affiche le contenu de l'agenda dans la console.
- F3 Ajoute un événement dont les informations sont données par l'utilisateur.
- F4 Supprime un événement
- F5 Export l'agenda sur forme HTML
- F6 enregistre l'agenda dans un fichier texte .agd
- F7 Quitte l'application.

## Comment lancer l'application:

L'application est fournit avec un makefile contenant trois commandes:
- "make all" permet de compiler et créer un exécutable pour l'application.
- "make clean" permet de nettoyer l'arborescence des fichiers binaires.
- "make clear_agendas" permet de supprimer tout les agendas.

Pour lancer l'application, executez la commande pour créer l'executable et lancez le.

### Détailles de fonctionnement.

Le menu principale, demandera à l'utilisateur de taper la fonction qu'il souhaite éxécuter, ce paramètre prend un chiffre cependant aucun format n'est à respecter.
Il est tout aussi bien possible de taper "1", "F01" ou bien "zeipufgzeifguyg1zipefhpieufg" le menu fonctionnera toujours. Cependant si vous ne renseignez pas une des fonctions possible, votre action sera annulé. A noté aussi que vous cherchez écrire plusieurs apellation de fonction, par exemple avec "1234567", seul la première sera executé.

La fonction F0 demande à l'utilisateur, le nom du fichier ou le chemin d'accès du quel charger ou créer le fichier de sauvegarde de l'agenda.
Ainsi il est possible de charger ou créer un fichier dans n'importe quel repertoire de l'ordinateur à condition que le chemin d'accès soit valide.
Dans le cas ou seul le nom est spécifié, le fichier sera créer par défaut dans le répertoire "agendas".
Le programme n'est pas prévu pour créer le chemin d'accès à votre place, si le chemin n'est pas valide, le programme ne pourra tout simplement pas créer votre fichier,
et vous reverra une erreur lorsque vous essairez de sauvegarder.

La fonction F01 demandera à l'utilisateur un titre et une description. Le titre, s'écrit sur une seul ligne et la description doit se termine avec un "." sur une ligne vide. A la fin du programme si tout s'est passé correctement, vous reviendrez sur le menu principale. Cette fonction est appellé 

La fonction F02 affichera de l'agenda son titre, sa description, et la liste des événements. Dans le cas ou aucun événements n'est présent dans l'agenda, la mention "Aucun événement" s'affichera à la place du premier. Pour revenir au menu principale, il suffit d'appuyer sur entrée.

La fonction F03 demandera le titre de l'événement puis sa description sur le même fonctionnement que la fonction F01 enfin elle demandera la date de début et de fin de l'événement sous format dd/mm/aaaa hh:mm les caractères séparateur importe peu. Si le format n'est pas respecté, le programme renvera la mention "format non respecté" suivie de "date invalide". Les dates prisent en compte sont celles du calendrier grégorien allant de l'an 0 à l'an 9999 sans prendre en compte les dates de passages du calendrier Julien au Grégorien. Dans le cas ou une date ne corresponderait au calendrié, la mention "date invalide" apparaitra et le programme redemandera la date. Lorsque un événement est ajouté correctement, le programme retournera au menu principale.

La fonction F04 permet de supprimer un événement, le fonction demandera le titre de l'événement à supprimer et le supprimera. A la fin du programme, si tout c'est passé corrèctement le programme devrait retourner au menu. Dans le cas où l'événement indiqué n'existe pas, la mention "cet événement n'existe pas" apparaitra et il suffira de taper entrée pour retourner au menu. Dans le cas ou plusieurs événements porte le même nom, la liste des événements possèdant le même nom s'affichera avec leur dates associées ainsi que la mention "Ces événements portent le même nom, le quel souhaitez vous supprimer ?". Il faudra alors taper le chiffre correspondant et alors l'événement sera supprimé.

La fonction F05 exportera l'agenda dans un tableau sous forme HTML avec les dates, le titre et la description. Cette page sera sauvegardé dans ./agendaweb/<nomdelagenda>.html si le fichier existe, il sera écrasé.

La fonction F06 enregistrera l'agenda dans l'arborescence spécifié au lancement du programme, si l'agd existe déjà, il sera modifié. Si l'agenda n'existe pas, le fichier correspondant sera créer à l'aborescence indiqué. Ce fichier est un fichier texte utilisant l'extension .agd

La fonction F07 permet de quitter l'application lorsqu'executé, si aucune modification n'a été appliqué à l'agenda par les fonctions F01,F03 ou F04, la fonction fera quitté dans l'agenda. Dans le cas contraire, la fonction demandera à l'utilisateur si il est sûr de vouloir quitter sans sauvegardé sont agenda.

## tests

Ce programme est fournit avec 7 fonctions de tests réalisé avec Expect sous langage TCL allant de F0.exp à F6.exp . Chaque fonctions de tests doit être executé individuellement et celle-ci viendra tester chaques fonctions du programme.