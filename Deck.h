//Angie Diaz 
//CPSC 1020
//Project 3: TigerGame
//File: Deck.h
//3/30/24
//Time: 8 hours 
//Desc: Deck class that contains vector of Cards and methods to access/modify deck vector 
#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include <random>
#include <chrono>
#include <stdexcept>


class Deck {
    private: 
        std::vector<Card>deck;
    public:
        //creates a vector deck with 30 cards
        Deck();
        //randomizes order of Card objects in deck vector
        void shuffle();
        //returns first Card in deck and then removes it
        Card drawCard();
        //accessor
        int getDeckSize() const;
        
};
  

#endif // DECK_H_
