double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        priority_queue<pair<double, int>> pq;
        pq.push({(double)1.0, start});
        for(int i = 0; i < edges.size(); i++){
            vector<int> edge = edges[i];
            graph[edge[0]].push_back({edge[1], succProb[i]});
            graph[edge[1]].push_back({edge[0], succProb[i]});
        }

        vector<bool> visited(n, false);//we could avoid using visit and push already visited node into queue,this will not affect ans as we are using max heap so prob other than first visit to the node will always be lesser,so our answer will not be affected
        //but time will increses bcs of push and pop of same node into queue

        while(!pq.empty()){
            auto [prob, pos] = pq.top();
            pq.pop();

            //since we are max heap so when ever we will reach end ,this prob will be maximum ,after this when ever we
            //will encounter end the corresponding prob wil be lesser than prev encounter
            if(pos == end)return prob;

            if(visited[pos])
                continue;
            visited[pos] = true;
            for(auto next: graph[pos])
                pq.push({prob* next.second, next.first});
        }
        return 0;
    }
