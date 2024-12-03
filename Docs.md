
# Project README: Board Game Classes

## Overview
This project implements the basic structure of a board game, including the game board, players, and a game manager to oversee interactions. Below is a breakdown of the classes, their responsibilities, and their relationships to help the team understand the code quickly.

---

## Class Diagram

### **1. Board**
#### **Purpose:** 
Represents the game board where the game is played.

#### **Attributes:**
- `vector<int> sizes` - Stores the dimensions of the board.
- `vector<vector<int>> matrix` - Represents the actual game board as a 2D matrix.

#### **Constructors:**
- `Board(int size[2])`  
  Initializes the board using a 2D array to define dimensions.
- `Board(vector<int> sizes)`  
  Initializes the board using a vector of dimensions.

#### **Methods:**
- `void print()`  
  Prints the current state of the board (implementation not yet provided).
- `bool placeSymbol(int x, int y, char symbol)`  
  Places a player's symbol at position `(x, y)`. Returns `true` if successful.
- `virtual char checkForWinner() = 0`  
  Abstract method to check for a winner. Must be implemented in derived classes.

---

### **2. Player**
#### **Purpose:** 
Represents a player in the game.

#### **Attributes:**
- `string name` - The player's name.
- `char symbol` - The player's symbol (e.g., 'X' or 'O').
- `int pos[2]` - The player's current position on the board.

#### **Constructor:**
- `Player(string name, char symbol)`  
  Initializes the player with a name and a symbol.

#### **Methods:**
- `void move(int x, int y)`  
  Updates the player's position to `(x, y)`.
- `char getSymbol()`  
  Returns the player's symbol.

---

### **3. RandomPlayer** *(inherits from Player)*
#### **Purpose:** 
A specialized player that makes random moves.

#### **Constructor:**
- `RandomPlayer(char symbol)`  
  Initializes a random player with the symbol `'random'`.

#### **Methods:**
- `void move()`  
  Generates random `(x, y)` positions and moves the player accordingly.

---

### **4. GameManager**
#### **Purpose:** 
Oversees the game flow, manages interactions between players and the board.

#### **Attributes:**
- `Board* board` - A pointer to the game board.
- `Player* player1` - A pointer to the first player.
- `Player* player2` - A pointer to the second player.