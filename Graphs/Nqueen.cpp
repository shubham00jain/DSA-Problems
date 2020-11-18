/*
In this we have to check 3 things before placing a queen:
1. Same row
2. Same column
3. Same diagonal

We eliminate column by placing one queen in every column ourselves in every iteration. [see code] We can further reduce the places to check by checking only to the left of the
current cell because we know nothing is on the right of cell. We now only have to check 3 places:
1. The row from i=0 to i<col
2. The upper left diagonal from i = row, j= col to i>=0 && j>=0
3. The lower left diagonal form i=row, j=col to i<n && j>=0
*/

#include <bits/stdc++.h>
using namespace std;

bool check(vector< vector<int> >&board, int row, int col, int n ){
    if(col>n-1)
        return false;
    
    int i,j;
    
    for(i=0; i<col;i++){
        if(board[row][i])
        return false;
    }
        
    for(i= row, j = col ; i>=0 && j >=0 ; i-- , j-- ){
        if(board[i][j])
            return false;
    }
    for(i =row , j = col; i< n && j>=0; i++, j--){
        if(board[i][j])
            return false;
    }
    return true;
}

void Nqueen(vector< vector<int> > &board, int col, int n, 
            vector< vector<int> > &res, vector<int> &sol ){
    
    if(col > n-1){
        res.push_back(sol);
        return;
    }
    
    for(int i=0; i<n;i++){
        if(check(board,i,col,n)){
            board[i][col] = 1;
            sol.push_back(i+1);
            Nqueen(board,col+1,n,res,sol);
            if(!sol.empty())
                sol.pop_back();
        }
        board[i][col] = 0;
    }
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector< vector<int> > board(n, vector<int>(n,0));
	    vector< vector<int> > res;
	    vector<int> sol;
	    Nqueen(board,0,n,res,sol);
	    if(!res.size())
	        cout << -1;
	   for(int i=0;i<res.size();i++){
	       cout << "[";
	       for(int j=0;j<res[i].size();j++){
	           cout << res[i][j]<<" ";
	       }
	       cout << "] ";
	   }
	   cout << endl;
	}
	
	return 0;
}
