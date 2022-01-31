int minDifference(int arr[], int n)  {
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)sum+=arr[i];
	   int dp[n+1][sum+1]; //dp[i][j]==true tells if we include till i  then we can get a subset of sum j
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<=n;i++)dp[i][0]=1;//making first col =1; as in recursion for sum=0 ans is true
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


     //since dp[i][j]==true tells us that we chose elements till i from array
     //then we can get a subset with sum j
     //and the size of this subset can be from 1 to i

     //so if we consider last row of dp array ie dp[num][i]  i -> 0-sum
     //if dp[num][i] is true means subset having all numbers and sum i exists
     //means there will also exist another subset having rest of the elements
     //and having sum = tsum-i
     //so we need to find min of these two sum
     //and we will see till mid of last row
     //for eg if total sum of all elements is 10
     //the sum will range from 0-10;
     //if subset with sum 1 exists than it is sure a subset with sum 9 will exist
     //to minimise the diff bw two we will start from sum=mid and come towards sum=0
     //if dp[n][sum]==true means this subset exist and we will stop loop as
     //we need max sum subset from left side to minimise the diff
     //for eg 5-5=0, 6-4=2 7-3=4 so as we go to more left diff increase


     for(int s1=sum/2;s1>=0;s1--)
     {
         if(dp[n][s1]==true)
         {
             int s2=sum-s1;
             return abs(s2-s1);

         }
     }

	}
