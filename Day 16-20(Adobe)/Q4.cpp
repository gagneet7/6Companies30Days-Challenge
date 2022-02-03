//similar to subset with sum k
    //we need to find out if there exists a subset having sum=(sum of all elements)/2;
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0;i<n;i++)sum+=arr[i];

        if(sum%2!=0)return 0;

        sum=sum/2;
        int dp[n+1][sum+1];
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=0;i<=sum;i++)dp[0][i]=0;
        dp[0][0]=1;

        for(int i=1;i<=n;i++)
        {
           for(int j=1;j<=sum;j++)
           {
               if(arr[i-1]>j)
               dp[i][j]=dp[i-1][j];

               else
               {
                   dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
               }

           }
        }
        return dp[n][sum];
    }
