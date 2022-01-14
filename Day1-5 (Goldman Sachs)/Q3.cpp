int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {

        long long int p=1;

        int cnt=0;
        for(int start=0,end=0;end<n;end++)
        {
            p=p*a[end];

            while(p>=k&&start<end)
             p=p/a[start++];

             if(p<k)
             cnt+=end-start+1;

        }
        return cnt;
    }
