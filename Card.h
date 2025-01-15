//Angie Diaz 
//CPSC 1020
//Project 3: TigerGame
//File: Card.h
//3/30/24
//Time: 8 hrs
//Desc: Card class that contains a card's info and methods to access and set the card's details 

#ifndef CARD_H_
#define CARD_H_

#include <string>


class Card {
    private:
        int rank=0;
        int value=0;
    public:
        enum Color{purple, orange, black};
        
        //constructors
        Card()=default; 
        Card(int r, Color c);

        //returns string in format color:rank 
        std::string strCard() const;

        //accessors
        int getRank() const;
        Color getColor() const;
        int getValue() const;

    private:
        Color color=purple;
};
  

#endif // CARD_H_
