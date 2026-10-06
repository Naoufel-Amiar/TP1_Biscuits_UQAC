cmake_minimum_required(VERSION 3.10)
project(TP1_Biscuits_UQAC)

# Spécifier le standard C++ (le 17 est un bon standard moderne par défaut)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Indiquer à CMake où trouver les fichiers d'en-tête (.h)
include_directories(
    include
    .
)

# Lister tous les fichiers sources (.cpp) nécessaires à la compilation
set(SOURCES
    ProjetBiscuitJNT.cpp
    Terminal.cpp
    source/Biscuit.cpp
    source/Client.cpp
    source/Commande.cpp
    source/ListeCommandes.cpp
    source/Structures.cpp
)

# Créer l'exécutable final nommé "TP1_Biscuits"
add_executable(TP1_Biscuits ${SOURCES})