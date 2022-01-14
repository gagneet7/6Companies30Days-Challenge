
int *findTwoElement(int *a, int n) {
        // code here
        int *arr;
        for(int i=0;i<n;i++)
        {
            if(a[abs(a[i])-1]>0)
            {
                a[abs(a[i])-1]=-a[abs(a[i])-1];
            }
            else
            {arr[0]=abs(a[i]);}
        }

        for(int i=0;i<n;i++)
        {
            if(a[i]>0)
            {arr[1]=i+1;break;}
        }
        return arr;
    }
