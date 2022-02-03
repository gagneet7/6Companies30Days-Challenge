 vector<string> winner(string arr[],int n)
    {

        map<string,int> m;
        int f=0;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
            f=max(f,m[arr[i]]);
        }

        vector<string> v;

        for(auto a:m)
        {
            if(a.second==f){
                v.push_back(a.first);
                v.push_back(to_string(f));
                break;
            }
        }
        return v;
    }
