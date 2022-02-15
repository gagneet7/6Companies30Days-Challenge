void help(string str,int k,string &maxm,int ctr){
       if(k==0)return;
       int n=str.size();
       char maxi=str[ctr];
       for(int i=ctr+1;i<n;i++)
       {
           if(str[i]>maxi)maxi=str[i];
       }

       if(maxi!=str[ctr])k--;//ctr is starting idx, if maxi!=str[ctr] this means str[ctr] will be swapped with maxi so k--
                             //else k remains same which means str[ctr] is maxi,so no need to swap

       for (int j=n-1;j>=ctr;j--)
       {
           if(str[j]==maxi)
           {
               swap(str[ctr],str[j]);
               if(str.compare(maxm)>0)maxm=str;

               help(str,k,maxm,ctr+1);
               swap(str[ctr],str[j]);
           }
       }
   }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string maxm="";
       help(str,k,maxm,0);
       return maxm;

    }
