void parenthesis(int open,int close,string s,int n,vector<string> &res)
    {
     if(open==n&&close==n){
         res.push_back(s);
         return;
     }

     if(open<n)parenthesis(open+1,close,s+"(",n,res);
     if(close<open)parenthesis(open,close+1,s+")",n,res);
    }
    vector<string> AllParenthesis(int n)
    {
        // Your code goes here
        vector<string> res;
        parenthesis(0,0,"",n,res);
        return res;
    }
