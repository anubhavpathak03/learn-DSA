#include<bits/stdc++.h>
using namespace std;

bool canPlace(int board[][20], int n, int x, int y) {
    
    // column
    for(size_t k = 0; k < x; k++) {
        if(board[k][y] == 1) {
            return false;
        }
    }

    // left Diag
    int i = x;
    int j = y;
    while(i>=0 && j>=0) {
        if(board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }
    // right Diag
    i = x;
    j = y;
    while(i>=0 && j<n) {
        if(board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    // agar if don't find queen in left diag & right diag or in same column then
    return true; // matlab us position pe queen rakh sakte hn
}

void printBoard(int n, int board[][20]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << endl;
}

int solveNQueen(int n, int board[][20], int i) {
    // base case 
    if (i == n) {
        // print board
        printBoard(n, board);
        return 1;
    }
    // rec case 
    // try to place the queen in every row
    int ways = 0;

    for(int j=0; j<n; j++) {
        // whether the current position (i, j) is safe or not
        if(canPlace(board, n, i, j)) {
            board[i][j] = 1;

            ways += solveNQueen(n, board, i + 1);

            // bool success = solveNQueen(n, board, i+1);
            // if(success) {
            //     return true;
            // }
            // agar success nhi mila tho agaye wale column mein check karengye or prev position se queen remove kardengye
            // backtrack
            board[i][j] = 0;
        }
    }
    // entire row mein hum kahin bhi queen nhi rakh paye
    // iska mtlab parent call mein update ki requirement hn
    // return false;

    return ways;


}

int main() {
    int board[20][20] = {0};
    int n;
    cin >> n;

    cout << solveNQueen(n, board, 0) << endl;

}