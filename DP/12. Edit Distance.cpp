// https://practice.geeksforgeeks.org/problems/edit-distance3702/1#

class Solution
{
	public:
	
	    long int solve( string s1, string s2, vector<vector<long int>>&dp, long int x, long int y){
	        
	        if(x == 0 ){
	            return dp[x][y] =  y;
	        }
	        
	        if(y == 0){
	            return dp[x][y] = x;
	        }
	        
            if( dp[x][y] !=-1  ){
                return dp[x][y];
            }
	        
	        
	        //same
	        if(s1[x-1] == s2[y-1])
	            return dp[x][y] =  solve( s1,s2,dp,x-1,y-1 );
	            
	       else{
	           
	           // replace
	           long int a = solve(s1,s2,dp,x-1,y-1);
	           // delete
	           long int b = solve(s1,s2,dp,x-1,y);
	           // insert
	           long int c = solve(s1,s2,dp,x,y-1);
	           
	           return dp[x][y] =  1+ min(a, min(b,c) );
	       }
	        
	        return -1;
	    }
	
		int editDistance(string s, string t)
		{   
		    long int n1 = s.size();
		    long int n2 = t.size();
		    
		    vector<vector<long int>> dp(n1+1, vector<long int>(n2+1, -1));
		    
		    return solve(s,t,dp,n1,n2);
		}
};
