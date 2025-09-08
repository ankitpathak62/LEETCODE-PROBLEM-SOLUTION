class Solution {
public:
    bool  isSafe(vector<vector<char>>&board,int row,int col,char value,int n){
        for(int i=0;i<n;i++){
            //for row
            if(board[row][i]==value){ // mean for any col of ith row if data is equal to value retunr false
                return false;
            }

            //for col
            if(board[i][col]==value){ // for any row(ith) with col if data is equal to value return false 
                return false;
            }

            //for 3*3 matrix
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==value){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        //get the size
        int n=board.size();

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                //This 2 loops are for iterating the matrix

                //in case we found the empty place
                if(board[row][col]=='.'){

                    //we can fill that place with values from 1-9 
                    for(char i='1';i<='9';i++){

                        if(isSafe(board,row,col,i,n))//mean we can place this value here
                        {
                            board[row][col]=i;
                            //now check will this value give the solution
                            bool isSolutionPossible=solve(board);

                            if(isSolutionPossible){
                                return true;
                            }
                            else{
                                //backtrack // mean we cannot find the solution by putting this value at this place
                                board[row][col]='.';
                            }
                        }
                    }
                    return false; // if any of the value form 1-9 could fit in
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        //make another function
        bool possible = solve(board);
        return ;
    }
};