int findInMountainArray(int k, MountainArray &mountainArr) {
        int peak;
        int s=0,e=mountainArr.length()-1;
        int a,b,c;

        //finding peak of array using binary search
        while(s<=e)
        {
            peak=(s+e)/2;

            //corner cases,1st and least element can't be peak as array is mountainarray
            if(peak==0){peak=1;break;}
            if(peak==mountainArr.length()-1){peak=mountainArr.length()-2;break;}

            a=mountainArr.get(peak-1);
            b=mountainArr.get(peak);
            c=mountainArr.get(peak+1);

            if(b>a&&b>c)break;//b is the peak

            else if(b>a)s=peak+1;//peak is on right side
            else e=peak-1; //peak is on left
        }

        if(mountainArr.get(peak)==k)return peak;

        //finding k on left of peak using bs
        s=0;e=peak-1;
        while(s<=e)
        {
            int mid=(s+e)/2;

            int cur=mountainArr.get(mid);
            if(cur==k)return mid;

            if(cur<k)s=mid+1;
            else e=mid-1;
        }

        //finding k on left of peak
        s=peak+1;e=mountainArr.length()-1;
        while(s<=e)
        {
            int mid=(s+e)/2;

            int cur=mountainArr.get(mid);
            if(cur==k)return mid;

            if(cur<k)e=mid-1;
            else s=mid+1;
        }

    return -1;//element not found
    }
