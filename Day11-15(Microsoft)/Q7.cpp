vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};

    int findarea(int i,int j,vector<vector<int>> &visited,vector<vector<int>>& grid)
    {
        visited[i][j]=1;

        int r=grid.size();
        int c=grid[0].size();
        int path=1;
        for(int d=0;d<8;d++)
        {
            int x=i+dir[d].first,y=j+dir[d].second;

            if(x>=0&&x<r&&y>=0&&y<c&&grid[x][y]==1&&visited[x][y]==0)
            {
                path+=findarea(x,y,visited,grid);
            }
        }
        return path;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int r=grid.size();
        int c=grid[0].size();

        vector<vector<int>> visited(r,vector<int>(c,0));//we can avoid using visited vector by making grid[i][j]=1 to 0 when we visit that cell

        int ans=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1&&visited[i][j]==0)
                {
                    ans=max(ans,findarea(i,j,visited,grid));
                }
            }
        }

        return ans;
    }


