long long help(string temp)
{
    int n = temp.size();
    long long num=0;
    for(int i=0;i<n;i++)
    {
        num = num*10+temp[i]-'0';
    }
    return num;
}

int missingNumber(const string& str)
{
    // Code here
    int n = str.size();
    for(int l=1;l<=6;l++)
    {
        int i=0;
        string temp = str.substr(i,l);

        long long prev = help(temp);

        int c=0;
        int flag=0;
        temp="";
        long long ans;
        int j=l;

        //for eg if l=2 then prev will have 2 digit number from start
        //and temp is empty now and j=2 now
        //to get next number,in loop it will keep on adding next chars to temp untill it becomes num>prev,which means we have got our next num in prev
        //if it satisfies below conditions,then we again make temp="" ans then increase further

        while(j<str.size())
         {
            temp = temp+str[j];
            long long num=help(temp);

            j++;
            if(prev+1==num)//pattern is going right ie inc by 1
            {
                prev = num;
                temp="";
            }

            else if(prev+2==num)//a number is missing
            {
                c++;//c keeps the count of missing numbers ,if more than 1 number is missing we return -1
                ans = prev+1;
                prev = num;
                temp="";
            }
            else if(prev<num)//if the diff bw prev and num is more than 2 means this inc sequence is not possible
            {
                flag=1;
            }

          if(c>1||flag==1)break;
         }


       if(c==1&&flag==0)return ans;//if only 1 missing exists and diff bw num and prev !>2

    }

    return -1;

}
