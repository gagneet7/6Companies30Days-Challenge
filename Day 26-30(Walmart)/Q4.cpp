int NumberOfPath(int a, int b)
    {
        //code here
        if(a==1||b==1)return 1;
        if(a==2&&b==2)return 2;

        int dp[a][b];//dp[i][j] = num of ways to reach i,j from 0,0
        memset(dp,0,sizeof(dp));


        for(int j=0;j<b;j++)
            dp[0][j]=1;

        for(int i=0;i<a;i++)
          dp[i][0]=1;


        for(int i=1;i<a;i++)
        {
            for(int j=1;j<b;j++)
            {
                dp[i][j]=dp[i][j-1]+dp[i-1][j];//we can reach i,j from i,j-1 and i-1,j
            }
        }
        return dp[a-1][b-1];
    }
