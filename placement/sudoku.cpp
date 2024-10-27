#include<bits/stdc++.h>
using namespace std;
# define N 9
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, int coloum, int num){
    for(int i=0; i<9; i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    
    for(int i=0; i<9; i++){
        if(grid[i][coloum] == num){
            return false;
        }
    }
    int sr = row-row%3, sc = coloum-coloum%3;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[i+sr][j+sc] == num){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int grid[N][N],int row, int coloum){
    if(row == N-1 && coloum == N) return true;
    if(coloum == N){
        row++;
        coloum=0;
    }
    if(grid[row][coloum] > 0) return solveSudoku(grid,row,coloum+1);
    
    for(int num=1; num<=N; num++){
        if(isSafe(grid,row,coloum,num)){
            grid[row][coloum] = num;
            if(solveSudoku(grid,row,coloum+1)){
                return true;
            }
        }
        grid[row][coloum] = 0;
    }
    return false;
}

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = { { 5, 8, 0, 0, 2, 0, 0, 4, 0 },
                       { 0, 9, 0, 0, 0, 0, 0, 7, 0 },
                       { 0, 4, 3, 0, 0, 1, 0, 0, 0 },
                       { 0, 0, 4, 0, 0, 0, 8, 9, 0 },
                       { 8, 6, 5, 0, 0, 0, 0, 0, 1 },
                       { 0, 0, 9, 0, 0, 8, 4, 0, 0 },
                       { 6, 5, 8, 9, 1, 3, 7, 2, 4 },
                       { 4, 0, 0, 6, 0, 0, 0, 0, 9 },
                       { 9, 0, 0, 0, 5, 0, 0, 0, 0 } };

    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "no solution  exists " << endl;

    return 0;
    // This is code is contributed by Pradeep Mondal P
}