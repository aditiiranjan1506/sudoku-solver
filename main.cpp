#include <iostream>
//#include <vector>
//#include <algorithm>
using namespace std;
const int SIZE = 9;

//functions- 
//finds the empty cells (cell of 0 value)
bool find_empty(int board[SIZE][SIZE], int &r, int &c) {
    for (r = 0; r < SIZE; r++) {
        for (c = 0; c < SIZE; c++) {
            if (board[r][c] == 0)
                return true;
        }
    }
    return false;
}
//checks whether the placing digit 'd' at row 'r' and column 'c' is valid.
//safe if-
// a. it does not exist in the same row.
// b. it does not exist in the same column.
// c. it does not exist in the corresponding 3x3 box.
bool is_safe(int board[SIZE][SIZE], int r, int c, int d) {

    // Row
    for (int i = 0; i < SIZE; i++)
        if (board[r][i] == d) return false;

    // Column
    for (int i = 0; i < SIZE; i++)
        if (board[i][c] == d) return false;

    // 3x3 box
    int sr = (r / 3) * 3;
    int sc = (c / 3) * 3;

    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            if (board[i][j] == d) return false;
        }        
    }
                   
    return true;
}
// backtracking algorithm - see the readme
bool solve(int board[SIZE][SIZE]) {
    int r, c;

    // base case - if there are no empty cell left, the sudoku is completely solved (yayy!)
    if (find_empty(board, r, c) == false) return true;

    // try every possible digit
    for (int d = 1; d <= 9; d++) {
        //if the placing is valid
        if (is_safe(board, r, c, d)) {
            board[r][c] = d; //digit placed!

            if (solve(board)) return true; //solving remaining board (recursiviely)

            //backtracking - undo the previous choice if it leads to a dead end
            board[r][c] = 0;
        }
    }
    // no valid digit can be placed in the cell
    return false;
}

//prints solved sudoku
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}
int main() {

    //initial unsolved puzzle (0 represents empty cell)
    int board[SIZE][SIZE] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},

        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},

        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    //Solve and displayy 
    if (solve(board)) {
        cout<<"\n";
        cout << "Solved Sudoku:\n";
        cout<<"\n";
        printBoard(board);
    }
    else {
        cout << "No solution exists.\n";
    }

    return 0;
}
// next - a heart shaped sudoku problem generator (SOON!)