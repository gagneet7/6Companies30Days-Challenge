int lis(vector<int> a)
    {
        int n=a.size();
        int dp[n+1];
        dp[0]=INT_MIN;
        for(int i=1;i<=n;i++)dp[i]=INT_MAX;
        for(int i=0;i<n;i++)
        {
          int idx=upper_bound(dp,dp+n+1,a[i])-dp;
          if(dp[idx-1]<a[i]&&a[i]<dp[idx])
            dp[idx]=a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]==INT_MAX)break;
            ans=i;
        }
        return ans;
    }

    int minInsAndDel(int A[], int B[], int n, int m) {
        // code here
        //1st delete elements from a which are not in b
        //find lcs of and b , since b is sorted so lcs will be longest inc subseq in a
        //add those elements in b which are missing in lis
        //del thos elements from a which are not in lis
        unordered_set<int> b_set;
        for(int i=0;i<m;i++)
        {
            b_set.insert(B[i]);
        }

        vector<int> a_new;
        int a_del=0;
        for(int i=0;i<n;i++)
        {
            if(b_set.find(A[i])!=b_set.end())a_new.push_back(A[i]);
            else a_del++;
        }

        int lis_size=lis(a_new);

        return a_del+(a_new.size()-lis_size)+(m-lis_size);
               //deleteing elements of a not in b + deleteing elements of a_new not in lis + adding elements of b not in lis
    }
