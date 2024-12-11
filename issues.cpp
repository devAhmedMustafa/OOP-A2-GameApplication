#include <iostream>
#include <vector>
#include "Core/Player.h"
#include "Core/Board.h"
#include "Core/GameManager.h"
//#include "Core/RandomPlayer.h"

using namespace std;

class HumanPlayer : public Player<char> {
public:
    // Constructor to initialize the player with a name and symbol
    HumanPlayer(string name, char symbol) : Player<char>(name, symbol)  {}

    // Implementation of the pure virtual getmove method
    void getmove(int& x, int& y) override {
        cout << this->name << ", enter your move (row and column): ";
        cin >> x >> y;
    }
};


// inheritance and polymorphism for game 3
class fivexfiveboard : public Board<char> {
    private:
    int pturns[2] = {12,12}; //each player has 12 turns
    int pscores[2] = {0,0};  // track scores for x, o in 3inrows
    public:
    fivexfiveboard(){
        rows = 5;
        columns = 5;

        board= new char*[rows]; //pointer to array of pointers
        for (int i = 0; i<rows ;i++){
            board[i]= new char[columns]; //array for each row
            for (int j=0; j<columns; j++){
                board[i][j]= '-'; //initialize cells
            }

        }
    }

    bool update_board(int x, int y, char symbol) override {
        int pindex = (symbol== 'X') ? 0 : 1;
        if (pturns[pindex] <= 0) {
            cout << "Player " << symbol << " has no turns left.\n";
            return false;
        }
        if (x>= 0 && x<rows && y>=0 && y<columns && board[x][y] == '-'){
            board[x][y]= symbol;
            pturns[pindex]--;
            n_moves++;
            return true;
        }
        return false;
    }

    void display_board() override {
        for(int i=0; i<rows; i++){
            for (int j=0; j<columns; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool is_win() override {
        pscores[0] = count_3_inrows('X');
        pscores[1] = count_3_inrows('O');
        // display scores
        if (game_is_over()) {
            cout << "X scored: " << pscores[0] << endl;
            cout << "O scored: " << pscores[1] << endl;
            if (pscores[0] > pscores[1]) {
                cout << "Player X wins!\n";
            } else if (pscores[1] > pscores[0]) {
                cout << "Player O wins!\n";
            } else {
                cout << "It's a draw!\n";
            }
        }
        return false; // there is no condition here it will be based on score of three in a rows
    }

    bool is_draw() override {
        return n_moves == 24;
    }

    bool game_is_over() override{
        return is_draw();
    }

    int count_3_inrows(char symbol){
        int count = 0;
        //check rows 
        for (int i=0 ; i<rows; i++){
            for (int j=0 ; j<3; j++){
                if (board[i][j]== symbol && board[i][j+1]== symbol && board[i][j+2]== symbol){
                    count++;
                }

            }
        }
    
       //check columns
        for (int i=0 ; i<3; i++){
            for (int j=0 ; j<columns; j++){
                if (board[i][j]== symbol && board[i+1][j]== symbol && board[i+2][j]== symbol){
                    count++;
                }
            }    

        }
    
        //check diagonal (from topleft to bottom right)
         for (int i=0 ; i<3; i++){
             for (int j=0 ; j<3; j++){
                 if (board[i][j]== symbol && board[i+1][j+1]== symbol && board[i+2][j+2]== symbol){
                    count++;
                }

            }
        }
        //check diagonal (from bottom left to top right)
         for (int i=2 ; i<rows; i++){
             for (int j=0 ; j<3; j++){
                 if (board[i][j]== symbol && board[i-1][j+1]== symbol && board[i-2][j+2]== symbol){
                    count++;
                 }

             }
        }
        return count;
    }
};


int main() {
    while (true) {
        cout << "\n==== Board Game Framework ====" << endl;
        cout << "1. Play 5x5 Tic Tac Toe" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        string pname1;
        string pname2;
        cin >> choice;

        if (choice == 2) {
            cout << "Goodbye!" << endl;
            break; // Exit the program
        } else if (choice == 1) {
            cout << "Starting 5x5 Tic Tac Toe..." << endl;

            // Create Tic Tac Toe board
            Board<char>* board = new fivexfiveboard();

            // Create players
            Player<char>* players[2];
            cout << "Enter player 'X' name :" << endl;
            cin >> pname1;
            cout << "Enter player 'O' name :" << endl;
            cin >> pname2;

            players[0] = new HumanPlayer(pname1, 'X');
            players[1] = new HumanPlayer(pname2, 'O');

            // Set board for players
//            players[0]->setBoard(board);
//            players[1]->setBoard(board);

            // Create GameManager for Tic Tac Toe
//            GameManager<char> gameManager(board, players);
//
//            // Run the game
//            gameManager.run();

            // Clean up memory
            delete players[0];
            delete players[1];
            delete board;

        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}