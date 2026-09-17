#!/bin/bash

# Aller dans le dossier build
cd build

# Compiler le projet
make

# Si la compilation réussit (le make renvoie 0), on lance le programme
if [ $? -eq 0 ]; then
    echo -e "\n--- Lancement du programme ---\n"
    ./ProjetBiscuitJNT ../data/TRANSACTIONS.txt
else
    echo -e "\n--- Échec de la compilation ---\n"
fi