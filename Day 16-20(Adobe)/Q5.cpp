 //using 1d array
 int numOfWays(int n, int x)
    {
        // code here
        long long dp[n+1];
        long long int mod=1e9+7;
        memset(dp,0,sizeof(dp));

        dp[0]=dp[1]=1;

        int maxnum=pow(n,1.0/x);

        for(int base=2;base<=maxnum;base++)
        {
            int curr=pow(base,x);

            for(int j=n;j>=curr;j--)
            {
                dp[j]=(dp[j]%mod+dp[j-curr]%mod)%mod;
            }
        }
        return dp[n]%p;
    }


    //using 2d array
    long long dp[1001][1001];
    long long int mod=1e9+7;
    int getall(int n,int power,int base)
    {
        if(dp[n][base]!=-1)return dp[n][base];

        int r=pow(base,power);
        if(r==n)return 1;

        if(r>n)return dp[n][base]=0;

        //we have 2 options
        //include base^power in result or not
        return dp[n][base]=(getall(n-r,power,base+1)+getall(n,power,base+1))%mod;
    }
    int numOfWays(int n, int x)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int base=1;
        return getall(n,x,base);//base can go from 1 to squareroot(n),so we check for all these recursively


    }
