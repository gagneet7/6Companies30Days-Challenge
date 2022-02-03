string amendSentence (string s)
    {
        // your code here
        string res="";
        res+=tolower(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(isupper(s[i]))
            {
                res+=" ";
                res+=tolower(s[i]);
            }
            else res+=s[i];
        }
        return res;
    }
