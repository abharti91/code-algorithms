#include<bits/stdc++.h>
using namespace std;
#define MAX 9
#define UNASSIGNED 0

bool findUnassignedLocation(int grid[MAX][MAX], int &row, int &col){
    for(row=0; row<9; row++){
        for(col=0; col<9; col++){
                if(grid[row][col] == UNASSIGNED)
                    return true;
        }
    }
    return false;
}

//check if element already in rowth row, colth col, 3*3 matrix
bool isSafe(int grid[MAX][MAX], int row, int col, int num){
    int i;
    //check if num is already present in current row indexed as row
    for(i=0; i<9; i++){
        if(grid[row][i] == num)
            return false;
    }

    for(i=0; i<9; i++){
        if(grid[i][col] == num)
            return false;
    }

    //checking in submatrix for (row,col)
    int row_submatrix = row - row%3;
    int col_submatrix = col - col%3;
    for(int x=row_submatrix; x<row_submatrix+3; x++){
        for(int y=col_submatrix; y<col_submatrix+3; y++){
            if(grid[x][y] == num)
                return false;
        }
    }
    //cout << "safe grid[" << row << "][" << col << "] = " << num << endl;
    return true;
}

bool isSudokuValid(int grid[MAX][MAX]){
    int row, col;

    //checks which row,col is UNASSIGNED and sets value for row and col
    //next steps will use this index (row,col)
    if(!findUnassignedLocation(grid, row, col))
        return true;

    //cout << "(" << row << "," << col << ")";

    for(int num=1; num<=9; num++){
        if(isSafe(grid, row, col, num)){
            grid[row][col] = num;

            if(isSudokuValid(grid))
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }
    //backtrack since all possible solutions exhausted for this (row,col)
    return false;
}

void printGrid(int grid[MAX][MAX]){
    cout << endl << "Output matrix-->" << endl;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int T, grid[MAX][MAX];
    cin >> T;
    while(T--){
        memset(grid, 0, sizeof(grid));
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cin >> grid[i][j];
            }
        }
        cout << isSudokuValid(grid);
        //printGrid(grid);
    }
    return 0;
}
