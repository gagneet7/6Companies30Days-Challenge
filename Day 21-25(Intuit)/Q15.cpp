 //using binary search concept
    //making a monotonic seacrh space ie min speed can be 1 and max speed can be equal to max banana among all piles
    bool canfinish(vector<int> &piles,int h,int speed)
    {
        int time=0;
        for(int i=0;i<piles.size();i++)
        {
            time+=ceil(1.0*piles[i]/speed);
            if(time>h)return false;
        }
        if(time>h)return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(), piles.end());

        int start=1,end=max;//monotonic search space

        int ans;
        while(start<=end)
        {
            int mid=(start+end)/2;

            if(canfinish(piles,h,mid)){ans=mid;end=mid-1;}
            else start=mid+1;
        }
        return ans;
    }
