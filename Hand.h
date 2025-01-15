//Angie Diaz 
//CPSC 1020
//Project 3: TigerGame
//File: Hand.h
//3/30/24
//Time: 8 hours
//Desc: Hand class that contains vector of Cards and methods to access/modify vector 
#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Card.h"
#include "Deck.h"
class Hand {
    private:
        std::vector<Card>hand;
    public:
        //default constructor: initalizes empty vector 
        Hand(): hand(std::vector<Card>()) {}
        //deals hand of cards from deck and into hand vector 
        Hand(Deck& deck, int N);

        //shows human current hand by displaying contents of hand vector 
        std::string strHand();

        //deals card based on user input 
        Card dealCard(int num);

        //accessors 
        int getHandSize()const;
        
        
  
};

#endif // HAND_H_
