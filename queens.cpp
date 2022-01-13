
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<string> > res ;
    bool isSafe(vector<string> board , int x , int y , int n){
        
        for(int row = 0 ; row < x ; row++){
            if(board[row][y] == 'Q')
                return false;
        }
        int row = x;
        int col = y;
        
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
                
        }
        row = x ; 
        col = y ;
        while(row >= 0 && col < n){
            if(board[row][col] == 'Q')
                return false;
            row--;
            col++;
                
        }
        return true;
    }
    
    void nQueen(vector<string> &board , int row , int n){
        
        if(row == n){
            res.push_back(board);
            return ;
        }
        
        for(int col = 0 ; col < n ; col++){
            
            if(isSafe(board , row , col, n)){
                board[row][col] = 'Q';
                
                nQueen(board , row+1 , n);
                 
                board[row][col] = '.'; // Backtracking
            }
        }
        
    }
public:
    vector <vector<string> > solveNQueens(int n) {
        
        //if(n <= 0) return {{}};
        vector<string> arr (n ,string(n , '.')) ;
       /* . . . . 
        . . . . 
        . . . . 
        . . . .  */

        
        nQueen(arr , 0 , n) ;
        for(int i = 0 ; i < n ; i++){
                 for(int j = 0 ; j < n ; j++){
                    cout<<res[i][j]<<" "<<endl ;
                    
                }
            cout<<endl;
            }  
       
        return res;
    } 
};

int main(){

    int n ;
    cin >> n;
    Solution ob1;
    ob1.solveNQueens(n) ;
    return 0;
}