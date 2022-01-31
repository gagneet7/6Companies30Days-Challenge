vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c)
    {
        // code here
        vector<int> res;

        int sr=0,sc=0,er=r-1,ec=c-1;

        while(sr<=er&&sc<=ec)
        {
            for(int i=sc;i<=ec;i++)
            {
                res.push_back(m[sr][i]);
            }
            sr++;


            for(int i=sr;i<=er;i++)
            {
                res.push_back(m[i][ec]);
            }
            ec--;


            if(sr<=er)
            {
            for(int i=ec;i>=sc;i--)
            {
                res.push_back(m[er][i]);
            }
            er--;
            }

            if(ec>=sc)
            {
            for(int i=er;i>=sr;i--)
            {
                res.push_back(m[i][sc]);
            }
            sc++;
            }

        }
        return res;
    }
