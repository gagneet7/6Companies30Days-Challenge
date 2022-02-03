vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
        ans.push_back(a[n-1]);
        int max=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]>=max){ans.push_back(a[i]);max=a[i];}
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
