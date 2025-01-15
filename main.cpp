//Angie Diaz 
//CPSC 1020
//Project 3: TigerGame
//File: main.cpp
//3/30/24
//Time: 8 hours
//Desc: Main file that instantiates Deck and Player objects to create card game, 
//Desc:contains functions to validate input, update scores, and print results 

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;


// 1. to validate input of card selection
bool inputVal(const Player& player, int cho);

// 2. determines number of points sent to player 
bool findWinner(int comp, int hum);

//3. prints out scores for each round
void printStats(const Player& h, const Player& c, int f);

//Extra credit challenge 2:
//Struct tracks how many rounds were played, points in each round, num of rounds a player won, and total points   
struct currentGame {
  int rounds; 
  vector<int>humanPoints;
  vector<int>computerPoints;

};
//Extra credit challenge 2: prints summary of games
void printGames(const vector<currentGame>&totalGames, int hW, int cW, int tH, int tC);

int main() {

    //variables to track for extra credit challenge 
    int humanWins=0;
    int computerWins=0;
    int totalHuman=0;
    int totalComputer=0;
    int choice, drawNum, repeat;
    
    //creating a vector of Game structs
    vector<currentGame> totalGames;
 

  //loop to keep game playing or stop depending on user input 
  do {
      cout<<"WELCOME TO TIGERCARD GAME!"<<endl;

    // 1. Create a deck of cards and shuffle it.
      Deck deckOfCards;
      deckOfCards.shuffle();
      cout<<"Deck was shuffled."<<endl<<endl;

    //EXTRA CREDIT CHALLENGE 1
    // 2. Create two players, each one with user-specified cards in their hand. (validate input)
      do {
        cout<<"How many cards would you like each player to draw? (must be 15 or less) ";
        cin>>drawNum;
      } while (drawNum<1 || drawNum>15); 
      cout<<"Each player has drawn "<<drawNum<<" cards. "<<endl; 

      //creating Game struct and resizing based on user input  
      currentGame game;
      game.rounds=drawNum; 
      game.humanPoints.resize(drawNum);
      game.computerPoints.resize(drawNum);

      Player computer(deckOfCards, drawNum);
      Player human(deckOfCards, drawNum);

    // 3. Play user-specified number of rounds: 
    //    - Have computer deal a card from their hand.
    //    - Show human their hand of cards so that they can make a selection.
    //    - Have human deal their card.
    //    - Determine who won the round and update points accordingly.
    //    - Print results for current round.

      for (int i=0; i<drawNum; i++) {
        cout<<"Round "<<i+1<<endl;
        cout<<"-----"<<endl;

        //stores current computer card 
        Card computerCard=computer.hand.dealCard(0);
        cout<<"The computer plays: "<<computerCard.strCard()<<endl;
        //getting value of computer's card, dealing that card 
        int computerVal=computerCard.getValue(); 

        cout<<"Your hand: "<<human.hand.strHand()<<endl; //printing hand

        //input validation 
        do {
          cout<<"Which numbered card do you want to play? ";
          cin>>choice;
        } while (!inputVal(human, choice));
        
        //stores current human card 
        Card humanCard=human.hand.dealCard(choice-1);
        cout<<"You played: "<<humanCard.strCard()<<endl; //printing choice 

        //getting value of human's card, dealing that card 
        int humanVal=humanCard.getValue(); 

        //to determine winner must call function to compare values
        if (computerVal!=humanVal) {
          if (findWinner(computerVal, humanVal)) {
            human.score+=(humanVal+computerVal);
            humanWins+=1;
            
          } else {
            computer.score+=(humanVal+computerVal);
            computerWins+=1;
          }
        } else {
          cout<<"It's a tie!"<<endl;
        } 
        
        //adding current scores to vectors 
        game.humanPoints[i]=human.score;
        game.computerPoints[i]=computer.score;
    
        //printing current game scores 
        printStats(human, computer, 0);
      }
    
    // 4. Print final game results.
    //adding game to totalGames vector 
    totalGames.push_back(game);
    printStats(human,computer,1);

    //adding final scores to the total scores 
    totalHuman+=human.score;
    totalComputer+=computer.score;

    cout<<"Would you like to play again? Enter 1 for yes and 0 for no: ";
    cin>>repeat;
    cout<<endl;
    //making sure user only enters 1 or 0 
    while (repeat!=0 && repeat!=1) {
      cout<<"Enter 1 to play again and 0 to end game. ";
      cin>>repeat; 
      cout<<endl;
    }
  } while (repeat==1);  //END OF DO-WHILE LOOP 

 
  //call printGames to print complete summary of all games 

  printGames(totalGames, humanWins, computerWins, totalHuman, totalComputer);
  

  return 0;

}

//validates input of card selection, returns T/F
bool inputVal(const Player& player, int cho) {
  if (cho<1 || cho>player.hand.getHandSize()) {
    return false;
  } else {
    return true; 
  }
}

//compares card value of computer v human and returns T/F
bool findWinner(int comp, int hum) {
  if (comp>hum) {
    cout<<"The computer wins this round!"<<endl<<endl;
    return false; 
  } else {
    cout<<"You win this round!"<<endl<<endl;
    return true; 
  }
}

//prints the current/final scores of human and computer 
void printStats(const Player& h, const Player& c, int f) {
  if (f==0) {
    cout<<"Current scores: "<<endl; 
    cout<<"Human: "<<h.score<<endl; 
    cout<<"Computer: "<<c.score<<endl<<endl;
  } else {
    cout<<"FINAL SCORE: "<<endl;
    cout<<"Human: "<<h.score<<endl;
    cout<<"Computer: "<<c.score<<endl<<endl;
    if (c.score>h.score) {
      cout<<"Computer wins!"<<endl<<endl;
    } else if (h.score>c.score) {
      cout<<"Human wins!"<<endl<<endl;
    } else {
      cout<<"Tie! No one wins!"<<endl<<endl;
    }
  }

}

//EXTRA CREDIT 2: function that prints total summary of all games played 
//For each game prints the number of points each round
//Prints total wins of all games for human and computer
//Prints total points of all games for human and computer 
void printGames(const vector<currentGame>&totalGames, int hW, int cW, int tH, int tC) {
  cout<<endl<<"TOTAL GAMES SUMMARY: "<<endl<<endl; 
  int count=1;
  //for every game in total games vector 
  for (const auto& g: totalGames) {
    //print which game the summary belongs to 
    cout<<"Game "<<count<<" Summary: "<<endl;
    cout<<"---------------"<<endl;
    //printing number of rounds and pts per each round
    cout<<"Number of rounds: "<<g.rounds<<endl;
    for (int i=0; i<g.rounds; i++) {
      cout<<"Round "<<i+1<<" points: "<<endl;
      cout<<"Human: "<<g.humanPoints[i]<<endl;
      cout<<"Computer: "<<g.computerPoints[i]<<endl<<endl;
    }
      count++; 

  }
  cout<<"Total rounds won by human: "<<hW<<endl;
  cout<<"Total rounds won by computer: "<<cW<<endl;
  cout<<"Total human points: "<<tH<<endl;
  cout<<"Total computer points: "<<tC<<endl; 

}