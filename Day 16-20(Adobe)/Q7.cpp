int dp[1001][1001];

//both players play optimally
//when ever we call solve we are making player 1 to choose from 2 option available
//but these option depend upon what player 2 will choose
int solve(vector<int>& A,int i,int j)
{
   if(i>j)
   {
       return 0;
   }
   if(i==j)
   {
       return A[i];
   }

   if(dp[i][j]!=-1)
   {
       return dp[i][j];
   }

   //if player 1 chooses first coin ie i'th coin then player 2 can choose i+1 or j'th coin
   //if player 2 chooses i+1 coin then player 1 can choose i+2 or j 'th coin in his next turn
   //if player 2 chooses jth coin then player 1 can choose i+1 or j-1 'th coin in his next turn
   //we need min of these bcs player 2 will make choice in which it gets max so player 1 will be left with the min option
   int left = A[i] + min(solve(A,i+2,j),solve(A,i+1,j-1));

   //if player 1 choses last coin ie jth coin then player 2 can choose ith or j-1'th coin
   int right = A[j] + min(solve(A,i,j-2),solve(A,i+1,j-1));

   return dp[i][j] = max(left,right);//player 1 will pick max of the 2 options
}
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	 memset(dp,-1,sizeof(dp));
     return solve(A,0,n-1);
    }
