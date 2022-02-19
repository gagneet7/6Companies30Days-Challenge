int solve(vector<int>& A,int i,int j,int sumi,int sumj)
{

   if(i+1==j)
   {
      //if alice chooses ith pile
      if(sumi+A[i]>sumj+A[j])return 1;

       //if alice chooses jth pile
       if(sumi+A[j]>sumj+A[i])return 1;
       return 0;
   }

   if(dp[i][j]!=-1)
   {
       return dp[i][j];
   }

   //if alice chooses ith pile then bob can choose i+1th or jth pile
   //if bob chooses i+1th pile , then in next turn alice will have to choose from i+2th and jth pile
   //if bob chooses jth pile ,then in next turn alice will choose from i+1th and j-1th pile
   //so if we can get true ans for these choices of alice then this means alice will win
   sumi+=A[i];
   int l1=solve(A,i+2,j,sumi,sumj+A[i+1]);
   if(l1==1)return dp[i][j]=1;
   int l2=solve(A,i+1,j-1,sumi,sumj+A[j]);
   if(l2==1)return dp[i][j]=1;
   sumi-=A[i];

   //if alice chooses jth pile then bob can choose ith or j-1th pile
   //if bob chooses ith pile , then in next turn alice will have to choose from i+1th and j-1th pile
   //if bob chooses j-1th pile ,then in next turn alice will choose from ith and j-2th pile
   sumi+=A[j];
   int r1=solve(A,i+1,j-1,sumi,sumj+A[i]);
   if(r1==1)return dp[i][j]=1;
   int r2=solve(A,i,j-2,sumi,sumj+A[j-1]);

   return dp[i][j]=r2;

}
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,n-1,0,0);
    }
