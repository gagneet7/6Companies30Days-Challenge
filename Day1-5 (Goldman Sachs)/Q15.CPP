bool canPair(vector<int> nums, int k) {
        // Code here.
        map <int, int> mp;
        int rem,freq;

        for(auto x : nums)
            mp[x%k]++;//we need freq map for remainders only bcs it is the rem that matter
                      //if rem of x%k is y then there must also be a num whoes rem is k-y
                      //so we need pairs of remainders like pair of 1,k-1   2,k-2  3,k-2 ..

        if(mp[0] %2 != 0) //mp[0] has the freq of numbers completely divisble by k
            return false;   //this freq should be even bcs these numbers can only be paired with each other

        for(auto x : mp)
        {
            rem = x.first;
            freq = x.second;

            if(rem!= 0 && mp[k-rem] != freq)//for eg k is 6 and num are 7,5 rem will be 1 and 5 so freq of these rems must be same
                return false;                 //rem 2 can pair with rem 4 , rem 3 with rem 3
        }
        return true;
    }
