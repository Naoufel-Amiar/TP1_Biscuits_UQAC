cmake_minimum_required(VERSION 3.10)

# Nom du projet et de l'exécutable final
project(ProjetBiscuitJNT)

# Forcer un standard C++ récent (très recommandé)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Indiquer au compilateur où chercher les fichiers .h
include_directories(include)

# Lier le main() avec tous les autres fichiers sources .cpp
add_executable(ProjetBiscuitJNT
    ProjetBiscuitJNT.cpp
    source/Client.cpp
    source/Commande.cpp
    source/ListeCommandes.cpp
)