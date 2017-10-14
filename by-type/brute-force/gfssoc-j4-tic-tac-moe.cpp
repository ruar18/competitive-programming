#include <iostream>

using namespace std;

int main()
{
        char board[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++)
                cin >> board[i][j];
        }
        // Griffy and Timothy
        bool G = false, T = false;
        // Row check
        for(int i = 0; i < 3; i++){
            if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
                G = true;
            if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
                T = true;
        }

        // Column check
        for(int i = 0; i < 3; i++){
            if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
                G = true;
            if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
                T = true;
        }

        // Major diagonal check
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
            G = true;
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
            T = true;

        // Minor diagonal check
        if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
            G = true;
        if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
            T = true;


        if(G && T)
            cout << "Error, redo" << endl;
        else if(!(G || T))
            cout << "Tie" << endl;
        else if(G)
            cout << "Griffy" << endl;
        else
            cout << "Timothy" << endl;
    }