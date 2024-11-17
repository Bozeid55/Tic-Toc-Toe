# Tic-Toc-Toe
==============================
= Tic Tac Toe Game - README: =
==============================
Description :
-------------
This project is a command-line Tic Tac Toe game developed in C++. The game offers two modes:
1) Player vs Player: Two players take turns to play on the same device.
2) Player vs Computer: A single player competes against the computer, which can play at three difficulty levels: Easy Medium, and Hard.

The game is built using OOP concepts like classes, encapsulation, and abstraction. It provides a user-friendly interface for an enjoyable gaming experience.


------------
- Features -
------------
- Two Game Modes:
    1) Player vs Player: Players alternate turns.
    2) Player vs Computer: Compete against the AI.

- Three Difficulty Levels:
    1) Easy: Randomly selects available spots.
    2) Medium: Prevents immediate wins and attempts to win if possible.
    3) Hard: Uses Medium strategies combined with additional logic for improved gameplay.

- Winner and Tie Detection: Identifies winners or declares a tie.

- Interactive Board: Displays the board after each turn.



---------------
- How to Play -
---------------
1) At the start, select your preferred game mode:
    - Press 1 for Player vs Player.
    - Press 2 for Player vs Computer.

2) Choose the difficulty level:
    - Easy
    - Medium
    - Hard

3) The game board consists of 9 cells, numbered from 1 to 9 as shown:
  -------------
  - 1 | 2 | 3 -
  -------------
  - 4 | 5 | 6 -
  -------------
  - 7 | 8 | 9 -
  -------------

3) On your turn:
    - Enter a number between 1 and 9 to place your marker in the corresponding cell.
    - The game ensures that the chosen cell is empty before placing your marker.

4) The game ends when:
    - A player gets three of their markers in a row (horizontally, vertically, or diagonally).
    - The board is full without any winner, resulting in a tie.

------------
- Controls -
------------
1) Enter numbers (1-9) to place your marker on the board during your turn. 
