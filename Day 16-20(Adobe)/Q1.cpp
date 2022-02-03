vector<int> subarraySum(int a[], int n, long long s)
    {
        // Your code here

        int sum=a[0];
        vector<int> result;
        if(sum==s){result.push_back(1);result.push_back(1);return result;}

        int st=0;
        for(int e=1;e<n;e++)
        {

            while(sum+a[e]>s&&st<e){sum-=a[st];st++;}
            sum+=a[e];

            if(sum==s)
               {
                   result.push_back(st+1);
                   result.push_back(e+1);
                   return result;
               }
        }
        result.push_back(-1);
        return result;
    }
