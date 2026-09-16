#ifndef BISCUIT_H
#define BISCUIT_H

#include <string>

struct Biscuit
{
    std::string type;
    int quantite;
    Biscuit* suivant;
};

#endif
