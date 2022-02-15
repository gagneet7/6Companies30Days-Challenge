int daysRequired(int cap,vector<int>& weights)
    {
        int days=1;
        int sum=0;
        for(int i=0;i<weights.size();i++)
        {
            if(sum+weights[i]<=cap)sum+=weights[i];
            else
            {
                days++;
                sum=weights[i];
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,maxx=0;
        for(auto a:weights)
        {
            sum+=a;
            maxx=max(maxx,a);
        }

        int l=maxx,r=sum;//boundaries for binary search  least capacity of ship=max weight and at max capacity can be sum of all weights
        int ans;
        while(l<=r)
        {
            int cap=(l+r)/2;

            //we find no of days required by ship with capapcity=cap to ships weight
            //if days required are <= given days then we decrease capapcity further as we need least capapcity possible
            if(daysRequired(cap,weights)<=days)
            {
                ans=cap;
                r=cap-1;
            }
            else l=cap+1;//increse cpapcity
        }
        return ans;
    }
