#include <iostream>
#include <string>
#include "../include/plants.h"

/////////////////////
//Plant's functions//
/////////////////////
Plant::Plant()
{

}

Plant::Plant(char myToken, std::string myName, const int& myLife, const int& myIllnessProb, const int& myBreedingProb, const int& myLifeFactor, const int& x, const int& y)
    : token(myToken), name(myName), life(myLife), illnessProb(myIllnessProb), breedingProb(myBreedingProb), lifeFactor(myLifeFactor)
{
    location.x = x; location.y = y;
}

Plant::~Plant()
{

}

char Plant::getToken()
{
    return token;
}

int Plant::getBreedingProb()
{
    return breedingProb;
}

int Plant::getIllnessProb()
{
    return illnessProb;
}

int Plant::getLife()
{
    return life;
}

int Plant::getLifeFactor()
{
    return lifeFactor;
}

int Plant::getPointX(){
    return location.x;
}

int Plant::getPointY(){
    return location.y;
}

void Plant::LoseLife(const int& eatCount)
{
    life -= eatCount;
}

void Plant::Growth()
{
    life += lifeFactor;
}

void Plant::setStats(char myToken, std::string myName, const int& myLife, const int& myIllnessProb, const int& myBreedingProb, const int& myLifeFactor, const int& x, const int& y)
{
    token = myToken; name = myName; life = myLife;
    illnessProb = myIllnessProb; breedingProb = myBreedingProb;
    lifeFactor = myLifeFactor; location.x = x; location.y = y;
}

//////////////////////////
//Seeded's fuctions//
//////////////////////////
Seeded::Seeded(char myToken, const int& x, const int& y)
{
    switch(myToken){
        case 'M' :    
            seeds = 10;
            foliage = 20;
            size = 2;
            setStats(myToken,"Maple",20,5,5,10, x, y);
            break;
        case 'O' : 
            seeds = 15;
            foliage = 30;
            size = 5;
            setStats(myToken,"Oak",30,20,20,15, x, y);
            break;
        case 'P' :
                seeds = 20;;
                foliage = 40;
                size = 5;
                setStats(myToken,"Pine",40,15,15,20, x, y);
            break;
    }
}

Seeded::~Seeded()
{

}

int Seeded::getLife()
{
    return (seeds + Plant::getLife());
}

int Seeded::getFoliage()
{
    return foliage;
}

int Seeded::getSeeds()
{
    return seeds;
}

int Seeded::getSize()
{
    return size;
}

void Seeded::LoseLife(int eatCount)
{
    if(seeds > 0) {
        if(seeds >= eatCount) {
            seeds -= eatCount;
        }
        else {
            eatCount -= seeds;
            seeds = 0;
        }
    }
    foliage -= eatCount;
    Plant::LoseLife(eatCount);
}

void Seeded::Growth(bool happened)
{
    if(happened) {
        foliage += getLifeFactor();
        seeds += getLifeFactor()*2;
    }
    else {
        if(foliage >= getLifeFactor()) {
            foliage -= getLifeFactor();
        }
        else {
            foliage = 0;
        }
        if(seeds >= getLifeFactor()*2) {
            seeds -= getLifeFactor()*2;
        }
        else {
            seeds = 0;
        }
    }
    size = foliage/getLifeFactor();
}

//////////////////////////////
/////Seedless's functions/////
//////////////////////////////

Seedless::Seedless(char myToken, const int& x, const int& y)
{
    switch(myToken){
        case 'G':
            setStats(myToken,"Grass",5,15,15,4, x, y);
            break;
        case 'A':
            setStats(myToken,"Algae",5,25,25,2, x, y);
            break;
    }
}

Seedless::~Seedless()
{

}