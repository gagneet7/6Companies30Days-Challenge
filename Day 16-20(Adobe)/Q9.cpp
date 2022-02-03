string nextPalin(string s) {
        //complete the function here
        int l=s.length();

        if(l<=3)return "-1";
        int mid=l/2;

        string a=s.substr(0,mid);//a is having elements from start to mid of string s
        //applying same of code of finding next higher string for string a
        int sm=mid-1;
        int i;
        for(i=mid-2;i>=0;i--)
        {
            if(a[i]<a[i+1]){sm=i;break;}
        }
        //sm has the idx of first element satisfying a[i]<a[i+1]

        if(i<0||sm==mid-1)//this means string a is highest string ,no higher string exists
        {
            return "-1";
        }


        for(int i=mid-1;i>sm;i--)
        {
                if(a[i]>a[sm])//first greater element than a[sm] from end
                   {
                       swap(a[sm],a[i]);
                       reverse(a.begin()+sm+1,a.end());
                       break;
                   }
        }

        string b=a;
        reverse(b.begin(),b.end());
        if(l%2==0)a=a+b;
        else
        {
              a=a+s[mid]+b;
        }

        return a;
    }
