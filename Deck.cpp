//Angie Diaz 
//CPSC 1020
//Project 3: TigerGame
//File: Deck.cpp
//3/30/24
//Time: 8 hrs
//Desc: Deck class method definitons that populate and shuffle the deck vector, as well as deals a card

#include "Deck.h"

//creates 30 cards and adds to vector deck 
Deck::Deck() {
    //15 purple cards ranked 1-15
    for (int i=0; i<15; i++) {
        deck.push_back(Card(i+1, Card::Color::purple));
    }
    //10 orange cards ranked 1-10
    for (int i=0; i<10; i++) {
        //creating instance of Card object and adding to deck
        deck.push_back(Card(i+1, Card::Color::orange));
    }
    //5 black cards ranked 6-10
    int count=6;
    for (int i=0; i<5; i++) {
        //creating instance of Card object and adding to deck
        deck.push_back(Card(count, Card::Color::black));
        count++;
    }

}

//randomizes order of Card objects in deck vector
 void Deck::shuffle() {
    //seeding with current time to be used thruout program 
    srand(unsigned(0));
    std::random_shuffle(deck.begin(), deck.end());
 }

//returns first Card in deck and then removes it
 Card Deck:: drawCard() {
    if (deck.empty()) {
        throw std::runtime_error("Empty deck, cannot draw.");
    }
    Card temporary;
    //storing first Card in deck 
    temporary=deck.front();
    //removing from deck
    deck.erase(deck.begin());
    return temporary; 

 }

 //returns current size of deck
int Deck::getDeckSize() const {
    return deck.size();
 }



