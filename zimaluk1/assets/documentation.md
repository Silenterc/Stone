Welcome to Stone, the Rpg Card Game engine
=====
Features
=====
- The Game loads the definitions of Cards and the list of Cards into a Deck from a config file
- The Game allows you to start a Game against another live Player. The exchange of turns happens through a confirmation screen
- The Game allows you to start a Game against an AI. The AI always aims to clear the enemy Board as much as possible, and if
the board is clear, then it attacks the enemy Player
- The Game allows you to save any started Game at any point of your turn, and allows you to load the saved Game from the Menu
Polymorphism
=====
1, There are two types of Players. An alive Player and the AI. Each Player's turn gets carried out differently. The alive Player's turn is dependent on the user input, the AI Player's turn is carried out by the AI.

2, There are 3 types of Cards. 
- A Basic Card, which does nothing special
- A Taunt Card, which has the highest priority when it's on the Board(you must destroy it first)
- A Battlecry Card, which carries out an Effect, when it is played 

  Polymorphism is mainly used for UI, saving/loading Cards, Taunt detection and performing a Battlecry Effect.

3, There are 5 types of Effects
- DrawCardEffect
- BoardDamageEffect
- AllDamageEffect
- HealBoardEffect
- HealHeroEffect

  Each Effect performs a different action when called.

