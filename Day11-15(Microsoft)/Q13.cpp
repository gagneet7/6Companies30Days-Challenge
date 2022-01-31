void dfs(int i,int c,int d,vector<int> adj[],vector<bool> &visited)
    {
        visited[i]=true;

        for(auto nbr:adj[i])
        {
            if(i==c&&nbr==d)continue;
            if(visited[nbr]==false)dfs(nbr,c,d,adj,visited);
        }
    }

    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        //we will start dfs from c and ignore edge cd during dfs
        //if still d is reachable from any other node this means edge cd was not bridge
        vector<bool> visited(V,false);
        dfs(c,c,d,adj,visited);

        if(visited[d])return 0;
        return 1;

    }
