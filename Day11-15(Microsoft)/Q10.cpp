int FindMaxSum(int a[], int n)
    {
        // Your code here
        int incl=a[0];
        int excl=0;
        for(int i=1;i<n;i++)
        {   int new_excl=max(excl,incl);//we can include previous element or can exclude it based upon what gives us max
            incl=excl+a[i];//excluding previous element and including this
            excl=new_excl;
        }
        return max(incl,excl);
    }
