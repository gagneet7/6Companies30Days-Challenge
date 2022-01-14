vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
    int n=string_list.size();
    map<string,vector<int>> m;
    for(int i=0;i<n;i++)
    {
       string s=string_list[i];
       sort(s.begin(),s.end());
       m[s].push_back(i);
    }

    vector<vector<string>> result;
     for(auto p:m)
     {
         vector<string> t;


         for(auto i:p.second)
          t.push_back(string_list[i]);


         result.push_back(t);
     }
     return result;
    }
