1. PRÉSENTATION DU PROJET

Ce projet a pour objectif de développer en C++ un programme permettant de gérer
des clients ainsi que leurs commandes de biscuits à l'aide de structures de
données chaînées.

Les différentes informations sont chargées à partir de fichiers texte puis
stockées dynamiquement en mémoire. Le programme permet ensuite d'exécuter une
suite de transactions permettant de consulter et de modifier ces données.

Le projet a notamment permis de mettre en pratique la manipulation des pointeurs,
des listes chaînées, des allocations dynamiques et la gestion de la mémoire.


2. FONCTIONNALITÉS

Le programme interprète les différentes commandes présentes dans le fichier
TRANSACTIONS.txt.

Les opérations implémentées sont :

O : chargement des fichiers contenant les clients et les commandes.

S : sauvegarde de l'état actuel des clients et des commandes dans les fichiers.

+ : ajout d'un nouveau client.

- : suppression d'un client ainsi que des données qui lui sont associées.

= : ajout d'une nouvelle commande entre deux clients.

? : affichage des commandes effectuées par un client.

$ : recherche et affichage du type de biscuit le plus populaire ainsi que
    de la quantité totale correspondante.


3. STRUCTURE DU PROGRAMME

Le programme repose principalement sur des structures chaînées permettant de
représenter les clients, les commandes et les biscuits.

Chaque client peut être associé à une liste de commandes et chaque commande
peut elle-même contenir une liste de biscuits.

Cette organisation permet de manipuler dynamiquement les différentes données
sans utiliser les conteneurs de la STL.

Le projet est séparé en plusieurs fichiers .h et .cpp afin de distinguer les
déclarations des structures et classes de leur implémentation.


4. COMPILATION AVEC CMAKE

Un fichier CMakeLists.txt a été mis en place afin de faciliter la compilation
du projet.

CMake permet de définir les différents fichiers sources nécessaires au programme,
les répertoires contenant les fichiers d'en-tête ainsi que la version de C++
utilisée.

La génération du projet avec CMake permet ensuite de créer un répertoire de
compilation (build) contenant les fichiers nécessaires à la compilation ainsi
que l'exécutable final du programme.

Cette solution permet également de conserver une méthode de compilation commune
entre les différents environnements de développement utilisés par les membres
du groupe.


5. VERSIONING ET TRAVAIL COLLABORATIF

Le développement du projet a été réalisé avec Git et GitHub afin de mettre en
place un système de versioning du code.

Chaque membre du groupe pouvait travailler sur sa propre branche afin de
développer ou de modifier une partie du programme sans perturber directement
la version principale.

Les différentes modifications pouvaient ensuite être fusionnées grâce au
système de branches et de merges de Git.

La branche master a ainsi servi à centraliser les différentes parties validées
du projet.

L'utilisation de GitHub nous a également permis de conserver un historique des
modifications et de faciliter le partage du code entre les membres du groupe.


6. VÉRIFICATION DE LA GESTION MÉMOIRE

Le programme utilisant des allocations dynamiques et des pointeurs, une attention
particulière a été portée à la libération de la mémoire.

L'outil Valgrind a été utilisé afin d'analyser l'exécution du programme et de
détecter d'éventuelles fuites de mémoire.

Ces tests nous ont permis d'identifier certaines allocations qui n'étaient pas
correctement libérées, notamment dans les structures chaînées contenant les
clients, les commandes et les biscuits.

Les fonctions de suppression et de libération de la mémoire ont ensuite été
corrigées afin de libérer correctement les différents éléments alloués
dynamiquement.

Une nouvelle analyse avec Valgrind a permis de vérifier le comportement du
programme après ces corrections et d'améliorer la propreté de la gestion
mémoire.


7. ORGANISATION DU DÉVELOPPEMENT

Le développement a donc reposé sur plusieurs outils complémentaires :

- C++ pour l'implémentation des structures de données et du programme ;
- CMake pour la configuration et la compilation du projet ;
- Git et GitHub pour le versioning et le travail collaboratif ;
- Valgrind pour l'analyse et la vérification de la gestion mémoire.

L'ensemble de ces outils a permis de développer, tester et intégrer les
différentes parties du programme tout en conservant une organisation commune
entre les membres du groupe.


8. UTILISATION DE L'INTELLIGENCE ARTIFICIELLE

Des outils d'intelligence artificielle générative ont été utilisés au cours du
développement du projet comme outils d'assistance, principalement pour le
diagnostic et la correction d'erreurs.

L'IA a notamment été utilisée lorsque nous rencontrions des erreurs de
compilation, des problèmes liés à la manipulation des pointeurs, aux listes
chaînées ou à la gestion de la mémoire. Elle nous a permis d'identifier plus
rapidement l'origine de certains problèmes, de proposer des pistes de correction
et, dans certains cas, de fournir des correctifs plus importants lorsque le
problème concernait plusieurs parties du code.

Son utilisation a donc principalement concerné :

- l'analyse et l'explication d'erreurs de compilation ;
- la recherche d'erreurs dans le code existant ;
- l'assistance à la correction de problèmes liés aux pointeurs et aux structures
  chaînées ;
- l'aide au diagnostic et à la correction de fuites ou de mauvaises libérations
  de mémoire ;
- la proposition ponctuelle de modifications ou de correctifs de code plus
  importants lorsqu'un problème le nécessitait.

Les propositions générées par l'IA ont été intégrées dans le cadre du
développement du projet, puis compilées et testées par les membres du groupe.
Des outils indépendants, notamment Valgrind pour la gestion mémoire, ont
également été utilisés afin de vérifier le comportement du programme après
certaines corrections.

L'intelligence artificielle a ainsi été utilisée comme un outil d'assistance au
développement et au débogage, et non comme unique moyen de conception ou de
réalisation du projet.
