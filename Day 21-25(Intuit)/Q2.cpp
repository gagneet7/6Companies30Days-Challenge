//logic is to start dfs from every i,j where board[i][j]=word[0]

vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};

    bool canplace(int i,int j,vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();

        if(i<0||i>=n||j<0||j>=m||board[i][j]=='*')return false;
        return true;
    }


    bool dfs(int i,int j,int idx,string word,vector<vector<char>>& board)
    {
        if(idx==word.length())return true;

        if(board[i][j]=='*')return false;


        if(board[i][j]==word[idx])
        {
            char c=board[i][j];
            board[i][j]='*';//for preventing visiting same cell

            for(auto a:dir)
            {
                if(canplace(i+a.first,j+a.second,board))
                    {
                        if(dfs(i+a.first,j+a.second,idx+1,word,board))
                            return true;
                    }
            }

            board[i][j]=c;
        }

        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])//starting dfs from every pos = word[0]
                 {
                     if(dfs(i,j,0,word,board))return true;
                 }
            }
        }
        return false;

    }
