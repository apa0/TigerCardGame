# TigerCardGame
Tiger Card Game project 
In TigerGame, there are three types of cards: purple, orange, black.
Each color has a varying number of cards ranked from 1 to 15, for a total of 30
cards in one deck:
  • 15 purple cards ranked 1-15
  • 10 orange cards ranked 1-10
  • 5 black cards ranked 6-10
  
Each card has a value:
  The value of purple cards is equal to their rank (e.g., purple:2 is worth 2 points)
  The value of orange cards is equal to twice their rank (e.g., orange:2 is worth 4 points)
  The value of black cards is equal triple their rank (e.g., black:7 is worth 21 points).
  
TigerGame is a computer game in which a player competes against the computer.

The game is played as follows:
  • There are two players, computer and human.
  • Each player draws a hand of 6 cards from the full deck, which has been
  shuffled before cards are drawn.
  • There are SIX rounds. Each round is played as follows:
    1. Computer moves first by selecting a card from its hand. For
    simplicity, this is implemented as a random draw. Human
    sees the card computer has played.
    2. Human selects a card from their hand to play against the computer’s
    card.
    3. The player whose card has the larger value wins the round. Any card
    can be played against any other card. Only their value determines
    who wins the round.
    2
    4. The player who wins the round is awarded points equal to the sum of
    the values of the two cards. For example, if computer plays purple:2
    and human plays orange:4, human wins the round and receives 10
    points.
    5. If there is a tie, no player receives points.
  • After six rounds, the player with the most points wins.
