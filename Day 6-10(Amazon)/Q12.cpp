string colName (long long int n)
    {
        // your code here
        string str="ZABCDEFGHIJKLMNOPQRSTUVWXY";
        string s="";
        while(n)
        {
            int k=n%26;
            s=str[k]+s;
            n--;
            n=n/26;

        }

        return s;
    }
