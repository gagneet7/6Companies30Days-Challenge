int atoi(string str) {
        //Your code here
        int ans=0;
        if(str[0]=='-')
        {
            for(int i=1;i<str.length();i++)
            {

                 if(str[i]<'0'||str[i]>'9')return -1;
                 int num=str[i]-48;
                 ans=ans*10+num;
            }
            return -ans;
        }
        else
        {
            for(int i=0;i<str.length();i++)
            {

                 if(str[i]<'0'||str[i]>'9')return -1;
                 int num=str[i]-48;
                 ans=ans*10+num;
            }
            return ans;
        }

    }
