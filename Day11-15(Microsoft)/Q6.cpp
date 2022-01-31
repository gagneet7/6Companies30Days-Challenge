vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void words(int no,string s,int a[], int N,vector<string> &ans)
    {
        if(no==N){ans.push_back(s);return;}

        for(int i=0;i<v[a[no]].size();i++)
        {
            words(no+1,s+v[a[no]][i],a,N,ans);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        words(0,"",a,N,ans);
        return ans;

    }
