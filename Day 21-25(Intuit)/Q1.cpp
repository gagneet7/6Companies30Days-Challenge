int findMinRec(int arr[], int i, int sumCalculated,int sumTotal,vector<vector<int>> &dp)
    {
        if (i == 0)
            return dp[i][sumCalculated]=abs((sumTotal - sumCalculated)
                       - sumCalculated);

        if(dp[i][sumCalculated]!=-1)return dp[i][sumCalculated];

        return dp[i][sumCalculated]=min(
            findMinRec(arr, i - 1, sumCalculated + arr[i - 1],sumTotal,dp),
            findMinRec(arr, i - 1, sumCalculated, sumTotal,dp));
    }
int minDifference(int arr[], int n)
{
        int sumTotal = 0;
        for (int i = 0; i < n; i++)
            sumTotal += arr[i];
        vector<vector<int>> dp(n+1,vector<int>(sumTotal+1,-1));
        return findMinRec(arr, n, 0, sumTotal,dp);
}
