//Angie Diaz 
//CPSC 1020
//Project 3: TigerGame
//File: Card.cpp
//3/30/24
//Time: 8 hrs
//Desc: Card class method definitions that set value, print out a card's info and get card's info

#include "Card.h"

Card::Card(int r, Color c): rank(r), color(c) {
    //set correct rank for card based on rank and color
    if (color==purple) {
        value=rank;
    } else if (color==orange){
        value=rank*2;
    } else {
        value=rank*3;
    }
}

//returns a string to show the color and rank of card 
std::string Card:: strCard() const {
    std::string cardInfo; 
    if (color==purple) {
        cardInfo="purple";
    } else if (color==orange) {
        cardInfo="orange";
    } else {
        cardInfo="black";
    }
    return cardInfo+":"+std::to_string(rank);
}

//getter functions 
int Card:: getRank() const {
    return rank;

}
Card::Color Card::getColor() const {
    return color;

}
int Card::getValue() const  {
    return value;

}