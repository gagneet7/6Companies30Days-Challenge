static bool compare(string &s1,string &s2){//is s2 is vec[i] then s1 is vec[i+1] ie s2 is before s1 in vec
        int l1=s1.length();
        int l2=s2.length();
        if(l1==l2)
        {
            if(s2>s1)return true;
            return false;
        }

        if(l2>l1)return true;
          return false;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),compare);
        return nums[nums.size()-k];
    }
