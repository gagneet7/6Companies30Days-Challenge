int longestMountain(vector<int>& arr) {

     int n = arr.size(),r = 1,ans = 0,left = 0,right = 0;
        while(r < n)
        {
            while(r < n && arr[r-1] == arr[r]) r++;
            while(r < n && arr[r-1] < arr[r]) r++,left++;
            while(r < n && arr[r-1] > arr[r]) r++,right++;
            if(left && right) ans = max(left+right+1,ans);
            right = left = 0;
        }
        return ans;
    }
