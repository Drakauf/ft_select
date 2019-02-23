<h1 align="center">
ft_select 
</h1>

<h3 align="center"><b>Description</b></h3>
<p>Ce projet a pour but de vous initier à la manipulation du terminal avec les termcaps. Vous allez ici apprendre à créer une interface utilisateur pour un programme lancé dans le terminal.</p>

<p><b>Objectif :</b> Interface utilisateur via le terminal, Bibliothèque Termcaps</p>
<p><b>Langage :</b> C.</p>
<p><b>Fonctions autorisées :</b>isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs, open, close, write, malloc, free, read, exit, signal + d'autres dans le cadre des bonus</p>

<h3 align="center">Consignes [Partie Obligatoire]</h3>
<p>• Ecrire un programme "ft_select" qui prend en paramètre une série d’arguments.
La liste d’arguments s’affiche.</p>
<p>• L’utilisateur peut alors se déplacer dans la liste des arguments à l’aide des flèches
(la liste est circulaire).</p>
<p>• Un ou plusieurs choix peuvent être sélectionnés ou désélectionnés à l’aide de la
touche espace. A chaque sélection effectuée, le curseur doit automatiquement se
positionner sur l’élément suivant.</p>
<p>• Dès que l’utilisateur valide la sélection à l’aide de la touche return, la liste des
choix doit être renvoyée au shell. Les choix renvoyés devront être separés par
le caractère espace. Ceci permettra alors d’utiliser votre programme ft_select à
l’intérieur d’un script shell (pour faire un "set", par exemple).
Vous devrez également gérer le redimensionnement de la fenêtre par l’utilisateur.
La liste doit s’afficher sur plusieurs colonnes si la taille de la fenêtre ne comporte
pas assez de lignes pour tout afficher en une seule colonne. Si l’utilisateur redimensionne la fenêtre en cours d’utilisation, l’ensemble des choix doit se repositionner
automatiquement et les choix selectionnés doivent le rester. Le curseur de selection
doit être positionné de manière raisonnable après un redimensionnement.</p>
<p>• Si la fenêtre est trop petite pour tout afficher (pas assez de lignes et/ou de colonnes,
alors le programme doit réagir raisonnablement tant que la dimension de la fenêtre
n’est pas suffisante. En aucun cas il ne doit quitter. Lorsque la fenêtre est de
nouveau assez grande, le programme doit fonctionner de nouveau normalement.</p>
<p>• Si l’utilisateur appuie sur la touche echap, le programme ne doit rien renvoyer au
shell et terminer normalement.</p>
<p>• Si l’utilisateur appuie sur la touche delete ou backspace, l’élément sur lequel
pointe le curseur doit être effacé de la liste. S’il n’y a plus d’élément dans la liste,
le comportement est le même que si l’utilisateur avait appuyé sur la touche echap.
<p>• choix non selectionné : texte normal.</p>
<p>• choix selectionné : texte video inversé.</p>
<p>• position curseur : texte souligné.</p>
<p>• choix selectionné + position curseur : texte video inversé souligné.
<p>• Quelque soit le moyen par lequel votre programme se termine, la configuration
par defaut de votre terminal DOIT être restaurée. Oui, même après avoir reçu
un signal (sauf signaux qu’on ne peut pas intercepter, mais ca veut dire que votre
programme ne fonctionne pas de toute façon).</p>
<p>• On doit pouvoir interrompre votre programme avec un ctrl+z et le restaurer avec
fg sans que cela influe sur son comportement.</p>
<p>• Si le programme est lancé avec un environnement vide, vous devez adopter un
comportement raisonnable.</p>

||<h3 align="center"> Documentation </h3>|
|:--------:|:---------:|
|Init Terminal| https://zestedesavoir.com/tutoriels/1733/termcap-et-terminfo/ |
|Termcaps|https://man.cx/termcap(5)/fr |
|[Non-]Canonique mode|http://www-igm.univ-mlv.fr/~dr/cs/node165.html|
|Termios|http://manpagesfr.free.fr/man/man3/termios.3.html https://en.wikibooks.org/wiki/Serial_Programming/termios|
|Puts|https://linux.die.net/man/3/putc|
|tgetent tgetstr tgoto|https://linux.die.net/man/3/tgetstr|
|Signaux|http://cristal.inria.fr/~remy/poly/system/camlunix/sign.html|
|tty_ioctl|http://man7.org/linux/man-pages/man4/tty_ioctl.4.html|

moyen d'ameliorer : 
Liste chainee, avec le nom, des coordonnees x et y pour les placer en tableau et ainsi de deplacer plus facilement en boucle sans trop faire de calcul et verifier si l'element n'as pas ete supprime.
