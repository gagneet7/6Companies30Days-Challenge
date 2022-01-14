int minSubArrayLen(int target, vector<int>& nums) {
        int minlen=INT_MAX;

        int sum=0;
        for(int start=0,end=0;end<nums.size();end++)
        {
            sum+=nums[end];

            while(sum>=target)
            {
                minlen=min(minlen,end-start+1);
                sum-=nums[start++];
            }

        }
        if(minlen==INT_MAX)return 0;
        return minlen;
    }
