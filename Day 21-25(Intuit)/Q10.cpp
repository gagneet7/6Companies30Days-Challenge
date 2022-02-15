void dfs(int i,vector<int> &visited,vector<vector<int>>& isConnected)
    {
        visited[i]=1;
       for(int j=0;j<isConnected[i].size();j++)
        {
            if(visited[j]==0&&isConnected[i][j]==1)
            {
                dfs(j,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();//no of cities
        vector<int> visited(n,0);

        //we need to count no of connected components
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                 dfs(i,visited,isConnected);
                 ans++;
            }
        }
        return ans;
    }
