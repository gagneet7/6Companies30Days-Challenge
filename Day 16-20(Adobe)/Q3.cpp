#define ll long long int
  const int MOD = 1e9 + 7;

    int kvowelwords(int n, int k) {
        // Write Your Code here
        vector<vector<ll>> dp(n+1,vector<ll>(k+1));

        for(int j=0;j<=k;j++)dp[0][j]=1;

        for(int i =1;i <= n;i++){

            for(int j = 0;j <= k;j++){

                    //in this we have 2 choices if ith letter is consonant
                    //if j>0 then ith letter can also be vowel

                    dp[i][j] = dp[i-1][k]*21%MOD;//we can atmost have k vowels together so in
                                //so if we have i-1 letter with k vowels then i th letter must be
                                //consonant which gives us 21 choices

                    if(j > 0)//means i words have atleast 1 vowel
                    {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-1]*5%MOD) % MOD;
                        //if ith letter is consonat + i-1 words with j-1 vowels * 5 vowels for
                        //ith letter to make total j vowels
                    }
                }

            }


            return dp[n][k];
    }
