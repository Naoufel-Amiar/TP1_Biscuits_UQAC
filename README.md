# TP1 - Commandes de biscuits

Cours : 8INF259 - Structures de donnees

## Structure

- `main.cpp` : point d'entree et lecture de TRANSACTIONS.txt
- `include/` : structures et declarations
- `src/` : implementations
- `data/` : fichiers texte de test

## Compilation

Depuis le dossier TP1_Biscuits :

```bash
g++ -g main.cpp src/ListeCommandes.cpp src/Client.cpp src/Commande.cpp -o programme
```

## Execution

Windows :

```bash
programme.exe data/TRANSACTIONS.txt
```

Linux/macOS :

```bash
./programme data/TRANSACTIONS.txt
```

## Contraintes du TP

Le projet est volontairement initialise sans implementation complete.
Les operations O, S, +, -, =, ? et $ restent a programmer.

Le TP interdit l'utilisation de la STL en dehors de :
- <fstream>
- <iostream>
- <string>
