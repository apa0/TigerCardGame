//Angie Diaz 
//CPSC 1020
//Project 3: TigerGame
//File: Player.h
//3/30/24
//Time:
//Desc: Player class with inline functions that contain a Hand object and constructors to instantiate the Hand object and set score

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Hand.h"
#include "Deck.h"
class Player {
    public:
        Hand hand; 
        int score=0;
        //default constructor
        Player() {}
        //argument constructor 
        Player(Deck& deck, int N): score(0) {
            hand=Hand(deck,N);
        }
        
       
};
  

#endif // PLAYER_H_
