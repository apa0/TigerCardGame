//Angie Diaz 
//CPSC 1020
//Project 3: TigerGame
//File: Hand.cpp
//3/30/24
//Time: 8 hours
//Desc: Hand class definition, contains constructor that adds to hand vector and methods to modify/access vector 

#include "Hand.h"

Hand::Hand(Deck& deck, int N) {
    //drawing N cards from deck 
    //adding into Hand vector 
    while (N>0) { 
        hand.push_back(deck.drawCard());
        N--;
    }
}

//shows human current hand by displaying contents of hand vector
//format color:rank 
std::string Hand:: strHand() {
    std::stringstream current;
    int count=1;
    for (const auto& card : hand) {  
        std::string color;
        switch (card.getColor()) {
            case Card::purple: 
                color="purple";
                break;
            case Card::orange:
                color="orange";
                break;
            case Card::black: 
                color="black";
                break;
            default:
                color="Not found";
        }
        current<<"["<<count<<"] "<<color<<":"<<card.getRank()<<" ";
        count++;
    }
    return current.str();


}

//deals card based on user input 
Card Hand:: dealCard(int num) {
    //checking that hand vector is not empty 
    if (hand.empty()) {
         std::cerr<<"Empty deck, cannot draw."<<std::endl;
         exit(1);
    }
    //storing card of choice here 
    Card deal=hand[num];
    //erasing card of choice from hand 
    hand.erase(hand.begin()+num);
    return deal; 
}

//returns current size of hand 
int Hand::getHandSize()const {
    return hand.size();
}
