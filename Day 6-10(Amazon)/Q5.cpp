 vector<vector<string>> displayContacts(int n, string contact[], string s)
    {

        int l=s.length();

        vector<vector<string>> res;

        for(int i=1;i<=l;i++)
        {
            string p=s.substr(0,i);
            vector<string> v;
            set<string> temp;
            for(int j=0;j<n;j++)
            {
                string t=contact[j].substr(0,i);
                if(p==t)temp.insert(contact[j]);
            }

            if(temp.empty())v.push_back("0");
            else
            {
                for(auto it:temp)v.push_back(it);
            }
            res.push_back(v);
       }

        return res;

    }
