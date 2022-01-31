vector <int> calculateSpan(int a[], int n)
    {
       // Your code here
       stack<int> s;
       s.push(0);
       vector<int> ans;
       ans.push_back(1);

       for(int i=1;i<n;i++)
       {
           if(a[i]<a[i-1])ans.push_back(1);
           else
           {

               while(!s.empty()&&a[i]>=a[s.top()])
               {
                 s.pop();
               }

               if(!s.empty())ans.push_back(i-s.top());
               else ans.push_back(i+1);
           }

           s.push(i);
       }
       return ans;
    }
