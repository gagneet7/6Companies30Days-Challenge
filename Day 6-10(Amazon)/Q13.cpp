int orangesRotting(vector<vector<int>>& grid) {

        int X[] ={0,0,-1,1};
		int Y[]= {-1,1,0,0};

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));//dp[i][j] gives the time taken to make orange at i,j rotten

        queue<pair<int, int>> q;

        int fresh=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    dp[i][j]=0;
                }
                else if(grid[i][j]==1)fresh++;
            }
        }
        if(fresh==0)return 0;

        int ans=0;
        while(!q.empty())
        {
            if(fresh==0)return ans;
            pair<int,int> p=q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int x=p.first+X[i];
                int y=p.second+Y[i];

                if(x>=0&&x<m&&y>=0&&y<n&&grid[x][y]==1&&dp[x][y]==-1)
                {
                    q.push({x,y});
                    dp[x][y]=dp[p.first][p.second]+1;
                    ans=max(ans,dp[x][y]);
                    fresh--;
                }
            }
        }

        if(fresh==0)return ans;
        return -1;

    }
