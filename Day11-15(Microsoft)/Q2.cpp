bool isPossible(int N, vector<pair<int, int> >& p) {
	    // Code here
	   vector <int> list[N];
        for(auto i : p)
            {
                list[i.second].push_back(i.first);
            }

        vector<int> indegree(N, 0);
        for(int i = 0; i < N; ++i)
        {
            for(auto it : list[i])
            {
                 indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < N; ++i)
        {
         if(indegree[i]==0)q.push(i);
        }

        int count = 0;
        while(!q.empty())
        {
         int node = q.front();
         count += 1;
         q.pop();

         for(auto i : list[node])
         {
             indegree[i]--;
             if(indegree[i]==0)q.push(i);
         }
        }

     if(count == N) return true;
     return false;

	}

//we can also do dfs same as detecting cycle in directed graph
//here we are also doing so if indegree of a node will not become 0 hence count!=N
//this also means there is a cycle in graph
