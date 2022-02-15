//binary search concept
//on(nlog(s)) s is sum of elements
    int minimumSubarraysRequired(vector<int>& nums, int maxSumAllowed)
   {
        int currentSum = 0;
        int splitsRequired = 1;

        for (int element : nums) {

            if (currentSum + element <= maxSumAllowed)
            {
                currentSum += element;
            }
            else
            {
                currentSum = element;
                splitsRequired++;
            }
        }

        return splitsRequired;
    }

    int splitArray(vector<int>& nums, int m) {

        int sum = 0;
        int maxElement = INT_MIN;
        for (int element : nums) {
            sum += element;
            maxElement = max(maxElement, element);
        }

        // Define the left and right boundary of binary search
        int left = maxElement;
        int right = sum;
        int minimumLargestSum = 0;
        while (left <= right) {

            int maxSumAllowed = left + (right - left) / 2;

            // Find the minimum subarrays splits if sum of each subarray is taken as maxSumAllowed.
            //If splitsRequired is less than or equal to m move towards left i.e., smaller values
            if (minimumSubarraysRequired(nums, maxSumAllowed) <= m) {
                right = maxSumAllowed - 1;
                minimumLargestSum = maxSumAllowed;
            }
            else
                left = maxSumAllowed + 1;
        }

        return minimumLargestSum;
    }



//dp sol o((n^2)*m) sc=o(n^2)
int dp[1001][51];
    int minLargestSum(int curidx,int m,vector<int> &presum)
    {
        int n=presum.size()-1;

        if(dp[curidx][m]!=-1)return dp[curidx][m];

        if(m==1){
            return dp[curidx][m]=presum[n]-presum[curidx];
        }

       int ans=INT_MAX;

       //we can include elements upto idx=n-m in current subarray
      //so we will include elements starting from curidx upto ith idx ,and from next idx we will start new subarray whose result we will find recursively
       for(int i=curidx;i<=n-m;i++)
       {
           //for including elements from curidx upto ith idx we need cur subarray sum uto ith idx
           int subsum=presum[i+1]-presum[curidx];

           //find max from cur subarray sum and sum that next subarray will return as we need to minof the max sum;
           int maxsum=max(subsum,minLargestSum(i+1,m-1,presum));

           //finding minimum among all subarray sum for all subarrays possible
           ans=min(ans,maxsum);

           if(subsum>=ans)break;//this means is current subarray sum becomes equal to ans ,so if we will include any element more in current subarray then subsum will increse and since we are finding min out of all these we will not go further

       }
        return dp[curidx][m]=ans;

    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        vector<int> presum(n+1,0);//prefix sum array
        for(int i=0;i<n;i++)
        {
            presum[i+1]=presum[i]+nums[i];
        }
        return  minLargestSum(0,m,presum);

    }
